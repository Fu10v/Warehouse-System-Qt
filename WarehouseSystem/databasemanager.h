#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QVector>
#include <optional>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>

// Проста структура для користувача
struct User {
    QString username;
    QString password; // У реальності тут має бути хеш
    QString role;     // "Manager" або "Worker"
};

struct Item {
    QString id;       // Унікальний ID з Mongo (OID)
    QString article;  // Артикул
    QString name;     // Назва
    double quantity;  // Кількість
    QString unit;     // Одиниця виміру
    double price;     // Ціна
    QString date;     // Дата
    QString supplier; // Постачальник
};

struct InventoryStats {
    int totalPositions;     // Кількість унікальних найменувань
    double totalQuantity;   // Загальна кількість штук (сума всіх quantity)
    double totalValue;      // Загальна вартість складу (сума quantity * price)
};

class DatabaseManager
{
public:
    // Патерн Singleton - щоб у нас був один менеджер на всю програму
    static DatabaseManager& instance();

    // Підключення до бази
    bool connectToDatabase(const QString& host, int port, const QString& dbName, const QString& username, const QString& password);
    void disconnect();
    bool isConnected() const;

    // Методи для вікна логіну
    // Повертає роль користувача, якщо логін/пароль вірні, або std::nullopt
    std::optional<QString> authenticateUser(const QString& username, const QString& password);

    QVector<Item> getAllItems();
    bool addItem(const Item& item);
    bool updateItem(const QString& id, const Item& item);
    bool deleteItem(const QString& id);

    InventoryStats getStatistics();

private:
    DatabaseManager(); // Приватний конструктор
    ~DatabaseManager() = default;

    // Внутрішні об'єкти MongoDB
    // instance має бути створений один раз
    std::unique_ptr<mongocxx::instance> m_instance;
    std::unique_ptr<mongocxx::client> m_client;
    mongocxx::database m_db;
    bool m_connected = false;
};

#endif // DATABASEMANAGER_H
