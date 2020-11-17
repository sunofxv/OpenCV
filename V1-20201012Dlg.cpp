
// V1-20201012Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "V1-20201012.h"
#include "V1-20201012Dlg.h"
#include "afxdialogex.h"

#include "opencv2/opencv.hpp"

using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CV120201012Dlg 对话框

#pragma comment(lib,"opencv_world440d.lib")
#pragma comment(lib,"opencv_world440.lib")

void on_Mouse(int event, int x, int y, int flags, void* userdata);

CV120201012Dlg::CV120201012Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_V120201012_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CV120201012Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CV120201012Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CV120201012Dlg 消息处理程序

BOOL CV120201012Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//showImg();
	//changeImg();
	//yanMo();
	//createNew();
	//imgCopy();
	//PixlShow();
	//pixelOperator();
	//trackingBar();
	//keyboardDemo();
	//colorMap();
	//bitwiseDemo();
	//channelDemo();
	//pixel_statistic();
	//drawDemo();
	//randomDraw();
	//mutiplyDraw();
	mouseDraw_Demo();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CV120201012Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CV120201012Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CV120201012Dlg::showImg()
{
	// 加载一幅图像
	Mat src = imread("E:\\PR\\resource\\picture\\2020-10-11_224039.png", IMREAD_GRAYSCALE);
    //判断是否加载成功
	if (src.empty())
	{
		MessageBox(_T("加载图像失败！"),_T("Error"));  // 

	}
	else
	{
		namedWindow("opencv lodeImg demo", WINDOW_AUTOSIZE);
		imshow("opencv lodeImg demo", src); // 显示图像

		waitKey(0);
	}
	
}

void CV120201012Dlg::changeImg()
{
	// 创建院士图像
	Mat src = imread("E:\\PR\\resource\\picture\\2020-10-11_224039.png");
	// 创建一个显示窗口
	namedWindow("change img",WINDOW_AUTOSIZE);
	// 定义一个变量作为转换之后的图像
	Mat out_IMG;
	cvtColor(src,out_IMG,COLOR_BGR2GRAY);
	// 显示
	imshow("change img", out_IMG);

	// 保存图像
	imwrite("E:\\PR\\resource\\picture\\2.tiff", out_IMG);
}

void CV120201012Dlg::yanMo()
{
	// 加载图像
	Mat mImg = imread("E:\\PR\\resource\\picture\\2020-10-11_224039.png");
	if (!mImg.data)
	{
		MessageBox(_T("图像加载失败！"),_T("error"));
		return;
	}
	// 加载一个窗口
	namedWindow("YanMo window test", WINDOW_AUTOSIZE);
	// 显示
	imshow("YanMo window test",mImg);

}

void CV120201012Dlg::createNew()
{
	Mat m1 = Mat::zeros(Size(400,400),CV_8UC1);

	m1 = Scalar(0,0,255);

	imshow("创建窗口",m1);

	waitKey(0);
}

void CV120201012Dlg::imgCopy()
{
	Mat m1 = Mat::zeros(Size(400, 400), CV_8UC1);

	m1 = Scalar(0, 0, 255);

	Mat m2, m3;
	m2 = m1.clone();

	imshow("创建窗口2", m2);
	m1.copyTo(m3);
	imshow("创建窗口3", m3);

	waitKey(0);
}

// 像素读写演示
void CV120201012Dlg::PixlShow()
{
	// 读取一幅图像
	Mat m1 = imread("E:\\PR\\resource\\picture\\2020-10-11_224039.png");
	if (!m1.data)
	{
		MessageBox(_T("图像加载失败！"),_T("error"));
		return;
	}
	// 获取图像的 行 列 值
	int width = m1.cols;
	int height = m1.rows;

	int channel = m1.channels();

	// 遍历行列的像素 -- 数组
	//for (int i = 0;i < height;i++)
	//{
	//	for (int j = 0;j < width;j++)
	//	{
	//		// 判断是 单通道还是3通道
	//		if (channel == 1)
	//		{
	//			// 获取每个点的像素值
	//			int pv = m1.at<uchar>(i, j);
	//			// 改变每个点的像素值
	//			m1.at<uchar>(i, j) = 255 - pv;  // 像素值反转
	//		}
	//		if (channel == 3)
	//		{
	//			Vec3b pv = m1.at<Vec3b>(i, j);
	//			m1.at<Vec3b>(i, j)[0] = 255 - pv[0];
	//			m1.at<Vec3b>(i, j)[1] = 255 - pv[1];
	//			m1.at<Vec3b>(i, j)[2] = 255 - pv[2];
	//		}
	//	}
	//}

	// 遍历行列的像素 -- 指针
	for (int i = 0;i < height;i++)
	{
		// 定义当前行指针
		uchar* pr = m1.ptr<uchar>(i);
		for (int j = 0;j < width;j++)
		{
			// 判断是 单通道还是3通道
			if (channel == 1)
			{
				// 获取每个点的像素值
				int pv = *pr;
				// 改变每个点的像素值
				*pr++ = 255 - pv;
			}
			if (channel == 3)
			{
				*pr++ = 255 - *pr;
				*pr++ = 255 - *pr;
				*pr++ = 255 - *pr;
			}
		}
	}

	imshow("像素读写",m1);
	waitKey(0);
}

//////////////////////  20201018  //////////////////////////////
// 图像像素的算术操作
void CV120201012Dlg::pixelOperator()
{
	Mat m1 = imread("E:\\壁纸\\周震南\\微信图片_20200610160556.jpg");
	// 定义变量接收操作之后的图像
	Mat img;
	img = m1 + Scalar(50,50,50);  // - / 都可以， * 需要使用opencv 的 API 函数
	/*namedWindow("图像像素算术操作", WINDOW_AUTOSIZE);
	imshow("图像像素算术操作",img);*/

	// 两幅图像相乘
	Mat m2 = Mat::zeros(m1.size(),m1.type());
	m2 = Scalar(2,2,2);
	// 乘法  
	multiply(m1,m2,img);
	namedWindow("图像像素算术操作 乘法", WINDOW_AUTOSIZE);
	imshow("图像像素算术操作 乘法", img);
	// 除法
	divide(m1, m2, img);
	namedWindow("图像像素算术操作 除法", WINDOW_AUTOSIZE);
	imshow("图像像素算术操作 除法", img);
	m2 = Scalar(59, 50, 52);  // 为使得效果更明显 加大数值
	// 减法
	subtract(m1, m2, img);
	namedWindow("图像像素算术操作 减法", WINDOW_AUTOSIZE);
	imshow("图像像素算术操作 减法", img);
	// 加法
	add(m1, m2, img);
	namedWindow("图像像素算术操作 加法", WINDOW_AUTOSIZE);
	imshow("图像像素算术操作 加法", img);
	
	
	/*
		saturate_cast<uchar>();
		可防止 （）中的运算 溢出， <0时 =0   >255时=255
	*/

	waitKey(0);
}



// 滚动条练习  使用滚动条改变图像亮度
// 响应函数

static void onTrack(int b,void*)
{
    // 对图像进行 算术操作
	Mat m1 = imread("E:\\壁纸\\虎太郎\\timg.jpg");
	Mat m2 = Mat::zeros(m1.size(), m1.type());
	m2 = Scalar(b, b, b);
	// 定义变量接收操作之后的图像
	Mat img;
	// 加法
	add(m1, m2, img);
	namedWindow("滚动条", WINDOW_AUTOSIZE);
	imshow("滚动条", img);
	//waitKey(0);   // 不能添加，添加后滚动条的数据显示不会更新
}
void CV120201012Dlg::trackingBar()
{
	// 定义一个窗口用来显示图像和滚动条
	namedWindow("滚动条", WINDOW_NORMAL);
	// 定义一个滚动条
	int lightValue = 50;
	int maxValue = 100;
	createTrackbar("Value", "滚动条", &lightValue,maxValue,onTrack);
	onTrack(50,0);  // 如果不加这句话，运行后显示的是一幅灰图像，拖动滚动条才显示正常图像
}

// 键盘响应操作
void CV120201012Dlg::keyboardDemo()
{
	// 定义一个变量来接收键盘按下的值
	
	Mat m = imread("E:\\壁纸\\周震南\\微信图片_20200610160556.jpg");
	if (m.empty())
	{
		MessageBox(_T("图像加载失败！"), _T("error"));
		return;
	}
	Mat img = m.clone();
	while (1)
	{
		int key = waitKey(100);
		if (key == 27)
		{
			break;
		}
		else if (key == 49)
		{
			cvtColor(m,img,COLOR_BGR2GRAY);
		}
		else if (key == 50)
		{
			cvtColor(m, img, COLOR_BGR2HSV);
		}
		else if (key == 51)
		{
			m = m + Scalar(50,50,50);
			img = m.clone();
		}
		namedWindow("键盘响应", WINDOW_NORMAL);
		imshow("键盘响应", img);
	}
}

// 颜色图
void CV120201012Dlg::colorMap()
{
	// 读取一张图像
	Mat m = imread("E:\\壁纸\\周震南\\微信图片_20200610160556.jpg");
	Mat img = Mat::zeros(m.size(),m.type());
	// 定义颜色表数组
	int m_colorMap[] = {
		COLORMAP_AUTUMN , //!< ![autumn](pics/colormaps/colorscale_autumn.jpg)
	COLORMAP_BONE , //!< ![bone](pics/colormaps/colorscale_bone.jpg)
	COLORMAP_JET , //!< ![jet](pics/colormaps/colorscale_jet.jpg)
	COLORMAP_WINTER , //!< ![winter](pics/colormaps/colorscale_winter.jpg)
	COLORMAP_RAINBOW, //!< ![rainbow](pics/colormaps/colorscale_rainbow.jpg)
	COLORMAP_OCEAN , //!< ![ocean](pics/colormaps/colorscale_ocean.jpg)
	COLORMAP_SUMMER , //!< ![summer](pics/colormaps/colorscale_summer.jpg)
	COLORMAP_SPRING , //!< ![spring](pics/colormaps/colorscale_spring.jpg)
	COLORMAP_COOL , //!< ![cool](pics/colormaps/colorscale_cool.jpg)
	COLORMAP_HSV , //!< ![HSV](pics/colormaps/colorscale_hsv.jpg)
	COLORMAP_PINK , //!< ![pink](pics/colormaps/colorscale_pink.jpg)
	COLORMAP_HOT , //!< ![hot](pics/colormaps/colorscale_hot.jpg)
	COLORMAP_PARULA , //!< ![parula](pics/colormaps/colorscale_parula.jpg)
	COLORMAP_MAGMA , //!< ![magma](pics/colormaps/colorscale_magma.jpg)
	COLORMAP_INFERNO , //!< ![inferno](pics/colormaps/colorscale_inferno.jpg)
	COLORMAP_PLASMA , //!< ![plasma](pics/colormaps/colorscale_plasma.jpg)
	COLORMAP_VIRIDIS , //!< ![viridis](pics/colormaps/colorscale_viridis.jpg)
	COLORMAP_CIVIDIS , //!< ![cividis](pics/colormaps/colorscale_cividis.jpg)
	COLORMAP_TWILIGHT , //!< ![twilight](pics/colormaps/colorscale_twilight.jpg)
	COLORMAP_TWILIGHT_SHIFTED , //!< ![twilight shifted](pics/colormaps/colorscale_twilight_shifted.jpg)
	COLORMAP_TURBO  , //!< ![turbo](pics/colormaps/colorscale_turbo.jpg)
	COLORMAP_DEEPGREEN   //!< ![deepgreen](pics/colormaps/colorscale_deepgreen.jpg)
	};
	if (m.empty())
	{
		MessageBox(_T("图像加载失败！"), _T("error"));
		return;
	}
	int index = 0;
	while (1)   // 循环显示
	{
		int key = waitKey(1000);  // 2 s一刷新
		if (key == 27)
		{
			break;
		}
		
		applyColorMap(m,img, m_colorMap[index%21]);
		index++;

		namedWindow("颜色表", WINDOW_NORMAL);
		imshow("颜色表", img);
		if (key == 83 || key == 115)  // 按下 s 键  保存当前图像
		{
			std::stringstream filename;
			filename << "E:\\壁纸\\colorMap\\" << index <<"--"<< m_colorMap [index%21]<< ".jpg";
			imwrite(filename.str(),img);
		}
	}
}
//图像位操作
void CV120201012Dlg::bitwiseDemo()
{
    // 创建俩张图像
	Mat m1 = Mat::zeros(Size(255,255),CV_8UC3);
	Mat m2 = Mat::zeros(Size(255, 255), CV_8UC3);
	// 使用 rectangle 来绘制图像
	rectangle(m1,Rect(150,150,80,80),Scalar(255,255,0),-1,LINE_8,0);
	rectangle(m2, Rect(200, 200, 80, 80), Scalar(0, 255, 255), -1, LINE_8, 0);  // -1 填充 >0 绘制（描边）

	// 运算
	Mat img;
	bitwise_and(m1,m2,img);
	imshow("与运算", img);
	bitwise_or(m1, m2, img);
	imshow("或运算", img);
	bitwise_xor(m1, m2, img);
	imshow("异或运算", img);
	bitwise_not(m2, img);
	imshow("非运算", img);

}
// 通道混合
void CV120201012Dlg::channelDemo()
{
	Mat m = imread("E:\\壁纸\\周震南\\微信图片_20200610160556.jpg");
	if (m.empty())
	{
		MessageBox(_T("图像加载失败！"), _T("error"));
		return;
	}
	//分离通道
	// 接收分离后通道的数组
	std::vector<Mat> chan;
	split(m,chan);

	imshow("蓝色B", chan[0]);
	imshow("绿色G", chan[1]);
	imshow("红色R", chan[2]);

	// 将单通道混合
	Mat m1 = Mat::zeros(m.size(),m.type());
	chan[0] = 0;
	chan[1] = 0;
	// 只显示 红色通道
	//try {
	//	merge(m, m1);
	//	imshow("只显示红色", m1);
	//}
	//catch (Exception e)
	//{
	//	std::string str;
	//	str = e.msg;
	//}
	

	//  通道混合
	int chanArry[] = {1,2,0,1,2,2};
	mixChannels(m,m1, chanArry,3);

	imshow("通道混合", m1);

}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////  20201021  ////////////////////////////////////////////////
// 图像像素值统计
void CV120201012Dlg::pixel_statistic()
{
	Mat m = imread("E:\\壁纸\\周震南\\微信图片_20200610160556.jpg");
	if (m.empty())
	{
		MessageBox(_T("图像加载失败！"), _T("error"));
		return;
	}

	// 获取图像每个通道像素的最大值和最小值以及位置点
	// 将图像分离成3个单通道
	std::vector<Mat> img;
	split(m, img);
	double min, max;
	Point minLoc, maxLoc;
	for (int i = 0;i < img.size();i++)
	{
		// 获取
		minMaxLoc(img[i],&min,&max,&minLoc,&maxLoc,Mat());
	}
	// 获取图像像素的平均值和方差
	Mat mean, stddev;
	meanStdDev(m,mean,stddev,Mat());
}
// 图像几何形状绘制
void CV120201012Dlg::drawDemo()
{
	Mat m = imread("E:\\壁纸\\周震南\\微信图片_20200610160556.jpg");
	if (m.empty())
	{
		MessageBox(_T("图像加载失败！"), _T("error"));
		return;
	}

	// 在图像上绘制矩形
	Rect rec;
	rec.x = 100;  // 横坐标
	rec.y = 100;  // 纵坐标
	rec.width = 50;  // 宽 50
	rec.height = 50;   // 高 50
	rectangle(m,rec,Scalar(0,255,255),-1,8,0);

	// 绘制圆形
	Point p;  // 圆心坐标
	p.x = 120;
	p.y = 120;
	circle(m,p,3,Scalar(255,255,0),-1,8,0);
	//绘制 线
	Point p1, p2; // 起点和终点
	p1.x = 50;
	p1.y = 50;
	p2.x = 100;
	p2.y = 100;
	line(m,p1,p2,Scalar(34,45,100),4,LINE_AA,0);

	// 绘制椭圆形
	//RotatedRect rr;
	//rr.center.x = 100.0;
	//rr.center.y = 100.0;
	//rr.size = Size(30, 50);
	//rr.angle = 45;
	//ellipse(m,rr,Scalar(90,90,90),-1,8);

	// 定义一张黑图，将两张图像进行合并
	Mat img = Mat::zeros(m.size(),m.type());
	img = Scalar(255,255,255);
	Mat dst;
	addWeighted(m,0.7,img,0.3,0,dst);

	imshow("绘制图像",dst);

}
// 随机图像绘制
void CV120201012Dlg::randomDraw()
{
    // 定义一张背景板
	Mat img = Mat(Size(300,300), CV_8UC3);
	img = Scalar(0, 0, 0);
	// 定义随机数
	RNG randomnum(12345);
	while (1)
	{
		int key = waitKey(10);
		if (key == 27)
			break;
		int x = randomnum.uniform(0,300);   //左上点的横坐标
		int y = randomnum.uniform(0, 300);   //右上点的纵坐标
		int w = randomnum.uniform(0, 300); //左下点的横坐标
		int h = randomnum.uniform(0, 300);  //右下点的纵坐标

		int b = randomnum.uniform(0, 255);  // 3 个颜色值
		int g = randomnum.uniform(0, 255);
		int r = randomnum.uniform(0, 255);

		// 画线
		line(img,Point(x,y),Point(w,h),Scalar(b, g, r),1,LINE_AA,0);

		//显示
		imshow("随机图像",img);
	}

}
// 绘制多边形
void CV120201012Dlg::mutiplyDraw()
{
	// 定义一张背景板
	Mat img = Mat(Size(800, 800), CV_8UC3);
	img = Scalar(0, 0, 0);

	// 定义5个顶点坐标
	Point p1(439, 126);
	Point p2(466, 198);
	Point p3(546, 198);
	Point p4(482, 244);
	Point p5(507, 316);
	Point p6(439, 275);
	Point p7(371,316);
	Point p8(396,244);
	Point p9(330, 198);
	Point p10(414, 198);
	// 将5个坐标放入一个容器中
	std::vector<Point> vecp;
	vecp.push_back(p1);
	vecp.push_back(p2);
	vecp.push_back(p3);
	vecp.push_back(p4);
	vecp.push_back(p5);
	vecp.push_back(p6);
	vecp.push_back(p7);
	vecp.push_back(p8);
	vecp.push_back(p9);
	vecp.push_back(p10);
	fillPoly(img,vecp,Scalar(255,0,0),8,0);
	polylines(img,vecp,true,Scalar(0,0,255),2,LINE_AA,0);
	std::vector<std::vector<Point>> contours;
	contours.push_back(vecp);
	//drawContours(img, contours, -1,Scalar(0,255,0),-1);

	imshow("多边形绘制",img);
}
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////  20201027  ///////////////////////////////////
	Point startP(-1, -1);
	Point endP(-1, -1);
// 鼠标事件绘制图像
// 鼠标响应事件  void setMousecallback(const string& winname, MouseCallback onMouse, void* userdata=0)
static void on_Mouse(int event, int x, int y, int flags, void* userdata)
{
	
	int w, h;
	
	Mat m = *((Mat*)userdata);
	
	// 判断鼠标事件
	if (event == EVENT_LBUTTONDOWN)   // 鼠标左键按下
	{
		// 获取鼠标点坐标
		startP.x = x;
		startP.y = y;
		//MessageBox(NULL, _T("鼠标左键按下"),NULL,0);
		//std::cout << "鼠标左键按下";
		
	}
	else if (event == EVENT_MOUSEMOVE)    // 鼠标在移动
	{
		//MessageBox(NULL, _T("鼠标移动"), NULL, 0);
		if (startP.x > 0 && startP.y > 0)   // 起始坐标不为负值时进行操作
		{
		//	MessageBox(NULL, _T("鼠标移动2"), NULL, 0);
			//获取鼠标坐标
			endP.x = x;
			endP.y = y;
			w = endP.x - startP.x;
			h = endP.y - startP.y;

			//画矩形
			rectangle(m, Rect(startP, endP), Scalar(0, 0, 255), 1, 1, 0);
			imshow("鼠标绘制", m);
		}
	}
	else if (event == EVENT_LBUTTONUP)   // 鼠标抬起
	{
		// 获取鼠标坐标
		endP.x = x;
		endP.y = y;
		w = endP.x - startP.x;
		h = endP.y - startP.y;

		//MessageBox(NULL, _T("鼠标左键抬起"), NULL, 0);
		if (w>0&&h>0)
		{
			// 画矩形
			rectangle(m, Rect(startP, endP), Scalar(255, 0, 0), 1, 1, 0);
			imshow("鼠标绘制", m);
			startP.x = -1;  // 当次完事后重置
			startP.y = -1;
		}
	}
}

void CV120201012Dlg::mouseDraw_Demo()
{
	// 创建一个窗口
	namedWindow("鼠标绘制", WINDOW_AUTOSIZE);
	 //创建一幅图像
	Mat img = Mat::zeros(Size(500,500),CV_8UC3);
	if (img.empty())
	{
		MessageBox(_T("图像加载失败！"), _T("error"));
		return;
	}


	// 调用鼠标响应事件函数
	setMouseCallback("鼠标绘制",on_Mouse,(void*)(&img));

	imshow("鼠标绘制",img);

	waitKey(0);
}








///////////////////////////////////////////////////////////////////////////////////////