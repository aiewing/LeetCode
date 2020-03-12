//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

 返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

  

 示例 1：

 输入：str1 = "ABCABC", str2 = "ABC"
 输出："ABC"
 示例 2：

 输入：str1 = "ABABAB", str2 = "ABAB"
 输出："AB"
 示例 3：

 输入：str1 = "LEET", str2 = "CODE"
 输出：""
  

 提示：

 1 <= str1.length <= 1000
 1 <= str2.length <= 1000
 str1[i] 和 str2[i] 为大写英文字母

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings
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
    string gcdOfStrings(string str1, string str2) {
        long count1 = str1.size();
        long count2 = str2.size();
        return checkString(str1, str2, checkoutCount(count1, count2));
    }
    
    long checkoutCount(long count1, long count2) {
        if (count1 == count2) {
            return count1;
        } else {
            return checkoutCount(min(count1, count2), abs(count1 - count2));
        }
    }
    
    string checkString(string str1, string str2, long count) {
        if (count == 0) {
            return "";
        }
        for (int i = 0; i < count; ++i) {
            if (str1[i] != str2[i]) {
                return "";
            }
        }
        string strTemp = str1.substr(0, count);
        long countTemp = strTemp.size();
        for (int i = 0; i < str1.size(); ++i) {
            if (str1[i] != strTemp[i % countTemp]) {
                return "";
            }
        }
        
        for (int i = 0; i < str2.size(); ++i) {
            if (str2[i] != strTemp[i % countTemp]) {
                return "";
            }
        }
        return strTemp;
    }
};

class Solution1 {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() == str2.size()) {
            if (checkString(str1, str2)) {
                return str1;
            } else {
                return "";
            }
        } else if (str1.size() > str2.size()) {
            string str3 = str1.substr(str2.size(), str1.size() - 1);
            return gcdOfStrings(str2, str3);
        } else {
            string str3 = str2.substr(str1.size(), str2.size() - 1);
            return gcdOfStrings(str1, str3);
        }
    }
    
    bool checkString(string str1, string str2) {
        for (int i = 0; i < str1.size(); ++i) {
            if (str1[i] != str2[i]) {
                return false;
            }
        }
        return true;
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
    string aaaaaaaa = aa-> gcdOfStrings("ABCABC", "ABC");
    long duration = getCurrentTime() - time;
    std::cout << duration << endl;
////    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}


