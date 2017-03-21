#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int len = 0;
    if (nums.size() == 0) return 0;
    vector<int>::iterator it;
    
    for (it = nums.begin(); it < nums.end(); ) {
        if (*it == val) {
            it = nums.erase(it);
        }
        else {
            it++;
        }
    }

    return nums.size();
}

/*
//Another implements: use two pointers
int removeElement(int A[], int n, int elem) {  
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    int cur = 0;  
    for(int i =0; i< n; i++)  
    {  
      if(A[i] == elem)  
        continue;  
      A[cur]=A[i];  
       cur++;  
     }  
     return cur;  
}
*/ 

int main() {
    vector<int> nums;
    int n, tmp;
    cout << "Please input the length of list: ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    int val;
    cout << "Please input the number you want to remove: ";
    cin >> val;
    int length = removeElement(nums, val);
    cout << "length = " << length << endl;

    for (int i=0;i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}