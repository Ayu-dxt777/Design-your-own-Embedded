#include <stdio.h>

int main()
{
    char s[] = "-123";
    int i = 0;
    int sign = 1;
    int result = 0;

    //sign handling 
    if(s[i] == '-'){
        sign = -1;
        i++;
    }
    else if (s[i] == '+'){
        i++;
    }

    //Number Conversion 
    while(s[i] >= '0' && s[i] <='9') {
        result = result * 10 + (s[i] - '0');
        i++;
    }

    result = result * sign;
    printf("%d\n",result);
    return 0;
}
