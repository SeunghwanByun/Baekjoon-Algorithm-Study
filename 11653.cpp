#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int NUM;
    scanf("%d", &NUM);

    int i = 2;
    while(NUM != 0 && i <= NUM){
        if(NUM % i == 0){
            NUM /= i;
            printf("%d\n", i);
            i = 2;
        }
        else{
            i++;
        }
    }

    return 0;
}
