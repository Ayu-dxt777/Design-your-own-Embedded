/*
Logic in 5 Lines :
1. Create a frequency array of size 256 to store counts of all ASCII characters.
2. Traverse the first string and increment the count corresponding to each character.
3. Traverse the second string and decrement the count corresponding to each character.
4. If the strings are anagrams, every increment will be canceled by a decrement.
5. Finally, check whether all 256 counts are zero; if yes, the strings are anagrams, otherwise they are not.

unsigned char --> array index between 0 to 255
*/
#include <stdio.h>
#include <string.h>

int isAnagram(char s1[], char s2[])
{
    int freq[256] = {0};
    int i;

    /* Lengths must match */
    if(strlen(s1) != strlen(s2))
    {
        return 0;
    }

    /* Count characters from first string */
    for(i = 0; s1[i] != '\0'; i++)
    {
        freq[(unsigned char)s1[i]]++; //increment the count of the character at that position , converting the characters to ascii 
    }

    /* Remove counts using second string */
    for(i = 0; s2[i] != '\0'; i++)
    {
        freq[(unsigned char)s2[i]]--;
    }

    /* If any count is non-zero, not an anagram */
    for(i = 0; i < 256; i++)
    {
        if(freq[i] != 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char s1[] = "geeks";
    char s2[] = "kseeg";

    if(isAnagram(s1, s2))
    {
        printf("Anagram\n");
    }
    else
    {
        printf("Not Anagram\n");
    }

    return 0;
}
