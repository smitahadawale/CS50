#include<stdio.h>
#include<cs50.h>
int main()
{
    float chnge;
    int count=0;
    float quarter=0.25;
    float dime=0.10;
    float nickel=0.05;
   float penny=0.010;
    printf("O hai! How much change is owed?");
    chnge=get_float();
    
    while(chnge<0)
        { 
            printf("How much change is owed?\n");
            chnge=get_float(); 
             
        }
    while(chnge>=quarter)
    {
        chnge=chnge-quarter;
        count++;
    }
     while(chnge>=dime)
    {
        chnge=chnge-dime;
        count++;
    }
     while(chnge>=nickel)
    {
        chnge=chnge-nickel;
        count++;
    }
     while(chnge>=penny || chnge>=0)
    {
        
        chnge=chnge-penny;
        count++;
    }
    
    printf("\n%d\n",count);
    return 0;
}