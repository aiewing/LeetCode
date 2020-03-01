//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*

 编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

 示例1:

  输入：[1, 2, 3, 3, 2, 1]
  输出：[1, 2, 3]
 示例2:

  输入：[1, 1, 1, 1, 2]
  输出：[1, 2]
 提示：

 链表长度在[0, 20000]范围内。
 链表元素在[0, 20000]范围内。
 进阶：

 如果不得使用临时缓冲区，该怎么解决？
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
 不适用临时缓冲区
 1. 把链表分成两个区域 一个是已经检测过不重复的 一个是为检测 可能有重复的
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *res = new ListNode(0);
        ListNode *temp = head;
        while (temp != NULL) {
            // 遍历左边的链表 查看是否有重复
            ListNode *aiNode = res;
            int flag = 0;
            while (aiNode->next != NULL) {
                if (aiNode->next->val == temp->val) {
                    flag = 1;
                    break;
                } else {
                    aiNode = aiNode->next;
                }
            }
            if (flag == 0) {
                aiNode->next = temp;
            }
            temp = temp->next;
            if (flag == 0) {
                aiNode->next->next = NULL;
            }
        }
        return res->next;
    }
};

class Solution1 {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *temp = head;
        unordered_map<int, int> aiMap;
        aiMap[temp->val] = 1;
        while (temp != NULL && temp->next != NULL) {
            if (aiMap[temp->next->val] == 1) {
                // 删除节点
                temp->next = temp->next->next;
            } else {
                aiMap[temp->next->val] = 1;
                temp = temp->next;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    ListNode * node1 = new ListNode(1);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(3);
    ListNode * node4 = new ListNode(3);
    ListNode * node5 = new ListNode(2);
    ListNode * node6 = new ListNode(1);
    ListNode * node7 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
//    node6->next = node7;
    
    ListNode *bb = aa->removeDuplicateNodes(node1);
    std::cout << "Hello, World!\n";
    return 0;
}
