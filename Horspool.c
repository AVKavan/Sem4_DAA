#include<stdio.h>
#include<string.h>

int table[128];

void shifttable(char* p)
{
    for(int i=0;i<128;i++)
    table[i]=strlen(p);

    for(int i=0;i<strlen(p)-1;i++)
    {
        table[p[i]]=strlen(p)-1-i;
    }
}



int horspool(char* text, char* pattern)
{
    shifttable(pattern);

    int plen=strlen(pattern);
    int slen=strlen(text);
    int i=plen-1;
    while(i<=slen-1)
    {
        int k=0;
        while(k<=plen-1 && pattern[plen-1-k]==text[i-k])
        k++;
        if(k==plen)
        return i-plen+2;
        else
        i=i+table[text[i]];
    }
    return -1;
}
int main()
{
    char text[100];
    char pattern[100];

    printf("Enter a text: ");
    scanf("%s",text);
    printf("Enter a pattern to search: ");
    scanf("%s",pattern);

    int pos=horspool(text,pattern);
    printf("The pattern is found at position %d",pos);

}