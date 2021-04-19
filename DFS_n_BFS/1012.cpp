#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int LATTICE[50][50] = { 0, };
int visited[50][50] = { 0, };

int T, M, N, K;
int num_worm = 0;

void dfs(int x, int y) {
	const int dy[] = { -1, 1, 0, 0 };
	const int dx[] = { 0, 0, -1, 1 };

	for (int dir = 0; dir < 4; ++dir) {
		int next_y = y + dy[dir];
		int next_x = x + dx[dir];

		if (visited[next_y][next_x] == 0 && LATTICE[next_y][next_x] == 1 && 
			next_y >= 0 && next_y < N && next_x >= 0 && next_x < M) {
			visited[next_y][next_x] = 1;
			dfs(next_x, next_y);
		}
	}
}

int main() {
	scanf("%d", &T);

	// Test Case
	for (int t = 0; t < T; ++t) {
		scanf("%d %d %d", &M, &N, &K);

		for (int k = 0; k < K; ++k) {
			int tempY, tempX;
			scanf("%d %d", &tempX, &tempY);

			LATTICE[tempY][tempX] = 1;
		}

		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				if (LATTICE[y][x] == 1 && visited[y][x] == 0) {
					visited[y][x] = 1;
					dfs(x, y);
					num_worm += 1;
				}
			}
		}

		printf("%d\n", num_worm);
		
		num_worm = 0;
		for (int y = 0; y < N; ++y) {
			memset(LATTICE[y], 0, sizeof(int) * M);
			memset(visited[y], 0, sizeof(int) * M);
		}
	}

	return 0;
}
