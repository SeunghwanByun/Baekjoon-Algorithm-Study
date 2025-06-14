#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> s;
    int time = 0;
    for(int i = 0; i < s.size(); i++){
        // ABC
        if(s[i] >= 65 && s[i] <= 67)
            time += 3;
        // DEF
        if(s[i] >= 68 && s[i] <= 70)
            time += 4;
        // GHI
        if(s[i] >= 71 && s[i] <= 73)
            time += 5;
        // JKL
        if(s[i] >= 74 && s[i] <= 76)
            time += 6;
        // MNO
        if(s[i] >= 77 && s[i] <= 79)
            time += 7;
        // PQRS
        if(s[i] >= 80 && s[i] <= 83)
            time += 8;
        // TUV
        if(s[i] >= 84 && s[i] <= 86)
            time += 9;
        // WXYZ
        if(s[i] >= 87 && s[i] <= 90)
            time += 10;
    }

    cout << time;


    return 0;
}
