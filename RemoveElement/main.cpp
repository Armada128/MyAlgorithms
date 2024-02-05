#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement_brutal(std::vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (val == nums.at(i)) {
                for (int j = i; j < size - 1; ++j) nums.at(j) = nums.at(j + 1);
                --i;
                --size;
            }
        }
        return size;
    }

    int removeElement_doublePointer(std::vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            int elem_fast = nums.at(fast);
            if (elem_fast != val) nums.at(slow++) = elem_fast;
        }
        return slow;
    }
};

void printVector(std::vector<int>& v, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << v.at(i);
        if (i < size - 1) std::cout << ", ";
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    std::vector<int> nums_1{3, 2, 2, 3};
    std::vector<int> nums_temp_1{nums_1};
    int res_1 = s.removeElement_brutal(nums_temp_1, 3);
    std::cout << "removed " << res_1 << " elements with value 3 from nums_1 (brutal)" << std::endl;
    std::cout << "nums_1: [";
    printVector(nums_temp_1, res_1);
    std::cout << "]" << std::endl;
    nums_temp_1 = nums_1;
    res_1 = s.removeElement_doublePointer(nums_temp_1, 3);
    std::cout << "removed " << res_1 << " elements with value 3 from nums_1 (doublePointer)" << std::endl;
    std::cout << "nums_1: [";
    printVector(nums_temp_1, res_1);
    std::cout << "]" << std::endl;

    std::vector<int> nums_2{0, 1, 2, 2, 3, 0, 4, 2};
    std::vector<int> nums_temp_2{nums_2};
    int res_2 = s.removeElement_brutal(nums_temp_2, 2);
    std::cout << "removed " << res_2 << " elements with value 2 from nums_2 (brutal)" << std::endl;
    std::cout << "nums_2: [";
    printVector(nums_temp_2, res_2);
    std::cout << "]" << std::endl;
    nums_temp_2 = nums_2;
    res_2 = s.removeElement_doublePointer(nums_temp_2, 2);
    std::cout << "removed " << res_2 << " elements with value 2 from nums_2 (doublePointer)" << std::endl;
    std::cout << "nums_2: [";
    printVector(nums_temp_2, res_2);
    std::cout << "]" << std::endl;
    return 0;
}
