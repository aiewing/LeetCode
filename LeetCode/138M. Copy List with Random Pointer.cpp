//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

 要求返回这个链表的深拷贝。

  

 示例：



 输入：
 {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

 解释：
 节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
 节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
  

 提示：

 你必须返回给定头的拷贝作为对克隆列表的引用。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

/*
 两个数组存储
 */
class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        vector<Node *> arr1;
        vector<Node *> arr2;
        Node *nHead = head;
        while (nHead != nullptr) {
            Node *node = new Node(nHead->val, nullptr, nullptr);
            arr1.push_back(nHead);
            arr2.push_back(node);
            nHead = nHead->next;
        }
        // 开始拼接
        nHead = head;
        Node *cHead = arr2.front();
        while (nHead != nullptr) {
            if (nHead->next != nullptr) {
                cHead->next = arr2[(find(arr1.begin(), arr1.end(), nHead->next) - arr1.begin())];
            }
            if (nHead->random != nullptr) {
                cHead->random = arr2[(find(arr1.begin(), arr1.end(), nHead->random) - arr1.begin())];
            }
            nHead = nHead->next;
            cHead = cHead->next;
        }
        return arr2.front();
    }
};

/*
 Map存储
 */
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        unordered_map<Node *, Node *> aMap;
        Node *nHead = head;
        while (nHead != nullptr) {
            Node *node = new Node(nHead->val, nullptr, nullptr);
            aMap.insert(pair<Node *, Node *>(nHead, node));
            nHead = nHead->next;
        }
        // 开始拼接
        nHead = head;
        Node *cHead = aMap[head];
        std::cout << "Hello, World!\n";
        while (nHead != nullptr) {
            if (nHead->next != nullptr) {
                cHead->next = aMap[nHead->next];
            }
            if (nHead->random != nullptr) {
                cHead->random = aMap[nHead->random];
            }
            nHead = nHead->next;
            cHead = cHead->next;
        }
        return aMap[head];
    }
};

/*
 插入法
 把新生成的放在老的边上
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node *nHead = head;
        while (nHead != nullptr) {
            Node *node = new Node(nHead->val, nullptr, nullptr);
            node->next = nHead->next;
            nHead->next = node;
            nHead = node->next;
        }
        
        // 设置random
        nHead = head;
        while (nHead != nullptr) {
            Node *node = nHead->next;
            if (nHead->random != nullptr) {
                node->random = nHead->random->next;
            } else {
                node->random = nullptr;
            }
            nHead = nHead->next->next;
        }
        
        // 重新拼接链表
        nHead = head;
        Node *node2 = new Node();
        Node *res = node2;
        while (nHead != nullptr) {
            node2->next = nHead->next;
            node2 = node2->next;
            nHead->next = nHead->next->next;
            nHead = nHead->next;
        }
        return res->next;
    }
};



int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    Node *node1 = new Node(1, nullptr, nullptr);
    Node *node2 = new Node(2, nullptr, nullptr);
    Node *node3 = new Node(3, nullptr, nullptr);
    node1->next = node2;
    node2->next = node3;
    node1->random = node2;
    node2->random = node3;
    node3->random = node1;
    Node *node = aa->copyRandomList(node1);
    std::cout << "Hello, World!\n";
    return 0;
}
