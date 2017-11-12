#pragma once
//主窗口的几种选项对应的函数

#ifndef CASE
#define CASE

extern void HuffmanImformation(int n, double *w, char *content, HuffmanCode HC);       //显示哈夫曼树详细信息
extern void PrintTree(int pos, HuffmanTree HT);                                        //打印哈夫曼树的大致样子
extern void CompressTxt(int n, double *w, char *content, HuffmanCode HC);              //压缩文件

#endif // !CASE

