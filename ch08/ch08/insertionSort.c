#include <stdio.h>

void InsertionSort(int a[], int n) {
	int i, j, key;

	for (i = 1; i < n; i++) {
		key = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (key >= a[j]) break;
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

int main(void) {
	int a[] = { 25,  9,  15,  38,  51,  72,  47,  36 };
	int i, n = sizeof(a) / sizeof(int);

	printf("���� �� : ");
	for (i = 0; i < n; i++) printf(" %d   ", a[i]);

	InsertionSort(a, n);

	printf("\n���� ���� �� : ");
	for (i = 0; i < n; i++) printf(" %d   ", a[i]);

	return 0;
}