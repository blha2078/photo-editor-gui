#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "imagemanipulation.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_select_new_file_clicked();

    void on_edit_image_clicked();

    void on_redSlider_valueChanged(int value);

    void on_greenSlider_valueChanged(int value);

    void on_blueSlider_valueChanged(int value);

    void on_brightnessSlider_valueChanged(int value);

    void on_save_image_clicked();

    void on_brightnessSlider_sliderReleased();

    void on_redSlider_sliderReleased();

    void on_greenSlider_sliderReleased();

    void on_blueSlider_sliderReleased();

    void on_contrastSlider_sliderReleased();

    void on_contrastSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QString mResourceDir;
    void ShowImage(QPixmap);
    void UpdateImage();
    void PreviewImage();
    imagemanipulation* pImage;
    QMovie *pLoadingSpinner;
};
#endif // MAINWINDOW_H
