#include <iostream>
#include <cstdio>

using namespace std;

bool find_prime_num(int n){
    for(int i = 2; i < n; ++i){
        if(n % i == 0)
            return false;
    }

    return true;
}

int main(){
    int N;
    scanf("%d", &N);

    int count = 0;
    for(int i = 0; i < N; ++i){
        int temp;
        scanf("%d", &temp);

        if(temp == 1)
            continue;
        
        else{
            if(find_prime_num(temp))
                count++;
        }
    }

    printf("%d", count);

    return 0;
}
