//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

 说明:

 返回的下标值（index1 和 index2）不是从零开始的。
 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 示例:

 输入: numbers = [2, 7, 11, 15], target = 9
 输出: [1,2]
 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 暴力求解法
 */
class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> temp = numbers;
        // 先去重
        int index = 0;
        while (index < numbers.size() - 1) {
            if (numbers[index] == numbers[index + 1]) {
                // 去重之前先判断是否成立
                if (numbers[index] * 2 == target) {
                    return aiewing(temp, numbers[index], numbers[index]);
                } else {
                    // 删除
                    numbers.erase(numbers.begin() + index + 1);
                }
            } else {
                index++;
            }
        }
        for (int i = 0; i < numbers.size() - 1; ++i) {
            for (int j = i + 1; j < numbers.size(); ++j) {
                if (numbers[i] + numbers[j] == target) {
                    return aiewing(temp, numbers[i], numbers[j]);
                }
            }
        }
        return {};
    }
    
    vector<int> aiewing(vector<int> nums, int one, int two) {
        int index1 = 0, index2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == one) {
                index1 = i;
                break;
            }
        }
        if (one == two) {
            return {index1 + 1, index1 + 2};
        } else {
            for (int i = index1; i < nums.size(); ++i) {
                if (nums[i] == two) {
                    index2 = i;
                    break;
                }
            }
        }
        return {index1 + 1, index2 + 1};
    }
};

/*
 双指针法
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0,right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                return {left + 1, right + 1};
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }

};

int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    vector<int> bb = {1, 2, 3, 4, 5, 5, 5, 5, 6, 7, 7, 7, 7, 7, 10, 10};
    vector<int> cc = aa->twoSum(bb, 9);
    std::cout << "Hello, World!\n";
    return 0;
}
