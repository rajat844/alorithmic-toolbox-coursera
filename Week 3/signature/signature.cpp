#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using namespace std;

bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.second < b.second);
}

vector<int> optimal_points(vector<pair<int, int>> points) {
    vector<int> intersection;

    while (points.size() != 0) {
        int index = 0;
        int a = points[index].second;
        intersection.push_back(a);
        points.erase(points.begin() + index);
        for (size_t i = 0; i < points.size();i++) {
            if (a >= points[i].first && a <= points[i].second) {
                points.erase(points.begin() + i);
                i = i - 1;
            }
        }
    }
    return intersection;
}



int main() {
    int n;
    std::cin >> n;
    vector<pair<int, int>> points(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end(), sortbysec);
    vector<int> solution = optimal_points(points);
    cout << solution.size() << endl;
    for (size_t i = 0; i < solution.size(); i++) {
        cout << solution[i] << " ";
    }
    return 0;
}
