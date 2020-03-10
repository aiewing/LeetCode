//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。


 示例 1：

 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 输出：Reference of the node with value = 8
 输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

 示例 2：

 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
 输出：Reference of the node with value = 2
 输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。

 示例 3：

 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 输出：null
 输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
 解释：这两个链表不相交，因此返回 null。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci
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
 双指针 优化
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while (tempA != tempB) {
            if (tempA != NULL) {
                tempA = tempA->next;
            } else {
                tempA = headB;
            }
            if (tempB != NULL) {
                tempB = tempB->next;
            } else {
                tempB = headA;
            }
        }
        return tempA;
    }
};

/*
 双指针 消除长度差
 */
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) {
            return headA;
        }
        int countA = 0, countB = 0;
        ListNode *headATemp = headA;
        while (headATemp != NULL) {
            countA++;
            headATemp = headATemp->next;
        }
        ListNode *headBTemp = headB;
        while (headBTemp != NULL) {
            countB++;
            headBTemp = headBTemp->next;
        }
        if (countA > countB) {
            while (headA != NULL) {
                headA = headA->next;
                if (--countA == countB) {
                    break;
                }
            }
        } else if (countA < countB) {
            while (headB != NULL) {
                headB = headB->next;
                if (--countB == countA) {
                    break;
                }
            }
        }
        //
        while (headA != NULL && headB != NULL) {
            if (headA == headB) {
                return headA;
            } else {
                headB = headB->next;
                headA = headA->next;
            }
        }
        return NULL;
    }
};

/*
 
 */
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) {
            return headA;
        }
        vector<ListNode *> arrA;
        vector<ListNode *> arrB;
        while (headA != NULL) {
            arrA.push_back(headA);
            headA = headA->next;
        }
        while (headB != NULL) {
            arrB.push_back(headB);
            headB = headB->next;
        }
        ListNode *last = NULL;
        long countA = arrA.size();
        long countB = arrB.size();
        for (int i = 1; i <= min(arrA.size(), arrB.size()); ++i) {
            if (arrA[countA - i] == arrB[countB - i]) {
                last = arrA[countA - i];
            } else {
                return last;
            }
        }
        return last;
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


