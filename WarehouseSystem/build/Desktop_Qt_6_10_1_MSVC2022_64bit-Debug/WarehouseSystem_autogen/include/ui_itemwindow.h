/********************************************************************************
** Form generated from reading UI file 'itemwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMWINDOW_H
#define UI_ITEMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ItemWindow
{
public:
    QGridLayout *gridLayout;
    QDoubleSpinBox *priceDoubleSpinBox;
    QLabel *label_6;
    QLineEdit *articleLineEdit;
    QLabel *label;
    QPushButton *cancelButton;
    QLabel *label_4;
    QLineEdit *nameLineEdit;
    QLabel *label_5;
    QLabel *label_7;
    QComboBox *unitComboBox;
    QDoubleSpinBox *quantityoubleSpinBox;
    QPushButton *okButton;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QLineEdit *supplierLineEdit;

    void setupUi(QDialog *ItemWindow)
    {
        if (ItemWindow->objectName().isEmpty())
            ItemWindow->setObjectName("ItemWindow");
        ItemWindow->resize(400, 500);
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
        ItemWindow->setPalette(palette);
        gridLayout = new QGridLayout(ItemWindow);
        gridLayout->setObjectName("gridLayout");
        priceDoubleSpinBox = new QDoubleSpinBox(ItemWindow);
        priceDoubleSpinBox->setObjectName("priceDoubleSpinBox");
        priceDoubleSpinBox->setMaximum(9999999999999.990234375000000);

        gridLayout->addWidget(priceDoubleSpinBox, 11, 0, 1, 2);

        label_6 = new QLabel(ItemWindow);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 14, 0, 1, 1);

        articleLineEdit = new QLineEdit(ItemWindow);
        articleLineEdit->setObjectName("articleLineEdit");

        gridLayout->addWidget(articleLineEdit, 3, 0, 1, 2);

        label = new QLabel(ItemWindow);
        label->setObjectName("label");

        gridLayout->addWidget(label, 4, 0, 1, 1);

        cancelButton = new QPushButton(ItemWindow);
        cancelButton->setObjectName("cancelButton");

        gridLayout->addWidget(cancelButton, 30, 1, 1, 1);

        label_4 = new QLabel(ItemWindow);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 8, 0, 1, 1);

        nameLineEdit = new QLineEdit(ItemWindow);
        nameLineEdit->setObjectName("nameLineEdit");

        gridLayout->addWidget(nameLineEdit, 5, 0, 1, 2);

        label_5 = new QLabel(ItemWindow);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 10, 0, 1, 1);

        label_7 = new QLabel(ItemWindow);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 22, 0, 1, 1);

        unitComboBox = new QComboBox(ItemWindow);
        unitComboBox->setObjectName("unitComboBox");

        gridLayout->addWidget(unitComboBox, 9, 0, 1, 2);

        quantityoubleSpinBox = new QDoubleSpinBox(ItemWindow);
        quantityoubleSpinBox->setObjectName("quantityoubleSpinBox");
        quantityoubleSpinBox->setMaximum(999999.989999999990687);

        gridLayout->addWidget(quantityoubleSpinBox, 7, 0, 1, 2);

        okButton = new QPushButton(ItemWindow);
        okButton->setObjectName("okButton");

        gridLayout->addWidget(okButton, 30, 0, 1, 1);

        label_2 = new QLabel(ItemWindow);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        dateEdit = new QDateEdit(ItemWindow);
        dateEdit->setObjectName("dateEdit");

        gridLayout->addWidget(dateEdit, 15, 0, 1, 2);

        label_3 = new QLabel(ItemWindow);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        supplierLineEdit = new QLineEdit(ItemWindow);
        supplierLineEdit->setObjectName("supplierLineEdit");

        gridLayout->addWidget(supplierLineEdit, 23, 0, 1, 2);


        retranslateUi(ItemWindow);

        QMetaObject::connectSlotsByName(ItemWindow);
    } // setupUi

    void retranslateUi(QDialog *ItemWindow)
    {
        ItemWindow->setWindowTitle(QCoreApplication::translate("ItemWindow", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("ItemWindow", "Date:", nullptr));
        label->setText(QCoreApplication::translate("ItemWindow", "Name:", nullptr));
        cancelButton->setText(QCoreApplication::translate("ItemWindow", "Cancel", nullptr));
        label_4->setText(QCoreApplication::translate("ItemWindow", "Unit:", nullptr));
        label_5->setText(QCoreApplication::translate("ItemWindow", "Price:", nullptr));
        label_7->setText(QCoreApplication::translate("ItemWindow", "Supplier:", nullptr));
        okButton->setText(QCoreApplication::translate("ItemWindow", "Ok", nullptr));
        label_2->setText(QCoreApplication::translate("ItemWindow", "Article:", nullptr));
        label_3->setText(QCoreApplication::translate("ItemWindow", "Quantity:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ItemWindow: public Ui_ItemWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMWINDOW_H
