#include <bits/stdc++.h>

    int linearSearch(int arr[],int n,int key){

        for(int i = 0; i < n;i++){
            if(arr[i] == key){
                return i;
            }
        }
        return -1;
    }

    int binarySearch(int arr[],int n,int key ){

        int s = 0;
        int e = n-1; 
        
        while(s <= e){
            int mid = (s+e)/2;


            if(arr[mid] == key){
                return mid;
            }
            else if(arr[mid] > key){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }

        }
        return -1;
        


    }
using namespace std;

int main(){

    int arr[] = {10,30,40,50,60,70,80};
    int n = 7;
    int key = 70;

    int ans = binarySearch(arr,n,key);

    cout << ans << endl;
    return 0;
}
