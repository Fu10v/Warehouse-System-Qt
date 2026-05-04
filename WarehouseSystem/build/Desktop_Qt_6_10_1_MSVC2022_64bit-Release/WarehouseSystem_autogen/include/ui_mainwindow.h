/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAdd_Item;
    QAction *actionEdit_Selecte_Item;
    QAction *actionDelete_Selected_Item;
    QAction *actionShow_Summary;
    QAction *actionAbout;
    QAction *actionConnect_to_Database_2;
    QAction *actionSave;
    QAction *actionAdd_Item_2;
    QAction *actionEdit_Item;
    QAction *actionDelete_Item;
    QAction *actionConnect_to_Database;
    QAction *actionDisconnect;
    QAction *actionRefresh_Data;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QLineEdit *SearclineEdit;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuData;
    QMenu *menuReports;
    QMenu *menuHelp;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 665);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(242, 237, 232, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush2);
        QBrush brush3(QColor(248, 246, 243, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush3);
        QBrush brush4(QColor(121, 119, 116, 255));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush4);
        QBrush brush5(QColor(161, 158, 155, 255));
        brush5.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush2);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush8(QColor(121, 119, 116, 127));
        brush8.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush8);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush2);
#endif
        MainWindow->setPalette(palette);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::FolderOpen));
        MainWindow->setWindowIcon(icon);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAdd_Item = new QAction(MainWindow);
        actionAdd_Item->setObjectName("actionAdd_Item");
        actionEdit_Selecte_Item = new QAction(MainWindow);
        actionEdit_Selecte_Item->setObjectName("actionEdit_Selecte_Item");
        actionDelete_Selected_Item = new QAction(MainWindow);
        actionDelete_Selected_Item->setObjectName("actionDelete_Selected_Item");
        actionShow_Summary = new QAction(MainWindow);
        actionShow_Summary->setObjectName("actionShow_Summary");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionConnect_to_Database_2 = new QAction(MainWindow);
        actionConnect_to_Database_2->setObjectName("actionConnect_to_Database_2");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentProperties));
        actionConnect_to_Database_2->setIcon(icon1);
        actionConnect_to_Database_2->setMenuRole(QAction::MenuRole::NoRole);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        actionSave->setIcon(icon2);
        actionSave->setMenuRole(QAction::MenuRole::NoRole);
        actionAdd_Item_2 = new QAction(MainWindow);
        actionAdd_Item_2->setObjectName("actionAdd_Item_2");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        actionAdd_Item_2->setIcon(icon3);
        actionAdd_Item_2->setMenuRole(QAction::MenuRole::NoRole);
        actionEdit_Item = new QAction(MainWindow);
        actionEdit_Item->setObjectName("actionEdit_Item");
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("emblem-documents")));
        actionEdit_Item->setIcon(icon4);
        actionEdit_Item->setMenuRole(QAction::MenuRole::NoRole);
        actionDelete_Item = new QAction(MainWindow);
        actionDelete_Item->setObjectName("actionDelete_Item");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        actionDelete_Item->setIcon(icon5);
        actionDelete_Item->setMenuRole(QAction::MenuRole::NoRole);
        actionConnect_to_Database = new QAction(MainWindow);
        actionConnect_to_Database->setObjectName("actionConnect_to_Database");
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName("actionDisconnect");
        actionRefresh_Data = new QAction(MainWindow);
        actionRefresh_Data->setObjectName("actionRefresh_Data");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 2, 0, 1, 2);

        SearclineEdit = new QLineEdit(centralwidget);
        SearclineEdit->setObjectName("SearclineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearclineEdit->sizePolicy().hasHeightForWidth());
        SearclineEdit->setSizePolicy(sizePolicy);
        SearclineEdit->setMinimumSize(QSize(0, 0));
        SearclineEdit->setClearButtonEnabled(false);

        gridLayout->addWidget(SearclineEdit, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1100, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuData = new QMenu(menuBar);
        menuData->setObjectName("menuData");
        menuReports = new QMenu(menuBar);
        menuReports->setObjectName("menuReports");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuData->menuAction());
        menuBar->addAction(menuReports->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionConnect_to_Database);
        menuFile->addAction(actionDisconnect);
        menuFile->addAction(actionRefresh_Data);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuData->addAction(actionAdd_Item);
        menuData->addAction(actionEdit_Selecte_Item);
        menuData->addSeparator();
        menuData->addAction(actionDelete_Selected_Item);
        menuReports->addAction(actionShow_Summary);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionConnect_to_Database_2);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionAdd_Item_2);
        toolBar->addAction(actionEdit_Item);
        toolBar->addSeparator();
        toolBar->addAction(actionDelete_Item);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Warehouse System", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAdd_Item->setText(QCoreApplication::translate("MainWindow", "Add Item...", nullptr));
        actionEdit_Selecte_Item->setText(QCoreApplication::translate("MainWindow", "Edit Selecte Item...", nullptr));
        actionDelete_Selected_Item->setText(QCoreApplication::translate("MainWindow", "Delete Selected Item", nullptr));
        actionShow_Summary->setText(QCoreApplication::translate("MainWindow", "Show Summary...", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionConnect_to_Database_2->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
#if QT_CONFIG(tooltip)
        actionConnect_to_Database_2->setToolTip(QCoreApplication::translate("MainWindow", "Connect to database", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "Save file", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAdd_Item_2->setText(QCoreApplication::translate("MainWindow", "Add Item", nullptr));
#if QT_CONFIG(tooltip)
        actionAdd_Item_2->setToolTip(QCoreApplication::translate("MainWindow", "Add item to file", nullptr));
#endif // QT_CONFIG(tooltip)
        actionEdit_Item->setText(QCoreApplication::translate("MainWindow", "Edit Item", nullptr));
#if QT_CONFIG(tooltip)
        actionEdit_Item->setToolTip(QCoreApplication::translate("MainWindow", "Edit item in file", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDelete_Item->setText(QCoreApplication::translate("MainWindow", "Delete Item", nullptr));
#if QT_CONFIG(tooltip)
        actionDelete_Item->setToolTip(QCoreApplication::translate("MainWindow", "Delete item from file", nullptr));
#endif // QT_CONFIG(tooltip)
        actionConnect_to_Database->setText(QCoreApplication::translate("MainWindow", "Connect to Database...", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        actionRefresh_Data->setText(QCoreApplication::translate("MainWindow", "Refresh Data", nullptr));
        SearclineEdit->setText(QCoreApplication::translate("MainWindow", "Enter item name", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        menuData->setTitle(QCoreApplication::translate("MainWindow", "Data", nullptr));
        menuReports->setTitle(QCoreApplication::translate("MainWindow", "Reports", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
