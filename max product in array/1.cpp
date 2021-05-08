// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MaxPairwiseProduct(const std::vector<int>& numbers)
{
    int result = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second)
        {
            if (((long long)numbers[first] * numbers[second] > result))
            {
                result = ((long long)numbers[first] * numbers[second]);
            }
        }
    }

    return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers)
{
    int n = numbers.size();
    long long  int result = 0;

    int a = -1;
    int b = -1;
    for (int i = 0; i < n; i++)
    {
        if (a== -1|| numbers[i] > numbers[a])
            a = i;
    }
    for (int i = 0; i < n; i++)
    {
        if ((i != a ) && ((b == -1 || (numbers[i] > numbers[b]))))
            b = i;
    }
    result = ((long long)(numbers[a])) * numbers[b];

    return result;

}

int main()
{   
   /* while (true)
    {
        int n = rand() % 1000 + 2;
        cout << n << "\n";
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
          a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << "\n";
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if (res1 != res2)
        {
            cout << "Wrong answer" << res1 << ' ' << res2 << endl;
            break;
        }
        else
            cout << "ok" << endl;
    }*/
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    

    long long int result = MaxPairwiseProductFast(numbers);
    cout << result << endl;
    return 0;
}