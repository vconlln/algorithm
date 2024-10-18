#include <stdio.h>
#include <malloc.h>

typedef int DataType;
typedef struct Node
{
    DataType data;
    struct Node *next;
} Node;

Node *Creat(int n){
    Node *rear = NULL, *s;
    int i;
    rear = (Node *)malloc(sizeof(Node));
    rear->data = 1;
    rear->next = rear;
    for (i = 2; i <= n; i++)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = i;
        s->next = rear->next; //将结点s插入尾结点rear的后面
        rear->next = s;
        rear = s; //指针rear指向当前最后一个结点
    }
    return rear;
}

void Joseph(Node *rear, int m)
{
    Node *pre = rear;
    Node *p = rear->next;
    int count = 1;
    printf("出环的顺序是：\n");

    while (p->next != p){
        if (count < m)
        {
            pre = pre->next; //工作指针pre 和 p后移
            p = p->next;
            count++;
        }
        else
        {
            printf("%d ", p->data); //输出
            pre->next = p->next;    //删除结点p
            free(p);                //释放结点p
            p = pre->next;          //保持p位于pre的next
            count = 1;              //将计数归1
        }
        
    }
    printf("\n");
    printf("幸存者是 %d\n", p->data);
    free(p); //不要忘记释放最后一个结点
}

int cir(int n , int m){
    int result = 0; // 对应 f(1, m)
    for (int i = 2; i <= n; i++) {
        result = (result + m) % i;
    }
    return result;
}

int main()
{
    int n, m;
    Node *rear = NULL;
    n = 11;
    printf("约瑟夫环的长度: %d\n",n);
   
    m = 3;
    rear = Creat(n);
    Joseph(rear, m);
    int survivor = cir(n, m);
    printf("最后一个幸存者的位置是: %d\n", survivor + 1);
    return 0;
}

