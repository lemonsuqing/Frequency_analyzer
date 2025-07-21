/********************************************************************************
** Form generated from reading UI file 'Frequency_analyzer.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQUENCY_ANALYZER_H
#define UI_FREQUENCY_ANALYZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frequency_analyzer
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Frequency_analyzer)
    {
        if (Frequency_analyzer->objectName().isEmpty())
            Frequency_analyzer->setObjectName("Frequency_analyzer");
        Frequency_analyzer->resize(800, 600);
        centralwidget = new QWidget(Frequency_analyzer);
        centralwidget->setObjectName("centralwidget");
        Frequency_analyzer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Frequency_analyzer);
        menubar->setObjectName("menubar");
        Frequency_analyzer->setMenuBar(menubar);
        statusbar = new QStatusBar(Frequency_analyzer);
        statusbar->setObjectName("statusbar");
        Frequency_analyzer->setStatusBar(statusbar);

        retranslateUi(Frequency_analyzer);

        QMetaObject::connectSlotsByName(Frequency_analyzer);
    } // setupUi

    void retranslateUi(QMainWindow *Frequency_analyzer)
    {
        Frequency_analyzer->setWindowTitle(QCoreApplication::translate("Frequency_analyzer", "Frequency_analyzer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frequency_analyzer: public Ui_Frequency_analyzer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQUENCY_ANALYZER_H
