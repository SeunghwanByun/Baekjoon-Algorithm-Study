#include <iostream>

using namespace std;

int Recursive(int N) {
	if (N > 1) {
		return N * Recursive(N - 1);
	}
	else
		return 1;
}

int main() {
	int N;

	cin >> N;

	cout << Recursive(N);

	return 0;
}
