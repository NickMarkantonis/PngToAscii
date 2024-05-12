#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>
#include "RGB.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

class Image {
public:
    Image(string name);

    int getHeight() const { return height; }
    int getWidth() const { return width; }
    RGB getColour(int posX, int posY) const { return colVal[posX][posY]; }

private:
    int height;
    int width;
    vector<vector<RGB>> colVal;
};

// constructor that reads the values from the image and saves them in the vector
Image::Image(string name) {
    Mat image=imread(name);
    if (image.empty()) {
        cout << "Error Opening image, please make sure it is located in the build/Debug folder" << endl;
        exit(1);
    }
    Vec3b buffer;

    // setting the height, width and the appropriate size of the array
    height=image.rows;
    width=image.cols;
    colVal.resize(height);
    for (int i=0;i<width;i++) colVal[i].resize(width);

    // reading the values from the image
    for (int i=0;i<image.rows;i++) {
        for (int j=0;j<image.cols;j++) {
            buffer = image.at<Vec3b>(i,j);
            colVal[i][j]=RGB(buffer[2],buffer[1],buffer[0]);
        }
    }
}

#endif IMAGE_H