#include <stdio.h>
#include <stdlib.h>

int main() {
    int x=1, y=2, z=3;
    int *p1=NULL, *p2=NULL;
    p1 = &x;
    printf("x = %d ", x);
    printf("y = %d ", y);
    printf("z = %d ", z);
    printf("p1 = %d \n", *p1);
    p2 = &z;
    printf("x = %d ", x);
    printf("y = %d ", y);
    printf("z = %d ", z);
    printf("p1 = %d ", *p1);
    printf("p2 = %d \n", *p2);
    *p1 = (*p2)+2;
    printf("x = %d ", x);
    printf("y = %d ", y);
    printf("z = %d ", z);
    printf("p1 = %d ", *p1);
    printf("p2 = %d \n", *p2);
    p1 = p2;
    printf("x = %d ", x);
    printf("y = %d ", y);
    printf("z = %d ", z);
    printf("p1 = %d ", *p1);
    printf("p2 = %d \n", *p2);
    p2 = &y;
    printf("x = %d ", x);
    printf("y = %d ", y);
    printf("z = %d ", z);
    printf("p1 = %d ", *p1);
    printf("p2 = %d \n", *p2);
    *p1 = *p2;
    printf("x = %d ", x);
    printf("y = %d ", y);
    printf("z = %d ", z);
    printf("p1 = %d ", *p1);
    printf("p2 = %d \n", *p2);
    *p2 = (*p1)*(*p2);
    printf("x = %d ", x);
    printf("y = %d ", y);
    printf("z = %d ", z);
    printf("p1 = %d ", *p1);
    printf("p2 = %d \n", *p2);
    *p2 += *p1;
    printf("x = %d ", x);
    printf("y = %d ", y);
    printf("z = %d ", z);
    printf("p1 = %d ", *p1);
    printf("p2 = %d \n", *p2);
    x = y++;
    printf("x = %d ", x);
    printf("y = %d ", y);
    printf("z = %d ", z);
    printf("p1 = %d ", *p1);
    printf("p2 = %d \n", *p2);
    *p1 = (*p2)++;
    printf("x = %d ", x);
    printf("y = %d ", y);
    printf("z = %d ", z);
    printf("p1 = %d ", *p1);
    printf("p2 = %d \n", *p2);
    
    return 0; 
}