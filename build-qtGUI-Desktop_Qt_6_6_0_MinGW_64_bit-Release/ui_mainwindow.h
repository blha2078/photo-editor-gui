/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicView;
    QGridLayout *editBar;
    QLabel *brightnessChangeLabel;
    QSlider *greenSlider;
    QLabel *blueChangeLabel;
    QSlider *redSlider;
    QLabel *redChangeLabel;
    QPushButton *edit_image;
    QSlider *brightnessSlider;
    QLabel *greenChangeLabel;
    QPushButton *save_image;
    QPushButton *select_new_file;
    QSlider *blueSlider;
    QLabel *label_2;
    QLabel *label;
    QSlider *contrastSlider;
    QLabel *contrastChangeLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1310, 687);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        graphicView = new QGraphicsView(centralwidget);
        graphicView->setObjectName("graphicView");
        graphicView->setMinimumSize(QSize(969, 0));
        graphicView->setMaximumSize(QSize(969, 16777214));

        gridLayout->addWidget(graphicView, 4, 0, 1, 1);

        editBar = new QGridLayout();
        editBar->setObjectName("editBar");
        brightnessChangeLabel = new QLabel(centralwidget);
        brightnessChangeLabel->setObjectName("brightnessChangeLabel");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(brightnessChangeLabel->sizePolicy().hasHeightForWidth());
        brightnessChangeLabel->setSizePolicy(sizePolicy);
        brightnessChangeLabel->setMinimumSize(QSize(80, 0));

        editBar->addWidget(brightnessChangeLabel, 4, 0, 1, 1);

        greenSlider = new QSlider(centralwidget);
        greenSlider->setObjectName("greenSlider");
        greenSlider->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(greenSlider->sizePolicy().hasHeightForWidth());
        greenSlider->setSizePolicy(sizePolicy1);
        greenSlider->setMinimum(-25);
        greenSlider->setMaximum(25);
        greenSlider->setOrientation(Qt::Horizontal);

        editBar->addWidget(greenSlider, 7, 1, 1, 1);

        blueChangeLabel = new QLabel(centralwidget);
        blueChangeLabel->setObjectName("blueChangeLabel");
        sizePolicy.setHeightForWidth(blueChangeLabel->sizePolicy().hasHeightForWidth());
        blueChangeLabel->setSizePolicy(sizePolicy);

        editBar->addWidget(blueChangeLabel, 8, 0, 1, 1);

        redSlider = new QSlider(centralwidget);
        redSlider->setObjectName("redSlider");
        redSlider->setEnabled(false);
        sizePolicy1.setHeightForWidth(redSlider->sizePolicy().hasHeightForWidth());
        redSlider->setSizePolicy(sizePolicy1);
        redSlider->setMinimum(-25);
        redSlider->setMaximum(25);
        redSlider->setOrientation(Qt::Horizontal);

        editBar->addWidget(redSlider, 6, 1, 1, 1);

        redChangeLabel = new QLabel(centralwidget);
        redChangeLabel->setObjectName("redChangeLabel");
        sizePolicy.setHeightForWidth(redChangeLabel->sizePolicy().hasHeightForWidth());
        redChangeLabel->setSizePolicy(sizePolicy);

        editBar->addWidget(redChangeLabel, 6, 0, 1, 1);

        edit_image = new QPushButton(centralwidget);
        edit_image->setObjectName("edit_image");
        edit_image->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(edit_image->sizePolicy().hasHeightForWidth());
        edit_image->setSizePolicy(sizePolicy2);

        editBar->addWidget(edit_image, 11, 1, 1, 1, Qt::AlignRight);

        brightnessSlider = new QSlider(centralwidget);
        brightnessSlider->setObjectName("brightnessSlider");
        brightnessSlider->setEnabled(false);
        sizePolicy1.setHeightForWidth(brightnessSlider->sizePolicy().hasHeightForWidth());
        brightnessSlider->setSizePolicy(sizePolicy1);
        brightnessSlider->setMinimum(-25);
        brightnessSlider->setMaximum(25);
        brightnessSlider->setOrientation(Qt::Horizontal);

        editBar->addWidget(brightnessSlider, 4, 1, 1, 1);

        greenChangeLabel = new QLabel(centralwidget);
        greenChangeLabel->setObjectName("greenChangeLabel");
        sizePolicy.setHeightForWidth(greenChangeLabel->sizePolicy().hasHeightForWidth());
        greenChangeLabel->setSizePolicy(sizePolicy);

        editBar->addWidget(greenChangeLabel, 7, 0, 1, 1);

        save_image = new QPushButton(centralwidget);
        save_image->setObjectName("save_image");
        save_image->setEnabled(false);
        sizePolicy2.setHeightForWidth(save_image->sizePolicy().hasHeightForWidth());
        save_image->setSizePolicy(sizePolicy2);
        save_image->setMaximumSize(QSize(16777215, 16777215));

        editBar->addWidget(save_image, 2, 1, 1, 1, Qt::AlignRight);

        select_new_file = new QPushButton(centralwidget);
        select_new_file->setObjectName("select_new_file");
        sizePolicy2.setHeightForWidth(select_new_file->sizePolicy().hasHeightForWidth());
        select_new_file->setSizePolicy(sizePolicy2);

        editBar->addWidget(select_new_file, 1, 1, 1, 1, Qt::AlignRight|Qt::AlignTop);

        blueSlider = new QSlider(centralwidget);
        blueSlider->setObjectName("blueSlider");
        blueSlider->setEnabled(false);
        sizePolicy1.setHeightForWidth(blueSlider->sizePolicy().hasHeightForWidth());
        blueSlider->setSizePolicy(sizePolicy1);
        blueSlider->setMinimum(-25);
        blueSlider->setMaximum(25);
        blueSlider->setOrientation(Qt::Horizontal);

        editBar->addWidget(blueSlider, 8, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        editBar->addWidget(label_2, 3, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        label->setMinimumSize(QSize(0, 0));

        editBar->addWidget(label, 9, 1, 2, 1);

        contrastSlider = new QSlider(centralwidget);
        contrastSlider->setObjectName("contrastSlider");
        contrastSlider->setEnabled(false);
        contrastSlider->setMinimum(-25);
        contrastSlider->setMaximum(25);
        contrastSlider->setOrientation(Qt::Horizontal);

        editBar->addWidget(contrastSlider, 5, 1, 1, 1);

        contrastChangeLabel = new QLabel(centralwidget);
        contrastChangeLabel->setObjectName("contrastChangeLabel");

        editBar->addWidget(contrastChangeLabel, 5, 0, 1, 1);


        gridLayout->addLayout(editBar, 4, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        brightnessChangeLabel->setText(QCoreApplication::translate("MainWindow", "Brightness: 0", nullptr));
        blueChangeLabel->setText(QCoreApplication::translate("MainWindow", "Blue: 0", nullptr));
        redChangeLabel->setText(QCoreApplication::translate("MainWindow", "Red: 0", nullptr));
        edit_image->setText(QCoreApplication::translate("MainWindow", "Edit Image", nullptr));
        greenChangeLabel->setText(QCoreApplication::translate("MainWindow", "Green: 0", nullptr));
        save_image->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
        select_new_file->setText(QCoreApplication::translate("MainWindow", "Select New File", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        contrastChangeLabel->setText(QCoreApplication::translate("MainWindow", "Contrast: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
