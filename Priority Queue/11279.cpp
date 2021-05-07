#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	priority_queue<int, vector<int>, less<int>> q;
	for (int i = 0; i < N; ++i) {
		int temp;
		scanf("%d", &temp);
		
		if (temp == 0) {
			if (q.empty()) printf("0\n");
			else {
				int max = q.top(); q.pop();
				printf("%d\n", max);
			}
		}
		else {
			q.push(temp);
		}
	}

	return 0;
}
