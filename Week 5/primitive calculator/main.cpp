#include <iostream>
#include <vector>
#include <list>

using namespace std;

void calculator(int32_t number, vector<int32_t>& solution, vector<int32_t>& sequence) {
    solution[0] = 0;
    solution[1] = 0;
    sequence[0] = 0;
    sequence[1] = 1;
    for (int32_t i = 2; i <= number;i++) {
        solution[i] = solution[i - 1] + 1;
        sequence[i] = i - 1;

        if (i % 3 == 0) {
            if (solution[i / 3] < solution[i]) {
                solution[i] = solution[i / 3] + 1;
                sequence[i] = i / 3;
            }
        }
        if (i % 2 == 0) {
            if (solution[i / 2] < solution[i]) {
                solution[i] = solution[i / 2] + 1;
                sequence[i] = i / 2;
            }
        }

    }

}


int main() {
    int32_t input;
    cin >> input;
    vector<int32_t> solution(input + 1, INT32_MAX);
    vector<int32_t> sequence(input + 1);
    calculator(input, solution, sequence);
    cout << solution[input] << "\n";
    list<int32_t> ans;
    ans.push_front(input);
    for (int32_t i = input; i != 1; i--) {
        ans.push_front(sequence[i]);
        i = sequence[i] + 1;
    }

    for( auto it = ans.begin();it != ans.end();it++){
        cout<< *it <<" ";
    }
}