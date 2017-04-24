
// jisuanqiDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "jisuanqi.h"
#include "jisuanqiDlg.h"
#include "afxdialogex.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CjisuanqiDlg 对话框



CjisuanqiDlg::CjisuanqiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_JISUANQI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CjisuanqiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CjisuanqiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON8, &CjisuanqiDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON6, &CjisuanqiDlg::OnBnClickedButton6)
	ON_EN_CHANGE(IDC_EDIT1, &CjisuanqiDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON16, &CjisuanqiDlg::OnBnClickedButton16)
	ON_BN_CLICKED(ID_APP_EXIT, &CjisuanqiDlg::OnBnClickedAppExit)
	ON_BN_CLICKED(IDC_BUTTON1, &CjisuanqiDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CjisuanqiDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CjisuanqiDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CjisuanqiDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CjisuanqiDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CjisuanqiDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &CjisuanqiDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CjisuanqiDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CjisuanqiDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CjisuanqiDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CjisuanqiDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CjisuanqiDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CjisuanqiDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CjisuanqiDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CjisuanqiDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CjisuanqiDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CjisuanqiDlg::OnBnClickedButton20)
END_MESSAGE_MAP()


// CjisuanqiDlg 消息处理程序
double temp = 0;
double a;
double a_temp = 0;
int flag=0;
char num[16];//16位数以内运算
int i = 0;
int j = 0,k;
CString str;
BOOL CjisuanqiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//m_edit.SetWindowText(_T("计算器"));
	// 将“关于...”菜单项添加到系统菜单中。
	
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CjisuanqiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CjisuanqiDlg::OnPaint()
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
HCURSOR CjisuanqiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CjisuanqiDlg::OnBnClickedAppExit()
{
	CDialogEx::OnOK();// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton1()
{
	a = a_temp;
	m_edit.SetWindowText(_T("√"));
	i = 0;
	a_temp = 0;
	num[j] = 0;
	flag = 6;// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton2()
{
	a = a_temp;
	m_edit.SetWindowText(_T("^2"));
	i = 0;
	a_temp = 0;
	num[j] = 0;
	flag = 7;// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton3()
{
	if (flag == 5)
	{
		i = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	}
	if (num[j] == '.');
	else
	{
	temp = 0;
	num[i] = '.';
	j = i;
	//m_edit.SetWindowText(_T("1"));
	m_edit.SetSel(i, i + 1);
	str.Format(_T("%c"), num[i]);
	m_edit.ReplaceSel(str);
	i++;
	 }
		
	// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton4()
{
	
	a = a_temp;
	m_edit.SetWindowText(_T("lg"));
	i = 0;
	a_temp = 0;
	num[j] = 0;
	flag = 8;// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton5()
{
	
		i = 0;
		temp = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	// TODO: 在此添加控件通知处理程序代码
}
void CjisuanqiDlg::OnBnClickedButton6()
{
	if (flag == 5)
	{
		i = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	}
	temp = 7;
	num[i] = temp;
	//m_edit.SetWindowText(_T("1"));
	m_edit.SetSel(i, i + 1);
	str.Format(_T("%d"), num[i]);
	m_edit.ReplaceSel(str);
	if (i<16)
		i++;
	if (num[j] == '.')
		a_temp = a_temp + temp / pow(10, (i - j - 1));
	else
		a_temp = a_temp * 10 + temp;// TODO: 在此添加控件通知处理程序代码
}

void CjisuanqiDlg::OnBnClickedButton7()
{
	if (flag == 5)
	{
		i = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	}
	temp = 8;
	num[i] = temp;
	//m_edit.SetWindowText(_T("1"));
	m_edit.SetSel(i, i + 1);
	str.Format(_T("%d"), num[i]);
	m_edit.ReplaceSel(str);
	if (i<16)
		i++;
	if (num[j] == '.')
		a_temp = a_temp + temp / pow(10, (i - j - 1));
	else
		a_temp = a_temp * 10 + temp;// TODO: 在此添加控件通知处理程序代码
}
void CjisuanqiDlg::OnBnClickedButton8()
{
	if (flag == 5)
	{
		i = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	}
	temp = 9;
	num[i] = temp;
	//m_edit.SetWindowText(_T("1"));
	m_edit.SetSel(i, i + 1);
	str.Format(_T("%d"), num[i]);
	m_edit.ReplaceSel(str);
	if (i<16)
		i++;
	if (num[j] == '.')
		a_temp = a_temp + temp / pow(10, (i - j - 1));
	else
		a_temp = a_temp * 10 + temp;// TODO: 在此添加控件通知处理程序代码
}

void CjisuanqiDlg::OnBnClickedButton9()
{
	a = a_temp;
	m_edit.SetWindowText(_T("x"));
	i = 0;
	a_temp = 0;
	num[j] = 0;
	flag = 3;// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton10()
{
	a = a_temp;
	m_edit.SetWindowText(_T("÷"));
	i = 0;
	a_temp = 0;
	num[j] = 0;
	flag = 4;// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton11()
{
	if (flag == 5)
	{
		i = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	}
	temp = 4;
	num[i] = temp;
	//m_edit.SetWindowText(_T("1"));
	m_edit.SetSel(i, i + 1);
	str.Format(_T("%d"), num[i]);
	m_edit.ReplaceSel(str);
	if (i<16)
		i++;
	if (num[j] == '.')
		a_temp = a_temp + temp / pow(10, (i - j - 1));
	else
		a_temp = a_temp * 10 + temp;// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton12()
{
	if (flag == 5)
	{
		i = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	}
	temp = 5;
	num[i] = temp;
	//m_edit.SetWindowText(_T("1"));
	m_edit.SetSel(i, i + 1);
	str.Format(_T("%d"), num[i]);
	m_edit.ReplaceSel(str);
	if (i<16)
		i++;
	if (num[j] == '.')
		a_temp = a_temp + temp / pow(10, (i - j - 1));
	else
		a_temp = a_temp * 10 + temp;// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton13()
{
	if (flag == 5)
	{
		i = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	}
	temp = 6;
	num[i] = temp;
	//m_edit.SetWindowText(_T("1"));
	m_edit.SetSel(i, i + 1);
	str.Format(_T("%d"), num[i]);
	m_edit.ReplaceSel(str);
	if (i<16)
		i++;
	if (num[j] == '.')
		a_temp = a_temp + temp / pow(10, (i - j - 1));
	else
		a_temp = a_temp * 10 + temp;// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton14()
{
	a = a_temp;
	m_edit.SetWindowText(_T("+"));
	i = 0;
	a_temp = 0;
	num[j] = 0;
	flag = 1;// TODO: 在此添加控件通知处理程序代码

}


void CjisuanqiDlg::OnBnClickedButton15()
{
	a = a_temp;
	m_edit.SetWindowText(_T("-"));
	i = 0;
	a_temp = 0;
	num[j] = 0;
	flag = 2;// TODO: 在此添加控件通知处理程序代码
}
void CjisuanqiDlg::OnBnClickedButton16()
{
	if (flag == 5)
	{
		i = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	}
	temp = 1;
	num[i] = temp;
	//m_edit.SetWindowText(_T("1"));
	m_edit.SetSel(i,i+1);
	str.Format(_T("%d"), num[i]);
	m_edit.ReplaceSel(str);
	if(i<16)
	i++;
	if (num[j] == '.')
		a_temp = a_temp  + temp/ pow(10,(i-j-1));
	else
	a_temp = a_temp * 10 + temp;
	// TODO: 在此添加控件通知处理程序代码
}

void CjisuanqiDlg::OnBnClickedButton17()
{
	if (flag == 5)
	{
		i = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	}
	temp = 2;
	num[i] = temp;
	//m_edit.SetWindowText(_T("1"));
	m_edit.SetSel(i, i + 1);
	str.Format(_T("%d"), num[i]);
	m_edit.ReplaceSel(str);
	if (i<16)
		i++;
	if (num[j] == '.')
		a_temp = a_temp + temp / pow(10, (i - j - 1));
	else
		a_temp = a_temp * 10 + temp;// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton18()
{
	if (flag == 5)
	{
		i = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	}
	temp = 3;
	num[i] = temp;
	//m_edit.SetWindowText(_T("1"));
	m_edit.SetSel(i, i + 1);
	str.Format(_T("%d"), num[i]);
	m_edit.ReplaceSel(str);
	if (i<16)
		i++;
	if (num[j] == '.')
		a_temp = a_temp + temp / pow(10, (i - j - 1));
	else
		a_temp = a_temp * 10 + temp;// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton19()
{
	if (flag == 5)
	{
		i = 0;
		a_temp = 0;
		num[j] = 0;
		m_edit.SetWindowText(_T(" "));
		flag = 0;
	}
	temp = 0;
	num[i] = temp;
	//m_edit.SetWindowText(_T("1"));
	m_edit.SetSel(i, i + 1);
	str.Format(_T("%d"), num[i]);
	m_edit.ReplaceSel(str);
	if (i<16)
		i++;
	if (num[j] == '.')
		a_temp = a_temp + temp / pow(10, (i - j - 1));
	else
		a_temp = a_temp * 10 + temp;// TODO: 在此添加控件通知处理程序代码
}


void CjisuanqiDlg::OnBnClickedButton20()
{
	switch (flag)
	{
	case 1:
		a = a + a_temp ;
		str.Format(_T("%f"), a);
		break;
	case 2:
		a = a - a_temp;
		str.Format(_T("%f"), a);
		break;
	case 3:
		a = a*a_temp;
		str.Format(_T("%f"), a);
		break;
	case 4:
		a = a / a_temp;
		str.Format(_T("%f"), a);
		break;
	case 6:
		a = sqrt(a);
		str.Format(_T("%f"), a);
		break;
	case 7:
		a = pow(a,2);
		str.Format(_T("%f"), a);
		break;
	case 8:
		a = log10(a);
		str.Format(_T("%f"), a);
		break;
	default:
		a =a_temp;
		str.Format(_T("%f"), a);
		break;
	}
	if(a-int(a)==0)
		str.Format(_T("%d"), int(a));
	m_edit.SetWindowText(str);
	a_temp = a;
	flag = 5;
	// TODO: 在此添加控件通知处理程序代码
}
void CjisuanqiDlg::OnEnChangeEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
}