//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给你两个整数数组 nums 和 index。你需要按照以下规则创建目标数组：

 目标数组 target 最初为空。
 按从左到右的顺序依次读取 nums[i] 和 index[i]，在 target 数组中的下标 index[i] 处插入值 nums[i] 。
 重复上一步，直到在 nums 和 index 中都没有要读取的元素。
 请你返回目标数组。

 题目保证数字插入位置总是存在。

  

 示例 1：

 输入：nums = [0,1,2,3,4], index = [0,1,2,2,1]
 输出：[0,4,1,3,2]
 解释：
 nums       index     target
 0            0        [0]
 1            1        [0,1]
 2            2        [0,1,2]
 3            2        [0,1,3,2]
 4            1        [0,4,1,3,2]
 示例 2：

 输入：nums = [1,2,3,4,0], index = [0,1,2,3,0]
 输出：[0,1,2,3,4]
 解释：
 nums       index     target
 1            0        [1]
 2            1        [1,2]
 3            2        [1,2,3]
 4            3        [1,2,3,4]
 0            0        [0,1,2,3,4]
 示例 3：

 输入：nums = [1], index = [0]
 输出：[1]
  

 提示：

 1 <= nums.length, index.length <= 100
 nums.length == index.length
 0 <= nums[i] <= 100
 0 <= index[i] <= i
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

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            res.insert(res.begin() + index[i], nums[i]);
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


