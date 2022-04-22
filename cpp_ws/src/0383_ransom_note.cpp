#include "helper.cpp" 
#include <algorithm>

// time: 260ms, beat 5.12%
// RAM: 8.5MB, beat 68.17%
class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        for (char i : ransomNote){
            if (std::count(ransomNote.begin(), ransomNote.end(), i) > std::count(magazine.begin(), magazine.end(), i) )
                return false;
        }
    return true;
    }
};

int main(){
    Solution solution;

    std::string ransomNote1 = "a";
    std::string magazine1 = "b";
    std::cout << solution.canConstruct(ransomNote1, magazine1) << std::endl;
    
    std::string ransomNote2 = "a";
    std::string magazine2 = "ba";
    std::cout << solution.canConstruct(ransomNote2, magazine2) << std::endl;

    std::string ransomNote3 = "ab";
    std::string magazine3 = "abbb";
    std::cout << solution.canConstruct(ransomNote3, magazine3) << std::endl;

    std::string ransomNote4 = "aab";
    std::string magazine4 = "baa";
    std::cout << solution.canConstruct(ransomNote4, magazine4) << std::endl;
}