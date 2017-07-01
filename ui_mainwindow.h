/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label_image_autostereogram;
    QLabel *label_image_map_depth;
    QPushButton *btn_select_autostereogram;
    QPushButton *btn_stop;
    QPushButton *btn_start;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_image_autostereogram = new QLabel(centralWidget);
        label_image_autostereogram->setObjectName(QStringLiteral("label_image_autostereogram"));
        label_image_autostereogram->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_image_autostereogram, 0, 0, 1, 1);

        label_image_map_depth = new QLabel(centralWidget);
        label_image_map_depth->setObjectName(QStringLiteral("label_image_map_depth"));
        label_image_map_depth->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_image_map_depth, 0, 1, 1, 1);

        btn_select_autostereogram = new QPushButton(centralWidget);
        btn_select_autostereogram->setObjectName(QStringLiteral("btn_select_autostereogram"));

        gridLayout->addWidget(btn_select_autostereogram, 2, 0, 1, 1);

        btn_stop = new QPushButton(centralWidget);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));

        gridLayout->addWidget(btn_stop, 3, 1, 1, 1);

        btn_start = new QPushButton(centralWidget);
        btn_start->setObjectName(QStringLiteral("btn_start"));

        gridLayout->addWidget(btn_start, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Solucionador de autoestereogramas", Q_NULLPTR));
        label_image_autostereogram->setText(QApplication::translate("MainWindow", "Autostereogram", Q_NULLPTR));
        label_image_map_depth->setText(QApplication::translate("MainWindow", "Map Depth", Q_NULLPTR));
        btn_select_autostereogram->setText(QApplication::translate("MainWindow", "Seleccionar autoestereograma", Q_NULLPTR));
        btn_stop->setText(QApplication::translate("MainWindow", "Detener", Q_NULLPTR));
        btn_start->setText(QApplication::translate("MainWindow", "Iniciar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
