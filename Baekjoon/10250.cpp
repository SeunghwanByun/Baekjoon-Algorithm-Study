#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    vector<vector<int>> testCase;
    
    for(int i = 0; i < T; i++){
        int tempH, tempW, tempN;
        cin >> tempH >> tempW >> tempN;
        vector<int> tempCase;
        tempCase.push_back(tempH);
        tempCase.push_back(tempW);
        tempCase.push_back(tempN);
        
        testCase.push_back(tempCase);
    }

    for(int t = 0; t < T; t++){
        int count = 1;
        for(int w = 0; w < testCase[t][1]; w++){ // width
            for(int h = 0; h < testCase[t][0]; h++){ // height
                int offset = w * testCase[t][0] + h;
                if(offset == testCase[t][2] - 1){
                    if(w + 1>= 10)
                        cout << h + 1 << w + 1 << endl;
                    else
                    {
                        cout << h + 1 << "0" << w + 1 << endl;
                    }
                    
                    w = testCase[t][1];
                    break;
                }
            }
        }
    }

    return 0;
}
