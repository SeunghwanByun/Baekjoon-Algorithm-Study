#include <iostream>
#include <cstdio>

using namespace std;

bool find_prime_num(int n){
    if(n == 1)
        return false;

    for(int i = 2; i < n; ++i){
        if(n % i == 0)
            return false;
    }

    return true;
}

int main(){
    int M, N;
    scanf("%d %d", &M, &N);

    int sum = 0, min = 0;
    bool check = false;
    for(int i = M; i <= N; ++i){
        if(find_prime_num(i)){
            if(check == false){
                check = true;
                min = i;
            }

            sum += i;
        }
    }

    if(check == false)
        printf("-1");
    else{
        printf("%d\n%d", sum, min);
    }

    return 0;
}
