#include <iostream>
using namespace std;
int cnt = 0;
void print(string name, int n)
{
    if (cnt == n)
        return;
    cnt++;
    cout << name << endl;
    print(name, n);
}

int main()
{
    print("tanveer", 3);
}