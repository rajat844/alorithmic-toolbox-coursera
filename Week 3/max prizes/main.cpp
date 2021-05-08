#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;
using namespace std;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    //write your code here
    int i = 1;
    while (accumulate(summands.begin(), summands.end(), 0) < n) {
        summands.push_back(i);
        i = i + 1;
    }
    if (accumulate(summands.begin(), summands.end(), 0) == n)
        return summands;
    else {
        summands.pop_back();
        summands.pop_back();
        int sum = accumulate(summands.begin(), summands.end(), 0);
        int last = n - sum;
        summands.push_back(last);
        return summands;
    }
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
