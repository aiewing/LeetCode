//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。

 返回使 A 中的每个值都是唯一的最少操作次数。

 示例 1:

 输入：[1,2,2]
 输出：1
 解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
 示例 2:

 输入：[3,2,1,2,1,7]
 输出：6
 解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
 可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
 提示：

 0 <= A.length <= 40000
 0 <= A[i] < 40000
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <sys/time.h>
#include<algorithm>

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
 计数解
 */
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() < 2) {
            return 0;
        }
        int maxA = INT_MIN;
        for (int i : A) {
            maxA = max(i, maxA);
        }
        vector<int> count(maxA + A.size());
        for (int i : A) {
            count[i]++;
        }
        int res = 0, taken = 0;
        for (int i = 0; i < maxA + A.size(); ++i) {
            if (count[i] > 1) {
                taken += (count[i] - 1);
                res -= i * (count[i] - 1);
            } else if (taken > 0 && count[i] == 0) {
                taken--;
                res += i;
            }
        }
        return res;
    }
};

/*
 DP解
 */
class Solution2 {
public:
    int minIncrementForUnique(vector<int>& A) {
        unordered_map<int, int> aMap;
        sort(A.begin(), A.end());
        int res = 0;
        for (int i : A) {
            if (aMap[i] == 0) {
                // 不需要移动
                aMap[i]++;
            } else {
                // 需要添加
                int temp = i + 1;
                while (1) {
                    if (aMap[temp] == 0) {
                        aMap[temp]++;
                        res += (temp - i);
                        break;
                    } else {
                        temp++;
                    }
                }
            }
        }
        return res;
    }
};

/*
 BF解
 */
class Solution1 {
public:
    int minIncrementForUnique(vector<int>& A) {
        unordered_map<int, int> aMap;
        sort(A.begin(), A.end());
        for (int i : A) {
            aMap[i]++;
        }
        int res = 0;
        for (int i : A) {
            int temp = i + 1;
            while (aMap[i] > 1) {
                // 需要进行递增
                while (1) {
                    if (aMap[temp] == 0) {
                        aMap[temp]++;
                        aMap[i]--;
                        res += (temp - i);
                        temp++;
                        break;
                    } else {
                        temp++;
                    }
                }
            }
        }
        return res;
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
    ListNode * node1 = new ListNode(4);
    ListNode * node2 = new ListNode(2);
    ListNode * node3 = new ListNode(1);
    ListNode * node4 = new ListNode(3);
    ListNode * node5 = new ListNode(5);
    ListNode * node6 = new ListNode(2);
    ListNode * node7 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
// [2,1,1,5,3,0,2,1,0,1] [2,1,1,5,3,0,2,1,0,1]
    vector<string> aaaaa = {"cat","bt","hat","tree"};
    vector<int> jjjj = {2,1,1,5,3,0,2,1,0,1};
    
    long time = getCurrentTime();
    int aaaaaaaa = aa->minIncrementForUnique(jjjj);
//    ListNode *aaaaaaaa = aa->sortList(node1);
    long duration = getCurrentTime() - time;
    std::cout << duration << endl;
////    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}


