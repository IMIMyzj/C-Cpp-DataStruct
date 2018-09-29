#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	HANDLE hFile;
	LPCTSTR lpFileName = "G:\\PS\\*.*";	//指定搜索的位置
	WIN32_FIND_DATA pNextInfo;	//搜索得到的文件信息将储存在pNextInfo中;
	hFile = FindFirstFile(lpFileName, &pNextInfo);//请注意是 &pNextInfo , 不是 pNextInfo;
	if (hFile == INVALID_HANDLE_VALUE)
	{
		//搜索失败
		exit(-1);
	}
	while (FindNextFile(hFile, &pNextInfo))
	{
		if (pNextInfo.cFileName[0] == '.')//过滤.和..
			continue;
		cout << "得到文件：" << pNextInfo.cFileName << endl;
	}

	while(1){}
}