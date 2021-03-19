// 2048
// 최대 20 x 20 매트릭스
// 1회 움직임에서 선택할 수 있는 경우의 수는 상, 하, 좌, 우 4가지
// 최대 5번 움직임만 생각하면 되기 때문에 다 해보면 됨.
// 4^5 = 1024 (움직임의 경우의 수)
// 1024 x 20 x 20 = 409600(움직임의 발생 횟수 * 보드의 크기)
// 코딩의 실수와 코딩 시간을 단축하기 위해 한 가지 방향만 구현하고,
// 보드를 90도만 돌리는 함수를 구현하면 코딩 시간 단축 가능


#include <stdio.h>

// 보드 사이즈
int n, ret;

struct BOARD {
	int map[20][20];

	void rotate() {
		int temp[20][20];

		// 시계 방향으로 로테이션..!
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				temp[y][x] = map[n - x - 1][y];
			}
		}

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				map[y][x] = temp[y][x];
			}
		}
	}

	int get_max() {
		int ret = 0;
			
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (map[y][x] > ret) {
					ret = map[y][x];
				}
			}
		}

		return ret;
	}
	
	void up() {
		int temp[20][20];

		// 위로 더하기 때문에 x부터 for문을 돈다.
		for (int x = 0; x < n; x++) {
			int flag = 0, target = -1;
			for (int y = 0; y < n; y++) {
				if (map[y][x] == 0) {
					continue;
				}

				if (flag == 1 && map[y][x] == temp[target][x]) {
					temp[target][x] *= 2, flag = 0;
				}
				else {
					temp[++target][x] = map[y][x], flag = 1;
				}
			}
			for (++target; target < n; ++target) {
				temp[target][x] = 0;
			}
		}
		// temp에 저장된 행렬을 map에 업데이트 해준다.
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				map[y][x] = temp[y][x];
			}
		}
	}
};

void dfs(BOARD cur, int count) {
	if (count == 5) {
		int candi = cur.get_max();
		if (ret < candi) {
			ret = candi;
		}
		return;
	}
	
	for (int dir = 0; dir < 4; dir++) {
		BOARD next = cur;
		next.up();
		dfs(next, count + 1);
		cur.rotate();
	}
}

int main() {
	// BOARD
	BOARD board;
	scanf_s("%d", &n);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			scanf_s("%d", &board.map[y][x]);
		}
	}

	ret = 0;
	dfs(board, 0);
	printf("%d\n", ret);

	return 0;
}
