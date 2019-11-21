//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 给你一个整数数组 arr 和一个整数 k。

 首先，我们要对该数组进行修改，即把原数组 arr 重复 k 次。

 举个例子，如果 arr = [1, 2] 且 k = 3，那么修改后的数组就是 [1, 2, 1, 2, 1, 2]。

 然后，请你返回修改后的数组中的最大的子数组之和。

 注意，子数组长度可以是 0，在这种情况下它的总和也是 0。

 由于 结果可能会很大，所以需要 模（mod） 10^9 + 7 后再返回。

  

 示例 1：

 输入：arr = [1,2], k = 3
 输出：9
 示例 2：

 输入：arr = [1,-2,1], k = 5
 输出：2
 示例 3：

 输入：arr = [-1,-2], k = 7
 输出：0
  

 提示：

 1 <= arr.length <= 10^5
 1 <= k <= 10^5
 -10^4 <= arr[i] <= 10^4

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/k-concatenation-maximum-sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
 
 */
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long leftMax = INT_MIN, rightMax = INT_MIN;
        long leftSum = 0, rightSum = 0, res = 0, dp = 0, maxDp = INT_MIN;
        for (int i = 0; i < arr.size(); ++i) {
            leftSum += arr[i];
            leftMax = max(leftSum, leftMax);
            rightSum += arr[arr.size() - i - 1];
            rightMax = max(rightSum, rightMax);
            if (dp >= 0) {
                dp = dp + arr[i];
            } else {
                dp = arr[i];
            }
            maxDp = max(maxDp, dp);
        }
        if (leftSum > 0) {
            res = leftSum * k;
            if (k > 2) {
                // 减去左边和右边的
                res = leftSum * (k - 2) + leftMax + rightMax;
            }
        }
        res = max(res, leftMax);
        res = max(res, rightMax);
        res = max(res, leftMax + rightMax);
        res = max(res, maxDp);
        return res % int(pow(10, 9) + 7);
    }
};

int main(int argc, const char * argv[]) {
    Solution *aa = new Solution();
    vector<int> bb = {-5,4,-4,-3,5,-3, 10, 11, -1, 13, 100, 11, -120};
    int cc = aa->kConcatenationMaxSum(bb, 3);
    std::cout << "Hello, World!\n";
    return 0;
}
