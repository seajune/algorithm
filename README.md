- [数组](#数组)
    - [思路](#思路（数组）)
    - [两数之和](#两数之和)
    - [两数之和II-输入有序数组](#两数之和II-输入有序数组)
    - [三数之和](#三数之和)
    - [最大子序和](#最大子序和)
    - [买卖股票的最佳时机](#买卖股票的最佳时机)
    - [买卖股票的最佳时机II](#买卖股票的最佳时机II)
    - [爬楼梯](#爬楼梯)
    - [斐波那契数](#斐波那契数)
    - [整数反转](#整数反转)
    - [回文数](#回文数)
    - [合并两个有序数组](#合并两个有序数组)
    - [x的平方根](#x的平方根)
- [字符串](#字符串）)
    - [思路](#思路（字符串）)
    - [最长回文串](#最长回文串)
    - [最长回文子串](#最长回文子串)
- [链表](#链表)
    - [思路](#思路（链表）)
    - [反转链表](#反转链表)
    - [环形链表](#环形链表)
    - [合并两个有序链表](#合并两个有序链表)

# 数组
## 思路（数组）
* 空间换时间，可以借助哈希表。
* 可以定义两个索引（首尾索引），同时遍历。
* 可以基于有序的条件下进行。
* 动态规划算法。
* 分治法。
* 斐波那契数列，迭代法。
* 取余、取模。

## 两数之和
思路
* 空间换时间，借助字典。时间复杂度：O(n)，空间复杂度：O(n)。

题解
* [Python3](./python3/array/two-sum.py)
* [C++](./c++/array/two-sum.cpp)

## 两数之和II-输入有序数组
思路
* 首尾同时遍历。时间复杂度：O(n)，空间复杂度：O(1)。

题解
* [Python3](./python3/array/two-sum-ii-input-array-is-sorted.py)
* [C++](./c++/array/two-sum-ii-input-array-is-sorted.cpp)

## 三数之和
思路<br>
* 先排序，在遍历中，在剩余的数组元素中进行首尾的同时遍历。时间复杂度：O(n^2)，空间复杂度：O(1)。

题解
* [Python3](./python3/array/3sum.py)
* [C++](./c++/array/3sum.cpp)

## 最大子序和
思路<br>
* **动态规划算法**。时间复杂度：O(n)，空间复杂度：O(1)。
* 分治法。时间复杂度：O(nlogn)，空间复杂度：O(logn)。

题解
* [Python3](./python3/array/maximum-subarray.py)
* [C++](./c++/array/maximum-subarray.cpp)

## 买卖股票的最佳时机
思路<br>
* 动态规划算法，遍历元素，如果是在历史最低点买入的，则当天卖出时利润最高。故记录一个历史最低买入。时间复杂度：O(n)，空间复杂度：O(1)。

题解
* [Python3](./python3/array/best-time-to-buy-and-sell-stock.py)
* [C++](./c++/array/best-time-to-buy-and-sell-stock.cpp)

## 买卖股票的最佳时机II
思路<br>
* 从卖出看买入，如果第二天价格下降，则当天卖出，并且记录历史最低买入。第二天为新的历史最低买入。注意天数为最后一天时，如果持续增，最后一天必定卖出。时间复杂度：O(n)，空间复杂度：O(1)。
* **贪心算法**，从买入看卖出，连续天只要上涨就记入利润，直到不再上涨，则卖出。把可能跨越多天的买卖都化解成相邻两天的买卖。时间复杂度：O(n)，空间复杂度：O(1)。

题解
* [Python3](./python3/array/best-time-to-buy-and-sell-stock-ii.py)
* [C++](./c++/array/best-time-to-buy-and-sell-stock-ii.cpp)

## 爬楼梯
思路<br>
* 斐波那契数列，迭代法。时间复杂度：O(n)，空间复杂度：O(1)。

题解
* [Python3](./python3/array/climbing-stairs.py)
* [C++](./c++/array/climbing-stairs.cpp)

## 斐波那契数
思路<br>
* 斐波那契数列，迭代法。时间复杂度：O(n)，空间复杂度：O(1)。
* 斐波那契数列，递归法。如果数据大，会超时。

题解
* [Python3](./python3/array/fibonacci-number.py)

## 整数反转
思路<br>
* 取模。时间复杂度：O(lgn)，空间复杂度：O(1)。

题解
* [Python3](./python3/array/reverse-integer.py)
* [C++](./c++/array/reverse-integer.cpp)

## 回文数
思路<br>
* 比较一半：通过取整和取余操作获取整数中对应的数字进行比较，首尾相应数字比较。时间复杂度：O(lgn)，空间复杂度：O(1)。
* 比较一半：将数字进行对折后看能否一一对应，即取出后半段数字进行翻转。时间复杂度：O(lgn)，空间复杂度：O(1)。
* 将整数转为字符串。反转字符串，跟原字符串比较。
* 将整数转为字符串。字符串首尾相应位数进行比较。

题解
* [Python3](./python3/array/palindrome-number.py)
* [C++](./c++/array/palindrome-number.cpp)

## 合并两个有序数组
思路<br>
* 从m+n-1位置到0位置逆序依次存入。时间复杂度：O(m+n)，空间复杂度：O(m)。

题解
* [Python3](./python3/array/merge-sorted-array.py)
* [C++](./c++/array/merge-sorted-array.cpp)

## x的平方根
思路<br>
* 二分查找。时间复杂度：O(logn)，空间复杂度：O(1)。
* 牛顿迭代法。时间复杂度：O(logn)，空间复杂度：O(1)。

题解
* [Python3](./python3/array/sqrtx.py)
* [C++](./c++/array/sqrtx.cpp)

# 字符串
## 思路（字符串）
* 空间换时间，借助哈希表。
* 中间扩展。

## 最长回文串
思路<br>
* 借助map存储字符的个数，最长回文串长度为字符的最大偶数求和再加一。时间复杂度：O(n)，空间复杂度：O(s)。

题解
* [Python3](./python3/string/longest-palindrome.py)

## 最长回文子串
思路<br>
* 中心扩展法，回文子串长度为奇数、偶数时分别考虑。时间复杂度：O(n^2)，空间复杂度：O(1)。

题解
* [Python3](./python3/string/longest-palindromic-substring.py)
* [C++](./c++/string/longest-palindromic-substring.cpp)

# 链表
## 思路（链表）
* 迭代。从头开始遍历。
* 递归。使用栈空间，需要额外的空间复杂度。
* 快慢指针。

## 反转链表
思路<br>
* 迭代。从头遍历，箭头反转。时间复杂度：O(n)，空间复杂度：O(1)。
* 递归。使本节点的下一节点的下一节点改成本节点，原头节点指向NULL。时间复杂度：O(n)，空间复杂度：O(n)。

题解
* [C++](./c++/linked_list/reverse-linked-list.cpp)

## 环形链表
思路<br>
* 快慢指针。时间复杂度：O(n)，空间复杂度：O(1)。

题解
* [C++](./c++/linked_list/linked-list-cycle.cpp)

## 合并两个有序链表
思路<br>
* 迭代。时间复杂度：O(m+n)，空间复杂度：O(1)。

题解
* [C++](./c++/linked_list/merge-two-sorted-lists.cpp)