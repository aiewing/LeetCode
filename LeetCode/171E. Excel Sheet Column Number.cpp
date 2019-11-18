//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给定一个Excel表格中的列名称，返回其相应的列序号。

 例如，

     A -> 1
     B -> 2
     C -> 3
     ...
     Z -> 26
     AA -> 27
     AB -> 28
     ...
 示例 1:

 输入: "A"
 输出: 1
 示例 2:

 输入: "AB"
 输出: 28
 示例 3:

 输入: "ZY"
 输出: 701

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/excel-sheet-column-number
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            int index = s[s.size() - 1 - i] - 'A';
            sum += (index + 1) * pow(26, i);
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    int bb = aa->titleToNumber("ZY");
    std::cout << "Hello, World!\n";
    return 0;
}
