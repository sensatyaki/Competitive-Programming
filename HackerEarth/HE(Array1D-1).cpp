#include "stdio.h"
#include "iostream"
using namespace std;
struct Queue
{
	int rear,front;
	int capacity;
	int *array;
};
struct Queue *CreateQueue(int size)
{
	struct Queue *Q=(struct Queue*)malloc(sizeof(struct Queue));
	Q->capacity=size;
	Q->front=Q->rear=-1;
	Q->array=(int*)malloc(Q->capacity*sizeof(int));
	if(!Q->array)
		return NULL;
	return Q;

}
void EnQueue(struct Queue *Q,int data)
{
	Q->rear=(Q->rear+1)%Q->capacity;
	Q->array[Q->rear]=data;
	if(Q->front==-1)
		Q->front=Q->rear;
}
int IsEmpty(struct Queue *Q)
{
	return (Q->front==-1);
}
int isFull(struct Queue *Q)
{
	return (((Q->rear+1)%Q->capacity)==Q->front);
}
int DeQueue(struct Queue *Q)
{
	int data=0;
	data=Q->array[Q->front];
	if(Q->front==Q->rear)
		Q->front=Q->rear=-1;
	else
		Q->front=(Q->front+1)%Q->capacity;
	return data;
	
}
int main(int argc, char const *argv[])
{
	int N;
	int arr[101];
	cin>>N;
	struct Queue *Q=CreateQueue(N);
	for(int i=0;i<N;++i)
	{
		int data;
		cin>>data;
		EnQueue(Q,data);
	}
	for(int i=0;i<N;++i)
	{
		cin>>arr[i];
	}
	int count,i,time;
	count=i=time=0;
	while(count!=N)
	{
		int Pid=DeQueue(Q);
		while(Pid!=arr[i])
		{
			EnQueue(Q,Pid);
			Pid=DeQueue(Q);
			++time;
		}
		++count;
		++i;
		++time;



	}
	cout<<time;
	return 0;
}
