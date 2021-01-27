#include <iostream>

using namespace std;

int Recursive_Fibonacci(int N) {
	if (N == 0)
		return 0;
	if (N == 1)
		return 1;
	if (N > 1)
		return Recursive_Fibonacci(N - 1) + Recursive_Fibonacci(N - 2);
}

int main() {
	int N;

	cin >> N;

	int fibonacci = 0;

	fibonacci = Recursive_Fibonacci(N);

	cout << fibonacci;

	return 0;
}
