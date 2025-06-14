#include <iostream>
#include <cstdio>

using namespace std;

void Swap(int *arrLeft, int *arrRight) {
	int Temp = *arrLeft;
	*arrLeft = *arrRight;
	*arrRight = Temp;
}

int Partition(int *arr, int Left, int Right) {
	int First = Left;
	int Pivot = arr[First];

	++Left;
	
	while (Left <= Right) {
		while (arr[Left] <= Pivot && Left < Right)
			++Left;

		while (arr[Right] > Pivot && Left <= Right)
			--Right;

		if (Left < Right)
			Swap(&arr[Left], &arr[Right]);
		else
			break;
	}

	Swap(&arr[First], &arr[Right]);

	return Right;
}

void QuickSort(int *arr, int Left, int Right) {
	if (Left < Right) {
		int Index = Partition(arr, Left, Right);
		
		QuickSort(arr, Left, Index - 1);
		QuickSort(arr, Index + 1, Right);
	}	
}

int main() {
	int N;
	cin >> N;

	int *arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	QuickSort(arr, 0, N - 1);

	for (int i = 0; i < N; i++)
		cout << arr[i] << endl;

	return 0;
}