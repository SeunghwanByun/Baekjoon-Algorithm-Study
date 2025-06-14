#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

using namespace std;

struct INFO {
	int loc, time = 0;
};

const int MAX_SIZE = 100000;
int N, K, min_time;

int LOCATION[MAX_SIZE] = { 0, };
int visited[MAX_SIZE] = { 0, };

void bfs() {
	// Start Finding
	int time = 0;

	queue<INFO> q;
	INFO start;
	start.loc = N;
	start.time = 0;;

	q.push(start);

	while (!q.empty()) {
		if (q.front().loc == K) {
			min_time = q.front().time;
			break;
		}

		INFO cur = q.front();
		q.pop();

		// Method of Location Transition
		for (int m = 0; m < 3; ++m) {
			int next_loca;
			if (m == 0) {
				next_loca = cur.loc - 1;
			}
			else if (m == 1) {
				next_loca = cur.loc + 1;
			}
			else {
				next_loca = cur.loc * 2;
			}
			
			if (visited[next_loca] == 0 && next_loca >= 0 && next_loca <= MAX_SIZE) {
				INFO temp;
				temp.loc = next_loca;
				temp.time = cur.time + 1;
				
				visited[next_loca] = 1;
				q.push(temp);
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);

	bfs();

	printf("%d", min_time);

	return 0;
}
