#ifndef ITEMWINDOW_H
#define ITEMWINDOW_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class ItemWindow;
}

class ItemWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ItemWindow(QWidget *parent = nullptr);
    ~ItemWindow();
    void setItemData(const Item& item);


private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();


private:
    Ui::ItemWindow *ui;
    QString m_currentId;
};

#endif // ITEMWINDOW_H
