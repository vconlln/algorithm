#include<stdio.h>

int fabo(int n){
    if(n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    int a = 0 , b = 1 , c = 1 ;
    for(int i = 2 ; i <= n ; i++){
        c = a + b ;
        a = b ;
        b = c ;
    }
    return b;
}

int main(){
    int n ;
    printf("Enter a number : ");
    scanf("%d",&n);
    printf("The %dth Fibonacci number is %d\n",n,fabo(n));
    return 0;
}