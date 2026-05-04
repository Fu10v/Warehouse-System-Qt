#include "loginwindow.h"
#include "databasemanager.h"
#include "mainwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
//Натискання кнопки login
void LoginWindow::on_loginButton_clicked()
{
    // Очищаємо попередні повідомлення про помилки
    ui->warningLabel->clear();

    // Отримуємо текст з полів (використовуємо твої назви!)
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    // Перевірка на порожнечу
    if (username.isEmpty() || password.isEmpty()) {
        ui->warningLabel->setText("Please fill in all fields!");
        ui->warningLabel->setStyleSheet("color: red; font-weight: bold;");
        return;
    }

    // Звертаємося до бази даних
    auto role = DatabaseManager::instance().authenticateUser(username, password);

    // Перевіряємо результат
    if (role.has_value()) {
        // --- УСПІХ ---
        QString userRole = role.value(); // "Manager" або "Worker"

        MainWindow *mainWindow = new MainWindow(userRole);
        mainWindow->show();

        // Закриваємо вікно логіну
        this->close();
    } else {
        // --- НЕВДАЧА ---
        ui->warningLabel->setText("Incorrect login or password!");
        ui->warningLabel->setStyleSheet("color: red; font-weight: bold;");

        // Очистка паролю для зручності
        ui->passwordEdit->clear();
        ui->passwordEdit->setFocus();
    }
}

