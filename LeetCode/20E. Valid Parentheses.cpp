//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

 有效字符串需满足：

 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 注意空字符串可被认为是有效字符串。

 示例 1:

 输入: "()"
 输出: true
 示例 2:

 输入: "()[]{}"
 输出: true
 示例 3:

 输入: "(]"
 输出: false
 示例 4:

 输入: "([)]"
 输出: false
 示例 5:

 输入: "{[]}"
 输出: true

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/valid-parentheses
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string str;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(') {
                str.push_back(')');
            } else if (c == '{') {
                str.push_back('}');
            } else if (c == '[') {
                str.push_back(']');
            } else if (c != ' ') {
                if (str.size() == 0 || str.back() != c) {
                    return false;
                }
                str.pop_back();
            }
        }
        return str.size() == 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    int bb = aa->isValid("LLLLRRRR");
    std::cout << "Hello, World!\n";
    return 0;
}
