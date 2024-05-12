#ifndef IMAGETOASCII_H
#define IMAGETOASCII_H

#include "Image.h"
#include <fstream>

void imageToAscii(Image *im,string name) {
    char greyScale[10]={' ','.',':','-','=','+','*','#','%','@'};
    char cur;

    // creating the .txt file
    name.resize(name.size()-4);
    ofstream file(name+".txt");
    if (!file) {
        cout << "Error trying to create a file" << endl;
        exit(1);
    }

    for (int i=0;i<im->getHeight();i++) {
        for (int j=0;j<im->getWidth();j++) {
            cur = greyScale[im->getColour(i,j).getBrightness()];
            file << cur << cur;
        }
        file << endl;
    }
    file.close();
}

#endif IMAGETOASCII_H