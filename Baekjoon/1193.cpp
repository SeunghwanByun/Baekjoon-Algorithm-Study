#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int value = 1, order = 1;
    int i = 1;
    while(true){
        if(n - i <= 0)
            break;
        n -= i;
        order = n;
        i++;

        value = i;
    }
    
    if(value % 2 == 0)
        cout << order << "/" << value - order + 1;
    else
    {
        cout << value - order + 1 << "/" << order;
    }

    return 0;
}
