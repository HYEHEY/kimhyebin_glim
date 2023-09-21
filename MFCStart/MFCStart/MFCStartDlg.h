
// MFCStartDlg.h: 헤더 파일
//

#pragma once
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")		// 콘솔창 띄우기


// CMFCStartDlg 대화 상자
class CMFCStartDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCStartDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	
	enum FourOP m_selectedOP;	// 사용자가 사칙 연산 중 무엇을 선택했는지 저장
	int m_nFirstNum;			// 계산을 위해 입력한 첫 번째 피 연산자 저장
	int m_nSecondNum;			// 두 번째 피 연산자를 저장
	int m_nResult;				// 계산 결과를 저장
	int m_nClickCnt;			// 클릭 횟수 저장


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSTART_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_nNum;
	afx_msg void OnBnClickedBtn0();
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn9();
	afx_msg void OnBnClickedBtnBack();
	afx_msg void OnBnClickedBtnReset();
	afx_msg void OnBnClickedBtnDivide();
	afx_msg void OnBnClickedBtnMustiply();
	afx_msg void OnBnClickedBtnMinus();
	afx_msg void OnBnClickedBtnPlus();
	afx_msg void OnBnClickedBtnResult();
};

// 사용자가 어떤 연산자 버튼을 눌렀는지 구분
enum FourOP {
	PLUS,
	MINUS,
	MUSTIPLY,
	DIVIDE,
	NONE
};