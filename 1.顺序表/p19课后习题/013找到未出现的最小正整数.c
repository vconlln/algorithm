#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 40
#define max(a,b) ((a>b)?a:b)
typedef int ElementType;

typedef struct SqList{
    ElementType data[MAX_SIZE];
    int length;
}SqList;

SqList * InitList(){
    SqList * list = (SqList*)malloc(sizeof(SqList));
    list->length = 0;
}

void print_list(SqList * list){
    for(int i = 0;i < list->length; i++){
        printf("%d,",list->data[i]);
    }
    printf("\n");
}

int Find_Miss_Min(SqList * list){
    SqList * count = InitList();
    int i;
    for(i =0 ; i < list->length; i++){  //初始化计数器数组,相当于真值表
        count->data[i] = 0;
        count->length++;
    }
    //如果出现了小于length的元素，则对应位置上的元素变为1
    for(i = 0; i < list->length; i++){
        if(list->data[i] > 0 && list->data[i] <= list->length){
            count->data[list->data[i] - 1] = 1;
        }
    }
    //print_list(count);
    //遍历计数器数组，如果有0,则为最小正整数，输出此时的i
    for(i =0 ; i < list->length; i++){
        if(count->data[i] == 0){
            break;
        }
    }
    printf("未出现的最小正整数是 %d\n",i + 1);
    return i + 1;
}

int main(){
    int arr1[] = {1,2,3,4,5,-2};
    SqList * list1 = InitList();

    for(int i= 0;i<sizeof(arr1)/sizeof(arr1[0]); i++){
        list1->data[i] = arr1[i];
        list1->length++;
    }
    print_list(list1);
    //printf("%d\n",list1->length);
    Find_Miss_Min(list1);
}