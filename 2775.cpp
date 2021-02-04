#include <iostream>

using namespace std;

int people(int k, int n){
    if(k == 0){
        return n;
    }
    else{
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += people(k-1, i);
        }

        return sum;
    }
}

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int k, n;

        cin >> k >> n;
        int sum;
        sum = people(k, n);
        cout << sum << "\n";
    }
    

    return 0;
}
