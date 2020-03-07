//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*

 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

  

 示例 1：

 输入：target = 9
 输出：[[2,3,4],[4,5]]
 示例 2：

 输入：target = 15
 输出：[[1,2,3,4,5],[4,5,6],[7,8]]
  

 限制：

 1 <= target <= 10^5
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
 双指针法
 */
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> temp;
        for (int left = 1, right = 2; left < right;) {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum == target) {
                temp.clear();
                for (int i = left; i <= right; ++i) {
                    temp.emplace_back(i);
                }
                res.emplace_back(temp);
                left++;
            } else if (sum < target)  {
                right++;
            } else {
                left++;
            }
        }
        return res;
    }
};

/*
 1. 先求出1-target 的合集
 */
class Solution1 {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<long> dpArr;
        long sum = 0;
        for (int i = 0; i < (target + 1) / 2; ++i) {
            sum += i + 1;
            dpArr.push_back(sum);
        }
        vector<vector<int>> res;
        for (int i = 0; i < dpArr.size(); ++i) {
            if (dpArr[i] == target) {
                // 放入数组
                res.push_back(getArrWith(1, i+1));
            } else if (dpArr[i] > target) {
                // 遍历寻找 (二分法最快)
                long targetNum = dpArr[i] - target;
                int left = 0;
                int right = i - 1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (dpArr[mid] > targetNum) {
                        if (mid == right) {
                            mid--;
                        }
                        right = mid;
                    } else if (dpArr[mid] < targetNum) {
                        if (mid == left) {
                            mid++;
                        }
                        left = mid;
                    } else {
                        // 放入数组
                        res.push_back(getArrWith(mid + 2, i + 1));
                        break;
                    }
                }
            }
        }
        return res;
    }
    
    // 检测是否可以找到
    
    
    vector<int> getArrWith(int start, int end) {
        vector<int> res;
        for (int i = start; i <= end; ++i) {
            res.push_back(i);
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
    Solution *aa = new Solution();
    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(3);
    ListNode * node4 = new ListNode(3);
    ListNode * node5 = new ListNode(3);
    ListNode * node6 = new ListNode(2);
    ListNode * node7 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    long time = getCurrentTime();
    vector<vector<int>> bb = aa->findContinuousSequence(999999);
    long duration = getCurrentTime() - time;
    std::cout << duration << endl;
//    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}


