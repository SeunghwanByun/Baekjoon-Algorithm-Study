#include <iostream>

using namespace std;

bool selfNumber(int num){
    bool is_SelfNumber = false;
    for(int i = 1; i < num; i++){
        int sum = 0;
        int temp = i;
        while(temp > 0){
            sum += temp % 10;
            temp /= 10;
        }
        sum += i;
        if(sum == num)
            return true;
    }

    return false;
}

int main(){
    for(int i = 1; i <= 10000; i++){
        bool checkNum;
        checkNum = selfNumber(i);
        if(checkNum == false)
            cout << i << endl;
    }
    
    return 0;
}
