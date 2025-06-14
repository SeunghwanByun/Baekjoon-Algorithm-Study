#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T, N;
vector<string> S;
string result;
bool found;

void dfs(int idx, string prev, string bitmask) {
    if (found) return;  // 사전순 가장 빠른 결과 찾았으면 종료
    if (idx == N) {
        result = bitmask;
        found = true;
        return;
    }

    // Case 1: 그대로 사용 (0)
    string current = S[idx];
    if (prev <= current)
        dfs(idx + 1, current, bitmask + "0");

    // Case 2: 뒤집어서 사용 (1)
    reverse(current.begin(), current.end());
    if (prev <= current)
        dfs(idx + 1, current, bitmask + "1");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        S.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> S[i];

        result = "";
        found = false;
        dfs(0, "", "");  // 첫 문자열 이전은 빈 문자열로 시작
        cout << result << '\n';
    }
    return 0;
}
