#include <stdio.h>
#include <stdlib.h>
#include "HuffmanTree.h"
#include "Queue.h"
#include "fun.h"

void HuffmanImformation(int n,double *w,char *content,HuffmanCode HC)
{
	system("cls");           //����
	printf("\n\n                             << ==================������������������=============== >>  \n\n\n");
	printf("		�ַ�			Ȩֵ				����������		\n");
	for (int i = 1; i <= n; i++)
	{
		if (content[i]=='\n')
			printf("		�س�		", content[i]);
		else if(content[i]==' ')
			printf("		�ո�		", content[i]);
		else if (content[i] == '	')
			printf("		�Ʊ�		", content[i]);
		else
			printf("		%c		", content[i]);
		printf("	%lf		", w[i]);
		printf("	%s		\n", HC[i]);
	}
	puts("\n\n\n");
}

void PrintTree(int pos, HuffmanTree HT)
{//��ӡ��������HT
	system("cls");           //����
	printf("\n\n                             << ==================������������������=============== >>  \n\n\n");
	printf("\n\n                             << ===================�����������³�����================ >>  \n\n");
	printf("\n\n           0����ʵ�ʲ����ڵ�Ҷ��������ֵ����Ȩ�أ�������Ļ���ޣ���ʱ��֧��̫��Ĺ���������ʾ  \n\n");
	int e;            //��ʱ���ճ����е�Ԫ��
	int level=1;
	int level1=level;
	LinkQueue Q;             //������������
	InitQueue(Q);           //��ʼ������Q
	EnQueue(Q, pos,1);          //������������λ�������
	while (!QueueEmpty(Q))    //���зǿ�
	{
		DeQueue(Q, e,level);    //��ͷԪ�س�����
		if (e == 0)
		{
			if (level == level1)
				printf("	0");
			else
				printf("\n	0");
			level1 = level;
			continue;
		}

		else if (level == level1)
		{
			printf("	%.3f", HT[e].weight);
		}
		else
		{
			printf("\n	%.3f", HT[e].weight);
		}
		level1 = level;
		EnQueue(Q, HT[e].lchild, level + 1);
		EnQueue(Q, HT[e].rchild, level + 1);
	}
	puts("\n\n\n\n");
}

void CompressTxt(int n, double *w, char *content, HuffmanCode HC)
{
	system("cls");           //����
	postion4:printf("\n\n                             << ==================������������������=============== >>  \n\n\n");
	postion2:printf("		��������Ҫ���ݵ�ǰ������������ѹ�����ļ� ��");
	char source[100];
	gets_s(source);
	printf("		������ѹ�����ĸ��ļ� ��");
	char des[100];
	gets_s(des);
	FILE *fp1;           //fp1ָ��Դ�ļ�
	FILE *fp2;           //fp1ָ��Ŀ���ļ�
	if ((fp1 = fopen(source, "rt")) == NULL)
	{//������
		printf("���ܴ���ָ����Դ�ļ������������롣\n");
		goto postion2;
	}
	if ((fp2 = fopen(des, "wt+")) == NULL)
	{//������
		printf("���ܴ���ָ����Դ�ļ������������롣\n");
		goto postion2;
	}
	char p;          //��ʱ����ļ����ÿһ���ַ�
	p = fgetc(fp1);
	int pos;              //���ڶ�λ
	while (p != EOF)
	{//ѭ����ȡ�ļ�ÿһ���ַ�ֱ�������ļ���ֹ��EOF
		pos = search(p, content, n);       //��n��Ҷ�����ҵ�p�ַ�
		if (pos == 0)
		{//���ַ���û����֮��Ӧ�Ĺ���������
			printf("ָ��ѹ���ļ��е�ǰ����������֧�ֵ��ַ�,������ѡ��һ��֧�ֵ��ļ��� \n");
			goto postion4;
		}
		fputs(HC[pos], fp2);       //��Ŀ���ļ�д���������
		p = fgetc(fp1);         //���Ŷ�ȡ��һ���ַ�
	}
	fclose(fp1);                        //�ر��ļ�
	fclose(fp2);
	printf("			\n�ļ�ѹ����� �� \n\n\n");
}