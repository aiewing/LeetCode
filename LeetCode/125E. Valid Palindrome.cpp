//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

 说明：本题中，我们将空字符串定义为有效的回文串。

 示例 1:

 输入: "A man, a plan, a canal: Panama"
 输出: true
 示例 2:

 输入: "race a car"
 输出: false

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/valid-palindrome
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <string>

using namespace std;

/*
 先筛选 后求解
 */
class Solution1 {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i] >= '0' && s[i] <= '9') ||
                (s[i] >= 'a' && s[i] <= 'z')) {
                temp.push_back(s[i]);
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                temp.push_back(s[i] + ('a' - 'A'));
            }
        }
        int left = 0 ,right = (int)temp.size() - 1;
        while (left < right) {
            if (temp[left++] != temp[right--]) {
                return false;
            }
        }
        return true;
    }
};

/*
 直接求解
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0 ,right = (int)s.size() - 1;
        while (left < right) {
            if (!isOK(s[left])) {
                left++;
                continue;
            }
            if (!isOK(s[right])) {
                right--;
                continue;
            }
            if (!isEqea(s[left++], s[right--])) {
                return false;
            }
        }
        return true;
    }
    
    bool isOK(char str) {
        if ((str >= '0' && str <= '9') ||
            (str >= 'a' && str <= 'z') ||
            (str >= 'A' && str <= 'Z')) {
            return true;
        }
        return false;
    }
    
    bool isEqea(char str1, char str2) {
        if ((str1 >= 'A' && str1 <= 'Z')) {
            str1 = str1 + ('a' - 'A');
        }
        if ((str2 >= 'A' && str2 <= 'Z')) {
            str2 = str2 + ('a' - 'A');
        }
        return str1 == str2;
    }
};

int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    string bb = "A man, a plan, a canal: Panama";
    aa->isPalindrome(bb);
    std::cout << "Hello, World!\n";
    return 0;
}
