#include <iostream>
#include <vector>
using namespace std;


int get_change(int m)
{
    int a{ 0 }, b{ 0 }, c{ 0 };
    a = m / 10;
    m = m % 10;
    b = m / 5;
    m = m % 5;
    c = m / 1;
    int n = a + b + c;
    return n;
}

int main()
{
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
