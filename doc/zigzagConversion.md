
**Problem**:
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


思路：
主要就是找数学规律。

n=3时
```
    0   
    1 3
    2
```

n=4时
```
    0     
    1   5
    2 4
    3
```

n=5时
```
    0       
    1     7
    2   6
    3 5
    4
```


首先观察到每个三角形状的重复。三角形大小是2*numRows - 2。
除了第一行和最后一行只有一个元素外，其他行都有两个元素。

输出时，按照行遍历 j=0,1,...,numRows-1
然后，遍历每个三角形，TRI_size=2*numRows - 2.三角形的第一个元素为i=0,TRI_size,2*TRI_size,...
每一行的第一个元素就是i+j
第二个元素是i+TRI_size-j
