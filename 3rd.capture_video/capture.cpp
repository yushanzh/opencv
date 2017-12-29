#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include <iostream> 
#include <stdlib.h> 
  
using namespace std;  
using namespace cv;  


 
int captureVideo()  
{  
	//打开视频文件：其实就是建立一个VideoCapture结构  
    VideoCapture capture("/Users/zhangyushan/Downloads/傲骨之战.The.Good.Fight.S01E06.中英字幕.WEBrip.720P.mp4");  
	
	//检测是否正常打开:成功打开时，isOpened返回ture  
    if(!capture.isOpened())  
        cout<<"fail to open!"<<endl;  

    //获取整个帧数  
    long totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);  
    cout<<"整个视频共"<<totalFrameNumber<<"帧"<<endl;  
  
    //设置开始帧()  
    long frameToStart = 300;  
    capture.set( CV_CAP_PROP_POS_FRAMES,frameToStart);  
    cout<<"从第"<<frameToStart<<"帧开始读"<<endl;  
  
    //设置结束帧  
    int frameToStop = 310;  
    if(frameToStop < frameToStart)  
    {  
        cout<<"结束帧小于开始帧，程序错误，即将退出！"<<endl;  
        return -1;  
    }  
    else  
    {  
        cout<<"结束帧为：第"<<frameToStop<<"帧"<<endl;  
    }
  
    //获取帧率  
    double rate = capture.get(CV_CAP_PROP_FPS);  
    cout<<"帧率为:"<<rate<<endl;  
  
    //定义一个用来控制读取视频循环结束的变量  
    bool stop = false;  
    //承载每一帧的图像  
    Mat frame;  
    //显示每一帧的窗口  
    namedWindow("Extracted frame");  
    //两帧间的间隔时间:  
    //int delay = 1000/rate;  
    int delay = 1000/rate;  
  
    //利用while循环读取帧  
    //currentFrame是在循环体中控制读取到指定的帧后循环结束的变量  
    long currentFrame = frameToStart;  
  
  
    //滤波器的核  
    int kernel_size = 3;  
    Mat kernel = Mat::ones(kernel_size,kernel_size,CV_32F)/(float)(kernel_size*kernel_size);  
  
    while(!stop)  
    {  
        //读取下一帧  
        if(!capture.read(frame))  
        {  
            cout<<"读取视频失败"<<endl;  
            return -1;    
        }  
          
        //这里加滤波程序  
        imshow("Extracted frame",frame);  
		
		ostringstream os;  
    	os<<currentFrame;  
    	string currentFrameStr;  
    	istringstream is(os.str());  
    	is>>currentFrameStr; 
		
		imwrite(currentFrameStr+".jpg",frame);
        filter2D(frame,frame,-1,kernel);  
  

        imshow("after filter",frame);  
        cout<<"正在读取第"<<currentFrame<<"帧"<<endl;  
        
		//waitKey(int delay=0)当delay ≤ 0时会永远等待；当delay>0时会等待delay毫秒  
        //当时间结束前没有按键按下时，返回值为-1；否则返回按键  
 		cout << "delay=" <<delay <<endl; 
        int c = waitKey(delay);  
        //按下ESC或者到达指定的结束帧后退出读取视频  
        if((char) c == 27 || currentFrame > frameToStop)  
        {  
            stop = true;  
        }  
        //按下按键后会停留在当前帧，等待下一次按键  
        if(c >= 0)  
        {  
            waitKey(0);  
        }  
        currentFrame++;  
    }
  
    //关闭视频文件  
    capture.release();  
    waitKey(0);  
    return 0;  
}

int captureCamera(){
	
	// 打开默认的摄像头
 	VideoCapture cap(0);
 	if (cap.isOpened() == false)
 	{
		cout << "Cannot open the video camera" << endl;
		cin.get(); //wait for any key press
  		return -1;
 	}

	//获取图像的宽高
 	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
 	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
 	cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;
 	string window_name = "Zhangyushan's Camera Feed";
 	namedWindow(window_name);

 	while (true)
 	{
  		Mat frame;
		//获取图像
  		bool bSuccess = cap.read(frame); 
		
  		//Breaking the while loop if the frames cannot be captured
  		if (bSuccess == false)
  		{
   			cout << "Video camera is disconnected" << endl;
   			cin.get(); //Wait for any key press
   			break;
  		}

  		//show the frame in the created window
  		imshow(window_name, frame);

  		//wait for for 10 ms until any key is pressed.
  		//If the 'Esc' key is pressed, break the while loop.
  		//If the any other key is pressed, continue the loop
  		//If any key is not pressed withing 10 ms, continue the loop
  		if (waitKey(10) == 27)
  		{
   			cout << "Esc key is pressed by user. Stoppig the video" << endl;
   			break;
  		}
 	}
 	return 0;
} 

int main() {
	cout << endl;
    cout << "Capture image." << endl;
    cout << "---------------" << endl;
    cout << "Options: " << endl;
    cout << endl;
    cout << "1) Capture Video " << endl;
    cout << "2) Capture Camera " << endl;
    cout << endl;
    cout << "Press number 1-2 to choose from above techniques: ";
    int num = 1;
    cin >> num;
    cout << endl;
	if (num == 1)
	{
		captureVideo();
	}else if (num == 2)
	{
		captureCamera();
	}
} 
