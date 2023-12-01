#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagemanipulation.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Update the window title if needed
    setWindowTitle("Blake File Viewer Application");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pImage;
    delete pLoadingSpinner;
}


void MainWindow::on_select_new_file_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Load Image"), mResourceDir, tr("Images (*.png *.jpg)"));

    if (filename.isEmpty()) {
        return;
    }

    // Enable sliders
    ui->brightnessSlider->setEnabled(true);
    ui->contrastSlider->setEnabled(true);
    ui->redSlider->setEnabled(true);
    ui->greenSlider->setEnabled(true);
    ui->blueSlider->setEnabled(true);
    ui->save_image->setEnabled(true);
    ui->edit_image->setEnabled(true);

    // delete old image to prevent memory leak
    delete pImage;

    // show sliders and labels
    ui->blueChangeLabel->show();

    // reset sliders
    ui->redSlider->setValue(0);
    ui->greenSlider->setValue(0);
    ui->blueSlider->setValue(0);
    ui->brightnessSlider->setValue(0);

    QPixmap inputPixmap(filename);
    pImage = new imagemanipulation(inputPixmap);
    ShowImage(pImage->getOutputPixmap());
}


void MainWindow::ShowImage(QPixmap p)
{
    if (!ui->graphicView->scene()) {
        qDebug() << "No Scene!";
        QGraphicsScene *scene = new QGraphicsScene(this);
        ui->graphicView->setScene(scene);
    }

    ui->graphicView->scene()->clear();  // Clear previous items from the scene
    ui->graphicView->scene()->addPixmap(p);

    // Set the scene rectangle to match the dimensions of the loaded image
    ui->graphicView->scene()->setSceneRect(p.rect());

    // Fit the view to the scene without any padding
    ui->graphicView->fitInView(ui->graphicView->sceneRect(), Qt::KeepAspectRatio);

    // Show the main window
    show();
}

void MainWindow::UpdateImage()
{
    int brightnessChange = ui->brightnessSlider->value();
    // editting image
    pImage->EditImage(
        ui->redSlider->value() + brightnessChange,
        ui->greenSlider->value() + brightnessChange,
        ui->blueSlider->value() + brightnessChange,
        ui->contrastSlider->value()
        );
    // updating display
    ShowImage(pImage->getOutputPixmap());
}

void MainWindow::PreviewImage()
{
    int brightnessChange = ui->brightnessSlider->value();
    // editting image
    pImage->PreviewEditImage(
        ui->redSlider->value() + brightnessChange,
        ui->greenSlider->value() + brightnessChange,
        ui->blueSlider->value() + brightnessChange,
        ui->contrastSlider->value()
        );
    // updating display
    ShowImage(pImage->getOutputPixmap());
}


void MainWindow::on_edit_image_clicked()
{
    UpdateImage();
}


void MainWindow::on_redSlider_valueChanged(int value)
{
    ui->redChangeLabel->setText("Red: " + QString::number(value));
//    updateSingleColor(0, value);
    PreviewImage();
}



void MainWindow::on_greenSlider_valueChanged(int value)
{
    ui->greenChangeLabel->setText("Green: " + QString::number(value));
//    updateSingleColor(1, value);
    PreviewImage();
}


void MainWindow::on_blueSlider_valueChanged(int value)
{
    ui->blueChangeLabel->setText("Blue: " + QString::number(value));
//    updateSingleColor(2, value);
    PreviewImage();
}


void MainWindow::on_brightnessSlider_valueChanged(int value)
{
    ui->brightnessChangeLabel->setText("Brightness: " + QString::number(value));
    PreviewImage();
}


void MainWindow::on_save_image_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(
        this,
        tr("Save Image"),
        QDir::homePath(),
        tr("Images (*.jpg);;All Files (*)")
        );

    if (!filePath.isEmpty()) {
        // Save the QPixmap as a JPG file
        if (pImage->getOutputPixmap().save(filePath, "JPG")) {
            qDebug() << "Image saved successfully!";
        } else {
            qDebug() << "Failed to save image.";
        }
    }
}


void MainWindow::on_brightnessSlider_sliderReleased()
{
    UpdateImage();
}


void MainWindow::on_redSlider_sliderReleased()
{
    UpdateImage();
}


void MainWindow::on_greenSlider_sliderReleased()
{
    UpdateImage();
}


void MainWindow::on_blueSlider_sliderReleased()
{
    UpdateImage();
}


void MainWindow::on_contrastSlider_sliderReleased()
{
    UpdateImage();
}


void MainWindow::on_contrastSlider_valueChanged(int value)
{
    ui->contrastChangeLabel->setText("Contrast: " + QString::number(value));
    PreviewImage();
}

