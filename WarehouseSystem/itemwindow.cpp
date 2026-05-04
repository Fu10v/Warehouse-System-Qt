#include "itemwindow.h"
#include "ui_itemwindow.h"
#include "databasemanager.h"
#include <QMessageBox>

ItemWindow::ItemWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ItemWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    if (ui->unitComboBox->count() == 0) {
        ui->unitComboBox->addItems({"pcs", "kg", "l", "pack", "m"});
    }
}

ItemWindow::~ItemWindow()
{
    delete ui;
}
//Заповнення полів даними
void ItemWindow::setItemData(const Item &item)
{
    // Запам'ятовуємо ID! Це найголовніше.
    m_currentId = item.id;

    // Заповнюємо поля даними з переданого товару
    ui->articleLineEdit->setText(item.article);
    ui->nameLineEdit->setText(item.name);
    ui->quantityoubleSpinBox->setValue(item.quantity);
    ui->unitComboBox->setCurrentText(item.unit);
    ui->priceDoubleSpinBox->setValue(item.price);

    // Встановлюємо дату (перетворюємо з рядка)
    ui->dateEdit->setDate(QDate::fromString(item.date, "yyyy-MM-dd"));

    ui->supplierLineEdit->setText(item.supplier);

    // Змінюємо заголовок вікна та текст кнопки
    this->setWindowTitle("Item editing");
    ui->okButton->setText("Update");
}
//Натискання кнопки Ok
void ItemWindow::on_okButton_clicked()
{
    // Валідація: Перевіряємо, чи заповнені обов'язкові поля
    if (ui->articleLineEdit->text().isEmpty() || ui->nameLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "The fields 'Article' and 'Name' are required!");
        return;
    }

    // Збираємо дані з форми у структуру Item
    Item item;
    item.article = ui->articleLineEdit->text();
    item.name = ui->nameLineEdit->text();
    item.quantity = ui->quantityoubleSpinBox->value();
    item.unit = ui->unitComboBox->currentText();
    item.price = ui->priceDoubleSpinBox->value();
    item.date = ui->dateEdit->date().toString("yyyy-MM-dd");
    item.supplier = ui->supplierLineEdit->text();

    // Відправляємо в базу даних
    bool success = false;
    if (m_currentId.isEmpty()) {
        // ID немає -> це ДОДАВАННЯ нового
        success = DatabaseManager::instance().addItem(item);
    } else {
        // ID є -> це ОНОВЛЕННЯ існуючого
        success = DatabaseManager::instance().updateItem(m_currentId, item);
    }
    // ------------------------------------

    if (success) {
        this->accept();
    } else {
        QMessageBox::critical(this, "Error", "Couldn't save changes!");
    }
}

// Натискання кнопки Cancel
void ItemWindow::on_cancelButton_clicked()
{
    // Просто закриваємо вікно без збереження
    this->reject();
}
