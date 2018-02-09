
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

#pragma comment(lib,"opengl32.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "GL\gl.h"
#include "GL\glu.h"


// COpenGLstartView

IMPLEMENT_DYNCREATE(COpenGLstartView, CView)

BEGIN_MESSAGE_MAP(COpenGLstartView, CView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
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

	// An OpenGL window must be created with the following flags and must not
	// include CS_PARENTDC for the class style.

	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
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
	CRect clientRect;

	// TODO: add draw code for native data here
	GetClientRect(&clientRect);
	glViewport(0, 0, clientRect.right, clientRect.bottom);

	glClearColor(0.5, 0.5, 0.75, 1.0);	// цвет фона
	glClear(GL_COLOR_BUFFER_BIT);	// очистка буфера цвета

	glPointSize(30);			// размер точек
	glColor3f(1.0, 0.0, 0.5);		// текущий цвет примитивов

	glBegin(GL_POINTS);
		glVertex2f(-1, -1);
		glVertex2f(-1, 1);
		glVertex2f(0, 0);
		glVertex2f(1, -1);
		glVertex2f(1, 1);
	glEnd();

	glFinish();
	// Быстро скопировать содержимое заднего буфера окна в передний буфер
	SwapBuffers(wglGetCurrentDC());
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
int COpenGLstartView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormat;
	CDC *pDC;

	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	pDC = GetDC();
	
	memset(&pfd, 0, sizeof(pfd));
	
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.cDepthBits = 16;
	
	iPixelFormat = ChoosePixelFormat(pDC->m_hDC, &pfd);	
	SetPixelFormat(pDC->m_hDC, iPixelFormat, &pfd);
	
	m_hglrc = wglCreateContext(pDC->m_hDC);
	
	wglMakeCurrent(pDC->m_hDC, m_hglrc);
	ReleaseDC(pDC);

	return 0;
}


void COpenGLstartView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	wglMakeCurrent(NULL, NULL);
}


void COpenGLstartView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}
