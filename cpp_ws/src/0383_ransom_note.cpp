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

// time: 260ms, beat 5.12%
// RAM: 8.5MB, beat 68.17%
class Solution2 {
public:
    bool canConstruct(std::string ransomNote, std::string magazine){
        int hash[26] = {0}; // use array with size 26 to represent hash table
        std::cout << hash[0] << std::endl;
        for(char i : magazine){
            hash[i-'a'] += 1;
        }
        for(char j : ransomNote ){
            hash[j-'a'] -= 1;
            if(hash[j-'a'] < 0)
                return false;
        }
        return true;
    }
};

int main(){
    Solution2 solution;

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