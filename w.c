#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int *pp = &b;
    int *p[3] = {&a, &b, &c};
    printf("%d\n", *(p+1)[0]);
    printf("%d\n", *p[1]);
    printf("%d\n", *p[2]);

    int **d = &pp;
    printf("%d\n", *d[0]); 
    return 0;
}