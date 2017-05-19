#include <iostream>
#include <string>
#include <vector>
#include "stdlib.h"

using namespace std;

bool isValid(string s) {
    if (s.size() > 0 && s.size() <= 3) {
        if (s.size() == 1) return true;
        if (s.size() == 2 && s[0] > '0') return true;
        if (s.size() == 3 && s[0] > '0' && atoi(s.c_str()) <= 255)
            return true;
        else return false;
    }
    else return false;
}

void backtrack(vector<string>& solutions, string& tempsol, int& n, int begin) {
    if (n > 3) return;
    if (n == 3) {
        if (begin < tempsol.size() && isValid(tempsol.substr(begin, tempsol.size()-begin))) {
            solutions.push_back(tempsol);
        }
        return;
    }

    for (int i=0; i < 3 && begin+i<tempsol.size(); i++) {
        if (isValid(tempsol.substr(begin, i+1))) {
            tempsol.insert(begin+i+1, ".");
            n++;
            backtrack(solutions, tempsol, n, begin+i+2);
            tempsol.erase(begin+i+1, 1);
            n--;
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> solutions;
    string tempsol = s;
    int n=0;
    backtrack(solutions, tempsol, n, 0);

    return solutions;
}

int main() {
    string s;
    cin >> s;
    vector<string> result = restoreIpAddresses(s);
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}