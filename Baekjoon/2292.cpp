#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;

    if(num == 1)
        cout << 1;
    else{
        int range = 1;
        int count = 1;
        while(true){
            if(num <= range)
                break;
            range += count * 6;
            count++;
        }

        cout << count;
    }
    
    return 0;
}
