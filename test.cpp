#include <stdio.h>
#include<math.h>

int main()
{
    int initialnum, finalnum, temp, r, sum = 0, i;
    printf("Enter initial value : ");
    scanf("%d", &initialnum);
    printf("Enter final value : ");
    scanf("%d", &finalnum);
    for (i = initialnum; i <= finalnum; i++)
    {
        temp = i;
        while (temp != 0)
        {
            r = temp % 10;
            sum = sum + pow(r, 3);
            temp = temp / 10;
        }
        if (sum == i)
        {
            printf("%d\n", i);
        }
        sum = 0;
    }
}