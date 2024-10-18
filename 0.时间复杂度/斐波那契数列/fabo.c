#include<stdio.h>

int fabo(int n){
    if(n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fabo(n-1) + fabo(n-2);
}
int main(){
    int n ;
    printf("Enter the position of the Fibonacci number: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is: %d", n, fabo(n));
    return 0;
}