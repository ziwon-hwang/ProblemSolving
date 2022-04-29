#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partiton(int* arr, int p, int r)
{
	int j, i,t;
	j = p;
	i = p - 1;

	for (; j < r; j++)
	{
		if (arr[j] < arr[r])
		{
			i++;
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;

		}
	}

	i++;

	t = arr[i];
	arr[i] = arr[r];
	arr[r] = t;

	return i;
}

void quickSort(int* arr[], int p, int r)
{
	int q; //loop variable

	if (p < r)
	{
		q = partiton(arr,p, r);
		quickSort(arr, p, q);
		quickSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}


int main(void)
{
	int* arr;
	int n;
	int i;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;

	}

	for (i = 0; i < n; i++)
		printf("%4d ", arr[i]);
	printf("\n");

	quickSort(arr, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%4d ", arr[i]);
	printf("\n");

	free(arr);
	return 0;

}