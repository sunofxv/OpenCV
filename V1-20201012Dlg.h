
// V1-20201012Dlg.h: 头文件
//

#pragma once


// CV120201012Dlg 对话框
class CV120201012Dlg : public CDialogEx
{
// 构造
public:
	CV120201012Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_V120201012_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void showImg();
	void changeImg();
	void yanMo();
	void createNew();
	void imgCopy();
	void PixlShow();
	void pixelOperator();
	void trackingBar();
	void keyboardDemo();
	void colorMap();
	void bitwiseDemo();
	void channelDemo();
	void pixel_statistic();
	void drawDemo();
	void randomDraw();
	void mutiplyDraw();
	void mouseDraw_Demo();
};

static void onTrack(int b, void*);
