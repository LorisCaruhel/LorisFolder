#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 100;
    int* pt = &x;

    *pt += 10;
    printf("%d\n", x);

    int* pt2 = (int*)malloc(sizeof(int));
    pt2 = &x;

    *pt2 += 10;
    printf("%d\n", x);

    return 0;
}