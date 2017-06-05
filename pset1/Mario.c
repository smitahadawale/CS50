#include<stdio.h>
#include<cs50.h>

int main()
{
        int height,count,k;
        printf("Enter Height:");
        height=get_int();
        
        char ch='#';
        while((height<0)||(height>23))
        { 
            printf("Retry:");
             height=get_int();
             
        }
        count=height-1;
            for(int i=1;i<=height;i++)
            {
                for( k=count;k>=1;k--)
                {
                    printf("  ");
                }
                for(int j=1;j<=i;j++)
                {
                    printf("%2c",ch);
                    
                }
                printf("\n");
                count--;
            }
            return 0;
        
        
}
    