#include "loginwindow.h"
#include "databasemanager.h" // <--- Наш новий клас
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Підключаємо базу даних
    if (!DatabaseManager::instance().connectToDatabase("localhost", 27017, "Warehouse_System", "", "")) {
        QMessageBox::critical(nullptr, "Error", "Failed to connect to database!");
        return -1;
    }

    // Запускаємо логін
    LoginWindow w;
    w.show();

    return a.exec();
}
