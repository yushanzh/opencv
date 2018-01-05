#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
 
using namespace cv;
using namespace std;
 
int main( )
{
		Mat image;
       	image = imread("demo.jpg", CV_LOAD_IMAGE_COLOR);  
 		if(! image.data )                             
       	{
			cout <<  "Could not open or find the image" << std::endl ;
            return -1;
		}
 
		//正常显示文件
       	namedWindow( "Display window", CV_WINDOW_AUTOSIZE );  
       	imshow( "Display window", image );                 
 		waitKey(0);
		destroyWindow("Display window");
		
		//转换颜色到gray
		Mat gray;
		cvtColor(image, gray, CV_BGR2GRAY);	   
       	namedWindow( "Result window", CV_WINDOW_AUTOSIZE );   
       	imshow( "Result window", gray );
       	waitKey(0);                                          
		destroyWindow("Result window");

		//转换颜色到hsv
		Mat hsv;
	   	cvtColor(image,hsv,CV_BGR2HSV);
	   	imshow("hsv",hsv);
		waitKey(0);
		destroyWindow("hsv");
		
		//转换颜色到lab
		Mat lab;
		cvtColor(image,lab,CV_BGR2Lab);
	    imshow( "Result window", lab);
		waitKey(0);
		destroyWindow("Result window");
       	return 0;
}
