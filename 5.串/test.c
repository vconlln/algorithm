#include <string.h>
#include <stdio.h>
int main(){
    char *s = "0123456789012345678901234567890";
    char *p;
    p = strchr(s, '5');
    printf("%s\n", p);
}