//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 排排坐，分糖果。

 我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。

 给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。

 然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。

 重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。

 返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。

  

 示例 1：

 输入：candies = 7, num_people = 4
 输出：[1,2,3,1]
 解释：
 第一次，ans[0] += 1，数组变为 [1,0,0,0]。
 第二次，ans[1] += 2，数组变为 [1,2,0,0]。
 第三次，ans[2] += 3，数组变为 [1,2,3,0]。
 第四次，ans[3] += 1（因为此时只剩下 1 颗糖果），最终数组变为 [1,2,3,1]。
 示例 2：

 输入：candies = 10, num_people = 3
 输出：[5,2,3]
 解释：
 第一次，ans[0] += 1，数组变为 [1,0,0]。
 第二次，ans[1] += 2，数组变为 [1,2,0]。
 第三次，ans[2] += 3，数组变为 [1,2,3]。
 第四次，ans[0] += 4，最终数组变为 [5,2,3]。
  

 提示：

 1 <= candies <= 10^9
 1 <= num_people <= 1000

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/distribute-candies-to-people
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
 1. 先判断现在的糖果最多可以分多少圈
 2. 先分配最后一圈之前分配的糖果
 3. 最后一圈遍历分配
  5
  1 1+n 1+2n
 */
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res (num_people, 0);
        int candiesCount = 0;
        int candiesSum = 0;
        while (1) {
            for (int i = 0; i < num_people; ++i) {
                candiesCount++;
                if (candies > (candiesSum + candiesCount)) {
                    // 可以分配
                    res[i] += candiesCount;
                    candiesSum += candiesCount;
                } else if (candies == (candiesSum + candiesCount)) {
                    res[i] += candiesCount;
                    return res;
                } else {
                    res[i] += candies - candiesSum;
                    return res;
                }
            }
        }
        return res;
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
    vector<int> bb = aa->distributeCandies(7, 4);
//    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}
