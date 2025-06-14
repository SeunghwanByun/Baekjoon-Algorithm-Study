#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

int N, M;
int MAZE[101][101] = { 0, };
int visited[101][101] = { 0, };

struct INFO {
	int cur_x = 1, cur_y = 1, cnt = 1;
};

int min_count = 987654321;

void bfs(queue<INFO> q) {
	const int dy[] = { -1, 1, 0, 0 };
	const int dx[] = { 0, 0, -1, 1 };

	while (!q.empty()) {
		if (q.front().cur_x == M && q.front().cur_y == N && q.front().cnt < min_count) {
			min_count = q.front().cnt;
		}

		INFO cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int next_y = cur.cur_y + dy[dir];
			int next_x = cur.cur_x + dx[dir];

			if (next_y > 0 && next_y <= N && next_x > 0 && next_x <= M && visited[next_y][next_x] == 0 && MAZE[next_y][next_x] != 0) {
				visited[next_y][next_x] = 1;

				INFO temp;
				temp.cur_y = next_y;
				temp.cur_x = next_x;
				temp.cnt = cur.cnt + 1;

				q.push(temp);
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= M; ++x) {
			scanf("%1d", &MAZE[y][x]);
		}
	}

	queue<INFO> q;

	INFO start;
	q.push(start);
	visited[start.cur_y][start.cur_x] = 1;

	bfs(q);

	printf("%d\n", min_count);

	return 0;
}
