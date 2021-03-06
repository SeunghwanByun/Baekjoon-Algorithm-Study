#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

typedef struct { int x, y; } coordinate;

int compare(coordinate* a, coordinate* b) {
	if (a->x == b->x)
		return (a->y < b->y ? 1 : (a->y == b->y ? 0 : -1));
	else
		return (a->x < b->x ? 1 : -1);
}

void quicksort(coordinate* arr, int left, int right) {
	if (left >= right) return;
	int l = left;
	int r = right;
	coordinate pivot = arr[(l + r) / 2];

	while (true) {
		while (compare(arr + l, &pivot) == 1) ++l;
		while (compare(&pivot, arr + r) == 1) --r;
		if (l >= r) break;
		coordinate temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
	}

	quicksort(arr, left, l - 1);
	quicksort(arr, r + 1, right);
}

int main() {
	int N;
	scanf("%d", &N);

	coordinate nArr[100000];

	for (int i = 0; i < N; ++i) {
		int tempX, tempY;
		scanf("%d %d", &tempX, &tempY);

		nArr[i].x = tempX;
		nArr[i].y = tempY;
	}

	quicksort(nArr, 0, N - 1);

	for (int i = 0; i < N; ++i) {
		printf("%d %d\n", nArr[i].x, nArr[i].y);
	}

	return 0;
}
