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
    sq->front = sq->rear = MAZSIZE - 1;
    return sq;
}

int QueueEmpty(SequenQueue *sq){
    return sq->front == sq->rear;
}

int Queue_IsFull(SequenQueue *sq){
    return sq->front == (sq->rear + 1) % MAZSIZE;
}

int Queue_En(SequenQueue *sq, Datatype x){
    if(Queue_IsFull(sq)){
        printf("队列已满，无法入队\n");
        return 0; // 入队失败
    }
    sq->rear = (sq->rear+1) % MAZSIZE;
    sq->data[sq->rear % MAZSIZE] = x;   //尾指针后移
    return 1;
}

int Queue_de(SequenQueue *sq){
    if(QueueEmpty(sq)){
        printf("队列为空，无法出队\n");
        return 0; // 出队失败
    }
    sq->front = (sq->front+1) % MAZSIZE;
    Datatype e = sq->data[sq->front];
    return 1;
}

void show_print(SequenQueue *sq) {
    if (QueueEmpty(sq)) {
        printf("队列为空\n");
    } else {
        printf("队列中的元素: ");
        int i = (sq->front + 1) % MAZSIZE;
        while (i != (sq->rear + 1) % MAZSIZE) {
            printf("%d->", sq->data[i]);
            i = (i + 1) % MAZSIZE;
        }
        printf("\n");
    }
}



int main(){
    SequenQueue * sq = InitQueue();
    Queue_En(sq,2);
    Queue_En(sq,3);
    Queue_En(sq,4);

    Queue_de(sq);   //先进先出
    Queue_En(sq,2);
    Queue_de(sq);   //先进先出
    Queue_En(sq,5);

    printf("%d\n",sq->front);
    printf("%d\n",sq->rear);
    show_print(sq);
}