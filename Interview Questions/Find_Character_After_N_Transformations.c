/*Given a decimal number m, convert it into a binary string and apply n iterations, 
in each iteration 0 becomes “01” and 1 becomes “10”. Find ith(based indexing) index character 
in the string after nth iteration.

Examples: 
 
Input: m = 5 i = 5 n = 3
Output: 1 

Explanation: 
In the first case m = 5, i = 5, n = 3. 
Initially, the string is  101  ( binary equivalent of 5 )
After 1st iteration -   100110
After 2nd iteration - 100101101001
After 3rd iteration -   100101100110100110010110 
The character at index 5 is 1, so 1 is the answer
Input: m = 11 i = 6 n = 4
Output: 1 */

#include <stdio.h>

typedef struct
{
    int bits[32];
    int size;
} Binary;

typedef struct
{
    char append[32];
}transform;

Binary decimaltobinary(int num)
{
    Binary result;
    result.size = 0;

    while(num > 0)
    {
        result.bits[result.size++] = num % 2;
        num /= 2;
    }

    return result; //of type binary structure result.size = length of array , result.bits[i] = element
}

transform transformation(Binary intStruct, int index, int iteration)
{
    transform t2 = {0};   // initialize

    int out = 0;

    while(iteration > 0)   // avoid extra iteration
    {
        // out = 0;

        for(int i = intStruct.size - 1; i >= 0; i--) // print in proper binary order
        {
            if(intStruct.bits[i] == 0)
            {
                t2.append[out++] = '0';
                t2.append[out++] = '1';
            }
            else
            {
                t2.append[out++] = '1';
                t2.append[out++] = '0';
            }
        }

        t2.append[out] = '\0';

        iteration--;
    }

    return t2;
}

int main()
{
    int number = 5;

    Binary bin = decimaltobinary(number);
    transform t3 = transformation(bin,5,3);

    printf("Binary of %d is: \n", number);

    for(int i = bin.size - 1; i >= 0; i--)
    {
        printf("%d\n", bin.bits[i]);
    }
    for(int k=0; k<32;k++)
    {
        printf("%c",t3.append[k]);
    }
    printf("\n");

    return 0;
}
