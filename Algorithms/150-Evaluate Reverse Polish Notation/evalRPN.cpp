#include <iostream>
#include <vector>
#include <string>

using namespace std;

int strToInt(string str) {
    int res = 0;
    bool sign = false;
    for (int i=0; i<str.size(); i++) {
        if (str[i] == '+') continue;
        if (str[i] == '-') {
            sign = true;
            continue;
        }
        res = res * 10 + (str[i]-'0');
    }

    if (sign) res = -res;

    return res;

}

int evalRPN(vector<string>& tokens) {
    vector<int> nums;
    int size = 0, tmp;
    for (int i=0; i<tokens.size(); i++) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            if (tokens[i] == "+") {
                tmp = nums[size-2] + nums[size-1];
            }
            else if (tokens[i] == "-") {
                tmp = nums[size-2] - nums[size-1];
            }
            else if (tokens[i] == "*") {
                tmp = nums[size-2] * nums[size-1];
            }
            else if (tokens[i] == "/") {
                tmp = nums[size-2] / nums[size-1];
            }
            nums.pop_back();
            nums.pop_back();
            nums.push_back(tmp);
            size--;
        }
        else {
            int num = strToInt(tokens[i]);
            nums.push_back(num);
            size++;
        }
    }

    return nums[0];
}

int main() {
    vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");

    int result = evalRPN(tokens);
    cout << result << endl;
    return 0;
}