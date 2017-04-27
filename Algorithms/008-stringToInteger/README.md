Atoi

**Problem:** 
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.


## Solution
**注意事项：**
要考虑函数能够处理所有情况
1. 能够正确处理的字符包括数字0-9和+，-符号
2. 忽略数字和+，-号出现前的所有空格。
3. 一旦数字或+,-号出现后，视为有效字符串开始，此后只能够接受数字。如果出现其他字符，则跳出循环，返回当前转换完成的数字。
4. 如果没有可转换的字符，返回0.
5. 如果超出数字返回，超出最大值，返回2147483647，超出最小值，返回-2147483648
