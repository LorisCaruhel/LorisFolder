#include <stdio.h>
#include <stdlib.h>

int main() {
    int y = 10;
    int x = 30;
    int* ptr1 = &x;
    y = *ptr1;
    *ptr1 = 50;
    int* ptr2 = ptr1;

    return 0;
}