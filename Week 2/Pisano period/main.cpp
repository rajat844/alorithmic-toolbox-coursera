#include <iostream>
using namespace std;

long long pisano_period(long long m)
{
    long long a = 0, b = 1, temp = a + b;
    for (int i = 0; i < (m * m); i++)
    {
        temp = (a + b) % m;
        a = b;
        b = temp;
        if (a == 0 && b == 1)
        {
            return i + 1;
        }
    }
}

long long get_fibonacci_huge_naive(long long n, long long m)
{
    long long remainder = n % pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long temp = remainder;

    for (int i = 1; i < remainder; i++) {
        temp = (first + second) % m;
        first = second;
        second = temp;
    }
    return temp % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
