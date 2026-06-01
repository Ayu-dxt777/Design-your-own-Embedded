/* with o(n2) complexity
The algorithm is correct for many cases, 
but it has O(n²) complexity because for every character in the first string, it rescans both strings to count frequencies. 
A more efficient approach is to maintain a frequency table of size 256, giving O(n) time and O(1) extra space. */
#include <stdio.h>
#include <string.h>


int freq(char c, char s1[], char s2[])
{
    int i=0;
    int j=0;
    int count =0;
    int jcount = 0;
    while(s1[i]!='\0')
    {
        if(s1[i] == c)
        {
            count++;
        }
        i++;
    }
    while(s2[j]!='\0')
    {
        if(s2[j] == c)
        {
            jcount++;
        }
        j++;
    }
    if (count==jcount)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}


int main(void) {
    int i =0;
    int finalcount = 0;
    int numberofwords =0;
    char s1[] = "geeks";
    char s2[] = "kseeg";
    if(strlen(s1)!=strlen(s2))
    {
        printf("not anagram\n");
    }
    else
    {
        while(s1[i]!='\0')
        {
            if (freq(s1[i], s1, s2)==1)
            {
                ++finalcount;
            }
            numberofwords++;
            i++;
        }
        if(finalcount==numberofwords)
        {
            printf("Anagram");
        }
        else
        {
            printf("Not Anagram");
        }
    }
    
}
