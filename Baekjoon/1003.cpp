#include <stdio.h>

long long fiboarr[50] = {0, 1, };

long long fibonacci(int n){
    if(n == 0 || n == 1){
        return fiboarr[n];
    }
    else if(fiboarr[n] == 0){
        fiboarr[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return fiboarr[n];
}

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; ++i){
        int temp;
        scanf("%d", &temp);

        if(temp == 0)
            printf("1 0\n");
        else
        {
            printf("%lld %lld\n", fibonacci(temp - 1), fibonacci(temp));
        }
    }

    return 0;
}
