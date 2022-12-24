#include<stdio.h>

/* 7 6 5 4
8 15 14 3
9 16 13 2
10 11 12 1 */

/* 11 10 9 8 7 6 
12 27 26 25 24 5 
13 28 35 34 23 4 
14 29 36 33 22 3 
15 30 31 32 21 2 
16 17 18 19 20 1 */
 

 int main() {
  int n, p, matrix[100][100] = {0};
  printf("Введите матрицу: ");
  scanf("%d", &n);
  while (n <= 0) {
   printf("Введен неверный размер\nВведите размер матрицы: ");
   scanf("%d", &n);
  } 
  printf("Введите элементы матрицы: ");
  for (int i = 0; i < n; ++i)
   for (int j = 0; j < n; ++j)
    scanf("%d", &matrix[i][j]);
  printf("Введенная матрица:\n");
  for (int i = 0; i < n; ++i) {
                 for (int j = 0; j < n; ++j)
                         printf("%d ", matrix[i][j]);
   printf("\n");
  }
  p = n/2;
  printf("Полученная последовательность:\n");
  for (int i = n - 1; i >= p; i--) {
    for (int j = i; j >= n - i - 1; j--) 
    printf("%d ", matrix[j][i]); 
    
   for (int j = i - 1; j >= n - i - 1 ; j--)
    printf("%d ", matrix[n - i - 1][j]); 
    
   for (int j = n - i; j <= i; j++) 
    printf("%d ", matrix[j][n - i - 1]);
    
   for (int j = n - i; j < i ; j++)
    printf("%d ", matrix[i][j]); 
  }
  printf("\n");
  return 0;
 }