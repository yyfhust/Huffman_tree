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
		printf("您指定的文件是一个空文件 :");
		return;
	}
	if (n == 1)
	{
		printf("您指定的文件只有一种字符。");
		return;
	}
	int m = 2 * n - 1;             //m为总结点数
	int i, j;                     //计数变量
	int s1, s2;
	HT = (HuffmanTree)malloc((m + 1)*sizeof(HTNode));    //动态分配m+1单位数组存放m个节点，0号下标不使用
	HuffmanTree p = HT;   //p指向结点，操作指针
	p++;            //0号不用
	w++;
	for (i = 1; i <= n; i++, p++, ++w)    //给1-n号结点赋初始值，权重分别对应w的第一号到第n号
		*p = { *w,0,0,0 };
	for (; i <= m; i++, p++)           //剩下非叶子结点全部权重赋值为0
		*p = { 0,0,0,0 };
	for (i = n + 1; i <= m; i++)                          //开始构造哈弗曼树
	{
		Select(HT, i - 1, s1, s2);//每一次在第一个结点到第i-1个结点中选出parent为0，且weight最小的两个节点，下标为s1,s2
		HT[s1].parent = i;             //s1,s2号元素双亲为i号结点
		HT[s2].parent = i;
		HT[i].lchild = s1;             //i号元素左右孩子为s1号和s2号结点
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;  //i号结点权重为s1,s2权重之和
	}
	printf("\n 哈夫曼树创建成功  。 \n\n\n");
	return;
}

void HuffmanCoding(HuffmanTree HT, HuffmanCode &HC, int n)
{//从叶子结点到根结点逆向求n个叶子的哈弗曼树HT的哈夫曼编码，n个叶子的编码存在HC[1]-HC[n]指向的字符串中
	HC = (HuffmanCode)malloc((n + 1)*sizeof(char *));
	char *cd = (char *)malloc(n*sizeof(char));            //分配编码工作空间
	cd[n - 1] = '\0';
	int start;                      //start用来标志最后存放在cd里面的编码的起始位置
	int c, f;                      //f记录双亲下标，c始终是上一个f
	for (int i = 1; i <= n; i++)   //从第一个叶子到第n个逐一求哈弗曼编码
	{
		start = n - 1;     //初始位置在cd的最后一个位置
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{
			if (HT[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		HC[i] = (char *)malloc((n - start)*sizeof(char));      //给第i个叶子的编码分配存储空间
		strcpy(HC[i], &cd[start]);
	}
	free(cd);     //释放工作空间
}

void HuffmanDecoding(HuffmanTree HT, int n, char *content)    //根据哈弗曼树HT解码
{
	printf("		请输入你要根据当前哈夫曼树进行解压缩的二进制码文件 ：");
	char source[100];
	gets_s(source);
	postion3:printf("		请输入解压缩到哪个文件 ：");
	char des[100];
	gets_s(des);
	FILE *fp1;           //fp1指向源文件
	FILE *fp2;           //fp1指向目标文件
	if ((fp1 = fopen(source, "rt")) == NULL)
	{//错误处理
		printf("不能打开你指定的文件，请检查你是否输入有误。\n");
		goto postion3;
	}
	if ((fp2 = fopen(des, "wt+")) == NULL)
	{//错误处理
		printf("不能打开你指定的文件，请检查你是否输入有误。\n");
		goto postion3;
	}
	char p;          //临时存放文件里的每一个字符
	p = fgetc(fp1);
	int f = 2 * n - 1;      //根节点位置      
	while (p != EOF)
	{
		while (HT[f].lchild != 0 && HT[f].rchild != 0)   //还没有到叶子
		{
			if (p == '0')            //0则找左孩子
				f = HT[f].lchild;
			else if (p == '1')
				f = HT[f].rchild;
			else
			{
				printf("不能对你给定的二进制码文件解压缩 。 \n");
				return;
			}
			p = fgetc(fp1);
		}
		fputc(content[f], fp2);         //解码的字符写入目标文件
		f = 2 * n - 1;
	}
	fclose(fp1);
	fclose(fp2);
	printf("		\n\n	解压缩成功！ \n\n\n");
}

