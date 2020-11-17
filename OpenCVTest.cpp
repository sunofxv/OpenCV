// OpenCVTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "opencv.hpp"

using namespace std;
using namespace cv;

#pragma comment(lib,"opencv_world440.lib")
#pragma comment(lib,"opencv_world440d.lib")

static int h = 0;
static int w = 0;

// 图像像素类型转换与归一化

void ChangeType(Mat &img)
{
    Mat pict;
    //先显示一下 img 的像素类型与值
    cout << img.type() << endl;    //输出 16 为 int 类型

    // 将图像类型转换为 float 类型
    img.convertTo(img,CV_32F);
    // 需要进行 归一化 才能进行显示
    normalize(img,pict,1.0,0);
    // 重新显示数据类型
    cout << pict.type() << endl;    //输出 16 为 int 类型
}
void ChangeSize(Mat& img)
{
    Mat imgzoomin, imgzoomout;

    int h = img.rows;
    int w = img.cols;

    resize(img,imgzoomin,Size(h , w / 2),0,0, INTER_LINEAR);
    imshow("zoomin",imgzoomin);
    resize(img, imgzoomout, Size(h * 2, w * 2), 0, 0, INTER_LINEAR);
    imshow("zoomout", imgzoomout);
    waitKey(0);
}

// 鼠标滚轮控制图像缩放

static void on_Mouse(int event, int x, int y, int flags, void* userdata)
{
    // 获得图像
    Mat image = *(Mat*)userdata;
    Mat imgzoom;
    int value;

    // 判断鼠标事件
    if (event == EVENT_MOUSEWHEEL)
    {
        // 获取鼠标滚轮的方向
        value = getMouseWheelDelta(flags);
        if (value > 0)   // 向上
        {
            // 放大
            
            resize(image, imgzoom,Size(h * 2,w * 2),0,0,INTER_LINEAR);
            h = h * 2;
            w = w * 2;
            cout << "h:" << h << "  w:" << w << "鼠标向上";
        }
        else if(value < 0 )  // 向下
        {
            
            resize(image,imgzoom,Size(h / 2, w / 2),0,0,INTER_LINEAR);
            h = h / 2;
            w = w / 2;
            cout << "h:" << h << "  w:" << w << "鼠标向下";
        }
        if (!image.empty())
        {
            // 显示
            imshow("鼠标缩放图像", imgzoom);;
        }
    }
}


void ControllSize(Mat &img)
{
    namedWindow("鼠标缩放图像");
    h = img.rows;
    w = img.cols;

    setMouseCallback("鼠标缩放图像", on_Mouse,(void*)(&img));

    imshow("鼠标缩放图像",img);
}


int main()
{
    Mat img1 = Mat::zeros(Size(500,500),CV_8UC3);
    Mat img2 = imread("E:\\壁纸\\1.bmp");
    if (img2.empty())
    {
        cout << "图像加载失败！";
        return 0;
    }
   // imshow("原图", img2);

    // 调用函数
   // ChangeType(img2);
    //ChangeSize(img2);
      ControllSize(img2);


      waitKey(0);
    
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
