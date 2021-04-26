#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int tetromino[19][4][4] = {
	{1, 1, 1, 1,
	 0, 0, 0, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0},
	{1, 0, 0, 0,
	 1, 0, 0, 0,
	 1, 0, 0, 0,
	 1, 0, 0, 0},
	{1, 1, 0, 0,
	 1, 1, 0, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0},
	{1, 0, 0, 0,
	 1, 0, 0, 0,
	 1, 1, 0, 0,
	 0, 0, 0, 0},
	{0, 0, 1, 0,
	 1, 1, 1, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0},
	{1, 1, 0, 0,
	 0, 1, 0, 0,
	 0, 1, 0, 0,
	 0, 0, 0, 0},
	{1, 1, 1, 0,
	 1, 0, 0, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0},
	{0, 1, 0, 0,
	 0, 1, 0, 0,
	 1, 1, 0, 0,
	 0, 0, 0, 0},
	{1, 1, 1, 0,
	 0, 0, 1, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0},
	{1, 1, 0, 0,
	 1, 0, 0, 0,
	 1, 0, 0, 0,
	 0, 0, 0, 0},
	{1, 0, 0, 0,
	 1, 1, 1, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0},
	{1, 0, 0, 0,
	 1, 1, 0, 0,
	 0, 1, 0, 0,
	 0, 0, 0, 0},
	{0, 1, 1, 0,
	 1, 1, 0, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0},
	{0, 1, 0, 0,
	 1, 1, 0, 0,
	 1, 0, 0, 0,
	 0, 0, 0, 0},
	{1, 1, 0, 0,
	 0, 1, 1, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0},
	{1, 1, 1, 0,
	 0, 1, 0, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0},
	{1, 0, 0, 0,
	 1, 1, 0, 0,
	 1, 0, 0, 0,
	 0, 0, 0, 0},
	{0, 1, 0, 0,
	 1, 1, 1, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0},
	{0, 1, 0, 0,
	 1, 1, 0, 0,
	 0, 1, 0, 0,
	 0, 0, 0, 0} };

int BOARD[503][503] = { 0, };

int multiply(int board_x, int board_y) {
	int res = 0;
	
	for (int t = 0; t < 19; ++t) {
		int temp_sum = 0;
		for (int y = 0; y < 4; ++y) {
			for (int x = 0; x < 4; ++x) {
				temp_sum += BOARD[board_y + y][board_x + x] * tetromino[t][y][x];
			}
		}

		if (temp_sum > res) {
			res = temp_sum;
		}
	}

	return res;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			scanf("%d", &BOARD[y][x]);
		}
	}

	int max = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			int temp = multiply(x, y);
			if (max < temp) {
				max = temp;
			}
		}
	}

	printf("%d", max);
	
	return 0;
}
