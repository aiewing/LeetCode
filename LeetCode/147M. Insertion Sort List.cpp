//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 对链表进行插入排序。


 插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

  

 插入排序算法：

 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
 重复直到所有输入数据插入完为止。
  

 示例 1：

 输入: 4->2->1->3
 输出: 1->2->3->4
 示例 2：

 输入: -1->5->3->4->0
 输出: -1->0->3->4->5

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/insertion-sort-list
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

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *resList = new ListNode(INT_MIN);
        resList->next = head;
        ListNode *currentList = head->next;
        head->next = nullptr;
        while (currentList != nullptr) {
            // 取出当前需要排序的数
            ListNode *sortList = currentList;
            currentList = currentList->next;
            
            ListNode *node = resList;
            while (node != nullptr) {
                if (node->next != nullptr) {
                    ListNode *left = node;
                    ListNode *right = node->next;
                    if (left->val <= sortList->val && right->val >= sortList->val) {
                        left->next = sortList;
                        sortList->next = right;
                        break;
                    }
                } else {
                    ListNode *left = node;
                    left->next = sortList;
                    sortList->next = nullptr;
                }
                node = node->next;
            }
        }
        return resList->next;
    }
};
int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(4);
    ListNode * node3 = new ListNode(29);
    ListNode * node4 = new ListNode(23);
    ListNode * node5 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    ListNode *bb = aa->insertionSortList(node1);
    std::cout << "Hello, World!\n";
    return 0;
}
