#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databasemanager.h"
#include "itemwindow.h"
#include "connectiondialog.h"
#include "statisticsdialog.h"
#include <QMessageBox>
#include "aboutwindow.h"

MainWindow::MainWindow(const QString &role, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_userRole(role)
{
    ui->setupUi(this);
    m_model = new QStandardItemModel(this);
    m_proxyModel = new QSortFilterProxyModel(this);
    m_proxyModel->setSourceModel(m_model);
    m_proxyModel->setFilterKeyColumn(-1);
    m_proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(m_proxyModel);
    setupTable();
    setupRolePermissions();
    loadData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Встановлюємо інтерфейс користувача за ролью
void MainWindow::setupRolePermissions()
{
    // Показуємо роль у статус-барі (внизу вікна)
    ui->statusbar->showMessage("User: " + m_userRole);

    // Якщо це звичайний робітник - ховаємо небезпечні кнопки
    if (m_userRole == "Worker") {
        ui->actionDelete_Selected_Item->setEnabled(false);
        ui->actionDelete_Item->setEnabled(false);
    }
}

//Налаштовуємо таблицю
void MainWindow::setupTable()
{
    // Задаємо заголовки стовпців
    m_model->setHorizontalHeaderLabels({
        "ID", "Article", "Name", "Quantity", "Unit", "Price", "Date", "Supplier"
    });

    // Ховаємо колонку ID (вона потрібна програмі, але не користувачу)
    // (Припустимо, ID - це 0-й стовпець)
    ui->tableView->setColumnHidden(0, true);

    // Розтягуємо останню колонку
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // Забороняємо редагувати комірки прямо в таблиці (тільки через кнопку Edit)
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Виділяти одразу весь рядок, а не одну клітинку
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

//Заповнюємо таблицю даними
void MainWindow::loadData()
{
    // Очищаємо старі дані (але залишаємо заголовки)
    m_model->removeRows(0, m_model->rowCount());

    // Отримуємо дані з бази
    QVector<Item> items = DatabaseManager::instance().getAllItems();

    // Заповнюємо модель
    for (const Item& item : items) {
        QList<QStandardItem*> row;

        // Створюємо комірки
        row << new QStandardItem(item.id);
        row << new QStandardItem(item.article);
        row << new QStandardItem(item.name);

        QStandardItem* qtyItem = new QStandardItem();
        qtyItem->setData(item.quantity, Qt::DisplayRole);
        row << qtyItem;

        row << new QStandardItem(item.unit);

        QStandardItem* priceItem = new QStandardItem();
        priceItem->setData(item.price, Qt::DisplayRole);
        row << priceItem;

        row << new QStandardItem(item.date);
        row << new QStandardItem(item.supplier);

        // Додаємо рядок у модель
        m_model->appendRow(row);
    }
}

void MainWindow::on_actionAdd_Item_2_triggered()
{
    // Створюємо вікно
    ItemWindow window(this);

    // Встановлюємо заголовок вікна
    window.setWindowTitle("Adding a new item");

    // Відкриваємо вікно і чекаємо
    if (window.exec() == QDialog::Accepted) {
        // Повідомлення про успішне виконання
        QMessageBox::information(this, "Item added",
                             "Item added successfully!");
        // Якщо користувач успішно додав товар і натиснув ОК,
        // перезавантажуємо таблицю, щоб побачити новий запис.
        loadData();
    }
}


void MainWindow::on_actionEdit_Item_triggered()
{
    auto selectionModel = ui->tableView->selectionModel();
    auto selectedRows = selectionModel->selectedRows();
    //Повідомлення про пусте поле
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a product to edit!");
        return;
    }

    // Отримуємо номер рядка (беремо перший виділений, якщо їх декілька)
    // Отримуємо індекс з ПРОКСІ (те, що бачить юзер)
    QModelIndex proxyIndex = selectedRows.first();

    // --- МАГІЯ: Перетворюємо його на реальний індекс моделі ---
    QModelIndex sourceIndex = m_proxyModel->mapToSource(proxyIndex);
    int row = sourceIndex.row();

    // Збираємо дані з моделі назад у структуру Item
    Item item;

    item.id       = m_model->item(row, 0)->text();
    item.article  = m_model->item(row, 1)->text();
    item.name     = m_model->item(row, 2)->text();
    item.quantity = m_model->item(row, 3)->data(Qt::DisplayRole).toDouble();
    item.unit     = m_model->item(row, 4)->text();
    item.price    = m_model->item(row, 5)->data(Qt::DisplayRole).toDouble();
    item.date     = m_model->item(row, 6)->text();
    item.supplier = m_model->item(row, 7)->text();

    // Відкриваємо вікно редагування
    ItemWindow window(this);

    // Передаємо зібраний item у вікно (щоб заповнити поля)
    window.setItemData(item);

    // Запускаємо вікно і чекаємо результату
    if (window.exec() == QDialog::Accepted) {
        //Повідомлення про успішне виконання
        QMessageBox::information(this, "Item added",
                                 "Item edited successfully!");
        // Якщо користувач натиснув "Оновити", перезавантажуємо таблицю,
        // щоб побачити зміни
        loadData();
    }
}


void MainWindow::on_actionDelete_Item_triggered()
{
    // Перевіряємо, чи виділений рядок
    auto selectionModel = ui->tableView->selectionModel();
    auto selectedRows = selectionModel->selectedRows();
    //Повідомлення про пустий рядок
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Please select the product to delete!");
        return;
    }

    // Запитуємо підтвердження
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Delete",
                                  "Are you sure you want to delete this item?\nThis action cannot be undone.",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return;
    }

    // Отримуємо ID з прихованої колонки
    QModelIndex proxyIndex = selectedRows.first();

    // Перетворення індексу
    QModelIndex sourceIndex = m_proxyModel->mapToSource(proxyIndex);
    int row = sourceIndex.row();

    QString id = m_model->item(row, 0)->text();

    // Викликаємо видалення
    if (DatabaseManager::instance().deleteItem(id)) {
        // Якщо успішно — оновлюємо таблицю
        loadData();
        // Повідомлення про успішне виконання
        QMessageBox::information(this, "Success", "Item successfully deleted.");
    } else {
        // Повідомлення про неуспішне виконання
        QMessageBox::critical(this, "Error", "Failed to delete product from database.");
    }
}

//Функція пошуку  таблиці
void MainWindow::on_SearclineEdit_textChanged(const QString &arg1)
{
    m_proxyModel->setFilterFixedString(arg1);
}


void MainWindow::on_actionAdd_Item_triggered()
{
    // Створюємо вікно
    ItemWindow window(this);

    // Встановлюємо заголовок вікна
    window.setWindowTitle("Adding a new item");

    // Відкриваємо вікно і чекаємо
    if (window.exec() == QDialog::Accepted) {
        // Повідомлення про успішне виконання
        QMessageBox::information(this, "Item added",
                                 "Item added successfully!");
        // Якщо користувач успішно додав товар і натиснув ОК,
        // перезавантажуємо таблицю, щоб побачити новий запис.
        loadData();
    }
}


void MainWindow::on_actionEdit_Selecte_Item_triggered()
{
    auto selectionModel = ui->tableView->selectionModel();
    auto selectedRows = selectionModel->selectedRows();
    //Повідомлення про пусте поле
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a product to edit!");
        return;
    }

    // Отримуємо номер рядка (беремо перший виділений, якщо їх декілька)
    // Отримуємо індекс з ПРОКСІ (те, що бачить юзер)
    QModelIndex proxyIndex = selectedRows.first();

    // --- МАГІЯ: Перетворюємо його на реальний індекс моделі ---
    QModelIndex sourceIndex = m_proxyModel->mapToSource(proxyIndex);
    int row = sourceIndex.row();

    // Збираємо дані з моделі назад у структуру Item
    Item item;

    item.id       = m_model->item(row, 0)->text();
    item.article  = m_model->item(row, 1)->text();
    item.name     = m_model->item(row, 2)->text();
    item.quantity = m_model->item(row, 3)->data(Qt::DisplayRole).toDouble();
    item.unit     = m_model->item(row, 4)->text();
    item.price    = m_model->item(row, 5)->data(Qt::DisplayRole).toDouble();
    item.date     = m_model->item(row, 6)->text();
    item.supplier = m_model->item(row, 7)->text();

    // Відкриваємо вікно редагування
    ItemWindow window(this);

    // Передаємо зібраний item у вікно (щоб заповнити поля)
    window.setItemData(item);

    // Запускаємо вікно і чекаємо результату
    if (window.exec() == QDialog::Accepted) {
        //Повідомлення про успішне виконання
        QMessageBox::information(this, "Item added",
                                 "Item edited successfully!");
        // Якщо користувач натиснув "Оновити", перезавантажуємо таблицю,
        // щоб побачити зміни
        loadData();
    }
}



void MainWindow::on_actionDelete_Selected_Item_triggered()
{
    // Перевіряємо, чи виділений рядок
    auto selectionModel = ui->tableView->selectionModel();
    auto selectedRows = selectionModel->selectedRows();
    //Повідомлення про пустий рядок
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Please select the product to delete!");
        return;
    }

    // Запитуємо підтвердження
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Delete",
                                  "Are you sure you want to delete this item?\nThis action cannot be undone.",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return;
    }

    // Отримуємо ID з прихованої колонки
    QModelIndex proxyIndex = selectedRows.first();

    // Перетворення індексу
    QModelIndex sourceIndex = m_proxyModel->mapToSource(proxyIndex);
    int row = sourceIndex.row();

    QString id = m_model->item(row, 0)->text();

    // Викликаємо видалення
    if (DatabaseManager::instance().deleteItem(id)) {
        // Якщо успішно — оновлюємо таблицю
        loadData();
        // Повідомлення про успішне виконання
        QMessageBox::information(this, "Success", "Item successfully deleted.");
    } else {
        // Повідомлення про неуспішне виконання
        QMessageBox::critical(this, "Error", "Failed to delete product from database.");
    }
}


void MainWindow::on_actionConnect_to_Database_2_triggered()
{
    ConnectionDialog dialog(this);

    // Відкриваємо вікно і чекаємо, поки користувач натисне "Connect"
    if (dialog.exec() == QDialog::Accepted) {

        // Беремо дані з полів
        QString host = dialog.getHost();
        int port = dialog.getPort();
        QString dbName = dialog.getDbName();

        // Пробуємо підключитися
        bool success = DatabaseManager::instance().connectToDatabase(host, port, dbName, "", "");

        // Реагуємо на результат
        if (success) {
            ui->statusbar->showMessage("Connected to: " + host);
            QMessageBox::information(this, "Success", "Successfully connected to the database!");

            // Одразу завантажуємо дані
            loadData();
        } else {
            ui->statusbar->showMessage("Disconnected");
            QMessageBox::critical(this, "Error", "Connection failed. Please check your details.");
        }
    }
}


void MainWindow::on_actionConnect_to_Database_triggered()
{
    ConnectionDialog dialog(this);

    // Відкриваємо вікно і чекаємо, поки користувач натисне "Connect"
    if (dialog.exec() == QDialog::Accepted) {

        // Беремо дані з полів
        QString host = dialog.getHost();
        int port = dialog.getPort();
        QString dbName = dialog.getDbName();

        // Пробуємо підключитися
        bool success = DatabaseManager::instance().connectToDatabase(host, port, dbName, "", "");

        // Реагуємо на результат
        if (success) {
            ui->statusbar->showMessage("Connected to: " + host);
            QMessageBox::information(this, "Success", "Successfully connected to the database!");

            // Одразу завантажуємо дані
            loadData();
        } else {
            ui->statusbar->showMessage("Disconnected");
            QMessageBox::critical(this, "Error", "Connection failed. Please check your details.");
        }
    }
}


void MainWindow::on_actionShow_Summary_triggered()
{
    // ЗАХИСТ: Перевірка прав доступу
    // Якщо поточний користувач - Worker, ми його не пускаємо
    if (m_userRole == "Worker") {
        QMessageBox::warning(this, "Access denied",
                             "Only managers have access to financial statistics!");
        return;
    }

    // Отримуємо статистику з бази
    InventoryStats stats = DatabaseManager::instance().getStatistics();

    // Відкриваємо вікно
    StatisticsDialog dialog(this);
    dialog.setStats(stats); // Передаємо підраховані цифри
    dialog.exec();
}


void MainWindow::on_actionAbout_triggered()
{
    AboutWindow window(this); // Створюємо вікно
    window.exec();
}

