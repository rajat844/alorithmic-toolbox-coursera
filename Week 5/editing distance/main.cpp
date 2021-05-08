#include <iostream>
#include <string>
#include <vector>


using namespace std;


int minimum(int x, int y, int z) {
  return min(min(x, y), z);
}

int edit_distance(const string& str1, const string& str2) {
  //write your code here
  
  int n = str1.length();
  int m = str2.length();
  int table[n+1][m+1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <=m;j++) {
      if (i == 0)
        table[i][j] = j;
      else if (j == 0)
        table[i][j] = i;
      else if (str1[i - 1] == str2[j - 1])
        table[i][j] = table[i - 1][j - 1];
      else
        table[i][j] = 1 + minimum(table[i][j - 1], table[i - 1][j], table[i - 1][j - 1]);
    }
  }
  return table[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
}
