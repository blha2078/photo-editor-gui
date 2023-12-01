#include "imagemanipulation.h"

imagemanipulation::imagemanipulation(QPixmap p)
    : mImage(p.toImage()),
    mOriginalImage(p.toImage())
{

}


int imagemanipulation::Truncate(int value)
{
    if(value < 0) return 0;
    if(value > 255) return 255;

    return value;
}

void imagemanipulation::EditImage(int redChange, int greenChange, int blueChange, int contrast)
{
    mImage = mOriginalImage.copy();
    RunTransforms(redChange, greenChange, blueChange, contrast);

}


void imagemanipulation::PreviewEditImage(int redChange, int greenChange, int blueChange, int contrast)
{
    int scaledHeight = 1000;
    mImage = mOriginalImage.scaledToHeight(scaledHeight, Qt::FastTransformation);
    RunTransforms(redChange, greenChange, blueChange, contrast);
}


void imagemanipulation::RunTransforms(int redChange, int greenChange, int blueChange, int contrast)
{
    int scaleFactor = 6;
    const int imageHeight = mImage.height();
    const int imageWidth = mImage.width();

    float const factor = (259.0 * ((contrast * scaleFactor) + 255.0)) / (255.0 * (259.0 - (contrast * scaleFactor)));

    for (int row = 0; row < imageHeight; ++row) {
        QRgb *rowData = reinterpret_cast<QRgb*>(mImage.scanLine(row));
        for (int col = 0; col < imageWidth; ++col) {
            QRgb &pixelData = rowData[col];

            int red = Truncate((int)(factor * ((qRed(pixelData) + (redChange * scaleFactor))   - 128) + 128));
            int green = Truncate((int)(factor * ((qGreen(pixelData) + (greenChange * scaleFactor)) - 128) + 128));
            int blue = Truncate((int)(factor * ((qBlue(pixelData) + (blueChange * scaleFactor)) - 128) + 128));

            pixelData = qRgb(red, green, blue);


        }
    }
}
QPixmap& imagemanipulation::getOutputPixmap()
{
    mOutputPixmap = QPixmap::fromImage(mImage);
    return mOutputPixmap;
}

//QImage imagemanipulation::VecToQImage(std::vector<std::vector<double>>){

//}

//std::vector<std::vector<std::vector<double>>> imagemanipulation::QImageToVec(QImage im){
//    const int imageHeight = im.height();
//    const int imageWidth = im.width();

//    // Creating a 3D vector without using new
//    std::vector<std::vector<std::vector<double>>> vec;

//    // Add some elements to the vector (for example, a 2x2x2 3D vector)
//    vec.resize(3, std::vector<std::vector<double>>(imageHeight, std::vector<double>(imageWidth, 0.0)));

//    // red
//    for (int row = 0; row < imageHeight; ++row) {
//        QRgb *rowData = reinterpret_cast<QRgb*>(mImage.scanLine(row));
//        for (int col = 0; col < imageWidth; ++col) {
//            QRgb &pixelData = rowData[col];

//            int red = std::min(std::max(qRed(pixelData) + redChange * 4, 0), 255);
//            int green = std::min(std::max(qGreen(pixelData) + greenChange * 4, 0), 255);
//            int blue = std::min(std::max(qBlue(pixelData) + blueChange * 4, 0), 255);

//            pixelData = qRgb(red, green, blue);

//        }
//    }
//}


//// Function to deconstruct SSA
//std::vector<std::vector<double>> imagemanipulation::SSADeconstructor(int u, int v, int h, int w) {
//    qDebug() << "Deconstructing SSA...";

//    // Getting trajectory matrix size
//    int p = u * v;
//    int q = (h - u + 1) * (w - v + 1);

//    // Setting X/window index to 0
//    int X_index = 1;

//    // Creating matrix
//    std::vector<std::vector<double>> X(p, std::vector<double>(q, 0.0));

//    // Top to bottom
//    for (int row = 0; row < w - v + 1; ++row) {
//        // Going through full picture frame from left to right
//        for (int col = 0; col < h - u + 1; ++col) {
//            // Top to bottom across window
//            for (int Wrow = 0; Wrow < v; ++Wrow) {
//                QRgb *rowData = reinterpret_cast<QRgb*>(mImage.scanLine(row + Wrow));
//                // Saving points left to right across window
//                for (int Wcol = 0; Wcol < u; ++Wcol) {
//                    // Updating the trajectory matrix based on M
//                    X[Wcol * u + Wrow][X_index - 1] = rowData[col + Wcol];
//                }
//            }
//            // Moving over to the next vector
//            X_index++;
//        }
//    }

//    return X;
//}


//// Function to modify SVD
//std::vector<std::vector<double>> SVDmodifier(const std::vector<std::vector<double>>& X, int L, int u, int v, int h, int w) {
//    qDebug() << "Modifying SVD...";

//    // Calculating p and q as size of X_new
//    int p = u * v;
//    int q = (h - u + 1) * (w - v + 1);

//    // Creating Eigen matrix for X
//    Eigen::MatrixXd X_eigen(X.size(), X[0].size());
//    for (int i = 0; i < X.size(); ++i) {
//        for (int j = 0; j < X[0].size(); ++j) {
//            X_eigen(i, j) = X[i][j];
//        }
//    }

//    // Calculating XXT
//    Eigen::MatrixXd XXT = X_eigen * X_eigen.transpose();

//    // Finding the SVD of XXT
//    Eigen::JacobiSVD<Eigen::MatrixXd> svd(XXT, Eigen::ComputeThinU | Eigen::ComputeThinV);
//    Eigen::MatrixXd U = svd.matrixU();
//    Eigen::MatrixXd V = svd.matrixV().transpose();

//    // This code only runs once, as L=1, but will allow using multiple
//    // eigenvectors if L > 1
//    Eigen::MatrixXd X_new_eigen = Eigen::MatrixXd::Zero(p, q);
//    for (int it = 0; it < L; ++it) {
//        // Each U is only using the first row/column as the first eigenvector
//        X_new_eigen += U.col(it) * (U.col(it).transpose() * X_eigen);
//    }

//    // Converting Eigen matrix to 2D vector
//    std::vector<std::vector<double>> X_new(p, std::vector<double>(q, 0.0));
//    for (int i = 0; i < p; ++i) {
//        for (int j = 0; j < q; ++j) {
//            X_new[i][j] = X_new_eigen(i, j);
//        }
//    }

//    return X_new;
//}

//// Function to modify SVD
//std::vector<std::vector<double>> SVDmodifier(const std::vector<std::vector<double>>& X, int L, int u, int v, int h, int w) {
//    qDebug() << "Modifying SVD...";

//    // Calculating p and q as size of X_new
//    int p = u * v;
//    int q = (h - u + 1) * (w - v + 1);

//    // Creating Eigen matrix for X
//    Eigen::MatrixXd X_eigen(X.size(), X[0].size());
//    for (int i = 0; i < X.size(); ++i) {
//        for (int j = 0; j < X[0].size(); ++j) {
//            X_eigen(i, j) = X[i][j];
//        }
//    }

//    // Calculating XXT
//    Eigen::MatrixXd XXT = X_eigen * X_eigen.transpose();

//    // Finding the SVD of XXT
//    Eigen::JacobiSVD<Eigen::MatrixXd> svd(XXT, Eigen::ComputeThinU | Eigen::ComputeThinV);
//    Eigen::MatrixXd U = svd.matrixU();
//    Eigen::MatrixXd V = svd.matrixV().transpose();

//    // This code only runs once, as L=1, but will allow using multiple
//    // eigenvectors if L > 1
//    Eigen::MatrixXd X_new_eigen = Eigen::MatrixXd::Zero(p, q);
//    for (int it = 0; it < L; ++it) {
//        // Each U is only using the first row/column as the first eigenvector
//        X_new_eigen += U.col(it) * (U.col(it).transpose() * X_eigen);
//    }

//    // Converting Eigen matrix to 2D vector
//    std::vector<std::vector<double>> X_new(p, std::vector<double>(q, 0.0));
//    for (int i = 0; i < p; ++i) {
//        for (int j = 0; j < q; ++j) {
//            X_new[i][j] = X_new_eigen(i, j);
//        }
//    }

//    return X_new;
//}
