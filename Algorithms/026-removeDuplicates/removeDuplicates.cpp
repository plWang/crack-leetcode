#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int cur;
    int len = 0;
    vector<int>::iterator it;
    if (nums.size() == 0) return 0;

    cur = nums[0];
    len++;
    for (it=nums.begin()+1; it < nums.end(); ) {
        if (*it != cur) {
            len++;
            cur = * it;
            it++;
        }
        else {
            it = nums.erase(it);
        }
    }

    return len;
}

int main() {
    vector<int> nums;
    int n, tmp;
    cout << "Please input the length of list: ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    int length = removeDuplicates(nums);
    cout << "length = " << length << endl;

    for (int i=0;i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}