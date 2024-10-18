#include <stdio.h>
 
int main() {
    int a = 10;
    int *p1 = &a;
    int b;
    int *p2 = &b;
 
    // 通过指针赋值
    *p2 = *p1;
 
    printf("a 的值是: %d, 地址是: %p\n", a, &a);
    printf("b 的值是: %d, 地址是: %p\n", b, &b);
 
    return 0;
}