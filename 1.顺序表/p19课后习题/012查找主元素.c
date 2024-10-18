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

int Majority(SqList * list){
    int count = 1;  //计数器，记录选择的元素的个数
    ElementType num = list->data[0];  //起初选择顺序表第一个元素
    for(int i = 1; i < list->length; i++){
        if(list->data[i] == num){    //是选取的元素
            count++;    
        }else{  //不是选取的元素
            if(count > 0){
                count--;    //有元素，则计数器减一
            }else{  //更换计数元素
                num = list->data[i];
                count = 1;
            }
        }
    }
    
    if(count > 0){  //计算主元素个数
        count = 0;
        for(int i=0; i<list->length; i++){
            if(list->data[i] == num){
                count++;
            }
        }
    }
    if(count > (list->length / 2)){     //确定是主元素
        printf("主元素是：%d 有 %d 个\n",num,count);
        return num;
    }else{
        printf("该顺序表无主元素");
        return -1;
    }
}

int main(){
    int arr1[] = {1,2,2,3,4,2,2,2,5,6,2,2,2,7,2,2,2,8};
    SqList * list1 = InitList();

    for(int i= 0;i<sizeof(arr1)/sizeof(arr1[0]); i++){
        list1->data[i] = arr1[i];
        list1->length++;
    }
    print_list(list1);
    //printf("%d\n",list1->length);
    Majority(list1);
}