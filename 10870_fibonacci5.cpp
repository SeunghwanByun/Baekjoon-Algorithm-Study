#include <iostream>

using namespace std;

int main() {	
	int N;
	
	cin >> N;
	
	int f0 = 0;
	int f1 = 1;
	int fibonacci = 0;
	
	if (N == 0)
		fibonacci = 0;
	else if (N == 1)
		fibonacci = 1;
	else {
		for (int i = 2; i <= N; i++) {
			fibonacci = f0 + f1;
			f0 = f1;
			f1 = fibonacci;
		}
	}

	cout << fibonacci;

	return 0;
}
