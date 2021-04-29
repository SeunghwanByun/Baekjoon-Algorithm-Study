// Convex Hull Problem is solved by Graham Scan
// 극좌표을 결정한다.
// 극좌표은 y좌표가 가장 작고, y값이 같다면 x값이 작은 좌표를 극값으로 설정한다.
// 극좌표를 기준으로 반시계방향으로 좌표를 정렬한다.
// 만약 같은 방향에 두 좌표가 있다면 더 가까운 좌표를 앞으로 오도록 정렬한다.
// 정렬이 끝났다면, 첫 좌표부터 시작하여 끝 좌표까지 계산하며 반시계방향이면 stack에 넣어주고,
// 시계방향이면 stack에서 빼주어서 stack에 외곽 좌표들을 쌓아준다.
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <stdlib.h>
#include <stack>
#include <algorithm>

using namespace std;

struct Coordinate{
	double x, y;
} Polar;
int N;

long long ccw(Coordinate p1, Coordinate p2, Coordinate p3) {
	long long res = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
	if (res > 0) return 1; // Counter Clockwise Direction
	else if (res < 0) return -1; // Clockwise Direction
	else return 0; // Same Direction
}

long double distance(Coordinate a, Coordinate b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool compare(Coordinate a, Coordinate b) {
	if (ccw(Polar, a, b) > 0) return true;
	else if (ccw(Polar, a, b) < 0) return false;
	else {
		if (distance(Polar, a) < distance(Polar, b)) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main() {
	scanf("%d", &N);

	Coordinate* nArr = (Coordinate*)malloc(sizeof(Coordinate) * N);

	for (int i = 0; i < N; ++i) {
		scanf("%lf %lf", &nArr[i].x, &nArr[i].y);
	}
	
	// Initialize Polar Coordinate
	Polar = nArr[0];

	// Searching and Renewing Polar Coordinate
	for (int i = 1; i < N; ++i) {
		if (nArr[i].y < Polar.y) {
			Polar = nArr[i];
		}
		else if (nArr[i].y == Polar.y) {
			if (nArr[i].x < Polar.x) {
				Polar = nArr[i];
			}
		}
	}

	sort(nArr, nArr + N, compare);

	stack<Coordinate> s;

	s.push(nArr[0]);
	s.push(nArr[1]);

	Coordinate first, second;

	for (int i = 2; i < N; ++i) {
		while (s.size() >= 2) {
			second = s.top();
			s.pop();
			first = s.top();

			if (ccw(first, second, nArr[i]) > 0) { // 반시계방향
				s.push(second);
				break;
			}
		}

		s.push(nArr[i]);
	}

	printf("%d", s.size());

	return 0;
}
