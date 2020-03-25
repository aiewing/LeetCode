//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2019/11/18.
//  Copyright © 2019 Aiewing. All rights reserved.
//

/*
 在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。

 每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。

 请你返回最终形体的表面积。

  

 示例 1：

 输入：[[2]]
 输出：10
 示例 2：

 输入：[[1,2],[3,4]]
 输出：34
 示例 3：

 输入：[[1,0],[0,2]]
 输出：16
 示例 4：

 输入：[[1,1,1],[1,0,1],[1,1,1]]
 输出：32
 示例 5：

 输入：[[2,2,2],[2,1,2],[2,2,2]]
 输出：46
  

 提示：

 1 <= N <= 50
 0 <= grid[i][j] <= 50

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/surface-area-of-3d-shapes
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <sys/time.h>
#include<algorithm>

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

/*
 判断上下左右是否被覆盖了一个面
 */
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            vector<int> subGrid = grid[i];
            for (int j = 0; j < subGrid.size(); ++j) {
                int count = subGrid[j];
                if (count > 0) {
                    //
                    res += (count * 6 - (count - 1) * 2);
                    if (i >= 0 && i < grid.size()) {
                       if ((j + 1) < grid[i].size()) {
                           res -= min(grid[i][j], grid[i][j + 1]) * 2;
                       }
                    }
                    if ((i + 1) < grid.size()) {
                       if (j >= 0 && j < grid[i].size()) {
                           res -= min(grid[i][j], grid[i + 1][j]) * 2;
                       }
                    }
                }
            }
        }
        return res;
    }
};

/*
 判断上下左右是否被覆盖了一个面
 */
class Solution1 {
public:
    int getCoverCount(int i, int j, vector<vector<int>>& grid) {
        int res = 0;
        if (i >= 0 && i < grid.size()) {
            if ((j - 1) >= 0 && (j - 1) < grid[i].size()) {
                res += min(grid[i][j], grid[i][j - 1]);
            }
            if ((j + 1) >= 0 && (j + 1) < grid[i].size()) {
                res += min(grid[i][j], grid[i][j + 1]);
            }
        }
        if ((i - 1) >= 0 && (i - 1) < grid.size()) {
            if (j >= 0 && j < grid[i].size()) {
                res += min(grid[i][j], grid[i - 1][j]);
            }
        }
        if ((i + 1) >= 0 && (i + 1) < grid.size()) {
            if (j >= 0 && j < grid[i].size()) {
                res += min(grid[i][j], grid[i + 1][j]);
            }
        }
        return res;
    }
    
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            vector<int> subGrid = grid[i];
            for (int j = 0; j < subGrid.size(); ++j) {
                int count = subGrid[j];
                if (count > 0) {
                    //
                    res += (count * 6 - (count - 1) * 2);
                    // 左边
                    res -= getCoverCount(i, j, grid);
                }
            }
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
// [2,1,1,5,3,0,2,1,0,1] [2,1,1,5,3,0,2,1,0,1]
    vector<string> aaaaa = {"cat","bt","hat","tree"};
    vector<vector<int>> jjjj = {{1, 2}, {3, 4}};
    
    long time = getCurrentTime();
    int aaaaaaaa = aa->surfaceArea(jjjj);
//    ListNode *aaaaaaaa = aa->sortList(node1);
    long duration = getCurrentTime() - time;
    std::cout << duration << endl;
////    bool bb = aa->isPalindrome(node1);
    std::cout << "Hello, World!\n";
    return 0;
}


