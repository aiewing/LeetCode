//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 编写一个程序，找到两个单链表相交的起始节点。

 如下面的两个链表：



 在节点 c1 开始相交。

  

 示例 1：



 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 输出：Reference of the node with value = 8
 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>


struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

/*
 暴力求解法
 */
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode *tempA = headA;
        while (tempA != NULL) {
            ListNode *tempB = headB;
            while (tempB != NULL) {
                if (tempA == tempB) {
                    return tempA;
                } else {
                    tempB = tempB->next;
                }
            }
            tempA = tempA->next;
        }
        return NULL;
    }
};

/*
 双指针
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        int countA = 0, countB = 0;
        while (tempA) {
            countA++;
            tempA = tempA->next;
        }
        while (tempB) {
            countB++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        while (countA != countB) {
            if (countA > countB) {
                tempA = tempA->next;
                countA--;
            }
            if (countB > countA) {
                tempB = tempB->next;
                countB--;
            }
        }
        // 开始双指针
        while (tempA != NULL && tempB != NULL) {
            if (tempA == tempB) {
                std::cout << "Hello, World!\n";
                return tempA;
            } else {
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }
        std::cout << "Hello, World!\n";
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *p1 = new ListNode(4);
    ListNode *p2 = new ListNode(1);
    ListNode *p3 = new ListNode(8);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(5);
    ListNode *p7 = new ListNode(0);
    p1->next = p2;
    
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    
    p6->next = p7;
    p7->next = p2;
    Solution * aa = new Solution();
    aa->getIntersectionNode(p1, p6);
    std::cout << "Hello, World!\n";
    return 0;
}
