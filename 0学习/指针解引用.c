#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num; // ptr 指向 num 的地址

    //在这里，int* 表示一个指向 int 类型数据的指针。将 ptr 转换为 int* 意味着告诉编译器，原本 ptr 指向的数据类型是 int。
    // 这是一个解引用操作。在类型转换之后，ptr 现在是一个指向 int 类型数据的指针。使用解引用操作符 * 会取出指针所指向的内存地址中的值。
    int value = *(int*)ptr; //首先将 ptr 视为一个指向 int 类型数据的指针，然后解引用这个指针以获取它所指向的 int 类型的值。
    printf("The value of num is: %d\n", value); // 输出: The value of num is: 10

    return 0;
}
