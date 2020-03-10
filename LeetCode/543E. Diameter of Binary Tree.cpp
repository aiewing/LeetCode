//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

 示例 :
 给定二叉树

           1
          / \
         2   3
        / \
       4   5
 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

 注意：两结点之间的路径长度是以它们之间边的数目表示。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
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


