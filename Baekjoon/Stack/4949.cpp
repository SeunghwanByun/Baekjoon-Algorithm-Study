#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<string> s;

    while(true){
        string sentence;

        getline(cin, sentence);

        if(sentence == ".")
            break;
        else
        {
            s.push_back(sentence);
        }   
    }

    for(int i = 0; i < s.size(); i++){
        stack<char> temp_stack;
        for(int j = 0; j < s[i].size(); j++){
            if(s[i][j] == '(' || s[i][j] == '[')
                temp_stack.push(s[i][j]);
            if(s[i][j] == ')' && !temp_stack.empty() && temp_stack.top() == '(')
                temp_stack.pop();
            if(s[i][j] == ']' && !temp_stack.empty() && temp_stack.top() == '[')
                temp_stack.pop();
        }
        if(temp_stack.empty())
            cout << "yes" << endl;
        else
        {
            cout << "no" << endl;
        }
        
    }

    return 0;
}
