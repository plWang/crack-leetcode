#include <iostream>
#include <vector>

using namespace std;

// vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     int i=0, j=0;
//     vector<int>::iterator it = nums1.begin();
//     int size1 = nums1.size();
//     if (m < size1) {
//         for (i=0; i<m; i++, it++);
//         it = nums1.erase(it, nums1.end());
//     }
//     it = nums1.begin();
//     i = 0;
//     while (j < n) {
//         if (i >= m) {
//             nums1.push_back(nums2[j]);
//             j++;
//         }
//         if (i < m) {
//             int a = *it;
//             int b = nums2[j];
//             if (a <= b) {
//                 i++;
//                 it++;
//             }
//             else {
//                 it = nums1.insert(it, nums2[j]);
//                 it++;
//                 j++;
//             }
//         }
//     }
//     return nums1;
// }

vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        }
        else {
            nums1[k--] = nums2[j--];
        }
    }
}


int main() {
    int m;
    int n;
    cout << "please input the length of nums1: ";
    cin >> m;
    cout << "please input the length of nums2: ";
    cin >> n;
    vector<int> nums1;
    vector<int> nums2;
    int a;
    for (int i=0; i<m; i++) {
        cin >> a;
        nums1.push_back(a);
    }
    for (int i=0; i<n; i++) {
        cin >> a;
        nums2.push_back(a);
    }

    vector<int> res = merge(nums1, m-1, nums2, n);

    for (int i=0; i<m+n; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
}