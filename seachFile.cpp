#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	HANDLE hFile;
	LPCTSTR lpFileName = "G:\\PS\\*.*";	//ָ��������λ��
	WIN32_FIND_DATA pNextInfo;	//�����õ����ļ���Ϣ��������pNextInfo��;
	hFile = FindFirstFile(lpFileName, &pNextInfo);//��ע���� &pNextInfo , ���� pNextInfo;
	if (hFile == INVALID_HANDLE_VALUE)
	{
		//����ʧ��
		exit(-1);
	}
	while (FindNextFile(hFile, &pNextInfo))
	{
		if (pNextInfo.cFileName[0] == '.')//����.��..
			continue;
		cout << "�õ��ļ���" << pNextInfo.cFileName << endl;
	}

	while(1){}
}