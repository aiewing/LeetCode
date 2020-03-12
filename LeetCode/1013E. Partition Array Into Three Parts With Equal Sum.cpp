//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

 形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

  

 示例 1：

 输出：[0,2,1,-6,6,-7,9,1,2,0,1]
 输出：true
 解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
 示例 2：

 输入：[0,2,1,-6,6,7,9,-1,2,0,1]
 输出：false
 示例 3：

 输入：[3,3,6,5,-2,2,5,1,-9,4]
 输出：true
 解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
  

 提示：

 3 <= A.length <= 50000
 -10^4 <= A[i] <= 10^4

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum
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

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        long sum = 0;
        long count = A.size();
        for (int i : A) {
            sum += i;
        }
        // 先判断能否被3整除
        if (sum % 3 == 0) {
            long temp = sum / 3;
            long sum1 = 0, sum2 = 0;
            long left = count - 1, right = 0;
            for (int i = 0; i < count; ++i) {
                sum1 += A[i];
                if (sum1 == temp) {
                    left = i;
                    break;
                }
            }
            for (long i = count - 1; i >= 0; --i) {
                sum2 += A[i];
                if (sum2 == temp) {
                    right = i;
                    break;
                }
            }
            if (right > left + 1) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
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
    vector<int> aaaaa = {0,2,1,-6,6,7,9,-1,2,0,1};
    
    long time = getCurrentTime();
    bool aaaaaaaa = aa-> canThreePartsEqualSum(aaaaa);
    long duration = getCurrentTime() - time;
    std::cout << duration << endl;
////    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}


