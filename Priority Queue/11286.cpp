#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main() {
	int N;
	scanf("%d", &N);

	priority_queue<int, vector<int>, compare> q;
	for (int i = 0; i < N; ++i) {
		int temp;
		scanf("%d", &temp);

		if (temp == 0) {
			if (q.empty()) {
				printf("0\n");
			}
			else {
				int min = q.top(); q.pop();
				printf("%d\n", min);
			}
		}
		else {
			q.push(temp);
		}
	}

	return 0;
}
