#include<stdio.h>

int main() {
	int k = -1, str = 0, stb = 0, n, max = 0, matrix[100][100] = {0};
	printf("Введите размер матрицы: ");
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
	//max = matrix[0][0];
	for (int i = 0; i < n; ++i) {
		max = matrix[i][i];
                for (int j = 0; j < n; ++j)
                        if (matrix[i][j] > max) {
				max = matrix[i][j];
			}
		matrix[i][i] = max;
		matrix[i][n-i-1] = max;
	}
	printf("Измененная матрица:\n");
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j)
                        printf("%d ", matrix[i][j]);
                printf("\n");
        }
	return 0;
}
