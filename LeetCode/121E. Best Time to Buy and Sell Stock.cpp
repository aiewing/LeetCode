//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*

 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

 注意你不能在买入股票前卖出股票。

 示例 1:

 输入: [7,1,5,3,6,4]
 输出: 5
 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 示例 2:

 输入: [7,6,4,3,1]
 输出: 0
 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <sys/time.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*
 DP求解法
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int temp = 0;
        for (int i = 1; i < prices.size(); ++i) {
            temp = prices[i] - prices[i - 1] + temp;
            if (temp > 0) {
                res = max(res, temp);
            } else {
                temp = 0;
            }
        }
        return res;
    }
};

/*
 暴力求解法
 */
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = i + 1; j < prices.size(); ++j) {
                res = max(res, prices[j] - prices[i]);
            }
        }
        return res;
    }
};


long getCurrentTime()
{
   struct timeval tv;
   gettimeofday(&tv,NULL);
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main(int argc, const char * argv[]) {
    
//    Solution *aa = new Solution();
//    ListNode * node1 = new ListNode(1);
//    ListNode * node2 = new ListNode(2);
//    ListNode * node3 = new ListNode(3);
//    ListNode * node4 = new ListNode(3);
//    ListNode * node5 = new ListNode(3);
//    ListNode * node6 = new ListNode(2);
//    ListNode * node7 = new ListNode(2);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
//
//    long time = getCurrentTime();
//    vector<vector<int>> bb = aa->findContinuousSequence(999999);
//    long duration = getCurrentTime() - time;
//    std::cout << duration << endl;
////    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}


