#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	priority_queue<int, vector<int>, greater<int>> bigQ;
	priority_queue<int, vector<int>, less<int>> smallQ;
	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);

		if (i == 0) {
			smallQ.push(num);
			printf("%d\n", smallQ.top());
		}
		else {
			if (smallQ.size() == bigQ.size()) {
				if (bigQ.top() <= num) {
					int temp = bigQ.top(); bigQ.pop();
					smallQ.push(temp);
					bigQ.push(num);
				}
				else {
					smallQ.push(num);
				}
			}
			else { // smallQ 사이즈가 더 크다.
				if (smallQ.top() > num) {
					int temp = smallQ.top(); smallQ.pop();
					bigQ.push(temp);
					smallQ.push(num);
				}
				else {
					bigQ.push(num);
				}
			}

			printf("%d\n", smallQ.top());
		}
	}

	return 0;
}
