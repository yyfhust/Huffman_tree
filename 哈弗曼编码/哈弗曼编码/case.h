#pragma once
//�����ڵļ���ѡ���Ӧ�ĺ���

#ifndef CASE
#define CASE

extern void HuffmanImformation(int n, double *w, char *content, HuffmanCode HC);       //��ʾ����������ϸ��Ϣ
extern void PrintTree(int pos, HuffmanTree HT);                                        //��ӡ���������Ĵ�������
extern void CompressTxt(int n, double *w, char *content, HuffmanCode HC);              //ѹ���ļ�

#endif // !CASE

