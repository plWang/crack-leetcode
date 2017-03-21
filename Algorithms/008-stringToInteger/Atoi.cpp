#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str) {
    int result = 0;
    int neg_flag = 0;
    int start_flag = 0;
    int tmp;
    for (int i=0; i<str.length(); i++) {
        if (str[i] == ' ') { 
            if (start_flag == 1) break;
            continue;
        }
        if (str[i] == '+' || str[i] == '-') {
            if (start_flag != 0) break;
            start_flag = 1;
            if (str[i] == '-') neg_flag = 1;
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            start_flag = 1;
            tmp = result * 10 + (str[i]-'0');
            if (tmp/10 != result) {
                if (neg_flag == 1) result = -2147483648;
                else                result = 2147483647;
                return result;
            }
            result = tmp;
        }
        else 
            break;
    }
    if (neg_flag == 1) result = -result;
    return result;
}

int main() {
    int result;
    string str;
    cin >> str;
    result = myAtoi(str);
    cout << "the result is " << result <<endl;
}
