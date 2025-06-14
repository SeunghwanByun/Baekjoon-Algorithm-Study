#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;

    int alphabet[26];
    fill_n(alphabet, 26, -1);

    // ASCII Code 'a'의 10진수는 97이다.
    for(int i = 0; i < s.size(); i++){
        if(alphabet[s[i] - 97] == -1)
            alphabet[s[i] - 97] = i;
    }
    
    for(int i = 0; i < 26; i++)
        cout << alphabet[i] << " ";


    return 0;
}
