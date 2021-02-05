#include <iostream>

using namespace std;

int main(){
    int T;

    cin >> T;

    for(int i = 0; i < T; i++){
        int X, Y;
        cin >> X >> Y;
        
        int length = Y - X - 1;
        int initial = 1;
        int count = 1;
        while(true){
            if(initial == length)
                break;
            else if(initial > length){
                initial -= (initial + 1);
                initial += initial;
                if(initial != length){
                    initial -= initial;
                    initial += (initial - 1);
                }                    
                count--;
            }
            else{
                initial += (initial + 1);
            }
            count++;
        }

        cout << count + 1;
    }

    return 0;
}
