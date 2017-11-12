
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

void InitQueue(LinkQueue &Q)
{//��ʼ��һ���ն���
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
	{
		printf("�������д洢�ռ����ʧ�� . \n");
		exit(1);
	}
	Q.front->next = NULL;
}
void EnQueue(LinkQueue &Q, int e,int level)
{//����Ԫ��eΪ�µĶ�βԪ��
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)
	{
		printf("�������пռ����ʧ�� ��");
		exit(1);
	}
	s->data = e;
	s->level = level;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}
void DeQueue(LinkQueue &Q, int &e,int &level)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return;
	p = Q.front->next;        //��Ҫɾ���Ķ�ͷ����ݴ��p
	e = p->data;                   //��Ҫɾ����ͷֵ����e
	level = p->level;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
}
bool QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}