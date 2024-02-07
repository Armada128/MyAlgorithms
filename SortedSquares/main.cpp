#include <iostream>
#include <vector>
#include <stddef.h>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> res(nums.size(), 0);
        int index_left = 0, index_right = nums.size() - 1, index_temp = index_right;
        int square_left = nums.at(index_left) * nums.at(index_left);
        int square_right = nums.at(index_right) * nums.at(index_right);
        while (index_left <= index_right) {
            if (square_left > square_right) {
                res.at(index_temp--) = square_left;
                ++index_left;
                square_left = nums.at(index_left) * nums.at(index_left);
            } else {
                res.at(index_temp--) = square_right;
                --index_right;
                square_right = nums.at(index_right) * nums.at(index_right);
            }
        }
        return res;
    }
};

void printVector(const std::vector<int>& v) {
    std::cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v.at(i);
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    Solution s;
    std::vector<int> nums_1{-4, -1, 0, 3, 10};
    auto res_1 = s.sortedSquares(nums_1);
    printVector(res_1);

    std::vector<int> nums_2{-7, -3, 2, 3, 11};
    auto res_2 = s.sortedSquares(nums_2);
    printVector(res_2);

    return 0;
}
