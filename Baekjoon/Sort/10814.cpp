#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct { 
	int age; 
	char name[101];
	int order;
} INFO;

int compare(INFO* a, INFO* b) {
	if (a->age == b->age)
		return (a->order < b->order ? 1 : (a->order == b->order ? 0 : -1));
	else
		return (a->age < b->age ? 1 : -1);
}

void quicksort(INFO* arr, int left, int right) {
	if (left >= right) return;

	int l = left;
	int r = right;
	INFO pivot = arr[(l + r) / 2];

	while (true) {
		while (compare(arr + l, &pivot) == 1) ++l;
		while (compare(&pivot, arr + r) == 1) --r;
		if (l >= r) break;
		INFO temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
	}

	quicksort(arr, left, l - 1);
	quicksort(arr, r + 1, right);
}

int main() {
	int N;
	scanf("%d", &N);

	INFO* arr;
	arr = (INFO*)malloc(sizeof(INFO) * N);
	
	int cnt = 1;
	for (int i = 0; i < N; ++i) {
		scanf("%d %s", &arr[i].age, arr[i].name);
		arr[i].order = cnt++;
	}

	quicksort(arr, 0, N - 1);

	for (int i = 0; i < N; ++i) {
		printf("%d %s\n", arr[i].age, arr[i].name);
	}

	free(arr);
	
	return 0;
}
