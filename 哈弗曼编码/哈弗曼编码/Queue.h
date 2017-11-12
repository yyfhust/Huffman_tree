#pragma once
//���нṹ�����Լ���ز�������
#ifndef QUEUE
#define QUEUE

typedef struct QNode        //���ṹ
{
	int data;
	int level; 
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct   //���е�����ṹ
{
	QueuePtr front, rear;   //��ͷ�Ͷ�βָ��
}LinkQueue;
void InitQueue(LinkQueue &Q);                      //��ʼ������
void EnQueue(LinkQueue &Q, int e,int level);         //���
void DeQueue(LinkQueue &Q, int &e,int &level);    //����
bool QueueEmpty(LinkQueue Q);                   //�����Ƿ�Ϊ��

#endif // !QUEUE
