## Climbing stairs

### Problem

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


### Solution

1. 递归算法
最简单的想法就是递归解法，每步都有两种选择，对于每种走法之后又各有两种走法。
写成递归代码也非常简单

```c++
int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbStairs(n-1) + climbStairs(n-2);
}
```

但是递归算法的速度非常慢，因为它重复计算了很多分支。

2. 动态规划问题
这个问题同样可以看作一个动态规划问题。要求第n阶的走法，我们只需要知道走到第n-1阶和第n-2阶的走法就可以了。使用动态规划的填表法可以提高效率。

```c++
int climbStairs(int n)  
    {  
        vector<int> res(n+1);  
        res[0] = 1;  
        res[1] = 1;  
        for (int i = 2; i <= n; i++)  
        {  
            res[i] = res[i-1] + res[i-2];  
        }  
        return res[n];  
    }  
```

但是上面的解法的空间复杂度很高，我们需要存储每一级的走法，实际上只需要三个变量就可以了。因为上面的问题实际上是一个Fibonacci数列问题，只不过起始的两个数是1和2而已。

```c++
int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int a = 1;
    int b = 2;
    int c = 0;
    for (int i=3; i<=n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
```
