#pragma once
//�������ܺ���

#ifndef FUN
#define FUN

void Select(HuffmanTree HF, int i, int &s1, int &s2);    //�ڵ�һ����㵽��i�������ѡ��parentΪ0����weight��С�������ڵ㣬�±�Ϊs1,s2
int search(char p, char *content, int ptr);             //����content����1�ŵ�ptr���Ƿ����ַ�p���޷���0���з����±�
void count(double *&w, int &n, char *&content);         //ͳ���ı��������ַ��ĸ���

#endif // !FUN
