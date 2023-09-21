#pragma once
#include "afxdialogex.h"

#define MAX_POINT	1000		// 상수 정의
// CDlgImage 대화 상자

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgImage();

	int nRadius;
	int nCenterX;
	int nCenterY;
	
	CImage m_image;
	CWnd* m_pParent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDlgImage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

private:
	void InitImage();
	
public:
	afx_msg void OnPaint();
	
	void drawData();
	void centerLine(CDC* pDC, CRect pRect);
	CRect rectData();
};
