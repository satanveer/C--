#include <iostream>
using namespace std;

void print(int arr[],int n){
    int len= sizeof(arr)/sizeof(arr[0]);
    if(len==1){
        cout<<arr[0];
    }
    len--;
    int temp;
    temp=arr[n];
    arr[n]=arr[len];
    arr[len]=temp;

    print(arr,n-1); 

}