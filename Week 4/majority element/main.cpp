#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cin >> a[i];
    }
    sort(a.begin(), a.end());
    int max_count = 0;
    int check = a[0];
    int count{1};
    for (size_t i{1}; i < a.size(); i++)
    {
        if (check == a[i])
            count++;
        else
        {
            check = a[i];
            count = 1;
        }
        if(max_count<count)
        max_count = count;
    }
    if (max_count>n/2)
        std::cout << 1;
    else
        std::cout << 0;
}
