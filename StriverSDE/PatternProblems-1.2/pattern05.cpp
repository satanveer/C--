#include <iostream>
using namespace std;
void pattern(int n)

{
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
   
}
int main()
{
   pattern(4);
}