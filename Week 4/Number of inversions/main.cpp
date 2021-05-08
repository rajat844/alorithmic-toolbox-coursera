#include <iostream>
#include <vector>

using std::vector;

void merge(vector<int>& a, int left, int m, int right, int& inversions) {
  int n1 = m - left + 1;
  int n2 = right - m;
  vector<int> L(n1);
  vector<int> R(n2);
  for (int i = 0; i < n1; i++)
    L[i] = a[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = a[m + 1 + j];


  int i = 0; int j = 0;int k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    }
    else {
      a[k] = R[j];
      j++;
      inversions = inversions + (m +1 - left - i);
    }
    k++;
  }
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(vector<int>& a, size_t left, size_t right, int& inversions) {

  if (left >= right)
    return;
  int m = left + (right - left) / 2;
  merge_sort(a, left, m, inversions);
  merge_sort(a, m + 1, right, inversions);
  merge(a, left, m, right, inversions);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int inversions = 0;
  merge_sort(a, 0, n - 1, inversions);
  std::cout << inversions;
  return 0;

}