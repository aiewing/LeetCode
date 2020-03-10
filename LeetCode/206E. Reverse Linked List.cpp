//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 反转一个单链表。

 示例:

 输入: 1->2->3->4->5->NULL
 输出: 5->4->3->2->1->NULL
 进阶:
 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reverse-linked-list
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
 递归法
 */
class Solution {
    ListNode *temp = new ListNode(0);
    ListNode *res = temp;
public:
    ListNode* reverseList(ListNode* head) {
        if (head != NULL) {
            ListNode *aie = reverseList(head->next);
            // 说明是最后一个
            temp->next = head;
            temp = temp->next;
            temp->next = NULL;
        }
        return res->next;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *res = new ListNode(0);
        while (head != NULL) {
            ListNode *temp = head;
            head = head->next;
            temp->next = res->next;
            res->next = temp;
        }
        return res->next;
    }
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        vector<ListNode *> tempArr;
        ListNode *tempNode = head;
        while (tempNode!= NULL) {
            tempArr.push_back(tempNode);
            tempNode = tempNode->next;
        }
        
        ListNode *res = new ListNode(0);
        ListNode *lastNode = res;
        for (int i = (int)tempArr.size() - 1; i >= 0; --i) {
            lastNode->next = tempArr[i];
            lastNode = lastNode->next;
        }
        lastNode->next = NULL;
        return res->next;
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
    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(3);
    ListNode * node4 = new ListNode(4);
    ListNode * node5 = new ListNode(5);
    ListNode * node6 = new ListNode(2);
    ListNode * node7 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
//
    long time = getCurrentTime();
    ListNode *bb = aa->reverseList(node1);
    long duration = getCurrentTime() - time;
    std::cout << duration << endl;
////    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}


