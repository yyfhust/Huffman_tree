
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

void InitQueue(LinkQueue &Q)
{//初始化一个空队列
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
	{
		printf("工作队列存储空间分配失败 . \n");
		exit(1);
	}
	Q.front->next = NULL;
}
void EnQueue(LinkQueue &Q, int e,int level)
{//插入元素e为新的队尾元素
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)
	{
		printf("工作队列空间分配失败 。");
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
	p = Q.front->next;        //将要删除的对头结点暂存给p
	e = p->data;                   //将要删除对头值赋给e
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