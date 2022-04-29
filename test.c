#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* arr[], int p, int q, int r)
{
	int i, j, k; // 왼쪽 정렬시 필요, 오른쪽 정렬시 필요, 합해서 정렬할떄 필요
	int* t;

	i = p;
	j = q + 1;

	t = (int*)malloc(sizeof(int) * (r - p + 1));

	k = 0;

	while (i <= q && j <= r)
	{
		if (arr[i] < arr[j])
		{
			t[k] = arr[i];
			i++;
		}
		else
		{
			t[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > q)//왼쪽 부분 다 소비 (i>p)->비교할거 없으니 오른쪽 다 복사
	{
		for (; j <= r; j++) //  오른쪽 부분 복사
		{
			t[k] = arr[j];
			k++;
		}
	}
	else //오른쪽 부분 다 소비->비교할 부분 없으니까 왼쪽 다 복사
	{
		for (; i <= q; i++)
		{
			t[k] = arr[j];
			k++;
		}
	}

	//t 어레이 다 옮겨담았으니 원형 어레이에 복사

	for (i = p, k = 0; i <= r; i++, k++)
		arr[i] = t[k];

	free(t);


}

void mergeSort(int* arr[], int p, int r)
{
	int q; //loop variable

	if (p < r)
	{
		q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
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

	mergeSort(arr, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%4d ", arr[i]);
	printf("\n");

	free(arr);
	return 0;

}