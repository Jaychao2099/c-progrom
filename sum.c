#include <stdio.h>
/*
int main()
{   long long int integer1;
    long long int integer2;
    long long int sum;
    printf("數字1是: ");
    scanf("%lld", &integer1);
    printf("數字2是: ");
    scanf("%lld", &integer2);
    sum = integer1 + integer2;
    printf("總和是 %lld。\n爽了嗎?", sum);
    return 0;
}
*/
int main()
{   long double num1;
    long double num2;
    long double sum;
    printf("數字1是: ");
    scanf("%Lf", &num1);
    printf("數字2是: ");
    scanf("%Lf", &num2);
    sum = num1 + num2;
    printf("總和是 %Lf。\n爽了嗎?", sum);
    return 0;
}