#include<stdio.h>
#include<stdlib.h>

void panduan(int *a,int b){
    *a = 99;
    b = 40;
}

int main(){
    int a = 10;
    int b = 20;
    int * p = &a;
    panduan(p,b);
    printf("目前%d\n", a);
    printf("目前%d", b);
}