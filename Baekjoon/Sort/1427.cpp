#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

char num_arr[10];

void qsort(int left, int right) {
	if (left >= right) return;
	int l = left - 1;
	int r = right + 1;
	int mid = num_arr[(l + r) / 2];
	while (true) {
		while (num_arr[++l] > mid);
		while (num_arr[--r] < mid);
		if (l >= r) break;
		int temp = num_arr[l];
		num_arr[l] = num_arr[r];
		num_arr[r] = temp;
	}
	
	qsort(left, l - 1);
	qsort(r + 1, right);
}

int main() {
	scanf("%s", num_arr);
	
	int len = strlen(num_arr);

	qsort(0, len);

	for (int i = 0; i < len; ++i) {
		printf("%c", num_arr[i]);
	}
	
	return 0;
}
