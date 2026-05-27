/* Given a string s representing a Roman numeral, find it's corresponding integer value.
Roman numerals are formed using the following symbols: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, and M = 1000.
Numbers are typically formed by combining these symbols from left to right, adding or subtracting their values based on specific rules.

How does the conversion work?

If a smaller value symbol comes before, we subtract. Otherwise, we add.
In IV, I comes before V and V has a larger value 5. So our result is 5 - 1 = 4.
In VI, V comes before I and I has a smaller value 1. So our result is 5 + 1 = 6.
In II, we have same values, so we add and get 1 + 1 = 2
In case of more than 2 characters, we traverse from left to right and group only when we see a
greater value character after a smaller value character. For example MXVII is 1000 + 10 + 5 + 1 + 1 = 1017. And XLVII is (50 - 10) + 5 + 1 + 1 = 47. Note that L is larger and comes after X. */

#include <stdio.h>

// Function to convert Roman character to integer
int value(char roman)
{
    if(roman == 'I')
        return 1;

    else if(roman == 'V')
        return 5;

    else if(roman == 'X')
        return 10;

    else if(roman == 'L')
        return 50;

    else if(roman == 'C')
        return 100;

    else if(roman == 'D')
        return 500;

    else if(roman == 'M')
        return 1000;

    return 0;
}

int main()
{
    char roman[20];
    int result = 0;
    int i = 0;

    printf("Enter Roman Numeral:\n");
    scanf("%s", roman);

    // Traverse the string
    while(roman[i] != '\0')
    {
        int current = value(roman[i]);
        int next = value(roman[i + 1]);

        // Roman numeral logic
        if(current < next)
        {
            result = result - current;
        }
        else
        {
            result = result + current;
        }

        i++;
    }

    printf("Integer value = %d\n", result);

    return 0;
}
