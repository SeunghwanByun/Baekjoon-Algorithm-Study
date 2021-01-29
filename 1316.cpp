#include <iostream>
#include <vector>

using namespace std;

bool check(string s){
    int position = 0;
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] != s[i + 1]){
            for(int j = i + 1; j < s.size(); j++){
                if(s[i] == s[j])
                    return false;
            }
        }
    }
    return true;
}

int main(){
    int N;
    cin >> N;

    vector<string> s;

    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        s.push_back(temp);
    }

    int count = 0;
    for(int i = 0; i < N; i++){
        bool is_Group = check(s[i]);
        if (is_Group == true)
            count++;
    }

    cout << count;
 
    return 0;
}
