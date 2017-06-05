#include<stdio.h>
#include<cs50.h>

int main()
{
    printf("Enter Minutes:");
    int minute=get_int();
    printf("Minutes:%d \n",minute);
    printf("Bottols:%d\n",minute*12);
    return 0;
}
