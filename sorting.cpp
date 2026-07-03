#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int mini = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}

void bubblesort(int arr[], int n){
    for(int i=0 ; i<n-1 ; i++){
        int didswap=0;
        for(int j=0 ; j<n-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap=1;
            }  
        }
        if(didswap ==0){
            break;
        }
    }
}

void insertionsort(int arr[], int n){
    for(int i=0; i<=n-1 ; i++){
        int j;
        j=i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

void merge(vector<int> &arr, int low, int mid, int high)[
    vector<int> temp;
    int left = low;
    int right = mid+1;
    


]
void ms(vector<int> &arr , int low, int high){
    if(low == high)return;
    int mid=(low+high) / 2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // selectionsort(arr, n);
    // bubblesort(arr,n);
    insertionsort(arr,n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}