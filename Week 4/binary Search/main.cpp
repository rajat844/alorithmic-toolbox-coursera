#include <iostream>
#include <cassert>
#include <vector>
using std::vector;

long long int binary_search(vector<long long int> &a, long long int x, long long int left, long long int right)
{
	if (right >= left)
	{
		long long int m = (left + right) / 2;
		if (a[m] == x)
			return m;
		else if (a[m] > x)
			return binary_search(a, x, left, m - 1);
		else
			return binary_search(a, x, m + 1, right);
	}
	else
		return -1;
}

// int linear_search(const vector<int> &a, int x)
// {
// 	for (size_t i = 0; i < a.size(); ++i)
// 	{
// 		if (a[i] == x)
// 			return i;
// 	}
// 	return -1;
// }

int main()
{
	long long int n;
	std::cin >> n;
	vector<long long int> a(n);
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cin >> a[i];
	}
	long long int m;
	std::cin >> m;
	vector<long long int> b(m);
	for (int i = 0; i < m; ++i)
	{
		std::cin >> b[i];
	}
	long long int left = 0;
	long long int right = a.size();
	for (size_t i = 0; i < m; ++i)
	{
		int position = binary_search(a, b[i], left, right);
		std::cout<<position<<" "; 
		
	}
}
