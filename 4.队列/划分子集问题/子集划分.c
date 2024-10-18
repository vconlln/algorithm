#include <stdio.h>
#include "SequenQueue.h"
#define n 9

void DivideIntoGroup(int R[][n], int cq[], int result[]){
    int front ,rear, group, pre, I, i;
    front = n-1;
    rear = n-1;
    int newr[n];  // 初始化 newr 数组

    for(i=0;i<n;i++){
        newr[i] = 0;    //全为0
        cq[i] = i+1;   // 初始化 cq 队列，为 1～9
    }

    group = 1;  //第一组
    pre = 0;    //前一个出队元素所在的组
    do {    
        //从 cq 队列中依次取出元素进行处理。
        front = (front + 1) % n;  //移动队列的头指针 front，让它指向队列的下一个元素（以循环方式，即队列尾部重新回到队首）。
        //I 表示矩阵 R 中的某一行（I - 1 表示行索引），该行的值将用于判断冲突情况。
        I = cq[front];     //从队列中取出当前元素 cq[front]，将其赋值给变量 I。
        //当前元素 I 是否小于上一个处理的元素 pre。用于判断是否需要进入一个新的分组。
        if (I < pre) {  //表示进入新的一组
        //pre 保存了前一个出队的元素，如果当前 I 比前一个元素小，意味着我们已经处理完当前组的所有元素，开始处理下一个分组，因此 group 自增，表示一个新的分组。
            group += 1;
            result[I - 1] = group;  //将当前元素 I 归为新的一组。
            
            // 将当前R的行复制到newr
            for (i = 0; i < n; i++) {
                newr[i] = R[I - 1][i];
            }
            //检查newr(第一行)中的元素与第(I-1)个元素是否冲突
            //也就是1是否与2冲突，如果发生冲突，需要将 I 放回队列末尾，以便后续处理。
            /*newr 中保存了当前分组中已经包含的元素的信息。如果 newr[I-1] != 0，
            说明该元素与之前的元素存在某种关系（冲突），需要跳过该元素并将其重新放回队列末尾*/
        } else if (newr[I - 1] != 0) {
            rear = (rear + 1) % n;  //移动尾指针，将其指向新的队尾。
            cq[rear] = I;   //将当前元素 I 插入到队尾。
        } else {    
            //没有冲突的元素，把第group组放入result
            result[I - 1] = group;
            //printf("第%d组的，%d行\n",group,I);
            //复制R的第I-1行到nerw中
            for (i = 0; i < n; i++) {
                newr[i] += R[I - 1][i];  // 累加更新newr

                //printf("%d ",newr[i]);
            }
            //printf("\n");
        }

        pre = I;   //将当前元素 I 赋值给 pre，用于下一次比较。
    } while (rear != front);    //直到空队列
}

int main() {
    // 将图片中的矩阵转化为二维数组 R
    int R[n][n] = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 1, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 0}
    };

    int cq[n];   // 队列数组
    int result[n]; // 结果数组

    DivideIntoGroup(R, cq, result);

    // 输出最终分组结果
    printf("Final group results:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
