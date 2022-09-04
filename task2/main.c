#include <stdio.h>
int num(char symbol)
{
    return (symbol >= '0' && symbol <= '9') ? 1 : -1;
}

int prosoft_atoi(const char *str)
{
   int result = 0; //Результат
   int sign = 1; // Результат 1 - '+', -1 - '-'
   int i = 0; //Индекс цикла for


  if (str == NULL)
           return 0;

   if(str[0] == '-')// проверяем число на знак
   {
       sign = -1;
       i++;
   }

   for(i; str[i] != '\0'; i++) //цикл, который преобразует строку в число
   {
       if (num(str[i])== -1 && str[i] != ' ') //услови проверяющее строка пустая или нет
           return sign * result;
       if (str[i] == ' ') //условие проверяющее есть ли в строке пробелы
           result = 0;
       else
           result = result * 10 + str[i] - '0'; //преобразование из строки в число
   }
   return sign * result;
}

int main() {
    printf("Test1: %d\n", prosoft_atoi("1"));         // 1
    printf("Test2: %d\n", prosoft_atoi("-1"));        // -1
    printf("Test3: %d\n", prosoft_atoi("1234567890"));// 1234567890
    printf("Test4: %d\n", prosoft_atoi(""));          // 0
    printf("Test5: %d\n", prosoft_atoi("test"));      // 0
    printf("Test6: %d\n", prosoft_atoi("22test"));    // 22
    printf("Test7: %d\n", prosoft_atoi("   537"));    // 537
    printf("Test8: %d\n", prosoft_atoi("xx123"));     // 0
    printf("Test9: %d\n", prosoft_atoi(NULL));        // 0
    printf("TestA: %d\n", prosoft_atoi("123-4"));     // 123
    printf("TestB: %d\n", prosoft_atoi("!123"));      // 0
    return 0;
}
