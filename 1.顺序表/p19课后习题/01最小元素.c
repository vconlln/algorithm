#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
#define MAX_SIZE 10
#define TO_STRING(x) #x

typedef struct SqList{
    ElementType data[MAX_SIZE];
    int length;
}SqList;

SqList * InitSqlist(){
    SqList * list = (SqList *)malloc(sizeof(SqList));
    list->length = 0;
}

//打印顺序表
void print_list(SqList *list){
  for(int i=0;i<list->length;i++){
    printf("%d ",list->data[i]);
    //printf("%d 内存：%d\n",list->data[i],&list->data[i]);
  }
  printf("\n");
}

//删除最小元素
int del_min(SqList *list){
    if(list->length == 0){
        exit(1);}
    int min_value = list->data[0];
    int index = 0;  //存储下标
    for(int i = 1; i < list->length ;i++){
        if(list->data[i] < min_value){   //*(int*)ptr解引用操作
        min_value = list->data[i];
        index = i;
        }
    }
    list->data[index] = list->data[list->length-1];
    list->length--;
    printf("顺序表最小的数字是 %d\n",min_value);
    return 1;
}

int main()
{
    SqList * list1= InitSqlist();
    int arr1[] = {10,4,3,8,9,2,5,6,7,20};
    for(int i =0; i < MAX_SIZE; i++){
      list1->data[i] = arr1[i];
      list1->length++;
    }
    print_list(list1);
    //printf("%d",list->length);
    del_min(list1);
    print_list(list1);
    return 0;
}