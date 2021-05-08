#include <iostream>
using namespace std;

long long lcm_naive(int a, int b)
{
    if (a != 0 && b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
        lcm_naive(a, b);
    }
    else
    {
        return a;
    }
   
}

int main() 
{
    long long int a, b;
    std::cin >> a >> b;
    long long int multiple = a * b;
    long long int gcd = lcm_naive(a, b);
    long long int  lcm = multiple / gcd;
    std::cout << lcm  << std::endl;
    return 0;
}
