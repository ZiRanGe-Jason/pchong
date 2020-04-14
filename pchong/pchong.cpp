#include "pch.h"
#include <iostream>
#include <stdio.h>
#include<fstream>
#include <string>
#include <io.h>
#include <direct.h>
#include <Windows.h>
#include <sstream>
#pragma comment(lib,"URlmon")
using namespace std;
int a, b,n=1;
string s, jpgurl;
bool download(const char* jpg,const char* url)
{
	char buffer[MAX_PATH];
	_getcwd(buffer, MAX_PATH);
	strcat_s(buffer,jpg);
	HRESULT Result = URLDownloadToFileA(NULL,url, buffer, 0, NULL);
	switch (Result)
	{
		case S_OK:return 1;
		case E_OUTOFMEMORY:return 0;
	}
	return 0;
}
int main()
{
	system("md jpgs");
	system("color 1f");
	FILE *stream; char geturl[1024];
	ifstream in1(geturl);
	in1.open("urlgot.ulg");
	in1.getline(geturl,sizeof(geturl));
	in1.close();
	download("\\web.in",geturl);
	freopen("web.in", "r",stdin);
	while (cin>>s)
	{
		if (s.find("src=\"") != s.npos)
		{
			a = s.find("src=\"");
			b = s.find("\"", a + 5);
			jpgurl=s.substr(a+5, b - a-5);
			string x = "./jpgs/",y=".jpg";
			stringstream ss;
			ss << x << n << y;
			download(ss.str().c_str(), jpgurl.c_str());
			if (_access(ss.str().c_str(), 0) == 0)n++;
			cout << ss.str().c_str() << ' ' << jpgurl.c_str() << endl;
		}
	}
	printf("---finishi---");
	return 0;
}
