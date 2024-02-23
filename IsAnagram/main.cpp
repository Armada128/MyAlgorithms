#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int, 52> alphabet{};
        for (const auto& c : s) {
            auto index = c - 'a';
            if (index >= 0 && index <= 25) alphabet.at(index) += 1;
            else {
                index = c - 'A';
                if (index >= 0 && index <= 25) alphabet.at(index + 26) += 1;
            }
        }
        for (const auto& c : t) {
            auto index = c - 'a';
            if (index >= 0 && index <= 25) alphabet.at(index) -= 1;
            else {
                index = c - 'A';
                if (index >= 0 && index <= 25) alphabet.at(index + 26) -= 1;
            }
        }
        return std::all_of(alphabet.begin(), alphabet.end(), [](const int& e){ return e == 0; });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    Solution sol;
    string s = "aNagram";
    string t = "Nagaram";
    std::cout << (sol.isAnagram(s, t) ? "true" : "false") << std::endl;

    s = "rat";
    t = "car";
    std::cout << (sol.isAnagram(s, t) ? "true" : "false") << std::endl;

    return 0;
}
