//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 删除链表中等于给定值 val 的所有节点。

 示例:

 输入: 1->2->6->3->4->5->6, val = 6
 输出: 1->2->3->4->5
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

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *tempNode = res;
        while (tempNode->next != NULL) {
            if (tempNode->next->val == val) {
                tempNode->next = tempNode->next->next;
            } else {
                tempNode = tempNode->next;
            }
        }
        return res->next;
    }
};


int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(6);
    ListNode * node4 = new ListNode(3);
    ListNode * node5 = new ListNode(4);
    ListNode * node6 = new ListNode(5);
    ListNode * node7 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    
    ListNode *bb = aa->removeElements(node1, 6);
    std::cout << "Hello, World!\n";
    return 0;
}
