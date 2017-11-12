#pragma once
//声明功能函数

#ifndef FUN
#define FUN

void Select(HuffmanTree HF, int i, int &s1, int &s2);    //在第一个结点到第i个结点中选出parent为0，且weight最小的两个节点，下标为s1,s2
int search(char p, char *content, int ptr);             //搜索content数组1号到ptr号是否有字符p，无返回0，有返回下标
void count(double *&w, int &n, char *&content);         //统计文本的所有字符的概率

#endif // !FUN
