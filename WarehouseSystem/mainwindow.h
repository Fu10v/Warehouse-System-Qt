#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStandardItemModel>
#include <QMainWindow>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &role, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAdd_Item_2_triggered();

    void on_actionEdit_Item_triggered();

    void on_actionDelete_Item_triggered();

    void on_SearclineEdit_textChanged(const QString &arg1);

    void on_actionAdd_Item_triggered();

    void on_actionEdit_Selecte_Item_triggered();

    void on_actionDelete_Selected_Item_triggered();

    void on_actionConnect_to_Database_2_triggered();

    void on_actionConnect_to_Database_triggered();

    void on_actionShow_Summary_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    QString m_userRole;
    QStandardItemModel *m_model;
    QSortFilterProxyModel *m_proxyModel;
    void loadData();
    void setupRolePermissions();
    void setupTable();

};
#endif // MAINWINDOW_H
