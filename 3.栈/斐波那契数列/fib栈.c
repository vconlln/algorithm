#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20 //定义数组的最大长度
typedef int ElementType; //定义结构类型

// 定义栈结构体
typedef struct Stack {
    ElementType data[MAXSIZE];  //定义ElementType类型的数组
    int top;  //定义栈顶索引
} Stack;

// 初始化栈
Stack* InitStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

// 判断栈是否为满栈
int isFull(Stack* s) {
    return s->top == MAXSIZE - 1;  // 修正：满栈时索引应为 MAXSIZE-1
}

// 判断栈是否为空栈
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 入栈操作
int push(Stack* s, ElementType value) {
    if (isFull(s)) { //判断栈是否为满栈
        printf("栈已满，不能再入栈\n");
        return -1;
    }
    //栈顶指针+1，并将值存入栈顶
    s->data[++s->top] = value;
    return 0;
}

// 出栈操作
ElementType pop(Stack* s) {
    if (isEmpty(s)) {  //判断栈是否为空栈
        printf("栈为空，无法出栈\n");
        return -1;
    }
    // 返回出栈元素，栈顶指针自减
    return s->data[s->top--];
}

// 使用栈计算斐波那契数列的第 n 项
int FibStack(int n) {
    Stack* s = InitStack();  // 初始化栈
    int result = 0;   // 第 0 个斐波那契数是 0

    push(s, n);  // 将初始的 n 压入栈

    while (!isEmpty(s)) {
        int value = pop(s);  // 弹出栈顶元素

        // 处理斐波那契数列的基础条件
        if (value == 1 || value == 2) {
            result += 1;
        } else {
            push(s, value - 1);  // 压入 F(n-1)
            push(s, value - 2);  // 压入 F(n-2)
        }
    }
    // 释放栈的内存
    free(s);
    return result;
}

int main() {
    int fib = FibStack(5);
    printf("%d\n", fib);  // 输出第 5 个斐波那契数
    return 0;
}
