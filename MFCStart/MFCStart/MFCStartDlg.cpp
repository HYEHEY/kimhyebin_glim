

// 간단한 계산기 만들기

// MFCStartDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCStart.h"
#include "MFCStartDlg.h"
#include "afxdialogex.h"
// #include <iostream>		// 콘솔창 띄우기

#ifdef _DEBUG
#define new DEBUG_NEWD
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCStartDlg 대화 상자



CMFCStartDlg::CMFCStartDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSTART_DIALOG, pParent)
	, m_nNum(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCStartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NUM, m_nNum);
}

BEGIN_MESSAGE_MAP(CMFCStartDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_0, &CMFCStartDlg::OnBnClickedBtn0)
	ON_BN_CLICKED(IDC_BTN_1, &CMFCStartDlg::OnBnClickedBtn1)
	ON_BN_CLICKED(IDC_BTN_2, &CMFCStartDlg::OnBnClickedBtn2)
	ON_BN_CLICKED(IDC_BTN_3, &CMFCStartDlg::OnBnClickedBtn3)
	ON_BN_CLICKED(IDC_BTN_4, &CMFCStartDlg::OnBnClickedBtn4)
	ON_BN_CLICKED(IDC_BTN_5, &CMFCStartDlg::OnBnClickedBtn5)
	ON_BN_CLICKED(IDC_BTN_6, &CMFCStartDlg::OnBnClickedBtn6)
	ON_BN_CLICKED(IDC_BTN_7, &CMFCStartDlg::OnBnClickedBtn7)
	ON_BN_CLICKED(IDC_BTN_8, &CMFCStartDlg::OnBnClickedBtn8)
	ON_BN_CLICKED(IDC_BTN_9, &CMFCStartDlg::OnBnClickedBtn9)
	ON_BN_CLICKED(IDC_BTN_BACK, &CMFCStartDlg::OnBnClickedBtnBack)
	ON_BN_CLICKED(IDC_BTN_RESET, &CMFCStartDlg::OnBnClickedBtnReset)
	ON_BN_CLICKED(IDC_BTN_DIVIDE, &CMFCStartDlg::OnBnClickedBtnDivide)
	ON_BN_CLICKED(IDC_BTN_MUSTIPLY, &CMFCStartDlg::OnBnClickedBtnMustiply)
	ON_BN_CLICKED(IDC_BTN_MINUS, &CMFCStartDlg::OnBnClickedBtnMinus)
	ON_BN_CLICKED(IDC_BTN_PLUS, &CMFCStartDlg::OnBnClickedBtnPlus)
	ON_BN_CLICKED(IDC_BTN_RESULT, &CMFCStartDlg::OnBnClickedBtnResult)
END_MESSAGE_MAP()


// CMFCStartDlg 메시지 처리기

BOOL CMFCStartDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	// 멤버 변수 
	m_selectedOP = NONE;
	m_nFirstNum = 0;
	m_nSecondNum = 0;
	m_nClickCnt = 0;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCStartDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCStartDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCStartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCStartDlg::OnBnClickedBtn0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);			// 컨트롤의 값을 멤버 변수로 전달
	m_nNum = m_nNum + '0';
	UpdateData(FALSE);			// 멤버 변수를 컨트롤로 전송
}

void CMFCStartDlg::OnBnClickedBtn1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nNum = m_nNum + '1';
	UpdateData(FALSE);
}


void CMFCStartDlg::OnBnClickedBtn2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nNum = m_nNum + '2';
	UpdateData(FALSE);
}


void CMFCStartDlg::OnBnClickedBtn3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nNum = m_nNum + '3';
	UpdateData(FALSE);
}


void CMFCStartDlg::OnBnClickedBtn4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nNum = m_nNum + '4';
	UpdateData(FALSE);
}


void CMFCStartDlg::OnBnClickedBtn5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nNum = m_nNum + '5';
	UpdateData(FALSE);
}


void CMFCStartDlg::OnBnClickedBtn6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nNum = m_nNum + '6';
	UpdateData(FALSE);
}


void CMFCStartDlg::OnBnClickedBtn7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nNum = m_nNum + '7';
	UpdateData(FALSE);
}


void CMFCStartDlg::OnBnClickedBtn8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nNum = m_nNum + '8';
	UpdateData(FALSE);
}


void CMFCStartDlg::OnBnClickedBtn9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nNum = m_nNum + '9';
	UpdateData(FALSE);
}

void CMFCStartDlg::OnBnClickedBtnBack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//bcakspace ======
	UpdateData(TRUE);
	CString nNum;
	GetDlgItemText(IDC_EDIT_NUM, nNum);
	int len = nNum.GetLength();
	CString Num = nNum.Mid(0, len - 1);
	m_nNum.Format(_T("%s"), Num);
	UpdateData(FALSE);
}


void CMFCStartDlg::OnBnClickedBtnReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//reset =====
	UpdateData(TRUE);
	m_nNum = ' ';
	UpdateData(FALSE);
}


void CMFCStartDlg::OnBnClickedBtnDivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//divide =====
	m_nClickCnt++;

	UpdateData(TRUE);
	m_selectedOP = DIVIDE;
	m_nFirstNum = _ttoi(m_nNum);	// 정수로 변환
	m_nNum = ' ';
	UpdateData(FALSE);
	
	if (m_nClickCnt >= 1) {
		// 복합 계산 방지
		GetDlgItem(IDC_BTN_DIVIDE) -> EnableWindow(FALSE);		// 버튼 비활성화
		GetDlgItem(IDC_BTN_MUSTIPLY) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_MINUS) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_PLUS) -> EnableWindow(FALSE);
	}
}


void CMFCStartDlg::OnBnClickedBtnMustiply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//mustiply =====
	m_nClickCnt++;

	UpdateData(TRUE);
	m_selectedOP = MUSTIPLY;
	m_nFirstNum = _ttoi(m_nNum);
	m_nNum = ' ';
	UpdateData(FALSE);

	if (m_nClickCnt >= 1) {
		//AfxMessageBox(_T("버튼을 두 번 이상 누르셨습니다."));
		GetDlgItem(IDC_BTN_DIVIDE) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_MUSTIPLY) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_MINUS) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_PLUS) -> EnableWindow(FALSE);
	}
}


void CMFCStartDlg::OnBnClickedBtnMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//minus ===== 
	m_nClickCnt++;

	UpdateData(TRUE);
	m_selectedOP = MINUS;
	m_nFirstNum = _ttoi(m_nNum);
	m_nNum = ' ';
	UpdateData(FALSE);

	if (m_nClickCnt >= 1) {
		//AfxMessageBox(_T("버튼을 두 번 이상 누르셨습니다."));
		GetDlgItem(IDC_BTN_DIVIDE) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_MUSTIPLY) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_MINUS) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_PLUS) -> EnableWindow(FALSE);
	}
}


void CMFCStartDlg::OnBnClickedBtnPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//plus =====
	m_nClickCnt++;

	UpdateData(TRUE);
	m_selectedOP = PLUS;
	m_nFirstNum = _ttoi(m_nNum);
	m_nNum = ' ';
	UpdateData(FALSE);

	if (m_nClickCnt >= 1) {
		//AfxMessageBox(_T("버튼을 두 번 이상 누르셨습니다."));
		GetDlgItem(IDC_BTN_DIVIDE) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_MUSTIPLY) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_MINUS) -> EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_PLUS) -> EnableWindow(FALSE);
	}
}


void CMFCStartDlg::OnBnClickedBtnResult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//result =====

	UpdateData(TRUE);
	m_nSecondNum = _ttoi(m_nNum);

	m_nClickCnt = 0;

	GetDlgItem(IDC_BTN_DIVIDE)->EnableWindow(TRUE);			// 버튼 활성화
	GetDlgItem(IDC_BTN_MUSTIPLY)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_MINUS)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_PLUS)->EnableWindow(TRUE);

	switch (m_selectedOP) { 
	case DIVIDE:
		m_nResult = m_nFirstNum / m_nSecondNum;
		break;

	case MUSTIPLY:
		m_nResult = m_nFirstNum * m_nSecondNum;
		break;

	case MINUS:
		m_nResult = m_nFirstNum - m_nSecondNum;
		break;

	case PLUS:
		m_nResult = m_nFirstNum + m_nSecondNum;
		break;
	
	default:
		break;
	}

	m_nNum.Format(_T("%d"), m_nResult);
	UpdateData(FALSE);
}
