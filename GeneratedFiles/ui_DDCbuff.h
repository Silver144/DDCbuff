/********************************************************************************
** Form generated from reading UI file 'DDCbuff.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DDCBUFF_H
#define UI_DDCBUFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DDCbuffClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DDCbuffClass)
    {
        if (DDCbuffClass->objectName().isEmpty())
            DDCbuffClass->setObjectName(QStringLiteral("DDCbuffClass"));
        DDCbuffClass->resize(600, 400);
        menuBar = new QMenuBar(DDCbuffClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        DDCbuffClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DDCbuffClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DDCbuffClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DDCbuffClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DDCbuffClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DDCbuffClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DDCbuffClass->setStatusBar(statusBar);

        retranslateUi(DDCbuffClass);

        QMetaObject::connectSlotsByName(DDCbuffClass);
    } // setupUi

    void retranslateUi(QMainWindow *DDCbuffClass)
    {
        DDCbuffClass->setWindowTitle(QApplication::translate("DDCbuffClass", "DDCbuff", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DDCbuffClass: public Ui_DDCbuffClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DDCBUFF_H
