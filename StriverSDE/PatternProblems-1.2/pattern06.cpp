#include <iostream>
using namespace std;
void pattern(int n)

{
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i+1;j++){
            cout<<j;
        }
        cout<<endl;
    }
   
}
int main()
{
   pattern(4);
}