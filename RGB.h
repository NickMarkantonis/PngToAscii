#ifndef RGB_H
#define RGB_H

#include <string>
#include <stdint.h>
#include <iostream>

using namespace std;

/**int8 (uint8_t) a integer that can have values between 0 and 255 (1 byte)
 * used to store the RGB values more efficiently */
typedef uint8_t int8;


// class RGB, saves a RGB value
class RGB {
public:
    RGB(); // deffault constructor
    RGB(int R,int G,int B);

    int getBrightness() const;
private:
    int8 r;
    int8 g;
    int8 b;
};

// Default constructor definition
RGB::RGB() : r(0), g(0), b(0) {}

// RGB constructor
RGB::RGB(int R,int G,int B) {
    if (R>255 || R<0){
        cout << "Wrong Red value ("<<R<<")"<<endl;
        exit(1);
    }
    if (G>255 || G<0){
        cout << "Wrong Green value ("<<G<<")"<<endl;
        exit(1);
    }
    if (B>255 || B<0){
        cout << "Wrong Blue value ("<<B<<")"<<endl;
        exit(1);
    }
    r=R;
    g=G;
    b=B;
}


int RGB::getBrightness() const {
    // Calculate brightness based on RGB values
    // Using a weighted sum of the RGB components
    // You can adjust the weights to fit your perception of brightness
    double brightness=0.2126 * r + 0.7152 * g + 0.0722 * b;
    
    // Map the brightness value from the range [0,255] to [1,10]
    int brightnessMapped=static_cast<int>((brightness / 255.0) * 10);
    return brightnessMapped;
}

#endif RGB_H
