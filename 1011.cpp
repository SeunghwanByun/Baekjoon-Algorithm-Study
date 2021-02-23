#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; ++i){
        long long x, y;
        cin >> x >> y;

        long long move, max = 0;
        while(max * max <= y - x)
            max++;
        max--;

        move = 2 * max - 1;
        long long rest_dist = y - x - max * max;

        rest_dist = (long long)ceil((double)rest_dist / (double)max);

        move += rest_dist;

        printf("%lld\n", move);        
    }

    return 0;
}
