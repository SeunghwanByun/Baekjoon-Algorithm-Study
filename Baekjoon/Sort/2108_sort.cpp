#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int freqValue(int* cnt);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	int fMean = 0;
	
	vector<int> numArr;

	int cnt[8001] = { 0, };

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		numArr.push_back(temp);
		fMean += temp;
		cnt[4000 + temp]++;
	}

	sort(numArr.begin(), numArr.end());

	cout << round(fMean / (double)N) << endl;
	cout << numArr[N / 2] << endl;
	cout << freqValue(cnt) << endl;
	cout << numArr[N - 1] - numArr[0] << endl;

	return 0;
}

int freqValue(int* cnt) {
	int max = 0;
	int maxIndex = 0;
	int offset = 0;
	for (int i = 0; i < 8001; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			offset = 0;
			maxIndex = i;
		}
		if (max == cnt[i] && offset != 2) {
			maxIndex = i;
			offset++;
		}
	}
	
	return maxIndex - 4000;
}
