#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<string> s;

    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        s.push_back(temp);
    }

    for(int i = 0; i < N; i++){
        stack<char> VPS;
        for(int j = 0; j < s[i].size(); j++){
            if(VPS.empty() || s[i][j] == '(')
                VPS.push(s[i][j]);
            if((s[i][j] == ')') && (VPS.top() == '(')){
                VPS.pop();
            }
        }

        cout << (VPS.empty() ?  "YES" : "NO") << endl;
    }

    return 0;
}
