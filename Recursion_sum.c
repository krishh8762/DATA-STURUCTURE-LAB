#include <stdio.h>

int sumofdigits(int n) {
   if (n == 0)
      return 0;

       return (n % 10) + sumofdigits(n / 10);
}

int main() {
   int n, result;

   printf("Enter a number: ");
   scanf("%d", &n);

   result = sumofdigits(n);

   printf("Sum of digits = %d\n", result);

   return 0;
}