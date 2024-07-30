#include <iostream>
using namespace std;

int coun = 0;

void print()
{

    if (coun == 3)
    {
        return;
    }
    cout << coun <<endl;
    coun++;
    print();
}

int main(){
    print();
}