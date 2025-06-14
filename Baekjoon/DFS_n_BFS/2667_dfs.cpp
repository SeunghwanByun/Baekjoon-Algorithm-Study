#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

int Village[25][25] = { 0, };
int visited[25][25] = { 0, };
int num[25][25] = { 0, };

int N, cnt = 1;
int num_village[625] = { 0, };

void dfs(int x, int y) {
	const int dy[] = { -1, 1, 0, 0 };
	const int dx[] = { 0, 0, -1, 1 };
	
	for (int dir = 0; dir < 4; ++dir) {
		int next_y = dy[dir];
		int next_x = dx[dir];

		if (y + next_y < N && y + next_y >= 0 && x + next_x < N && x + next_x >= 0) {
			if (Village[y + next_y][x + next_x] == 1 && visited[y + next_y][x + next_x] == 0) {
				visited[y + next_y][x + next_x] = 1;
				num[y + next_y][x + next_x] = cnt;
				num_village[cnt]++;
				dfs(x + next_x, y + next_y);
			}
		}
	}
}

void sort(int* arr) {
	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; j < cnt - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			scanf("%1d", &Village[y][x]);
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (Village[y][x] == 1 && visited[y][x] == 0) {
				visited[y][x] = 1;
				num[y][x] = cnt;
				num_village[cnt]++;
				dfs(x, y);
				cnt++;
			}
		}
	}

	printf("%d\n", cnt - 1);

	sort(num_village);

	for (int i = 1; i < cnt; ++i) {
		printf("%d\n", num_village[i]);
	}

	return 0;
}
