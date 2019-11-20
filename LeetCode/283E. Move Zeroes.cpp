//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

 示例:

 输入: [0,1,0,3,12]
 输出: [1,3,12,0,0]
 说明:

 必须在原数组上操作，不能拷贝额外的数组。
 尽量减少操作次数。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/move-zeroes
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 暴力求解法
 冒泡排序法
 */
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int left = 0, right = (int)nums.size() - 1;
        bool flag = false;
        while (left < right) {
            for (int i = left; i <= right; ++i) {
                if (flag) {
                    // 直接交换
                    swapNum(nums, i, i - 1);
                } else {
                    if (nums[i] == 0) {
                        // 开始叫唤
                        flag = true;
                    }
                }
            }
            if (flag) {
                if (nums[left] != 0) {
                    left++;
                }
                right--;
                flag = false;
            } else {
                return;
            }
        }
    }
    
    void swapNum(vector<int> & nums, int left, int right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
};

/*
 一次遍历法
 当前的0和第一个不为零的数字交换 就相当于滑窗一样移动
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = (int)nums.size();
        if (count <= 1) {
            return;
        }
        int left = 0, right = 1;
        while (right < count && left < count) {
            if (nums[left] != 0) {
                left++;
                right = max(right, left + 1);
            } else if (nums[right] == 0) {
                right++;
            } else {
                // 交换
                swapNum(nums, left++, right++);
            }
        }
    }
    
    void swapNum(vector<int> & nums, int left, int right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
};

int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    vector<int> bb = {4,2,4,0,0,3,0,5,1,0};
    aa->moveZeroes(bb);
    std::cout << "Hello, World!\n";
    return 0;
}
