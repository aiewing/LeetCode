//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 编写一个函数，检查输入的链表是否是回文的。

  

 示例 1：

 输入： 1->2
 输出： false
 示例 2：

 输入： 1->2->2->1
 输出： true
  

 进阶：
 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/palindrome-linked-list-lcci
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;



struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*
 O(n) 时间复杂度和 O(1) 空间复杂度
 1. 先遍历到中间节点（双指针法）
 2. 从中间节点之后的节点都进行翻转
 3. 对比中间节点和起始节点
 4。 遍历是否相同
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode *nodeOne = head;
        ListNode *nodeTwo = head;
        while (nodeTwo != NULL && nodeTwo->next != NULL) {
            nodeOne = nodeOne->next;
            nodeTwo = nodeTwo->next->next;
        }
        // nodeOne就是中间节点
        ListNode *newNode = new ListNode(0);
        
        // 翻转节点
        while (nodeOne != NULL) {
            ListNode *temp = nodeOne;
            nodeOne = nodeOne->next;
            temp->next = newNode->next;
            newNode->next = temp;
        }
        
        // 对比节点
        ListNode *temp = newNode->next;
        while (head != NULL && temp != NULL) {
            if (temp->val == head->val) {
                temp = temp->next;
                head = head->next;
            } else {
                return false;
            }
        }
        return true;
    }
};

class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode *temp = head;
        vector<int> arr;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        // 判断是否是回味序列
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            if (arr[left++] != arr[right--]) {
                return false;
            }
        }
        return true;
    }
};

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
    
    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}
