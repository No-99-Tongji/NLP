#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

//const int maxWordLen = 29;
//const int bankCapacity = 133819;
const int maxWordLen = 9;
const int bankCapacity = 10;
const int maxSentenseLen = 101;

char bank[bankCapacity][maxWordLen];
char sortedDic[(maxWordLen - 1) / 2][100000][maxWordLen];
int numOfEachLenth[(maxWordLen - 1) / 2];

int main()
{
	//����ʵ�
	cout << "��һ������ִ���" << endl;
	cout << "������ʵ䣨��󳤶�" << (maxWordLen - 1) / 2 << ' ' << "�ʻ�����" << bankCapacity << "��" << endl;
	for (int i = 0; i < bankCapacity; i++)
	{
		char temp[maxSentenseLen];
		cin >> temp;
		strcpy(sortedDic[strlen(temp) / 2 - 1][numOfEachLenth[strlen(temp) / 2 - 1]++], temp);
	}
	//�������
	char input[51];
	cout << "�����������ľ���:";
	cin >> input;
	cout << endl;
	char result[20][maxWordLen] = {0};
	int numOfWords = 0;
	int beginPos = 0;
	//i�Ǵʻ㳤��
	for (int i = (maxWordLen - 1) / 2 - 1; i >= 0; i--)
	{
		if ((i + 1) * 2 > strlen(input) - beginPos)
			continue;
		//j�Ǵʵ�i�����µڼ�����
		for (int j = 0; j < numOfEachLenth[i]; j++)
			//k��input��ʼ�Աȵ�λ�ã�һ����һ���ֵؼ��٣�
			for (int k = 0; k < strlen(input); k += 2)
				if (!strncmp(&input[k], sortedDic[i][j], (i + 1) * 2))
				{
					strcpy(result[k / 2], sortedDic[i][j]);
					beginPos += (i + 1) * 2;
				}
	}
	//����ִʽ��
	for (int i = 0; i < 20; i++)
	{
		if (result[i][0] == 0)
			continue;
		else
			cout << result[i] << "/";
	}

	return 0;
}