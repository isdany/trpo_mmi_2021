#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void round10(const char *n)
{
    long int res = 0;
    int kol = strlen(n);
    char *mass;
    mass = (char*)malloc(kol*sizeof(char) + 1);
    if (atoi(n) % 10 != 0) //отделяем последнее число от строки
    {
        if (atoi(n) % 10 <= 4) //услови, чтобы определить в какую сторону будем округлять число
        {
           res = res + atoi(n) - 1;
           itoa(res,mass ,10); // перевод из int в char
           strcpy(n, mass);    // копировать массив mass в массив
           round10(n);         //используем фукцию round10 в нутри самой себя
        }
        if (atoi(n) % 10 > 4)
        {
            res = res + atoi(n) + 1;
            itoa(res,mass ,10);
            strcpy(n, mass);
            round10(n);
        }
    }
    else
        return;
}

int main()
{
    char a[5] = "1234";
    char b[4] = "199";
    round10(a);  // 1230;
    printf("\n %s \n", a);
    round10(b);   // 200
    printf("\n %s \n", b);

    // Ваши тесты...
    return 0;
}
