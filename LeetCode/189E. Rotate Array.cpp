//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

 示例 1:

 输入: [1,2,3,4,5,6,7] 和 k = 3
 输出: [5,6,7,1,2,3,4]
 解释:
 向右旋转 1 步: [7,1,2,3,4,5,6]
 向右旋转 2 步: [6,7,1,2,3,4,5]
 向右旋转 3 步: [5,6,7,1,2,3,4]
 示例 2:

 输入: [-1,-100,3,99] 和 k = 2
 输出: [3,99,-1,-100]
 解释:
 向右旋转 1 步: [99,-1,-100,3]
 向右旋转 2 步: [3,99,-1,-100]
 说明:

 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 要求使用空间复杂度为 O(1) 的 原地 算法。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/rotate-array
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
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) {
            return;
        }
        vector<int> temp;
        for (int i = 0; i < k; ++i) {
            temp.push_back(nums[nums.size() - k + i]);
        }
        for (int i = (int)nums.size() - 1; i >= k; --i) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; ++i) {
            nums[i] = temp[i];
        }
    }
};

/*
 循环求解法(超时)
 */
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) {
            return;
        }
        k = k % nums.size();
        if (k == 0 || nums.size() <= 1) {
            return;
        }
        for (int i = 0; i < k; ++i) {
            int temp = nums.back();
            for (int j = (int)nums.size() - 1; j > 0; --j) {
                nums[j] = nums[j - 1];
            }
            nums.front() = temp;
        }
    }
};

/*
 先首尾交换 然后一直移动到相应的位置
 */
class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        int count = (int)nums.size();
        k = k % count;
        if (k == 0) {
            return;
        }
        if (k > count / 2) {
            // 向左移动 count - k
            // 首尾交换
            rotateNum(nums, 0, count - 1, 0, count - k);
        } else {
            // 向右移动 k
            // 首尾交换
            rotateNum(nums, 0, count - 1, 1, k);
        }
    }
    
    void rotateNum(vector<int>& nums, int left, int right, int type, int k) {
        // 先进行一次首尾交换
        for (int i = 0; i < k; ++i) {
            swapNum(nums, left + i, right - k + i + 1);
        }
        // 以下情况就可以走出循环了
        int count = right - left + 1;
        if (k == count / 2) {
            if (count % 2 == 0) {
                return;
            } else {
                // 中间的数和后面的人换
                if (type == 0) {
                    for (int i = k - 1; i >= 0; --i) {
                        swapNum(nums, left + i, left + i + 1);
                    }
                } else {
                    for (int i = 0; i < k; ++i) {
                        swapNum(nums, right - k + i, right - k + i + 1);
                    }
                }
                return;
            }
        }
        
        if (type == 0) { // 向左移动
            right -= k;
            
            while (right - left >= k * 2) {
                for (int i = 0; i < k; ++i) {
                    swapNum(nums, left + i, right - k + i + 1);
                }
                right -= k;
            }
            count = right - left + 1;
            if (k > count / 2) {
                // 向右移动 count - k
                // 首尾交换
                rotateNum(nums, left, right, 1, count - k);
            } else {
                // 向左移动 k
                // 首尾交换
                rotateNum(nums, left, right, 0, k);
            }
        } else { // 向右移动
            left += k;
            while (right - left >= k * 2) {
                for (int i = 0; i < k; ++i) {
                    swapNum(nums, left + i, right - k + i + 1);
                }
                left += k;
            }
            count = right - left + 1;
            if (k > count / 2) {
                // 向左移动 count - k
                // 首尾交换
                rotateNum(nums, left, right, 0, count - k);
            } else {
                // 向右移动 k
                // 首尾交换
                rotateNum(nums, left, right, 1, k);
            }
        }
    }
    
    void swapNum(vector<int>& nums, int left, int right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
};

/*
 三次翻转法
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = (int)nums.size();
        k %= length;
        if (length <= 1 || k <= 0) {
            return;
        }
        reverse(nums, 0, length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, length - 1);
    }
    
    void reverse(vector<int> &nums, int start, int end) {
        int temp;
        for (int i = start; i <= (start + end) / 2; ++i) {
            temp = nums[i];
            nums[i] = nums[end - (i - start)];
            nums[end - (i - start)] = temp;
        }
    }
};

/*
 1, 2, 3, 4, 5, 6,  7, 8, 9，10, 11, 12, 13, 14, 15
15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
 
 
  1, 2, 3,    4, 5, 6, 7, 8, 9，10, 11, 13, 14, 15
  13, 14, 15, 4, 5, 6, 7, 8, 9，10, 11, 1, 2, 3,
  4, 5, 6, 7, 8, 9，10, 11, 13, 14, 15， 1, 2, 3,
 
  1, 2, 3, 4, 5, 6, 7, 8, 9
  7, 8, 9, 4, 5, 6, 1, 2, 3
  4, 5, 6, 7, 8, 9, 1, 2, 3
 
 10 11 7 8 9
 
 [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27]
 38
 
 */
int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    vector<int> bb = {1,2};
    aa->rotate(bb, 2);
    std::cout << "Hello, World!\n";
    return 0;
}
