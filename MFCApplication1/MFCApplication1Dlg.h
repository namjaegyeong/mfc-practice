
// MFCApplication1Dlg.h: 헤더 파일
//

#pragma once

#include <afxmt.h>  // For CMutex
#include <afxwin.h> // For AfxBeginThread

// CMFCApplication1Dlg 대화 상자
class CMFCApplication1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
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
	afx_msg void OnClickedButton1();

	CWinThread* m_pThread1;
	CWinThread* m_pThread2;
	bool m_bExitFlag;

	// Global mutex and shared data variable.
	CMutex g_mutex;
	int g_sharedData = 0;

	static UINT ThreadProc(LPVOID pParam);
	static void Wait(ULONGLONG dwMillisecond);

	void ExitThread();
};
