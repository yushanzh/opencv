#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main( )
{
 		Mat image;
		string imgstr = "source.jpg";
       
		// LOAD image
		image = imread(imgstr, CV_LOAD_IMAGE_COLOR);   
 		
		// Check for invalid input
       	if (!image.data )  // Check for invalid input
       	{
			cout <<  "Could not open or find the image" << std::endl ;
			return -1;
       	}
 
       	//DISPLAY image
       	namedWindow( "window", CV_WINDOW_AUTOSIZE ); // Create a window for display.
       	imshow( "window", image ); // Show our image inside it.
 
       	//SAVE image
       	imwrite("result.jpg",image);
 
       	waitKey(0);  
       	return 0;
}
