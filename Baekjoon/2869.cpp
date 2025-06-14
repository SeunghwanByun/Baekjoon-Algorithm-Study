#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, V;

    cin >> A >> B >> V;

    if((V - B) % (A - B) == 0)
        cout << (V - B) / (A - B);
    else
    {
        cout << (V - B) / (A - B) + 1;
    }
    
    return 0;
}
