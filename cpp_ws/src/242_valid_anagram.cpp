#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

void info(std::vector<char> result_vector)
{   
    int length = result_vector.size();
    std::cout << "The vector is: [";
    for (auto i = 0; i < length - 1; ++i)
        std::cout << result_vector[i] << ", ";
    std::cout << result_vector[length-1] << "]" << std::endl;
}


class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::vector<char> vector_s(s.begin(), s.end()); 
        std::vector<char> vector_t(t.begin(), t.end());
        // info(vector_s);

        if (vector_s.size() != vector_t.size())
        {
            return false;
        }

        std::sort(vector_s.begin(), vector_s.end());
        // info(vector_s);
        std::sort(vector_t.begin(), vector_t.end());
        // info(vector_t);

        for (auto i = 0; i < vector_s.size(); ++i)
        {
            if (vector_s[i] != vector_t[i])
            {
                return false;
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