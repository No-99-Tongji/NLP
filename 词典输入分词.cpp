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
	//输入词典
	cout << "第一代规则分词器" << endl;
	cout << "请输入词典（最大长度" << (maxWordLen - 1) / 2 << ' ' << "词汇数量" << bankCapacity << "）" << endl;
	for (int i = 0; i < bankCapacity; i++)
	{
		char temp[maxSentenseLen];
		cin >> temp;
		strcpy(sortedDic[strlen(temp) / 2 - 1][numOfEachLenth[strlen(temp) / 2 - 1]++], temp);
	}
	//输入句子
	char input[51];
	cout << "请输入待处理的句子:";
	cin >> input;
	cout << endl;
	char result[20][maxWordLen] = {0};
	int numOfWords = 0;
	int beginPos = 0;
	//i是词汇长度
	for (int i = (maxWordLen - 1) / 2 - 1; i >= 0; i--)
	{
		if ((i + 1) * 2 > strlen(input) - beginPos)
			continue;
		//j是词典i长度下第几个词
		for (int j = 0; j < numOfEachLenth[i]; j++)
			//k是input开始对比的位置（一个字一个字地减少）
			for (int k = 0; k < strlen(input); k += 2)
				if (!strncmp(&input[k], sortedDic[i][j], (i + 1) * 2))
				{
					strcpy(result[k / 2], sortedDic[i][j]);
					beginPos += (i + 1) * 2;
				}
	}
	//输出分词结果
	for (int i = 0; i < 20; i++)
	{
		if (result[i][0] == 0)
			continue;
		else
			cout << result[i] << "/";
	}

	return 0;
}