#include <stdio.h>
#include <string.h>
#define MaxSize 50 

typedef struct
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book;
int book()
{
//book = {"C 语言", "RUNOOB", "编程语言", 123456};
    Book book;  /* 声明 books，类型为 Books */
    strcpy( book.title, "C Programming");
    strcpy( book.author, "Nuha Ali");
    strcpy( book.subject, "C Programming Tutorial");
    book.book_id = 6495407;

    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);
}

/* 
使用：typedef int ElemType;//定义ElemType为int类型
你想让它是什么类型自己用typedef重定义就行。
也可以用模板表示，类似template<class T>里面的T。*/
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
}SqList;

void main(){
    SqList test;
    strcpy( test.data, "C Programming");
    test.length = 5;
    printf("data: %s\n",test.data);
    
    printf("length: %d\n",MaxSize*sizeof(ElemType));
}