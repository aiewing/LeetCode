//
//  main.cpp
//  Test
//
//  Created by Aiewing on 2020/2/22.
//  Copyright © 2020 Aiewing. All rights reserved.
//

#include <iostream>

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long left = 1;
        long right = n;
        long res;
        long flag;
        while (1) {
            res = (left + right) / 2;
            flag = guess(res);
            if (flag == 0) {
                break;
            } else if (flag == -1) {
                right = res - 1;
            } else {
                left = res + 1;
            }
        }
        return (int)res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
