#include <iostream>
using namespace std;
int cnt = 0;
void print(int n)
{
    if (cnt == n)
    {
        return;
    }
    cnt++;
    cout << cnt;

    print(n);
}
int main()
{
    print(5);
}