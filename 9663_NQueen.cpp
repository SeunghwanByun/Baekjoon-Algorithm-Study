#include <iostream>
#define MAX 15
using namespace std;

int board[MAX];
int N, total = 0;

bool is_Possible(int rows)
{
    for (int i = 0; i < rows; i++)
        if (board[i] == board[rows] || abs(board[rows] - board[i]) == rows - i)// 대각선이거나 같은 라인
            return false;
    //board[i]가 의미하는 것이 X좌표, i가 의미하는것이 Y좌표이므로 차이가 일정하다면 대각선에 있다고 볼 수 있다.
    return true;
}

void N_Queen(int x)
{
    if (x == N)
        total++;
    else
    {
        for (int i = 0; i < N; i++)
        {
            board[x] = i; // 퀸 배치
            if (is_Possible(x)) // 배치 가능 하다면 다음 행에 퀸 배치, 가능하지않다면 다른 위치로 퀸 배치 변경
                N_Queen(x + 1);
        }
    }
}
int main() {
    cin >> N;
    N_Queen(0);
    cout << total;
}
