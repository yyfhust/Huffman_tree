#include "HuffmanTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Select(HuffmanTree HF, int i, int &s1, int &s2)    //��HF����ĵ�һ�Ž�㵽��i�Ž����ѡ��parentΪ0����weight��С�����������±꣬��¼��s1,s2��
{
	double min1 = 100;           //min1�����СȨ�أ���ʼֵ��һ������1��ֵ
	double min2 = 99;            //min2��Ŵ�СȨ��
	int minnum1 = 1;             //��ʱ�����С�±�
	int minnum2 = 2;             //��ʱ��Ŵ�С�±�
	double temp_weight;
	int temp_num;
	for (int j = 1; j <= i; j++)
	{
		if (HF[j].parent == 0 && HF[j].weight < min2)
		{
			min2 = HF[j].weight;
			minnum2 = j;;
		}
		if (min2 < min1)
		{
			temp_weight = min1;
			min1 = min2;
			min2 = temp_weight;

			temp_num = minnum1;
			minnum1 = minnum2;
			minnum2 = temp_num;
		}
	}
	s1 = minnum1;
	s2 = minnum2;
	/*double min = 100;           //min�����СȨ�أ���ʼֵ��һ������1��ֵ
	int minnum=1;             //��ʱ�����С�±�
	for (int j = 1; j <= i; j++)         //�ҳ���һ��Ȩֵ��С�Ľ��
	{
	if (HF[j].parent == 0 && HF[j].weight < min)
	{
	min = HF[j].weight;
	minnum = j;;
	}
	}
	s1 = minnum;
	min = 100;
	minnum = 2;
	for (int j = 1; j <= i; j++)          //�ҳ��ڶ���Ȩֵ��С�Ľ��
	{
	if (HF[j].parent == 0 && HF[j].weight < min&&j != s1)
	{
	min = HF[j].weight;
	minnum = j;
	}
	}
	s2 = minnum;*/
}
int search(char p, char *content, int ptr)                   //��content����1�ŵ�ptrλ���������Ƿ����ַ�p�����򷵻�0�����򷵻�λ��
{
	for (int i = 1; i <= ptr; i++)
	{
		if (content[i] == p)
			return i;
	}
	return 0;
}
void count(double *&w, int &n, char *&content)                         //ͳ��ָ���ı������ַ����ֵĸ���,�ַ��͸��ʷֱ�˳���������w��content��
{
	w = (double *)malloc(70 * sizeof(double));              //��w��content����洢�ռ�,0��λ�ò��ã�70�㹻
	for (int i = 1; i < 70; i++)  //��ʼ��
		w[i] = 0;
	content = (char *)malloc(70 * sizeof(char));

	int ptr = 1;                               //���contentĩ���±�
	char p;                                   //��ʱ���ÿһ���ַ�
	int total = 0;                        //ͳ���ܹ�������ٸ��ַ�
	int pos;                             //����ظ��ַ����뵽��һ��λ��
	char FileName[100];                   //����ļ���            
	postion1:printf(" ��������Ҫ��ȡ�ַ���������������txt�ļ� �� ");
	gets_s(FileName);
	FILE *fp;           //fpΪ�ļ�ָ��
	if ((fp = fopen(FileName, "r")) == NULL)
	{//������
		printf(" ���ܴ���ָ�����ļ�������������!\n\n");
		goto postion1;                   //��������ֱ���û�������ȷ��·��
	}
	p = fgetc(fp);
	if (p < -1 || p>127)
	{
		printf("���������ַ����ݲ�֧�����ģ�������ѡ���ļ� \n");
		goto postion1;
	}
	while (p != EOF)
	{//ѭ����ȡ�ļ�ÿһ���ַ�ֱ�������ļ���ֹ��EOF
		++total;      //�ַ�������1
		if (search(p, content, ptr) == 0)
		{//�ڵ�ǰcontent�Ѿ��洢���ַ���û��p��p��һ���µ��ַ�)
			content[ptr] = p;      //��contentĩ�˲���p
			w[ptr] = 1;
			++ptr;            //ĩ��λ�ú���
		}
		else
		{//��һ��֮ǰ�Ѿ���ȡ���ַ�
			pos = search(p, content, ptr);   //�ҵ�p�ַ���λ��pos
			++w[pos];
		}
		p = fgetc(fp);       //���������ȡ
		if (p < -1 || p>127)
		{
			printf(" ���������ַ����ݲ�֧�����ģ�������ѡ���ļ� \n");
			goto postion1;
		}
	}
	for (int i = 1; i < ptr; i++)          //����ת��Ϊ����
		w[i] = w[i] / total;
	n = ptr - 1;                       //Ҷ����
	fclose(fp);                        //�ر��ļ�
}