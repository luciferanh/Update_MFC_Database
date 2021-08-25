#include "pch.h"
#include "Nguoi.h"


CDatabase* CNguoi::GetDatabase()
{
	bool is_connect = false;
	db.Close(); 
	CString connectString = _T("");
	connectString.Format(L"Driver={SQL Server};Server=%s;Database=%s;Uid=%s;Pwd=%s;", \
		server, databaseName, username, password);
	if (!db.IsOpen() && !db.OpenEx(connectString))
		is_connect = false;
	else is_connect = true;

	return &db;
}

void CNguoi::Exc(CListCtrl& )
{
	try
	{
		
		CString SqlString = _T("SELECT * FROM T1");
		db.ExecuteSQL(SqlString);

		db.Close();


	}
	catch (CDBException* pe)
	{
		// The error code is in pe->m_nRetCode
		pe->ReportError();
		pe->Delete();
	}
}
