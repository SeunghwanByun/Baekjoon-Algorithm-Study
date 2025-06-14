#include <iostream>

int arr[100000];

// 두 배열의 합병
void merge(int list[], int left, int mid, int right){
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;
    
    // list의 합병
    while(i <= mid && j <= right){
        if(list[i] <= list[j])
            arr[k++] = list[i++];
        else
            arr[k++] = list[j++];
    }
    
    // 한 쪽 부분에 남은 값들 복사
    if (i > mid) {
        for (l = j; l <= right; l++)
            arr[k++] = list[l];
    }
    else{
        for (l = i; l <= mid; l++)
            arr[k++] = list[l];
    }
    
    // 인자로 온 배열에 값 복사
    for(l = left; l <= right; l++)
        list[l] = arr[l];
}

// 합병 정렬
void merge_sort(int list[], int left, int right){
    int mid;
    if (left < right){
        mid = (left + right) / 2;
        merge_sort(list, left, mid); // 분할
        merge_sort(list, mid + 1, right); // 분할
        merge(list, left, mid, right);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    int N;
    
    std::cin >> N;
    
    int* arr = new int[N];
    
    for(int i = 0; i < N; i++)
        std::cin >> arr[i];
    
    merge_sort(arr, 0, N - 1);
    
    for(int i = 0; i < N; i++)
        std::cout << arr[i] << std::endl;
    
    return 0;
}
