#include <iostream>

using namespace std;

bool HanNumber(int num){
    if(num == 1000)
        return false;
    int sub1, sub2;
    sub1 = num % 10;
    num /= 10;
    sub1 -= num % 10;

    sub2 = num % 10;
    num /= 10;
    sub2 -= num % 10;

    if(sub1 != sub2)
        return false;

    return true;
}

int main(){
    int N;
    cin >> N;

    int count = 0;
    for(int i = 1; i <= N; i++){
        bool checkHanNum = false;
        if(i < 100)
            count++;
        else{
            checkHanNum = HanNumber(i);
            if(checkHanNum == true)
                count++;
        }
    }

    cout << count;    
    
    return 0;
}
