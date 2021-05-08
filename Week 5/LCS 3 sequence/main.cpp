#include <iostream>
#include <vector>

using namespace std;
int maximum(int a, int b, int c) {
    return (max(max(a, b), c));
}
int lcs3(vector<int>& a, vector<int>& b, vector<int>& c) {
    int n = a.size();
    int m = b.size();
    int o = c.size();

    int table[n + 1][m + 1][o + 1];

    for (int i = 0; i <= n;i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= o; k++) {
                if (i == 0 || j == 0 || k == 0)
                    table[i][j][k] = 0;
                else if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
                    table[i][j][k] = table[i - 1][j - 1][k - 1] + 1;
                else
                    table[i][j][k] = maximum(table[i - 1][j][k], 
                                             table[i][j - 1][k], 
                                            table[i][j][k - 1]);


            }
        }
    }
    return table[n][m][o];
}

int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++) {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++) {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++) {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}
