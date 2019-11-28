//
//  main.cpp
//  LeetCode
//
//  Created by Aiewing on 2019/11/17.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

 Note:

 The number of elements initialized in nums1 and nums2 are m and n respectively.
 You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 Example:

 Input:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3

 Output: [1,2,2,3,5,6]
*/

/*
 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

 说明:

 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 示例:

 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3

 输出: [1,2,2,3,5,6]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/merge-sorted-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = 0, index2 = 0;
        vector<int> res;
        while (index1 < m && index2 < n) {
            if (nums1[index1] <= nums2[index2]) {
                res.push_back(nums1[index1]);
                index1++;
            } else {
                res.push_back(nums2[index2]);
                index2++;
            }
        }
        while (index1 < m) {
            res.push_back(nums1[index1]);
            index1++;
        }
        while (index2 < n) {
            res.push_back(nums2[index2]);
            index2++;
        }
        nums1 = res;
    }
};

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = 0, index2 = 0;
        // 遍历需要插入的数组
        while (index2 < n) {
            // 如果第一个数组的数字小于第二个数组的数字就换到下一个数字
            if (nums1[index1] < nums2[index2] && index1 < m) {
                index1++;
            } else {
                // 插在前面
                nums1.insert(nums1.begin() + index1, nums2[index2]);
                index1++;
                index2++;
                m++;
            }
        }
        // 删除多余
        nums1.erase(nums1.end() - n, nums1.end());
    }
};

int main(int argc, const char * argv[]) {
//    Solution *aa = new Solution();
//    vector<int> bb = {2,0};
//    vector<int> cc = {1};
//    aa->merge(bb, 1, cc, 1);
    std::cout << "Hello, World!\n";
    return 0;
}



