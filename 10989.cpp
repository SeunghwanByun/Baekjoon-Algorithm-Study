#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int N;
	cin >> N;
    
    int count[10001] = {0};
    
	for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
		count[temp]++;
	}
    
	for (int i = 1; i <= 10000; i++) {
		for (int c = 0; c < count[i]; c++) {
			cout << i << "\n";
		}
	}

	return 0;
}
