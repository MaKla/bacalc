/********************************************************************************
** Form generated from reading UI file 'qtguicalculator.ui'
**
** Created: Mon 18. Jan 18:52:51 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUICALCULATOR_H
#define UI_QTGUICALCULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtGuiCalculator
{
public:
    QTabWidget *tabWidget;
    QWidget *calculatorTab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *termInput;
    QSpacerItem *verticalSpacer;
    QPushButton *submitButton;
    QWidget *connectionTab;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *hostLabel;
    QLineEdit *hostInput;
    QLabel *portLabel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpinBox *portInput;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QPushButton *testconButton;
    QPushButton *makeconButton;
    QWidget *helpTab;

    void setupUi(QWidget *qtGuiCalculator)
    {
        if (qtGuiCalculator->objectName().isEmpty())
            qtGuiCalculator->setObjectName(QString::fromUtf8("qtGuiCalculator"));
        qtGuiCalculator->resize(266, 244);
        QPalette palette;
        QBrush brush(QColor(208, 217, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        qtGuiCalculator->setPalette(palette);
        tabWidget = new QTabWidget(qtGuiCalculator);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 251, 241));
        calculatorTab = new QWidget();
        calculatorTab->setObjectName(QString::fromUtf8("calculatorTab"));
        verticalLayoutWidget = new QWidget(calculatorTab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 231, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QPalette palette1;
        QBrush brush1(QColor(71, 92, 94, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(176, 191, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush3);
        QBrush brush4(QColor(215, 223, 247, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        QBrush brush5(QColor(88, 95, 120, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush5);
        QBrush brush6(QColor(117, 127, 160, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush6);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label->setWordWrap(false);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        termInput = new QLineEdit(verticalLayoutWidget);
        termInput->setObjectName(QString::fromUtf8("termInput"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Calibri"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        termInput->setFont(font1);

        verticalLayout->addWidget(termInput);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        submitButton = new QPushButton(verticalLayoutWidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setEnabled(false);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Calibri"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        submitButton->setFont(font2);

        verticalLayout->addWidget(submitButton);

        tabWidget->addTab(calculatorTab, QString());
        connectionTab = new QWidget();
        connectionTab->setObjectName(QString::fromUtf8("connectionTab"));
        verticalLayoutWidget_2 = new QWidget(connectionTab);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 221, 191));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        hostLabel = new QLabel(verticalLayoutWidget_2);
        hostLabel->setObjectName(QString::fromUtf8("hostLabel"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
        hostLabel->setPalette(palette2);
        hostLabel->setFont(font);
        hostLabel->setTextFormat(Qt::AutoText);
        hostLabel->setScaledContents(false);
        hostLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        hostLabel->setWordWrap(false);

        verticalLayout_2->addWidget(hostLabel);

        hostInput = new QLineEdit(verticalLayoutWidget_2);
        hostInput->setObjectName(QString::fromUtf8("hostInput"));
        hostInput->setFont(font1);

        verticalLayout_2->addWidget(hostInput);

        portLabel = new QLabel(verticalLayoutWidget_2);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
        portLabel->setPalette(palette3);
        portLabel->setFont(font);
        portLabel->setTextFormat(Qt::AutoText);
        portLabel->setScaledContents(false);
        portLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        portLabel->setWordWrap(false);

        verticalLayout_2->addWidget(portLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        portInput = new QSpinBox(verticalLayoutWidget_2);
        portInput->setObjectName(QString::fromUtf8("portInput"));
        portInput->setMaximumSize(QSize(50, 16777215));
        portInput->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        portInput->setMaximum(64000);
        portInput->setValue(2000);

        horizontalLayout->addWidget(portInput);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        testconButton = new QPushButton(verticalLayoutWidget_2);
        testconButton->setObjectName(QString::fromUtf8("testconButton"));
        testconButton->setEnabled(false);
        testconButton->setFont(font2);

        verticalLayout_2->addWidget(testconButton);

        makeconButton = new QPushButton(verticalLayoutWidget_2);
        makeconButton->setObjectName(QString::fromUtf8("makeconButton"));
        makeconButton->setEnabled(false);
        makeconButton->setFont(font2);
        makeconButton->setFlat(false);

        verticalLayout_2->addWidget(makeconButton);

        tabWidget->addTab(connectionTab, QString());
        helpTab = new QWidget();
        helpTab->setObjectName(QString::fromUtf8("helpTab"));
        tabWidget->addTab(helpTab, QString());

        retranslateUi(qtGuiCalculator);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(qtGuiCalculator);
    } // setupUi

    void retranslateUi(QWidget *qtGuiCalculator)
    {
        qtGuiCalculator->setWindowTitle(QApplication::translate("qtGuiCalculator", "qtGuiCalculator", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        qtGuiCalculator->setToolTip(QApplication::translate("qtGuiCalculator", "Make sure to have a connection an insert a term.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("qtGuiCalculator", "Please insert your term ", 0, QApplication::UnicodeUTF8));
        termInput->setText(QString());
        submitButton->setText(QApplication::translate("qtGuiCalculator", "Submit", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(calculatorTab), QApplication::translate("qtGuiCalculator", "Calculator", 0, QApplication::UnicodeUTF8));
        hostLabel->setText(QApplication::translate("qtGuiCalculator", "Please insert the host ", 0, QApplication::UnicodeUTF8));
        hostInput->setText(QString());
        portLabel->setText(QApplication::translate("qtGuiCalculator", "Please insert the port", 0, QApplication::UnicodeUTF8));
        testconButton->setText(QApplication::translate("qtGuiCalculator", "Test", 0, QApplication::UnicodeUTF8));
        makeconButton->setText(QApplication::translate("qtGuiCalculator", "Connect", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(connectionTab), QApplication::translate("qtGuiCalculator", "Connection", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(helpTab), QApplication::translate("qtGuiCalculator", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qtGuiCalculator: public Ui_qtGuiCalculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUICALCULATOR_H
