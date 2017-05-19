## Problem

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

## Solution

这是一个动态规划问题。
有两种思路。

1. Top-Down
一种是top-down的思路，从三角形的顶点开始出发，计算到达下面各个节点所需的最短路径。到达每个节点有两种路径, 如下图所示
x y
 k

dp[i][k] = min(dp[i-1][x], dp[i-1][y]) + triangle[i][k]; 

然而这种方法所需的存储空间与三角形的大小一样，因此空间复杂度为O(N^2)。

```c++
int minPathSum(vector<vector<int> >& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    if (n == 0) return 0;

    vector<vector<int> > dp(m, vector<int>(n, 0));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (i==0) {
                if (j==0) dp[i][j] = grid[i][j];
                else dp[i][j] = dp[i][j-1] + grid[i][j];
            }
            else {
                if (j==0) dp[i][j] = grid[i][j] + dp[i-1][j];
                else dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[m-1][n-1];
}
```

2. Bottom-up
另外一种思路是bottom-up的方法，从三角形底边出发。对于一个节点k, 它有两个子节点x, y，如下图所示。

 k
x y

所以minpath[i][k] = min(minpath[i+1][x], minpath[i+1][y]) + triangle[i][k]
而且，由于minpath[i]计算完之后，minpath[i+1]的值就不再有用，因此我们可以只使用一个一维的数组，然后迭代更新。

对第k层来说
minpath[i] = min(minpath[i], minpath[i+1]) + triangle[k][i]

```c++
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
```