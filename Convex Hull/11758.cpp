#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int res;

	res = 1 * (x1 * y2 - y1 * x2) + 1 * (x2 * y3 - y2 * x3) + 1 * (x3 * y1 - x1 * y3);

	if (res > 0)
		return 1;
	else if (res == 0)
		return 0;
	else
		return -1;
}

int main() {
	int x1, y1, x2, y2, x3, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

	printf("%d", ccw(x1, y1, x2, y2, x3, y3));

	return 0;
}
