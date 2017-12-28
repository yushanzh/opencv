#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/line_descriptor/descriptor.hpp>
#include <unistd.h>
#include <iostream>
#include <stdio.h>  

using namespace cv;


int print_help(){
	printf("-t	Type of drawing.");
	printf("\n\t 1:draw a line.");
	printf("\n\t 2:draw a circle.");
	printf("\n\t 3:draw a ellipse.");
	printf("\n\t 4:draw a rectangle.");
	printf("\n\t 5:draw a polygon.");
	printf("\n\t 6:write text.");
	return(0);
}


//draw a line
int draw_line(const	cv::Mat& image){
	line(image, Point( 15, 20 ), Point( 370, 50), Scalar( 110, 220, 0 ),  2, 8 );
 	imshow("Image", image);
	waitKey( 0 );
	return 0;
}

//draw a cicle
int draw_circle(Mat& image){
  	circle( image, Point( 200, 200 ), 32.0, Scalar( 0, 0, 255 ), 1, 8 );
  	imshow("Image",image);
	waitKey(0);
	return 0;
}

//draw ellipse
int draw_ellipse(Mat& image){
	// Draw a ellipse 
	ellipse( image, Point( 200, 200 ), Size( 100.0, 160.0 ), 45, 0, 360, Scalar( 255, 0, 0 ), 1, 8 );
	ellipse( image, Point( 200, 200 ), Size( 100.0, 160.0 ), 135, 0, 360, Scalar( 255, 0, 0 ), 10, 8 );
	ellipse( image, Point( 200, 200 ), Size( 150.0, 50.0 ), 135, 0, 360, Scalar( 0, 255, 0 ), 1, 8 );
	imshow("Image",image);
	waitKey(0);
	return (0);
}


//draw rectangle
int draw_rectangle(Mat& image){
	// Draw a rectangle ( 5th argument is not -ve)
	rectangle( image, Point( 15, 20 ), Point( 70, 50), Scalar( 0, 55, 255 ), +1, 4 );
	imshow("Image1",image);
	// Draw a filled rectangle ( 5th argument is -ve)
	rectangle( image, Point( 115, 120 ), Point( 170, 150), Scalar( 100, 155, 25 ), -1, 8 );
	imshow("Image2",image);
	waitKey(0);
	return (0);
}

int draw_polygon(Mat& image){
 	/** Create some points */
	int w = 400;
	Point rook_points[1][20];
	rook_points[0][0] = Point( w/4.0, 7*w/8.0 );
	rook_points[0][1] = Point( 3*w/4.0, 7*w/8.0 );
 	rook_points[0][2] = Point( 3*w/4.0, 13*w/16.0 );
  	rook_points[0][3] = Point( 11*w/16.0, 13*w/16.0 );
  	rook_points[0][4] = Point( 19*w/32.0, 3*w/8.0 );
  	rook_points[0][5] = Point( 3*w/4.0, 3*w/8.0 );
  	rook_points[0][6] = Point( 3*w/4.0, w/8.0 );
  	rook_points[0][7] = Point( 26*w/40.0, w/8.0 );
  	rook_points[0][8] = Point( 26*w/40.0, w/4.0 );
  	rook_points[0][9] = Point( 22*w/40.0, w/4.0 );
  	rook_points[0][10] = Point( 22*w/40.0, w/8.0 );
  	rook_points[0][11] = Point( 18*w/40.0, w/8.0 );
  	rook_points[0][12] = Point( 18*w/40.0, w/4.0 );
  	rook_points[0][13] = Point( 14*w/40.0, w/4.0 );
  	rook_points[0][14] = Point( 14*w/40.0, w/8.0 );
  	rook_points[0][15] = Point( w/4.0, w/8.0 );
  	rook_points[0][16] = Point( w/4.0, 3*w/8.0 );
  	rook_points[0][17] = Point( 13*w/32.0, 3*w/8.0 );
  	rook_points[0][18] = Point( 5*w/16.0, 13*w/16.0 );
  	rook_points[0][19] = Point( w/4.0, 13*w/16.0) ;
 
  	const Point* ppt[1] = { rook_points[0] };
  	int npt[] = { 20 };
	fillPoly( image, ppt, npt, 1, Scalar( 255, 255, 255 ), 8 );
	imshow("Image",image);
	
	waitKey(0);
	return(0);
}

int put_text(Mat& image){
	putText(image, "Hello Zhangyushan", Point(50,100), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,200,200), 4);
  imshow("Image",image);
 
  waitKey(0);
  return(0);
}

int main(int argc, char *argv[]) { 

	std::ostream stream(nullptr);
	stream.rdbuf(std::cout.rdbuf());
	int oc;
	if ((oc = getopt(argc, argv, "t:h")) != -1) {
		switch(oc) {
			case 't':
				stream << "t="<< optarg << std::endl;
				break;
			default:
				stream << "ERROR" << std::endl;
				print_help();
				return(0);
		}
	} else{
		print_help();
		return (0);
	}
	
	Mat image = Mat::zeros( 400, 400, CV_8UC3 );
	int type = atoi(optarg);
	switch(type) {
		case 1: 
			draw_line(image);
			break;
		case 2:
			draw_circle(image);
			break;
		case 3:
			draw_ellipse(image);
			break;
		case 4:
			draw_rectangle(image);
			break;
		case 5:
			draw_polygon(image);
			break;
		case 6 :
			put_text(image);
			break;
		default :
			print_help();
			
	}

  return(0);
}

