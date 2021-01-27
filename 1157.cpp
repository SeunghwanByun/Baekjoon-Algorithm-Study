#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;

    int alphabet[26] = {0, };

    // ASCII CODE 
    // 65~90 대문자
    // 97~122 소문자
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 65 && s[i] <= 90)
            alphabet[s[i] - 65]++;
        if(s[i] >= 97 && s[i] <= 122)
            alphabet[s[i] - 97]++;
    }

    int max = 0;
    int maxIndex = 0;
    for(int i = 0; i < 26; i++){
        if(alphabet[i] > max){
            max = alphabet[i];
            maxIndex = i;
        }
    }

    int count = 0;
    for(int i = 0; i < 26; i++){
        if(alphabet[i] == max)
            count++;
    }

    if(count == 1)
        cout << char(maxIndex + 65);
    else
        cout << "?";

    return 0;
}
