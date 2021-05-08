#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cfloat>

using namespace std;

double dist(pair<int, int> a, pair<int, int>b) {
  return (sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)));
}

double bruteForce(vector<pair<int, int>>& point, int right, int left) {
  double min = DBL_MAX;
  for (int i = left; i < right;++i) {
    for (int j = i + 1;j < right;++j) {
      if (dist(point[i], point[j]) < min)
        min = dist(point[i], point[j]);
    }
  }
  return min;
}

bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}

double stripclosest(vector<pair<int, int>>& strip, int size, double d) {
  sort(strip.begin(), strip.end(), sortbysec);

  for (int i = 0; i < strip.size(); ++i) {
    for (int j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < d; ++j) {
      if (dist(strip[i], strip[j]) < d)
        d= dist(strip[i], strip[j]);
    }
  }
  return d;
}

double minimal_distance(vector<pair<int, int>>& point, int left, int right) {
  //write your code here
  if ((right - left) <= 3)
    return (bruteForce(point, right, left));

  int mid = left + (right - left) / 2;

  double dl = minimal_distance(point, left, mid);
  double dr = minimal_distance(point, mid, right);

  double d = min(dl, dr);

  int n = right - left;
  pair<int, int> midpoint = point[left + (n / 2)];
  vector<pair<int, int>> strip;
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (abs(point[left + i].first - midpoint.first) < d) {
      strip.push_back(point[left + i]);
      j++;
    }
  }
  double d1 = stripclosest(strip, j, d);
  double mindistance = min(d,d1);
  return mindistance;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<pair<int, int>>point(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> point[i].first >> point[i].second;
  }
  sort(point.begin(), point.end());
  std::cout << std::fixed;
  std::cout << std::setprecision(15) << minimal_distance(point, 0, n) << "\n";
}
