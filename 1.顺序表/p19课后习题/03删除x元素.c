#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 15 //定义最大长度
typedef int ElementType;

typedef struct {
  ElementType data[MAX_SIZE]; //用静态数组表示顺序表
  int length; //定义数组长度 
} SqList; //结构体名字

//初始化顺序表
SqList * InitList(){
  //你的指针是什么类型的，你申请的malloc空间就要返回什么类型的
  //malloc返回的是void* 
  //该函数返回一个指针指向已分配大小的内存如果请求失败则返回null
  SqList *list = (SqList *)malloc(sizeof(SqList)); 
  //此处返回结构体类型指针
  list->length = 0;
  return list;
}

//打印顺序表
void print_list(SqList *list){
  for(int i=0;i<list->length;i++){
    printf("%d ",list->data[i]);
    //printf("%d 内存：%d\n",list->data[i],&list->data[i]);
  }
  printf("\n");
}

//删除表中值为x的所有元素
void del_x(SqList* list, ElementType x){
  int same_num = 0;   //定义值为x的元素个数
  for(int i = 0; i < list->length; i++){  //遍历顺序表
    if(list->data[i] == x){   //如果为x
      same_num++;   // 加一
      list->data[i] = 0;  //并把这个值清除
    }else if(same_num != 0){    //如果遇到值为x的元素
      list->data[i-same_num] = list->data[i];   //如果有x，把后面的元素依次往前挪
      list->data[i] = 0;  //并把后面的元素清除
    } // 如果还没遇到x值，就继续遍历
  }
  list->length = list->length - same_num; //顺序表长度减去删除的x的个数
  printf("顺序表里面有 %d 个值为 %d 的元素，删除后的顺序表如下:\n",same_num,x);
  print_list(list);
}

int main(){
  SqList *list1 = InitList();
  int arr1[] = {1,1,1,3,4,2,5,6,7,2,2};
  for(int i =0; i < sizeof(arr1)/sizeof(arr1[0]); i++){
    list1->data[i] = arr1[i];
    list1->length++;
  }
  print_list(list1);
  del_x(list1,2);
  //print_list(list1);
  return 0;
}