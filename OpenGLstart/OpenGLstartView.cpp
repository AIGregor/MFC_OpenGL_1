
// OpenGLstartView.cpp : implementation of the COpenGLstartView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OpenGLstart.h"
#endif

#include "OpenGLstartDoc.h"
#include "OpenGLstartView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpenGLstartView

IMPLEMENT_DYNCREATE(COpenGLstartView, CView)

BEGIN_MESSAGE_MAP(COpenGLstartView, CView)
END_MESSAGE_MAP()

// COpenGLstartView construction/destruction

COpenGLstartView::COpenGLstartView()
{
	// TODO: add construction code here

}

COpenGLstartView::~COpenGLstartView()
{
}

BOOL COpenGLstartView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// COpenGLstartView drawing

void COpenGLstartView::OnDraw(CDC* /*pDC*/)
{
	COpenGLstartDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// COpenGLstartView diagnostics

#ifdef _DEBUG
void COpenGLstartView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGLstartView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGLstartDoc* COpenGLstartView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGLstartDoc)));
	return (COpenGLstartDoc*)m_pDocument;
}
#endif //_DEBUG


// COpenGLstartView message handlers
