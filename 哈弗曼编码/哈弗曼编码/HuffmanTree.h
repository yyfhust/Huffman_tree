#pragma once
//哈夫曼树结构的定义和相关操作函数

#ifndef HUFFMANTREE
#define HUFFMANTREE

typedef struct                //结点的定义  ,HTNode为结点类型，HuffmanTree为指向此类结点的指针类型
{
	double weight;           //权重（概率）
	unsigned int parent, lchild, rchild;   //双亲和左右孩子的下标
}HTNode, *HuffmanTree;
typedef struct           //叶子单独具有的属性定义，除了权值外，还有代表的字符和二进制码
{
	double weight;     //权重
	char data;         //代表的字符
	char *code;        //以code开头的字符串表示该叶子结点的二进制码
}Node;
typedef char ** HuffmanCode;                                         //二维字符指针类型后面用Huffmancode表示
extern void HuffmanCoding(HuffmanTree HT, HuffmanCode &HC, int n);   //哈夫曼编码函数
extern void HuffmanDecoding(HuffmanTree HT, int n, char *content);   //哈夫曼解码
extern void CreatHuffman(HuffmanTree &HT, double *w, int n);          //创建一个哈夫曼树

#endif // !HUFFMANTREE





