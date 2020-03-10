//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

 若队列为空，pop_front 和 max_value 需要返回 -1

 示例 1：

 输入:
 ["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
 [[],[1],[2],[],[],[]]
 输出: [null,null,null,2,1,2]
 示例 2：

 输入:
 ["MaxQueue","pop_front","max_value"]
 [[],[],[]]
 输出: [null,-1,-1]
  

 限制：

 1 <= push_back,pop_front,max_value的总操作数 <= 10000
 1 <= value <= 10^5

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
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

class MaxQueue {
public:
    vector<int> _queue;
    int maxNum = INT_MIN;
    
    MaxQueue() {

    }
    
    int max_value() {
        if (_queue.size() > 0) {
            return maxNum;
        }
        return -1;
    }
    
    void push_back(int value) {
        maxNum = max(value, maxNum);
        _queue.push_back(value);
    }
    
    int pop_front() {
        if (_queue.size() > 0) {
            int num = _queue.front();
            _queue.erase(_queue.begin());
            // 处理最大值
            if (_queue.size() == 0) {
                maxNum = INT_MIN;
            } else {
                if (num == maxNum) {
                    maxNum = INT_MIN;
                    // 重新计算
                    for (int i = 0; i < _queue.size(); ++i) {
                        maxNum = max(maxNum, _queue[i]);
                    }
                }
            }
            return num;
        } else {
            return -1;
        }
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

long getCurrentTime()
{
   struct timeval tv;
   gettimeofday(&tv,NULL);
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main(int argc, const char * argv[]) {
    MaxQueue* obj = new MaxQueue();
    int param_1 = obj->max_value();
    obj->push_back(1);
    int param_3 = obj->pop_front();
    
//    Solution *aa = new Solution();
//    ListNode * node1 = new ListNode(1);
//    ListNode * node2 = new ListNode(2);
//    ListNode * node3 = new ListNode(3);
//    ListNode * node4 = new ListNode(3);
//    ListNode * node5 = new ListNode(3);
//    ListNode * node6 = new ListNode(2);
//    ListNode * node7 = new ListNode(2);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
//
//    long time = getCurrentTime();
//    vector<vector<int>> bb = aa->findContinuousSequence(999999);
//    long duration = getCurrentTime() - time;
//    std::cout << duration << endl;
////    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}


