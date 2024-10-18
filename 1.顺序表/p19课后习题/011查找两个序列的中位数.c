#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 40
//#define max(a,b) ((a>b)?a:b)
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

int max(int a, int b) {
  if (a>b)
    return a;
  else
    return b;
}

//合并顺序表
int merge(SqList * list1, SqList * list2 , SqList * All_list){
    if(list1->length + list2->length > MAX_SIZE){
        printf("list1和list2相加长度超过顺序表长度\n");
        return 0;
    }
    int index1=0,index2=0,index_all=0;  // 各个顺序表的计数器
    while(index1 < list1->length && index2 < list2->length){
        if(list1->data[index1] <= list2->data[index2]){     //小的先放进来
            All_list->data[index_all++] = list1->data[index1++];    //放入后，计数器自+1
        }else{
            All_list->data[index_all++] = list2->data[index2++];
        }
    }
    while(index1 < list1->length){  //遍历完第一个顺序表
        All_list->data[index_all++] = list1->data[index1++];
    }
    while(index2 < list2->length){
        All_list->data[index_all++] = list2->data[index2++];
    }
    All_list->length = index_all;
    return 1;
}

//删除表中相同的元素，只留下一个
int del_same(SqList* list){
  if (list->length == 0){
    return 0;
  }
  int i,j;  //i是记录不同元素的个数，j是计数器用于遍历顺序表
  for(i = 0, j = 1; j < list->length; j++){  //遍历顺序表
    if(list->data[i] != list->data[j]){   //找到下一个与上一个值不同的元素，把i+1后，将那个不同的元素覆盖前面的元素
      list->data[++i] = list->data[j];  //把元素前移
    }
  }
  list->length = i+1;
  print_list(list);
  return 1;
}

ElementType Search_mid(SqList * A, SqList * B){
    if(A->length != B->length){return 0;}
    int low1 = 0, high1 = A->length - 1;
    int low2 = 0, high2 = B->length - 1;
    SqList * C = InitList();
    while(low1 != high1 || low2 != high2){
        int mid1 = (low1 + high1) / 2;
        int mid2 = (low2 + high2) / 2;
        int num = (low1 + high1) % 2;
        if(A->data[mid1] == B->data[mid2]){     //相等，则升序顺序表中位数即为两个序列拼起来的中位数
            printf("中位数是 %d\n",A->data[mid1]);
            printf("两个升序顺序表合并后是：\n");
            merge(A,B,C);
            del_same(C);
            return A->data[mid1];
        }
        if(A->data[mid1] < B->data[mid2]){   //如果A的小，舍弃A中较小的一半，舍弃B中较大的一半
            if(num == 0){   //如果是奇数
                low1 = mid1;    //舍弃A的前一半
                high2 = mid2;   //舍弃B的后一半
            }else{          //如果是偶数
                low1 = mid1 + 1;    // '/'为向下取整，并且 A[mid1] < B[mid2] ，所以A舍弃前面 mid1 + 1个元素，B的mid2不用舍弃
                high2 = mid2;
            }
        }else{
            if(num == 0){   //如果是奇数
                high1 = mid1;    //舍弃A的后一半
                low2 = mid2;   //舍弃B的前一半
            }else{          //如果是偶数
                high1 = mid1;    // A[mid1] > B[mid2] ，所以A舍弃前面 mid1 个元素，B 的第 mid2 各元素需要舍弃，所以mid2 + 1
                low2 = mid2 + 1;
            }
        }
    }
    printf("中位数是 %d\n",A->data[low1] < B->data[low2]? A->data[low1]:B->data[low2]);
    printf("两个升序顺序表合并后是：\n");
    merge(A,B,C);
    del_same(C);
    return A->data[low1] < B->data[low2]? A->data[low1]:B->data[low2];
}

int main(){
    int arr1[] = {1,2,3,4,5,6,7,8};
    int arr2[] = {2,3,5,6,7,8,9,10};
    int arr3[] = {4,6,7,8,9,10,11,12};

    SqList * list1 = InitList();
    SqList * list2 = InitList();
    SqList * list3 = InitList();
    for(int i= 0;i<sizeof(arr1)/sizeof(arr1[0]); i++){
        list1->data[i] = arr1[i];
        list1->length++;
    }
    for(int i= 0; i < sizeof(arr2)/sizeof(arr2[0]); i++){
        list2->data[i] = arr2[i];
        list2->length++;
    }

    for(int i= 0; i < sizeof(arr3)/sizeof(arr3[0]); i++){
        list3->data[i] = arr3[i];
        list3->length++;
    }
    print_list(list1);
    //printf("%d\n",list1->length);
    print_list(list2);
    print_list(list3);
    Search_mid(list1,list3);
}