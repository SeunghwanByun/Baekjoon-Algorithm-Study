// 소수 구하기 문제는 에라토스테네스의 체 알고리즘으로 풀면 최적화 알고리즘이 된다.
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int M, N;
int arrNum[1000000] = { 0, };

void is_primeNum() {
	for (int i = 2; i <= N; ++i) {
		if (arrNum[i] == 1)
			continue;
		for (int j = i + i; j <= N; j += i) {
			arrNum[j] = 1;
		}
	}
}

int main() {
	scanf("%d %d", &M, &N);

	is_primeNum();

	for (int i = M; i <= N; ++i) {
		if (arrNum[i] == 0 && i > 1)
			printf("%d\n", i);
	}

	return 0;
}
