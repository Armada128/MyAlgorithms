#include <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen_brutal(int target, std::vector<int>& nums) {
        auto len_min = nums.size() + 1;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums.at(j);
                if (sum >= target) {
                    int len_temp = j - i + 1;
                    if (len_temp < len_min) len_min = len_temp;
                    break;
                }
            }
        }
        if (len_min > nums.size()) return 0;
        else return len_min;
    }

    int minSubArrayLen_slidingWindow(int target, std::vector<int>& nums) {
        auto len_min = nums.size() + 1;
        int sum = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums.at(right);
            while (sum >= target) {
                int len_temp = right - left + 1;
                if (len_temp < len_min) len_min = len_temp;
                sum -= nums.at(left);
                ++left;
            }
        }
        if (len_min > nums.size()) return 0;
        else return len_min;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    Solution s;
    std::vector<int> nums_1{2, 3, 1, 2, 4, 3};
    int res_1 = s.minSubArrayLen_brutal(7, nums_1);
    res_1 ? std::cout << "minimum sub array length with minimum sum of 7 of nums_1 is (brutal): " << res_1 << std::endl : std::cout << "no matching sub array for nums_1 (brutal)" << std::endl;
    res_1 = s.minSubArrayLen_slidingWindow(7, nums_1);
    res_1 ? std::cout << "minimum sub array length with minimum sum of 7 of nums_1 is (slidingWindow): " << res_1 << std::endl : std::cout << "no matching sub array for nums_1 (slidingWindow)" << std::endl;

    std::vector<int> nums_2{1, 4, 4};
    int res_2 = s.minSubArrayLen_brutal(4, nums_2);
    res_2 ? std::cout << "minimum sub array length with minimum sum of 4 of nums_2 is (brutal): " << res_2 << std::endl : std::cout << "no matching sub array for nums_2 (brutal)" << std::endl;
    res_2 = s.minSubArrayLen_slidingWindow(4, nums_2);
    res_2 ? std::cout << "minimum sub array length with minimum sum of 4 of nums_2 is (slidingWindow): " << res_2 << std::endl : std::cout << "no matching sub array for nums_2 (slidingWindow)" << std::endl;

    std::vector<int> nums_3{1, 1, 1, 1, 1, 1, 1, 1};
    int res_3 = s.minSubArrayLen_brutal(11, nums_3);
    res_3 ? std::cout << "minimum sub array length with minimum sum of 11 of nums_3 is (brutal): " << res_3 << std::endl : std::cout << "no matching sub array for nums_3 (brutal)" << std::endl;
    res_3 = s.minSubArrayLen_slidingWindow(11, nums_2);
    res_3 ? std::cout << "minimum sub array length with minimum sum of 11 of nums_3 is (slidingWindow): " << res_3 << std::endl : std::cout << "no matching sub array for nums_3 (slidingWindow)" << std::endl;

    return 0;
}
