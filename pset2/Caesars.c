#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(int argc,string argv[])
{
    int position=0,i,n,key;
    if(argc!=2)
    {
       printf("Key is Missing");
       return 1;
    }
    else
    {
        key=atoi(argv[1]);
    }
    printf("Enter Plaintext:");//Enter Plaintext
    string plaintext=get_string();
    
    for(i=0,n=strlen(plaintext);i<n;i++)
    {
        if(isupper(plaintext[i]))//if Plaintext is uppercase character
        {
            position=(plaintext[i]-65)+key;
            printf("%c",(position%26)+65);
        }
        else
         if(islower(plaintext[i]))//if plaintext is lowercase character
        {
            position=(plaintext[i]-97)+key;
            printf("%c",(position%26)+97);
        }
        else
        {
            printf("%c",plaintext[i]);//if plaintext is special character or digit
        }
            
    }
    printf("\n");
    return 0;
    
}