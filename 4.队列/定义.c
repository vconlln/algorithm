#include<stdio.h>
#include<stdlib.h>

#define MAZSIZE 4
typedef int Datatype;

typedef struct {
    Datatype data[MAZSIZE];
    int front,rear,tar; //front是队头指针,tar = 1为空， = 0为满
}SequenQueue;

SequenQueue * InitQueue(){
    SequenQueue *sq = (SequenQueue *)malloc(sizeof(SequenQueue));
    sq->front = sq->rear = -1;
    return sq;
}

int QueueEmpty(SequenQueue *sq){
    return sq->front == sq->rear;
}

int Queue_IsFull(SequenQueue *sq){
    return sq->rear == MAZSIZE - 1;
}

int Queue_En(SequenQueue *sq, Datatype x){
    if(Queue_IsFull(sq)){
        printf("队列已满，无法入队\n");
        return 0; // 入队失败
    }
    sq->data[++sq->rear] = x;   //尾指针后移
    return 1;
}

int Queue_de(SequenQueue *sq){
    if(QueueEmpty(sq)){
        printf("队列为空，无法出队\n");
        return 0; // 出队失败
    }
    Datatype e = sq->data[sq->front];
    sq->front = sq->front+1;
    return 1;
}

void show_print(SequenQueue * sq){
    if (QueueEmpty(sq)) {
        printf("队列为空\n");
    } else {
        printf("队列中的元素: ");
        for (int i = sq->front + 1; i <= sq->rear; i++) {
            printf("%d->", sq->data[i]);
        }
        printf("\n");
    }
}


int main(){
    SequenQueue * sq = InitQueue();
    Queue_En(sq,2);
    Queue_En(sq,3);
    Queue_En(sq,4);
    Queue_En(sq,5);

    Queue_de(sq);   //先进先出
    Queue_En(sq,2);     //假溢出
    show_print(sq);
}