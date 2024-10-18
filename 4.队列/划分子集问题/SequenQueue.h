#ifndef SEQUENQUEUE_H
#define SEQUENQUEUE_H

#define MAZSIZE 4
typedef int Datatype;

typedef struct {
    Datatype data[MAZSIZE];
    int front, rear; // 队头指针和队尾指针
} SequenQueue;

// 函数声明
SequenQueue* InitQueue();                 // 初始化队列
int QueueEmpty(SequenQueue *sq);          // 判断队列是否为空
int Queue_IsFull(SequenQueue *sq);        // 判断队列是否为满
int Queue_En(SequenQueue *sq, Datatype x); // 入队
int Queue_de(SequenQueue *sq);            // 出队
void show_print(SequenQueue *sq);         // 打印队列内容

#endif /* SEQUENQUEUE_H */
