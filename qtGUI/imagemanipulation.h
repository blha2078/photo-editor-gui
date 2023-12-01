#ifndef IMAGEMANIPULATION_H
#define IMAGEMANIPULATION_H

#include <QMainWindow>

class imagemanipulation
{
public:
    imagemanipulation(QPixmap);
    void EditImage(int, int, int, int);
    void PreviewEditImage(int, int, int, int);
    // void EditSingleColor(int, int);
    QPixmap& getOutputPixmap();
    void RunTransforms(int, int, int, int);
    int Truncate(int);
    std::vector<std::vector<double>> SSA(const std::vector<std::vector<double>>&, int, int, int, int, int);
    std::vector<std::vector<double>> SVDmodifier(const std::vector<std::vector<double>>&, int, int, int, int, int);
    std::vector<std::vector<double>> SSADeconstructor(int, int, int, int);
    std::vector<std::vector<double>> SSAReconstructor(const std::vector<std::vector<double>>&, int, int, int, int);
    std::vector<std::vector<double>> QImageToVec(QImage im);
    QImage VecToQImage(std::vector<std::vector<double>>);

private:
    QPixmap mOutputPixmap;
    QImage mImage;
    const QImage mOriginalImage;
};

#endif // IMAGEMANIPULATION_H
