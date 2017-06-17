#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int romanToInt(string s) {
    int n = s.length();
    int res = 0;
    int last = 10000;
    int acc = 0;
    int data;
    for (int i=0; i < n; i++) {
        switch (s[i]) {
            case 'I': {
                data = 1;
                break;
            }
            case 'V': {
                data = 5;
                break;
            }
            case 'X': {
                data = 10;
                break;
            }
            case 'L': {
                data = 50;
                break;
            }
            case 'C': {
                data = 100;
                break;
            }
            case 'D': {
                data = 500;
                break;
            }
            case 'M': {
                data = 1000;
                break;
            }
        }
        cout << "data= " << data <<", acc= "<< acc <<", res=" << res << endl;
        if (last > data) {
            res += data;
            last = data;
            acc = data;
        }
        else if (last == data) {
            res += data;
            last = data;
            acc += data;
        }
        else {
            res = res - 2*acc + data;
        }
    }
    return res;
}

int main() {
    string s;
    int a;
    cin >> s;
    a = romanToInt(s);
    cout << "result= " << a << endl;
    return 0;
}