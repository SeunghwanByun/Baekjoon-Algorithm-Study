#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int visited[300][300] = { 0, };
int I, cur_x, cur_y, target_x, target_y;
int min_cnt = 987654321;

struct INFO {
	int cur_x, cur_y, cnt = 0;
};

void bfs() {
	INFO start;
	start.cur_x = cur_x;
	start.cur_y = cur_y;

	queue<INFO> q;

	q.push(start);

	const int dy[] = { -2, -2, -1, -1, +1, +1, +2, +2 };
	const int dx[] = { -1, +1, -2, +2, -2, +2, -1, +1 };

	while (!q.empty()) {
		if (q.front().cur_x == target_x && q.front().cur_y == target_y && q.front().cnt < min_cnt) {
			min_cnt = q.front().cnt;
		}
		
		INFO cur = q.front();
		q.pop();

		for (int dir = 0; dir < 8; ++dir) {
			int next_y = cur.cur_y + dy[dir];
			int next_x = cur.cur_x + dx[dir];

			if (visited[next_y][next_x] == 0 && next_y >= 0 && next_y < I && next_x >= 0 && next_x < I) {
				visited[next_y][next_x] = 1;
				INFO temp;
				temp.cur_x = next_x;
				temp.cur_y = next_y;
				temp.cnt = cur.cnt + 1;

				q.push(temp);
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; ++t) {
		scanf("%d %d %d %d %d", &I, &cur_x, &cur_y, &target_x, &target_y);
		
		visited[cur_y][cur_x] = 1;
		bfs();
		printf("%d\n", min_cnt);

		for (int y = 0; y < I; ++y) {
			memset(visited[y], 0, sizeof(int) * I);
		}

		min_cnt = 987654321;
	}

	return 0;
}
