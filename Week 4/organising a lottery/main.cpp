#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> fast_count_segments(vector<pair<int, int>> segments, vector<int> points, int n, int m) {
  sort(segments.begin(), segments.end());
  vector<int> cnt(points.size());
  for (int i = 0;i < m;i++) {
    int segment_count = 0;
    for (int j = 0;j < n;j++) {
      if (points[i] >= segments[j].first && points[i] <= segments[j].second)\
        segment_count++;
      else if (points[i] < segments[j].first)
        j = n;
    }
    cnt[i] = segment_count;
  }


  return cnt;
}

// vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
//   vector<int> cnt(points.size());
//   for (size_t i = 0; i < points.size(); i++) {
//     for (size_t j = 0; j < starts.size(); j++) {
//       cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
//     }
//   }
//   return cnt;
// }

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<pair<int, int>> segments;
  for (size_t i = 0; i < n; i++) {
    int a; int b;
    std::cin >> a >> b;
    segments.push_back(make_pair(a, b));
  }
  vector<int> points(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(segments, points, n, m);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
