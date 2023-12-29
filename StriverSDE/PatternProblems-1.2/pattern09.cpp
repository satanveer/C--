#include <iostream>
using namespace std;

void pattern(int x){
    for(int i=0;i<x;i++){
        for(int j=0;j<x-i;j++){
            cout<<" ";
        }
        for(int k=0;k<2*i+1;k++){
            cout<<"*";
        }
        for(int l=0;l<x-i;l++){
            cout<<" ";
        }
        cout<<endl;

    }
}
void pattern2(int n){
    
    for(int i=0;i<n;i++){
        cout<<" ";
        for(int k=0;k<i;k++){
            cout<<" ";
        }
        for(int j=0;j<2*n-(2*i+1);j++){
            cout<<"*";
        }
         for(int l=0;l<i;l++){
            cout<<" ";
        }
        
        cout<<endl;
        
    }
}
int main(){
    pattern(5);
    pattern2(5);
}
