#include "HuffmanTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Select(HuffmanTree HF, int i, int &s1, int &s2)    //从HF数组的第一号结点到第i号结点中选出parent为0，且weight最小的两个结点的下标，记录在s1,s2中
{
	double min1 = 100;           //min1存放最小权重，初始值给一个大于1的值
	double min2 = 99;            //min2存放次小权重
	int minnum1 = 1;             //临时存放最小下标
	int minnum2 = 2;             //临时存放次小下标
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
	/*double min = 100;           //min存放最小权重，初始值给一个大于1的值
	int minnum=1;             //临时存放最小下标
	for (int j = 1; j <= i; j++)         //找出第一个权值最小的结点
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
	for (int j = 1; j <= i; j++)          //找出第二个权值最小的结点
	{
	if (HF[j].parent == 0 && HF[j].weight < min&&j != s1)
	{
	min = HF[j].weight;
	minnum = j;
	}
	}
	s2 = minnum;*/
}
int search(char p, char *content, int ptr)                   //在content数组1号到ptr位置里面找是否有字符p，无则返回0，有则返回位置
{
	for (int i = 1; i <= ptr; i++)
	{
		if (content[i] == p)
			return i;
	}
	return 0;
}
void count(double *&w, int &n, char *&content)                         //统计指定文本各个字符出现的概率,字符和概率分别按顺序存在数组w和content中
{
	w = (double *)malloc(70 * sizeof(double));              //给w，content分配存储空间,0号位置不用，70足够
	for (int i = 1; i < 70; i++)  //初始化
		w[i] = 0;
	content = (char *)malloc(70 * sizeof(char));

	int ptr = 1;                               //标记content末端下标
	char p;                                   //临时存放每一个字符
	int total = 0;                        //统计总共输入多少个字符
	int pos;                             //存放重复字符插入到哪一个位置
	char FileName[100];                   //存放文件名            
	postion1:printf(" 请输入你要读取字符建立哈夫曼树的txt文件 ： ");
	gets_s(FileName);
	FILE *fp;           //fp为文件指针
	if ((fp = fopen(FileName, "r")) == NULL)
	{//错误处理
		printf(" 不能打开你指定的文件，请重新输入!\n\n");
		goto postion1;                   //重新输入直到用户输入正确的路径
	}
	p = fgetc(fp);
	if (p < -1 || p>127)
	{
		printf("含有中文字符，暂不支持中文！请重新选择文件 \n");
		goto postion1;
	}
	while (p != EOF)
	{//循环读取文件每一个字符直到遇到文件终止符EOF
		++total;      //字符总数加1
		if (search(p, content, ptr) == 0)
		{//在当前content已经存储的字符中没有p（p是一个新的字符)
			content[ptr] = p;      //在content末端插入p
			w[ptr] = 1;
			++ptr;            //末端位置后移
		}
		else
		{//是一个之前已经读取的字符
			pos = search(p, content, ptr);   //找到p字符的位置pos
			++w[pos];
		}
		p = fgetc(fp);       //接着往后读取
		if (p < -1 || p>127)
		{
			printf(" 含有中文字符，暂不支持中文！请重新选择文件 \n");
			goto postion1;
		}
	}
	for (int i = 1; i < ptr; i++)          //数量转化为概率
		w[i] = w[i] / total;
	n = ptr - 1;                       //叶子数
	fclose(fp);                        //关闭文件
}