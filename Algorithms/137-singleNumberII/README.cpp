## Problem

Given an array of integers, every element appears three times 
except for one, which appears exactly once. Find that single one.

## Solution 
用三个32位的整数ones, twos, threes分别记录各个位上1出现次数为1次、2次、3次的值。
当出现3次时该位清零，最后答案就是ones的值。

各位的变化规则：
twos |= ones & nums[i]  //ones和nums[i]都为1时，twos的对应位为1
ones ^= nums[i]  //ones和nums[i]都为1时，进位到twos, ones相应位为0；只有当二者不同（一个为0，一个为1）时
                 // ones对应位才为1
three &= ones & twos;  // ones和twos对应位都为1则threes
ones &= ~threes   // ones中与twos相加等于3的位清零
twos &= ~threes