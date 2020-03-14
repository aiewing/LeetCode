//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

 示例 1:

 输入: 4->2->1->3
 输出: 1->2->3->4
 示例 2:

 输入: -1->5->3->4->0
 输出: -1->0->3->4->5

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/sort-list
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
 归并排序
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return aiSortList(head, count);
    }
    
    ListNode * aiSortList(ListNode *head, int count) {
        if (count > 1) {
            // 分为两段
            int left = count / 2;
            int right = 0;
            ListNode *temp = head;
            while (temp != NULL) {
                if (++right == left) {
                    break;
                }
                temp = temp->next;
            }
            ListNode *rightNode = aiSortList(temp->next, count - left);
            temp->next = NULL;
            ListNode *leftNode = aiSortList(head, left);
            // 排序
            ListNode *res = new ListNode(0);
            temp = res;
            while (leftNode != NULL && rightNode != NULL) {
                if (leftNode->val < rightNode->val) {
                    temp->next = leftNode;
                    temp = temp->next;
                    leftNode = leftNode->next;
                } else {
                    temp->next = rightNode;
                    temp = temp->next;
                    rightNode = rightNode->next;
                }
            }
            while (leftNode != NULL) {
                temp->next = leftNode;
                temp = temp->next;
                leftNode = leftNode->next;
            }
            while (rightNode != NULL) {
                temp->next = rightNode;
                temp = temp->next;
                rightNode = rightNode->next;
            }
            return res->next;
        } else {
            return head;
        }
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
//
    vector<int> aaaaa = {0,2,1,-6,6,7,9,-1,2,0,1};
    
    long time = getCurrentTime();
//    string aaaaaaaa = aa-> gcdOfStrings("ABCABC", "ABC");
    ListNode *aaaaaaaa = aa->sortList(node1);
    long duration = getCurrentTime() - time;
    std::cout << duration << endl;
////    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}


