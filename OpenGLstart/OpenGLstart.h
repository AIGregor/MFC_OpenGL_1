
// OpenGLstart.h : main header file for the OpenGLstart application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// COpenGLstartApp:
// See OpenGLstart.cpp for the implementation of this class
//

class COpenGLstartApp : public CWinApp
{
public:
	COpenGLstartApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COpenGLstartApp theApp;
