#include <iostream>

using namespace std;

int main() {
	int N;

	cin >> N;

	int num = 0;
	for (int i = 1; i < N; i++) {
		int sum = 0;
		int temp = i;
		while (temp >= 1) {
			sum += temp % 10;
			temp /= 10;
		}

		if (sum + i == N) {
			num = i;
			break;
		}		
	}
	
	cout << num;

	return 0;
}
