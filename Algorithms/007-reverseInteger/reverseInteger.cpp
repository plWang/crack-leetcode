#include <iostream>
#include <stdlib.h>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int tmp;
        while (x != 0){
            tmp = result * 10 + x%10;
            x = x / 10;
            if (result != tmp /10) { // 判断是否溢出
                result = 0;
                break;
            }
            result = tmp;
        }
        return result;
    }
};


int main() {
    Solution solution;
    int a;
    cin >> a;
    int result = solution.reverse(a);
    cout << result << endl;
    return 0;
}
