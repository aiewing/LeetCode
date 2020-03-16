//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

 示例1:

  输入："aabcccccaaa"
  输出："a2b1c5a3"
 示例2:

  输入："abbccd"
  输出："abbccd"
  解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
 提示：

 字符串长度在[0, 50000]范围内。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/compress-string-lcci
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
    string compressString(string S) {
        if (S.size() < 3) {
            return S;
        }
        char lastChar = S.front();
        int count = 0;
        string res;
        res.push_back(lastChar);
        for (auto c : S) {
            if (c == lastChar) {
                count++;
            } else {
                res.append(to_string(count));
                res.push_back(c);
                lastChar = c;
                count = 1;
            }
        }
        res.append(to_string(count));
        if (res.size() >= S.size()) {
            return S;
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
//
    vector<int> aaaaa = {0,2,1,-6,6,7,9,-1,2,0,1};
    
    long time = getCurrentTime();
    string aaaaaaaa = aa->compressString("aabcccccaa");
//    ListNode *aaaaaaaa = aa->sortList(node1);
    long duration = getCurrentTime() - time;
    std::cout << duration << endl;
////    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}


