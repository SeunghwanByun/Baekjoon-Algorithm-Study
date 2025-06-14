#include <iostream>

using namespace std;

string croatia[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(){
    string s;
    cin >> s;

    for(int i = 0; i < 8; i++){
        if(s.find(croatia[i]) != string::npos){
            s.replace(s.find(croatia[i]), croatia[i].size(), "!");
            i = -1;
        }            
    }

    cout << s.size();

    return 0;
}
