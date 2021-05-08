#include <iostream>

int gcd_naive(int a, int b) {
    if (a != 0 && b != 0)
    {
       int temp =  a % b;
       a = b;
       b = temp;
       gcd_naive(a, b);
    }
    else
    {
        return a;
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;
    int solution = gcd_naive(a, b);
    std::cout << solution<< std::endl;
    return 0;
}
