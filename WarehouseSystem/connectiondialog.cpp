#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
    ui->hostLineEdit->setText("localhost");
    ui->portSpinBox->setValue(27017);
    ui->dbNameLineEdit->setText("Warehouse_System");
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

//Натискання кнопки connect
void ConnectionDialog::on_connectPushButton_clicked()
{
    this->accept(); // Закриває вікно з кодом "Accepted"
}
//Натискання кнопки cancel
void ConnectionDialog::on_cancelPushButton_clicked()
{
    this->reject(); // Закриває вікно з кодом "Rejected"
}

// Геттери
QString ConnectionDialog::getHost() const { return ui->hostLineEdit->text(); }
int ConnectionDialog::getPort() const { return ui->portSpinBox->value(); }
QString ConnectionDialog::getDbName() const { return ui->dbNameLineEdit->text(); }

