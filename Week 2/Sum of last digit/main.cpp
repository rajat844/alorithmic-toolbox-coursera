#include <iostream>
using namespace std;


int fibonacci_sum_naive(long long n) 
{
    n = (n + 2) % 60;
    int fibbonacci[n];
    fibbonacci[0] = 0;
    fibbonacci[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibbonacci[i] = (fibbonacci[i - 1] % 10 + fibbonacci[i - 2] % 10) % 10;
    }
    if (fibbonacci[n] == 0)
        return 9;
    else
        return (fibbonacci[n]% 10)-1 ;

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
