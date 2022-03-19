#include "helper.cpp"
#include <unordered_map>
#include <algorithm>


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


class Solution2 {
public:
    bool isAnagram(std::string s, std::string t) {
        std::vector<char> vector_s(s.begin(), s.end()); 
        std::vector<char> vector_t(t.begin(), t.end());
        // info(vector_s);

        if (vector_s.size() != vector_t.size())
        {
            return false;
        }

        // this approach is not working 
        std::unordered_map<char, int> map_s;
        std::unordered_map<char, int> map_t;

        for (auto i = 0; i < vector_s.size(); ++i)
        {
            map_s.insert({vector_s[i], i});
            map_t.insert({vector_t[i], i});
        }
        for (auto it=map_t.begin(); it!=map_t.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        for (auto i = 0; i < vector_s.size(); ++i)
        {
            // there may exist conflicting
            auto iter = map_t.find(vector_s[i]);
            std::cout << i << " " ;
            if (iter == map_t.end())
            {
                return false;
            }
            else
            {   
                std::cout << iter->first << std::endl;
                map_t.erase(iter);
                for (auto it=map_t.begin(); it!=map_t.end(); ++it)
                    std::cout << it->first << " => " << it->second << '\n';
            }
        }
        
        return true;
    }
};


int main(){
    Solution solution;

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