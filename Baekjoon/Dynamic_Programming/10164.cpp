// 다이나믹 프로그래밍
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int SIZE = 16; // 0을 쓰지 않기 위해

int cache[SIZE][SIZE];
int N, M, K;

// 경우의 수 배열 채우기
int solve(int y, int x) {
	if (y == 1 || x == 1) {
		return cache[y][x] = 1;
	}
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	ret = solve(y - 1, x) + solve(y, x - 1);
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d %d %d", &N, &M, &K);

	int ret = 0;
	if (K == 0) {
		ret = solve(N, M);
	}
	else {
		int yy = (K + M - 1) / M;
		int xx = K % M;
		xx = (xx == 0) ? (M) : (xx);
		ret = solve(yy, xx) * solve(N - yy + 1, M - xx + 1);
	}

	printf("%d\n", ret);

	return 0;
}
