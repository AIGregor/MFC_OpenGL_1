
// OpenGLstartView.h : interface of the COpenGLstartView class
//

#pragma once


class COpenGLstartView : public CView
{
protected: // create from serialization only
	COpenGLstartView();
	DECLARE_DYNCREATE(COpenGLstartView)

// Attributes
public:
	COpenGLstartDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~COpenGLstartView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in OpenGLstartView.cpp
inline COpenGLstartDoc* COpenGLstartView::GetDocument() const
   { return reinterpret_cast<COpenGLstartDoc*>(m_pDocument); }
#endif

