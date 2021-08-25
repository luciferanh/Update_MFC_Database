#pragma once
#include "odbcinst.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include <afxdb.h>

class CNguoi: public CRecordset
{
public:
	CDatabase db;
	CString id,Ten;
	CString server = _T("DESKTOP-LERS9E6"), databaseName = _T("mytest"), username = _T("vietanhh"), password = _T("123456");
	CNguoi() { ; };
	~CNguoi() { db.Close(); };
	CDatabase* GetDatabase();
	void Exc(CListCtrl&);
};

