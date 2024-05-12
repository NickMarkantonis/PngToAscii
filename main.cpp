#include <iostream>
#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main() {
  Mat image = imread("image1.jpg");
  
  if (image.empty()) {
    cout << "Could not open or find the image" << endl;
    return -1;
  }

  // Separate color channels
  vector<Mat> channels(3);
  split(image, channels);
  Mat array_B = channels[0];
  Mat array_G = channels[1];
  Mat array_R = channels[2];

  imshow("Image", image);
  waitKey(0);

  return 0;
}