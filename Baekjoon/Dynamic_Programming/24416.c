#include <stdio.h>

int global_count_func1 = 0;
int global_count_func2 = 0;

int fib_recursive(int n){
    if(n == 1 || n == 2){
        global_count_func1++;
        return 1;
    }else{
        return (fib_recursive(n - 1) + fib_recursive(n - 2));
    }
}

int fibonacci_array[40] = {0};
int fib_dynamic_programming(int n){
    fibonacci_array[1] = 1;
    fibonacci_array[2] = 1;
    
    for(int i = 3; i <= n; i++){
        fibonacci_array[i] = fibonacci_array[i - 1] + fibonacci_array[n - 2];
        global_count_func2++;
    }
    
    return fibonacci_array[n];
}

int main(){
    int n = 0;
    scanf("%d", &n);
    
    fib_recursive(n);
    fib_dynamic_programming(n);
    
    printf("%d %d\n", global_count_func1, global_count_func2);
    return 0;
}
