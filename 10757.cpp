#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B;
    
    cin >> A >> B;

    // A + B = 93421
    // A = "92857";
    // B = "564";

    int rest = 0;
    string s;
    int as = A.size() - 1;
    int bs = B.size() - 1;
    
    while(as >= 0 || bs >= 0){
        int temp_sum;
        if(as >= 0 && bs >= 0)
            temp_sum = int(A[as] - '0') + int(B[bs] - '0') + rest;
        if(as >= 0 && bs < 0)
            temp_sum = int(A[as] - '0') + rest;
        if(bs >= 0 && as < 0)
            temp_sum = int(B[bs] - '0') + rest;
        
        if(temp_sum >= 10){
            s.push_back(char(temp_sum % 10) + '0');
            rest = 1;
        }
        else
        {
            s.push_back(char(temp_sum) + '0');
            rest = 0;
        }

        as--;
        bs--;

        if(as < 0 && bs < 0 && temp_sum >= 10)
            s.push_back('1');
    }

    
    for(int i = s.size() - 1; i >= 0; i--){
        cout << s[i];
    }

    return 0;
}
