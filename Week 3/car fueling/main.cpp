#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int>& stops)
{
    int initial = 0;
    int refuel = 0;
    while (dist > initial)
    {
        initial = initial + tank;
        if (initial >= dist)
            return refuel;
        while (dist > initial)
        {
            if (stops.size() == 0)
                return -1;
            if (stops[0] > initial)
                return -1;
            else
            {
                int position = 0;
                int i = stops.size();
                while(initial < stops[i-1])
                {
                    i--;
                }
                position = i - 1;
                initial = stops[position];
                stops.erase(stops.begin(), stops.begin() + position+1);
                refuel = refuel + 1;
                break;
            }
        }
    }
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    sort(stops.begin(), stops.end());
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
