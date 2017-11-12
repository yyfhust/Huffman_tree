#include <stdio.h>
#include <stdlib.h>
#include "HuffmanTree.h"
#include "Queue.h"
#include "fun.h"

void HuffmanImformation(int n,double *w,char *content,HuffmanCode HC)
{
	system("cls");           //清屏
	printf("\n\n                             << ==================哈夫曼编码与解码程序=============== >>  \n\n\n");
	printf("		字符			权值				哈夫曼编码		\n");
	for (int i = 1; i <= n; i++)
	{
		if (content[i]=='\n')
			printf("		回车		", content[i]);
		else if(content[i]==' ')
			printf("		空格		", content[i]);
		else if (content[i] == '	')
			printf("		制表		", content[i]);
		else
			printf("		%c		", content[i]);
		printf("	%lf		", w[i]);
		printf("	%s		\n", HC[i]);
	}
	puts("\n\n\n");
}

void PrintTree(int pos, HuffmanTree HT)
{//打印哈夫曼树HT
	system("cls");           //清屏
	printf("\n\n                             << ==================哈夫曼编码与解码程序=============== >>  \n\n\n");
	printf("\n\n                             << ===================哈夫曼树大致长这样================ >>  \n\n");
	printf("\n\n           0代表实际不存在的叶子其余数值代表权重，由于屏幕有限，暂时不支持太大的哈夫曼树显示  \n\n");
	int e;            //临时接收出队列的元素
	int level=1;
	int level1=level;
	LinkQueue Q;             //建立工作队列
	InitQueue(Q);           //初始化队列Q
	EnQueue(Q, pos,1);          //哈夫曼树树根位置入队列
	while (!QueueEmpty(Q))    //队列非空
	{
		DeQueue(Q, e,level);    //对头元素出队列
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
	system("cls");           //清屏
	postion4:printf("\n\n                             << ==================哈夫曼编码与解码程序=============== >>  \n\n\n");
	postion2:printf("		请输入你要根据当前哈夫曼树进行压缩的文件 ：");
	char source[100];
	gets_s(source);
	printf("		请输入压缩到哪个文件 ：");
	char des[100];
	gets_s(des);
	FILE *fp1;           //fp1指向源文件
	FILE *fp2;           //fp1指向目标文件
	if ((fp1 = fopen(source, "rt")) == NULL)
	{//错误处理
		printf("不能打开你指定的源文件，请重新输入。\n");
		goto postion2;
	}
	if ((fp2 = fopen(des, "wt+")) == NULL)
	{//错误处理
		printf("不能打开你指定的源文件，请重新输入。\n");
		goto postion2;
	}
	char p;          //临时存放文件里的每一个字符
	p = fgetc(fp1);
	int pos;              //用于定位
	while (p != EOF)
	{//循环读取文件每一个字符直到遇到文件终止符EOF
		pos = search(p, content, n);       //从n个叶子中找到p字符
		if (pos == 0)
		{//该字符并没有与之对应的哈夫曼编码
			printf("指定压缩文件有当前哈夫曼树不支持的字符,请重新选择一个支持的文件： \n");
			goto postion4;
		}
		fputs(HC[pos], fp2);       //向目标文件写入二进制码
		p = fgetc(fp1);         //接着读取下一个字符
	}
	fclose(fp1);                        //关闭文件
	fclose(fp2);
	printf("			\n文件压缩完成 。 \n\n\n");
}