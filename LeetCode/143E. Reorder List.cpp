//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 示例 1:

 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 示例 2:

 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reorder-list
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
 1. 先拆成两个链表
 2. 将后面的链表翻转
 3. 拼接链表
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        int count = 0;
        ListNode *node = head;
        while(node != nullptr) {
            count++;
            node = node->next;
        }
        if (count <= 2) {
            return;
        }
        int countOne = (count + 1) / 2;
        // 分割
        int index = 0;
        node = head;
        ListNode *nodeTwo = nullptr;
        while (node != nullptr) {
            index++;
            if (index == countOne) {
                nodeTwo = node->next;
                node->next = nullptr;
                break;
            }
            node = node->next;
        }
        
        // 翻转链表
        vector<ListNode *> arr;
        node = nodeTwo;
        while (node != nullptr) {
            arr.push_back(node);
            node = node->next;
        }
        arr.front()->next = nullptr;
        reverse(arr.begin(), arr.end());
        
        index = 0;
        node = head;
        while (index < arr.size()) {
            ListNode *temp = arr[index];
            temp->next = head->next;
            head->next = temp;
            head = temp->next;
            index++;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(3);
    ListNode * node4 = new ListNode(4);
    ListNode * node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
//    node4->next = node5;
    
    aa->reorderList(node1);
    std::cout << "Hello, World!\n";
    return 0;
}
