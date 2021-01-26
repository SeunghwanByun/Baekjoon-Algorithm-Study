#include <iostream>
#include <stack>

using namespace std;

int main(){
    int N;
    cin >> N;

    stack<int> s;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;

        if(temp == 0){
            s.pop();
        }
        else
        {
            s.push(temp);
        }
    }

    int size = s.size();

    if(s.empty() == true)
        cout << 0;
    else{
        int sum = 0;
        for(int i = 0; i < size; i++){
            int temp = s.top();
            s.pop();
            sum += temp;
        }
        cout << sum;
    }

    return 0;
}
