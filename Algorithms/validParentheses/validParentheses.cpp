#include <iostream>
#include <vector>

using namespace std;

bool isValid(string s) {
    vector<char> stack;
    for (int i=0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack.push_back(s[i]);
        }
        else {
            if (stack.size() == 0) return false;
            switch (s[i]) {
                case ')': {
                    if (stack.back() != '(') return false;
                    else stack.pop_back();
                    break;
                }
                case ']': {
                    if (stack.back() != '[') return false;
                    else stack.pop_back();
                    break;
                }
                case '}': {
                    if (stack.back() != '{') return false;
                    else stack.pop_back();
                    break;
                }
            }
        }
    }
    if (stack.size() == 0) return true;
    else return false;
}

int main () {
    string s;
    cin >> s;
    bool res = isValid(s);
    if (res) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}