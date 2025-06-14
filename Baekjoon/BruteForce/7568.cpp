#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    int * order = new int[N];
    fill_n(order, N, 1);

    vector<int> weight;
    vector<int> height;

    for(int i = 0; i < N; i++){
        int tempW;
        int tempH;
        cin >> tempW >> tempH;

        weight.push_back(tempW);
        height.push_back(tempH);        
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(weight[i] < weight[j] && height[i] < height[j])
                order[i]++;
        }
    }

    for(int i = 0; i < N; i++){
        cout << order[i] << " ";
    }

    delete order;

    return 0;
}
