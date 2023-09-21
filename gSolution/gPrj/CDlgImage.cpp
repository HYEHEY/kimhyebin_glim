// CDlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "gPrj.h"
#include "afxdialogex.h"
#include "CDlgImage.h"
#include <iostream>


// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgImage, pParent)
{
	nRadius = 0;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgImage::InitImage()
{
	// 이미지 생성
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
			m_image.SetColorTable(0, 256, rgb);
		}
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth * nHeight);
}

void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}
}

#define COLOR_YELLOW	RGB(0xffff, 0xffff, 0)
void CDlgImage::drawData()
{
	CPaintDC dc(this);
	CDC* pDC = &dc;

	CRect bg(-1, -1, 640, 480);
	pDC->Rectangle(bg);

	CPen pen;
	pen.CreatePen(PS_SOLID, 5, COLOR_YELLOW);
	CPen* pOldPen = pDC->SelectObject(&pen);

	CRect rect = rectData();
	pDC->Ellipse(rect);

	centerLine(pDC, rect);
}

CRect CDlgImage::rectData()
{
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	int nSumX = rand() % (nWidth - nRadius * 2) + nRadius;
	int nSumY = rand() % (nHeight - nRadius * 2) + nRadius;

	int nLeft = nSumX - nRadius;
	int nTop = nSumY - nRadius;
	int nRight = nSumX + nRadius;
	int nBottom = nSumY + nRadius;

	CRect rect(nLeft, nTop, nRight, nBottom);

	return rect;
}

void CDlgImage::centerLine(CDC* pDC, CRect pRect)
{
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, COLOR_YELLOW);
	CPen* pOldPen = pDC->SelectObject(&pen);

	int nLeft = pRect.left;
	int nRight = pRect.right;
	int nTop = pRect.top;
	int nBottom = pRect.bottom;
	
	nCenterX = (nRight + nLeft) / 2;
	nCenterY = (nBottom + nTop) / 2;
	//printf("%d", nCenterX);
	
	pDC->MoveTo(nCenterX - 10, nCenterY);
	pDC->LineTo(nCenterX + 10, nCenterY);
	
	pDC->MoveTo(nCenterX, nCenterY - 10);
	pDC->LineTo(nCenterX, nCenterY + 10);
}
