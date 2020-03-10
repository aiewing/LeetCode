//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*

 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

 示例 1:

 输入: coins = [1, 2, 5], amount = 11
 输出: 3
 解释: 11 = 5 + 5 + 1
 示例 2:

 输入: coins = [2], amount = 3
 输出: -1
 说明:
 你可以认为每种硬币的数量是无限的。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/coin-change
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 DP解
 1. 推导公式: F(S) = D(left) + D(right) + 2
 1. 推导公式: D(left) = max(D(left), D(right)) + 1
 
 */
class Solution {
    int res = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return res;
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        res = max(res, (left + right));
        return max(left, right) + 1;
    }
};


long getCurrentTime()
{
   struct timeval tv;
   gettimeofday(&tv,NULL);
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main(int argc, const char * argv[]) {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    
    Solution *aa = new Solution();
    int bb = aa->diameterOfBinaryTree(node1);
    std::cout << "Hello, World!\n";
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


