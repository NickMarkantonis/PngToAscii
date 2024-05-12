#include <iostream>
#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

#include "Image.h"
#include "imageToAscii.h"

using namespace cv;
using namespace std;

int main() {
  string name;
  cout << "Input image name: ";
  cin >> name;

  Image *img=new Image(name);
  imageToAscii(img,name);

  return 0;
}