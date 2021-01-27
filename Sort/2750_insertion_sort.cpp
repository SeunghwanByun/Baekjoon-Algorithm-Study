#include <iostream>
#include <cstring>

using namespace std;

void InsertionSort(int *arr, int length) {
	int key;

	for (int i = 1; i < length; i++) {
		if (arr[i - 1] <= arr[i])
			continue;

		if (arr[i - 1] > arr[i]) {
			key = arr[i];
			for (int j = 0; j < i; j++) {
				if (arr[j] > key) {
					memmove(&arr[j + 1], &arr[j], sizeof(int) * (i - j));
					arr[j] = key;
					break;
				}
			}
		}		
	}
}

int main() {
	int N;
	cin >> N;

	int *arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	InsertionSort(arr, N);

	for (int i = 0; i < N; i++)
		cout << arr[i] << endl;
	
	return 0;
}