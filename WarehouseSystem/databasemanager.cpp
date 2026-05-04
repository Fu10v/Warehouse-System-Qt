#include "databasemanager.h"
#include <QDebug>

#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

DatabaseManager::DatabaseManager()
{
    // Ініціалізація драйвера
    m_instance = std::make_unique<mongocxx::instance>();
}
//Функція підключення до бази даних
bool DatabaseManager::connectToDatabase(const QString& host, int port, const QString& dbName, const QString& username, const QString& password)
{
    try {
        // Формуємо рядок підключення (URI)
        // Формат: mongodb://user:password@host:port
        QString uriString = "mongodb://";

        if (!username.isEmpty() && !password.isEmpty()) {
            uriString += username + ":" + password + "@";
        }

        uriString += host + ":" + QString::number(port);

        // Створюємо URI та клієнта
        mongocxx::uri uri(uriString.toStdString());
        m_client = std::make_unique<mongocxx::client>(uri);

        // Обираємо базу даних
        m_db = (*m_client)[dbName.toStdString()];

        // Перевірка зв'язку (Ping)
        auto adminDb = (*m_client)["admin"];
        adminDb.run_command(make_document(kvp("ping", 1)));

        qDebug() << "Connected to:" << uriString << " DB:" << dbName;
        m_connected = true;
        return true;

    } catch (const std::exception& e) {
        qCritical() << "Connection error:" << e.what();
        m_connected = false;
        return false;
    }
}
//Функція відключення
void DatabaseManager::disconnect()
{
    // У Mongo драйвері немає явного "disconnect",
    // тому можемо просто скинути клієнта
    m_client.reset();
    m_connected = false;
    qDebug() << "Disconnected.";
}
//Геттер підключення
bool DatabaseManager::isConnected() const
{
    return m_connected;
}

std::optional<QString> DatabaseManager::authenticateUser(const QString &username, const QString &password)
{
    try {
        auto collection = m_db["Users"];

        auto result = collection.find_one(make_document(
            kvp("username", username.toStdString()),
            kvp("password", password.toStdString())
            ));

        if (result) {
            auto doc = result->view();
            std::string role = std::string(doc["role"].get_string().value);
            return QString::fromStdString(role);
        }

    } catch (const std::exception& e) {
        return QString::fromStdString("Authentication failed");
        qCritical() << "Authentication error:" << e.what();
    }

    return std::nullopt;
}
//Отримання всіх окументів з бази даних
QVector<Item> DatabaseManager::getAllItems()
{
    QVector<Item> items;

    try {
        auto collection = m_db["Data"];

        // Знайти всі документи (порожній фільтр {})
        auto cursor = collection.find({});

        for (auto&& doc : cursor) {
            Item item;

            // Отримуємо ID (перетворюємо OID в рядок)
            item.id = QString::fromStdString(doc["_id"].get_oid().value.to_string());

            // Отримуємо рядкові поля
            if (doc["article"]) item.article = QString::fromStdString(std::string(doc["article"].get_string().value));
            if (doc["name"])    item.name = QString::fromStdString(std::string(doc["name"].get_string().value));
            if (doc["unit"])    item.unit = QString::fromStdString(std::string(doc["unit"].get_string().value));
            if (doc["date"])    item.date = QString::fromStdString(std::string(doc["date"].get_string().value));
            if (doc["supplier"]) item.supplier = QString::fromStdString(std::string(doc["supplier"].get_string().value));

            // Отримуємо числа (double)
            if (doc["quantity"]) item.quantity = doc["quantity"].get_double().value;
            if (doc["price"])    item.price = doc["price"].get_double().value;

            items.append(item);
        }
    } catch (const std::exception& e) {
        qCritical() << "Error fetching items:" << e.what();
    }

    return items;
}
//Додання предмету до бази даних
bool DatabaseManager::addItem(const Item &item)
{
    try {
        // Обираємо колекцію з товарами
        auto collection = m_db["Data"];

        // Створюємо документ (BSON)
        auto doc_value = make_document(
            kvp("article", item.article.toStdString()),
            kvp("name", item.name.toStdString()),
            kvp("quantity", item.quantity),
            kvp("unit", item.unit.toStdString()),
            kvp("price", item.price),
            kvp("date", item.date.toStdString()),
            kvp("supplier", item.supplier.toStdString())
            );

        // Відправляємо в базу
        // insert_one повертає результат, який містить ID нового запису
        auto result = collection.insert_one(doc_value.view());

        // Перевіряємо результат
        if (result) {
            // Для налагодження виведемо ID створеного запису
            qDebug() << "Successfully added item. New ID:"
                     << QString::fromStdString(result->inserted_id().get_oid().value.to_string());
            return true;
        }

    } catch (const std::exception& e) {
        qCritical() << "Error adding item to MongoDB:" << e.what();
    }

    return false; // Якщо сталася помилка
}
//Оновлення предмету в базі даних
bool DatabaseManager::updateItem(const QString &id, const Item &item)
{
    try {
        auto collection = m_db["Data"];

        // Створюємо фільтр (шукаємо по _id)
        bsoncxx::oid oid(id.toStdString());
        auto filter = make_document(kvp("_id", oid));

        // Створюємо команду оновлення ($set)
        auto update_doc = make_document(kvp("$set", make_document(
                                                        kvp("article", item.article.toStdString()),
                                                        kvp("name", item.name.toStdString()),
                                                        kvp("quantity", item.quantity),
                                                        kvp("unit", item.unit.toStdString()),
                                                        kvp("price", item.price),
                                                        kvp("date", item.date.toStdString()),
                                                        kvp("supplier", item.supplier.toStdString())
                                                        )));

        // Виконуємо оновлення
        auto result = collection.update_one(filter.view(), update_doc.view());

        return result && result->modified_count() > 0;

    } catch (const std::exception& e) {
        qCritical() << "Error updating item:" << e.what();
        return false;
    }
}
//Видалення предмету
bool DatabaseManager::deleteItem(const QString &id)
{
    try {
        auto collection = m_db["Data"];

        // Перетворюємо рядок ID у формат MongoDB ObjectId
        bsoncxx::oid oid(id.toStdString());

        // Створюємо фільтр: видалити документ, у якого "_id" == oid
        auto filter = make_document(kvp("_id", oid));

        // Виконуємо видалення
        auto result = collection.delete_one(filter.view());

        // Перевіряємо, чи було щось видалено (deleted_count > 0)
        if (result && result->deleted_count() > 0) {
            qDebug() << "Item deleted successfully. ID:" << id;
            return true;
        } else {
            qWarning() << "Item not found or not deleted. ID:" << id;
            return false;
        }

    } catch (const std::exception& e) {
        qCritical() << "Error deleting item:" << e.what();
        return false;
    }
}

InventoryStats DatabaseManager::getStatistics()
{
    InventoryStats stats;
    stats.totalPositions = 0;
    stats.totalQuantity = 0.0;
    stats.totalValue = 0.0;

    // Отримуємо всі товари (використовуємо вже існуючий метод)
    QVector<Item> items = getAllItems();

    stats.totalPositions = items.size();

    // Проходимося по списку і сумуємо
    for (const Item& item : items) {
        stats.totalQuantity += item.quantity;
        stats.totalValue += (item.quantity * item.price);
    }

    return stats;
}
