#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

using namespace std;

int A[1000000];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}

	int B, C;
	scanf("%d %d", &B, &C);

	long long ret = 0;
	ret += N;

	for (int i = 0; i < N; ++i) {
		if ((A[i] - B) > 0) {
			if ((A[i] - B) % C == 0)
				ret += (A[i] - B) / C;
			else
				ret += (A[i] - B) / C + 1;
		}
	}

	printf("%lld\n", ret);

	return 0;
}
