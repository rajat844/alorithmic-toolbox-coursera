#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool isOperator(char op) {
    return (op == '+' || op == '-' || op == '*');
}

vector<long long> result(string s, map<string, vector<long long>> memo) {
    if (memo.find(s) != memo.end())
        return memo[s];
    vector<long long> res;
    for (int i = 0; i < s.size(); i++) {
        if (isOperator(s[i])) {
            vector<long long> resPre = result(s.substr(0, i), memo);
            vector<long long> resSuf = result(s.substr(i + 1), memo);

            for (int j = 0; j < resPre.size(); j++) {
                for (int k = 0; k < resSuf.size();k++) {
                    if (s[i] == '+')
                        res.push_back(resPre[j] + resSuf[k]);
                    else if (s[i] == '-')
                        res.push_back(resPre[j] - resSuf[k]);
                    else if (s[i] == '*')
                        res.push_back(resPre[j] * resSuf[k]);
                }
            }
        }
    }
    if (res.size() == 0)
        res.push_back(atoi(s.c_str()));
    memo[s] = res;
    return res;
}

vector<long long> possibleResult(string s) {
    map<string, vector<long long>> memo;
    return result(s, memo);
}


int main() {
    string s;
    std::cin >> s;
    vector<long long> res = possibleResult(s);
    long long temp{ INT32_MIN };
    for (int i = 0; i < res.size(); i++) {
        if (res[i] > temp) {
            temp = res[i];
        }
    }
    cout << temp;
    return 0;
}
