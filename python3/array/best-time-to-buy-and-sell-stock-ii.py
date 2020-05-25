'''买卖股票的最佳时机 II
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

提示：

1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
'''

'''
思路一：从卖出看买入，如果第二天价格下降，则当天卖出，并且记录历史最低买入。第二天为新的历史最低买入。
注意天数为最后一天时，如果持续增，最后一天必定卖出。
时间复杂度：O(n)。
空间复杂度：O(1)。
'''
class Solution:
    def maxProfit(self, prices):
        if len(prices) < 2:
            return 0
        res = 0
        min = prices[0]
        for i in range(1, len(prices)):
            if prices[i] < prices[i - 1]:
                res += prices[i - 1] - min
                min = prices[i]
            elif i == len(prices) - 1:
                res += prices[i] - min
            else:
                continue
        return res

'''
思路二：贪心算法，从买入看卖出，连续天只要上涨就记入利润，直到不再上涨，则卖出。把可能跨越多天的买卖都化解成相邻两天的买卖。
时间复杂度：O(n)。
空间复杂度：O(1)。
参考：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/best-time-to-buy-and-sell-stock-ii-zhuan-hua-fa-ji/
'''
class Solution:
    def maxProfit(self, prices):
        if len(prices) < 2:
            return 0
        res = 0
        for i in range(len(prices) - 1):
            if prices[i] < prices[i + 1]:
                res += prices[i + 1] - prices[i]
        return res