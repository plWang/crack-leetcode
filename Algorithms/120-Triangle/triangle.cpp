#include <iostream>
#include <vector>

#define INT_MAX 10000;

using namespace std;

// Solution 1: top-down
// int minimumTotal(vector<vector<int> >& triangle) {
//     int m = triangle.size();
//     if (m==1) return triangle[0][0];
//     vector<vector<int> > dp;
//     for (int i=0; i<m; i++) { //initialize with all 0
//         vector<int> tmp(i+1, 0);
//         dp.push_back(tmp);
//     }

//     dp[0][0] = triangle[0][0];
//     for (int i=1; i<m; i++) {
//         for (int j=0; j<i+1; j++) {
//             int start = (j-1 < 0)?0:j-1;
//             int end = (j>i-1)?i-1:j;
//             int minSum = INT_MAX;
//             for (int k=start; k<=end; k++) {  //find all ways
//                 int sum = dp[i-1][k] + triangle[i][j];
//                 if (sum < minSum) minSum = sum;
//             }
//             dp[i][j] = minSum;
//         }
//     }

//     int minSum = INT_MAX;
//     for (int i=0; i<dp[m-1].size(); i++) {
//         if (dp[m-1][i] < minSum) 
//             minSum = dp[m-1][i];
//     }
//     return minSum;

// }


//Solution 2: bottom-up
int minimumTotal(vector<vector<int> >& triangle) {
    int m = triangle.size();
    vector<int> minPath(m, 0);
    for (int k=m-1; k>=0; k--) {
        for (int i=0; i<=k; i++) {
            if (k==m-1) minPath[i] = triangle[k][i];
            else {
                minPath[i] = min(minPath[i], minPath[i+1]) + triangle[k][i];
            }
        }
    }

    return minPath[0];
}


int main() {
    vector<vector<int> >triangle;
    int arr1[] = {-1};
    int arr2[] = {2, 3};
    int arr3[] = {0,1,2,3};
    vector<int> row1(arr1, arr1+sizeof(arr1)/sizeof(int));
    vector<int> row2(arr2, arr2+sizeof(arr2)/sizeof(int));
    vector<int> row3(arr3, arr3+sizeof(arr3)/sizeof(int));
    triangle.push_back(row1);
    triangle.push_back(row2);
    triangle.push_back(row3);

    int res = minimumTotal(triangle);
    cout << res;
}