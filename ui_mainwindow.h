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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_image_autostereogram;
    QLabel *label_image_right;
    QLabel *label_image_map_depth;
    QLabel *label_image_left;
    QPushButton *btn_select_autostereogram;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(679, 349);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_image_autostereogram = new QLabel(centralWidget);
        label_image_autostereogram->setObjectName(QStringLiteral("label_image_autostereogram"));
        label_image_autostereogram->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_image_autostereogram, 1, 0, 1, 1);

        label_image_right = new QLabel(centralWidget);
        label_image_right->setObjectName(QStringLiteral("label_image_right"));
        label_image_right->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_image_right, 2, 1, 1, 1);

        label_image_map_depth = new QLabel(centralWidget);
        label_image_map_depth->setObjectName(QStringLiteral("label_image_map_depth"));
        label_image_map_depth->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_image_map_depth, 1, 1, 1, 1);

        label_image_left = new QLabel(centralWidget);
        label_image_left->setObjectName(QStringLiteral("label_image_left"));
        label_image_left->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_image_left, 2, 0, 1, 1);

        btn_select_autostereogram = new QPushButton(centralWidget);
        btn_select_autostereogram->setObjectName(QStringLiteral("btn_select_autostereogram"));

        gridLayout_2->addWidget(btn_select_autostereogram, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btn_start = new QPushButton(centralWidget);
        btn_start->setObjectName(QStringLiteral("btn_start"));

        horizontalLayout_3->addWidget(btn_start);

        btn_stop = new QPushButton(centralWidget);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));

        horizontalLayout_3->addWidget(btn_stop);


        verticalLayout->addLayout(horizontalLayout_3);

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
        label_image_right->setText(QApplication::translate("MainWindow", "Image Right", Q_NULLPTR));
        label_image_map_depth->setText(QApplication::translate("MainWindow", "Map Depth", Q_NULLPTR));
        label_image_left->setText(QApplication::translate("MainWindow", "Image Left", Q_NULLPTR));
        btn_select_autostereogram->setText(QApplication::translate("MainWindow", "Seleccionar autoestereograma", Q_NULLPTR));
        btn_start->setText(QApplication::translate("MainWindow", "Iniciar", Q_NULLPTR));
        btn_stop->setText(QApplication::translate("MainWindow", "Detener", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
