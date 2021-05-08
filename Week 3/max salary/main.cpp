#include <iostream>
#include  <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool isGreater(string digit, string maxdigit) {
    if (digit + maxdigit >= maxdigit + digit)
        return true;
    else
        return false;
}

string largest_number(vector<string>a) {
    string result;
    stringstream ret;
    string test{ a[0] };
    while (a.size()) {
        string maxdigit("0");
        size_t index = 0;
        for (int digit = 0;digit < a.size();digit++) {
            if (isGreater(a[digit], maxdigit)) {
                maxdigit = a[digit];
                index = digit;
            }
        }
        ret << maxdigit;
        a.erase(a.begin() + index);
    }
    ret >>result;
    return result;
}


int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    cout << largest_number(a);
    return 0;
}
