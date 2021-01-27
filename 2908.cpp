#include <iostream>
#include <vector>

using namespace std;

int reverseNum(int num){
    int rNum = 0;
    rNum += 100 * (num % 10);
    num /= 10;
    rNum += 10 * (num % 10);
    num /= 10;
    rNum += num;

    return rNum;
}

int main(){
    int A, B;

    cin >> A >> B;

    A = reverseNum(A);
    B = reverseNum(B);

    if(A > B)
        cout << A;
    if(B > A)
        cout << B;

    return 0;
}
