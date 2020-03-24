//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

 注意：本题相对原题稍作改动

  

 示例 1：

 输入： [1,2,3,1]
 输出： 4
 解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
 示例 2：

 输入： [2,7,9,3,1]
 输出： 12
 解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
 示例 3：

 输入： [2,1,4,5,3,1,1,3]
 输出： 12
 解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/the-masseuse-lcci
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <sys/time.h>
#include<algorithm>

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
 DP[i] = max(DP[i - 1], DP[i - 2] + F[i])
 */
class Solution {
public:
    int massage(vector<int>& nums) {
        long count = nums.size();
        if (count == 0) {
            return 0;
        }
        vector<int> dp(count);
        for (int i = 0; i < count; ++i) {
            if (i == 0) {
                dp[i] = nums[i];
            } else if (i == 1) {
                dp[i] = max(nums[i], nums[i - 1]);
            } else {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }
        }
        return dp[count - 1];
    }
};

long getCurrentTime()
{
   struct timeval tv;
   gettimeofday(&tv,NULL);
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main(int argc, const char * argv[]) {
//    TreeNode *node1 = new TreeNode(1);
//    TreeNode *node2 = new TreeNode(2);
//    TreeNode *node3 = new TreeNode(3);
//    TreeNode *node4 = new TreeNode(4);
//    TreeNode *node5 = new TreeNode(5);
//
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
    
//    Solution *aa = new Solution();
//    int bb = aa->diameterOfBinaryTree(node1);
//    std::cout << "Hello, World!\n";
    
    Solution *aa = new Solution();
    ListNode * node1 = new ListNode(4);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(1);
    ListNode * node4 = new ListNode(3);
    ListNode * node5 = new ListNode(5);
    ListNode * node6 = new ListNode(2);
    ListNode * node7 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
// [2,1,1,5,3,0,2,1,0,1] [2,1,1,5,3,0,2,1,0,1]
    vector<string> aaaaa = {"cat","bt","hat","tree"};
    vector<int> jjjj = {2,1,1,5,3,0,2,1,0,1};
    
    long time = getCurrentTime();
    int aaaaaaaa = aa->minIncrementForUnique(jjjj);
//    ListNode *aaaaaaaa = aa->sortList(node1);
    long duration = getCurrentTime() - time;
    std::cout << duration << endl;
////    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}


