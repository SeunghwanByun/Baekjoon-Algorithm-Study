// 관중석
// 최대 공약수 문제 풀이로 풀 수 있다.
// 최대 공약수는 유클리드 호제법으로 구할 수 있다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int seat[2000][2001]; // [분자][분모]

int gcd(int a, int b) {
	return (b) ? gcd(b, a % b) : (a);
}

int main() {
	int ret = 0;
	int from, to;
	scanf("%d %d", &from, &to);
	for (int i = from; i <= to; ++i) {
		for (int j = 0; j < i; ++j) {
			int g = gcd(i, j);
			int up = j / g;
			int down = i / g;
			if (seat[up][down] == 0) {
				seat[up][down] = 1;
				++ret;
			}
		}
	}
	printf("%d\n", ret);

	return 0;
}
