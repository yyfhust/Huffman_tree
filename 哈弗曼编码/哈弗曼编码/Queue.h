#pragma once
//队列结构定义以及相关操作定义
#ifndef QUEUE
#define QUEUE

typedef struct QNode        //结点结构
{
	int data;
	int level; 
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct   //队列的链表结构
{
	QueuePtr front, rear;   //对头和队尾指针
}LinkQueue;
void InitQueue(LinkQueue &Q);                      //初始化队列
void EnQueue(LinkQueue &Q, int e,int level);         //入队
void DeQueue(LinkQueue &Q, int &e,int &level);    //出队
bool QueueEmpty(LinkQueue Q);                   //队列是否为空

#endif // !QUEUE
