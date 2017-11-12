#pragma once
//���������ṹ�Ķ������ز�������

#ifndef HUFFMANTREE
#define HUFFMANTREE

typedef struct                //���Ķ���  ,HTNodeΪ������ͣ�HuffmanTreeΪָ��������ָ������
{
	double weight;           //Ȩ�أ����ʣ�
	unsigned int parent, lchild, rchild;   //˫�׺����Һ��ӵ��±�
}HTNode, *HuffmanTree;
typedef struct           //Ҷ�ӵ������е����Զ��壬����Ȩֵ�⣬���д�����ַ��Ͷ�������
{
	double weight;     //Ȩ��
	char data;         //������ַ�
	char *code;        //��code��ͷ���ַ�����ʾ��Ҷ�ӽ��Ķ�������
}Node;
typedef char ** HuffmanCode;                                         //��ά�ַ�ָ�����ͺ�����Huffmancode��ʾ
extern void HuffmanCoding(HuffmanTree HT, HuffmanCode &HC, int n);   //���������뺯��
extern void HuffmanDecoding(HuffmanTree HT, int n, char *content);   //����������
extern void CreatHuffman(HuffmanTree &HT, double *w, int n);          //����һ����������

#endif // !HUFFMANTREE





