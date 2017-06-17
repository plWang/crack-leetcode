## Problem 

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

- Best Time To Buy And Sell Stock I: 只允许买卖一次
- Best Time To Buy And Sell Stock II: 不限制买卖次数，但同时只能持有一支股票（当然可以同天卖出然后同天买入）
- Best Time To Buy And Sell Stock III: 允许最多两次买卖，但同时只能持有一支股票（当然可以同天卖出然后同天买入）

### Solution

I: 动态规划算法

记录从开始到当前天的最小价格和最大收入。

对当前天来说，最大收入

maxPro = max(maxPro, prices[i]-minPrices)


II: 不限制买卖次数，只需把diff>0的加起来就可以了。

III: 

只允许最多两次买卖，那么可以将prices按照当前天i分为两个部分，然后在两个部分分别用问题I的方法求解。
然后两部分的最大值相加就是最大的利润。
从前向后遍历一遍可以获得maxLeftProfit, 然后从后向前遍历一遍可以获得maxRightProfif。