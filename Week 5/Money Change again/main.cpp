#include <iostream>

using namespace std;

int get_change(int m) {
  int coins[]{ 1,3,4 };
  int change[m + 1];
  change[0] = 0;

  for (int i = 1; i <= m; i++)
    change[i] = INT16_MAX;

  for (int i = 1;i <= m; i++) {
    for (int j = 0; j < 3;j++) {
      if (coins[j] <= i) {
        int part = change[i - coins[j]];
        if (part != INT16_MAX && part + 1 < change[i])
          change[i] = part + 1;
      }
    }
  }

  return change[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
