#include <iostream>

using namespace std;

void BubbleSort(int* arr, int length) {
	for (int l = length - 1; l > 0; l--) {
		for (int i = 0; i < l; i++) {
			if (arr[i] >= arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

int main() {
	int N;

	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	BubbleSort(arr, N);

	for (int i = 0; i < N; i++)
		cout << arr[i] << endl;
}