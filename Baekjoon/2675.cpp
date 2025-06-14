#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> arrInt;
    vector<string> arrString;

    for(int i = 0; i < N; i++){
        int tempInt;
        string tempString;
        cin >> tempInt >> tempString;

        arrInt.push_back(tempInt);
        arrString.push_back(tempString);
    }

    for(int t = 0 ; t < arrInt.size(); t++){
        for(int s = 0; s < arrString[t].size(); s++){
            for(int i = 0; i < arrInt[t]; i++){
                cout << arrString[t][s];
            }
        }
        cout << endl;
    }

    return 0;
}
