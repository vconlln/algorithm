#include "SequenQueue.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化队列
SequenQueue* InitQueue() {
    SequenQueue *sq = (SequenQueue *)malloc(sizeof(SequenQueue));
    sq->front = sq->rear = MAZSIZE - 1;
    return sq;
}

// 判断队列是否为空
int QueueEmpty(SequenQueue *sq) {
    return sq->front == sq->rear;
}

// 判断队列是否为满
int Queue_IsFull(SequenQueue *sq) {
    return sq->front == (sq->rear + 1) % MAZSIZE;
}

// 入队操作
int Queue_En(SequenQueue *sq, Datatype x) {
    if (Queue_IsFull(sq)) {
        printf("队列已满，无法入队\n");
        return 0; // 入队失败
    }
    sq->rear = (sq->rear + 1) % MAZSIZE;
    sq->data[sq->rear % MAZSIZE] = x;   // 尾指针后移
    return 1;
}

// 出队操作
int Queue_de(SequenQueue *sq) {
    if (QueueEmpty(sq)) {
        printf("队列为空，无法出队\n");
        return 0; // 出队失败
    }
    sq->front = (sq->front + 1) % MAZSIZE;
    Datatype e = sq->data[sq->front];
    return 1;
}

// 打印队列中的内容
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
