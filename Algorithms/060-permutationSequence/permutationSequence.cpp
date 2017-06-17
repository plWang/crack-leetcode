#include <iostream>
#include <vector>

using namespace std;

int multiply(int n) {
    if (n == 0 || n == 1) return 1;
    int res = 1;
    while (n)
        res *= (n--);

    return res;
}

void getPermutationCore(vector<char>& candidates, string& result, int n, int k) {
    if (n == 0) return;

    int i = (k-1)/multiply(n-1);
    result.push_back(candidates[i]);
    candidates.erase(candidates.begin()+i);
    k -= i*multiply(n-1);
    n--;
    getPermutationCore(candidates, result, n, k);
}

string getPermutation(int n, int k) {
    vector<char> candidates;
    for (int i=1; i<=n; i++)
        candidates.push_back(i+'0');

    string result = "";
    getPermutationCore(candidates, result, n, k);

    return result;
}

int main() {
    int n;
    cin >> n;
    cout << multiply(n) << endl;
}