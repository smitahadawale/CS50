#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    string s=get_string();
    int n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            printf("%c",toupper(s[i]));
        }
        if(s[i]==' ')
        {
            printf("%c",toupper(s[i+1]));
            
        }
        
    }
    printf("\n");
    
    return 0;
}