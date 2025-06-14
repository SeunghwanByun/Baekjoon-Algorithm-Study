#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    string subject = "666";
    int i = 666;
    int order = 1;
    while(true){
        if(std::to_string(i).find(subject) != string::npos){
            if(order == N)
                break;
            else
                order++;
            
        }
        i++;
    }

    cout << i << endl;

    return 0;
}
