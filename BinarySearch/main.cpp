#include <iostream>
#include <vector>

class solution {
public:
    int search(std::vector<int>& nums, int target) {
        int leftBound = 0;
        int rightBound = nums.size() - 1;
        while (leftBound <= rightBound) {
            int middleIndex = 0.5 * (leftBound + rightBound);
            int middleValue = nums.at(middleIndex);
            if (target == middleValue) return middleIndex;
            else if (target < middleValue) rightBound = middleIndex - 1;
            else leftBound = middleIndex + 1;
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    solution s;
    std::vector<int> nums_1{-1, 0, 3, 5, 9, 12};
    std::cout << "target index for 9: " << s.search(nums_1, 9) << std::endl;
    std::cout << "target index for 2: " << s.search(nums_1, 2) << std::endl;
    return 0;
}
