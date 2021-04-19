#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

int N, M;
int TOMATO_BOX[1000][1000] = { 0, };
int visited[1000][1000] = { 0, };
int min_day = 0;

struct good_tomato_info {
	int cur_x, cur_y, day;
};

void bfs(queue<good_tomato_info> q) {
	const int dy[] = { -1, 1, 0, 0 };
	const int dx[] = { 0, 0, -1, 1 };

	while (!q.empty()) {
		good_tomato_info cur = q.front();
		q.pop();
		min_day = cur.day;

		for (int dir = 0; dir < 4; ++dir) {
			int next_y = cur.cur_y + dy[dir];
			int next_x = cur.cur_x + dx[dir];

			if (TOMATO_BOX[next_y][next_x] == 0 && visited[next_y][next_x] == 0 && next_y >= 0 && next_y < N && next_x >= 0 && next_x < M) {
				visited[next_y][next_x] = 1;
				TOMATO_BOX[next_y][next_x] = 1;
				
				good_tomato_info temp;
				temp.cur_x = next_x;
				temp.cur_y = next_y;
				temp.day = cur.day + 1;

				q.push(temp);
			}
		}
	}
}

int main() {
	scanf("%d %d", &M, &N);
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			scanf("%d", &TOMATO_BOX[y][x]);
		}
	}

	queue<good_tomato_info> q;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (TOMATO_BOX[y][x] == 1) {
				visited[y][x] = 1;
				good_tomato_info temp;
				temp.cur_y = y;
				temp.cur_x = x;
				temp.day = 0;

				q.push(temp);
			}
		}
	}

	bfs(q);

	bool is_valid = true;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (TOMATO_BOX[y][x] == 0) {
				is_valid = false;
				break;
			}
		}
		if (is_valid == false)
			break;
	}

	if (is_valid == false) {
		printf("-1");
	}
	else {
		printf("%d", min_day);
	}

	return 0;
}
