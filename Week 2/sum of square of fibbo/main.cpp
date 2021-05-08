#include <iostream>
#include <algorithm>
#include <array>


using namespace std;
int pisanoperiod()
{
    long long a = 0;
    long long b = 1;
    long long temp = a + b;
    for (int i = 0; i < (10 * 10); i++)
    {
        temp = (a + b) % 10;
        a = b;
        b = temp;
        if (a == 0 && b == 1)
        {
            return i + 1;
        }
    }
}



long long fibonacci_sum_naive(long long m)
{
    m = m % pisanoperiod();
    long long int fibbonacci[m];
    fibbonacci[0] = 0;
    fibbonacci[1] = 1;
    for (long long i = 2; i <= m; i++)
    {
        fibbonacci[i] = (fibbonacci[i - 1] + fibbonacci[i - 2]);
    }
    return (fibbonacci[m]) % 10;
}

int
main()
{
    long long n;
    std::cin >> n;

    long long sum = (fibonacci_sum_naive(n) * fibonacci_sum_naive(n + 1));
    sum = sum % 10;
    std::cout << sum << endl;
    return 0;
}