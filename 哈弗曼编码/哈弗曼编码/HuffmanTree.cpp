#include "HuffmanTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include "Queue.h"

void CreatHuffman(HuffmanTree &HT, double *w, int n)
{
	if (n == 0)
	{
		printf("��ָ�����ļ���һ�����ļ� :");
		return;
	}
	if (n == 1)
	{
		printf("��ָ�����ļ�ֻ��һ���ַ���");
		return;
	}
	int m = 2 * n - 1;             //mΪ�ܽ����
	int i, j;                     //��������
	int s1, s2;
	HT = (HuffmanTree)malloc((m + 1)*sizeof(HTNode));    //��̬����m+1��λ������m���ڵ㣬0���±겻ʹ��
	HuffmanTree p = HT;   //pָ���㣬����ָ��
	p++;            //0�Ų���
	w++;
	for (i = 1; i <= n; i++, p++, ++w)    //��1-n�Ž�㸳��ʼֵ��Ȩ�طֱ��Ӧw�ĵ�һ�ŵ���n��
		*p = { *w,0,0,0 };
	for (; i <= m; i++, p++)           //ʣ�·�Ҷ�ӽ��ȫ��Ȩ�ظ�ֵΪ0
		*p = { 0,0,0,0 };
	for (i = n + 1; i <= m; i++)                          //��ʼ�����������
	{
		Select(HT, i - 1, s1, s2);//ÿһ���ڵ�һ����㵽��i-1�������ѡ��parentΪ0����weight��С�������ڵ㣬�±�Ϊs1,s2
		HT[s1].parent = i;             //s1,s2��Ԫ��˫��Ϊi�Ž��
		HT[s2].parent = i;
		HT[i].lchild = s1;             //i��Ԫ�����Һ���Ϊs1�ź�s2�Ž��
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;  //i�Ž��Ȩ��Ϊs1,s2Ȩ��֮��
	}
	printf("\n �������������ɹ�  �� \n\n\n");
	return;
}

void HuffmanCoding(HuffmanTree HT, HuffmanCode &HC, int n)
{//��Ҷ�ӽ�㵽�����������n��Ҷ�ӵĹ�������HT�Ĺ��������룬n��Ҷ�ӵı������HC[1]-HC[n]ָ����ַ�����
	HC = (HuffmanCode)malloc((n + 1)*sizeof(char *));
	char *cd = (char *)malloc(n*sizeof(char));            //������빤���ռ�
	cd[n - 1] = '\0';
	int start;                      //start������־�������cd����ı������ʼλ��
	int c, f;                      //f��¼˫���±꣬cʼ������һ��f
	for (int i = 1; i <= n; i++)   //�ӵ�һ��Ҷ�ӵ���n����һ�����������
	{
		start = n - 1;     //��ʼλ����cd�����һ��λ��
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{
			if (HT[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		HC[i] = (char *)malloc((n - start)*sizeof(char));      //����i��Ҷ�ӵı������洢�ռ�
		strcpy(HC[i], &cd[start]);
	}
	free(cd);     //�ͷŹ����ռ�
}

void HuffmanDecoding(HuffmanTree HT, int n, char *content)    //���ݹ�������HT����
{
	printf("		��������Ҫ���ݵ�ǰ�����������н�ѹ���Ķ��������ļ� ��");
	char source[100];
	gets_s(source);
	postion3:printf("		�������ѹ�����ĸ��ļ� ��");
	char des[100];
	gets_s(des);
	FILE *fp1;           //fp1ָ��Դ�ļ�
	FILE *fp2;           //fp1ָ��Ŀ���ļ�
	if ((fp1 = fopen(source, "rt")) == NULL)
	{//������
		printf("���ܴ���ָ�����ļ����������Ƿ���������\n");
		goto postion3;
	}
	if ((fp2 = fopen(des, "wt+")) == NULL)
	{//������
		printf("���ܴ���ָ�����ļ����������Ƿ���������\n");
		goto postion3;
	}
	char p;          //��ʱ����ļ����ÿһ���ַ�
	p = fgetc(fp1);
	int f = 2 * n - 1;      //���ڵ�λ��      
	while (p != EOF)
	{
		while (HT[f].lchild != 0 && HT[f].rchild != 0)   //��û�е�Ҷ��
		{
			if (p == '0')            //0��������
				f = HT[f].lchild;
			else if (p == '1')
				f = HT[f].rchild;
			else
			{
				printf("���ܶ�������Ķ��������ļ���ѹ�� �� \n");
				return;
			}
			p = fgetc(fp1);
		}
		fputc(content[f], fp2);         //������ַ�д��Ŀ���ļ�
		f = 2 * n - 1;
	}
	fclose(fp1);
	fclose(fp2);
	printf("		\n\n	��ѹ���ɹ��� \n\n\n");
}

