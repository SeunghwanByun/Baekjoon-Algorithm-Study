#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <stdlib.h>
#include <string.h>

typedef struct room {
	int start, end;
} ROOM;

int compare(const void* a, const void* b) {
	ROOM info1 = *(ROOM*)a;
	ROOM info2 = *(ROOM*)b;

	if (info1.end == info2.end) {
		return (info1.start > info2.start ? 1 : (info1.start == info2.start ? 0 : -1));
	}
	else {
		return (info1.end > info2.end ? 1 : -1);
	}
}

int main() {
	int N;
	scanf("%d", &N);

	ROOM* nArr = (ROOM*)malloc(sizeof(ROOM) * N);
	memset(nArr, 0, sizeof(ROOM) * N);

	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &nArr[i].start, &nArr[i].end);
	}

	qsort(nArr, N, sizeof(nArr[0]), compare); // 회의가 끝나는 순서대로 정렬

	int cnt = 0;
	int last_end_time = 0;

	for (int i = 0; i < N; ++i) {
		if (i == 0) {
			cnt++;
			last_end_time = nArr[i].end;
		}
		else if (last_end_time <= nArr[i].start) {
			cnt++;
			last_end_time = nArr[i].end;
		}
	}

	printf("%d\n", cnt);

	free(nArr);

	return 0;
}
