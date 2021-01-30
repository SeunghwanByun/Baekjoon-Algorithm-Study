#include <iostream>

using namespace std;

int main(){
    int x1, y1, x2, y2, x3, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int x_coord[1000] = {0, };
    int y_coord[1000] = {0, };
    
    x_coord[x1]++;
    x_coord[x2]++;
    x_coord[x3]++;

    y_coord[y1]++;
    y_coord[y2]++;
    y_coord[y3]++;

    int x4, y4;
    for(int i = 0; i < 1000; i++){
        if(x_coord[i] == 1)
            x4 = i;
        if(y_coord[i] == 1)
            y4 = i;
    }

    cout << x4 << " " << y4;

    return 0;
}
