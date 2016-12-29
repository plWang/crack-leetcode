#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int count;
    int plus = 1;
    int i;
    for (i=digits.size()-1; i >= 0 ; i--) {
        if (plus == 1) {
            digits[i] += 1;
            if (digits[i] == 10) {
                digits[i] = 0;
                plus = 1;
            }
            else plus = 0;
        }
    }
    std::vector<int>::iterator it = digits.begin();
    if (i < 0 && plus == 1) digits.insert(it, 1);
    return digits;
}

int main() {
    vector<int> digits;
    vector<int> result;
    int len, a;
    cout << "Pleast input the length of the array" << endl;
    cin >> len;
    for (int i=0; i<len; i++) {
        cin >> a;
        digits.push_back(a);
    }
    result = plusOne(digits);
    for (int i=0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}