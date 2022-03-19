#include "helper.cpp"
#include <unordered_map>
#include <algorithm>

// This solution uses std::sort function
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // std::sort can be used to sort a string, an array or a vector 
        std::sort(s.begin(), s.end());
        // std::cout << s << std::endl;
        std::sort(t.begin(), t.end());
        // std::cout << t << std::endl;

        return s == t;
    }
};


// This solution uses two maps containing the frequencies of every character and compare them
class Solution2 {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size())
        {
            return false;
        }

        // the map should store the frequencies of every character
        std::unordered_map<char, int> map_s;
        std::unordered_map<char, int> map_t;

        for (auto i = 0; i < s.size(); ++i)
        {
            ++map_s[s[i]];
            ++map_t[t[i]];
        }
        
        // for (auto it=map_t.begin(); it!=map_t.end(); ++it)
        //     std::cout << it->first << " => " << it->second << '\n';

        for (auto i = 0; i < s.size(); ++i)
        {
            if (map_s[s[i]] != map_t[s[i]])
            {
                return false;
            }
        }
        
        return true;
    }
};


int main(){
    Solution2 solution;

    std::string s1 = "anagram";
    std::string t1 = "nagaram";
    std::cout << solution.isAnagram(s1, t1) << std::endl;

    std::string s2 = "rat";
    std::string t2 = "car";
    std::cout << solution.isAnagram(s2, t2) << std::endl;

    std::string s3 = "a";
    std::string t3 = "ab";
    std::cout << solution.isAnagram(s3, t3) << std::endl;
}