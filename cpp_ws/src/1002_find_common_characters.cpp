#include "helper.cpp"
#include <unordered_map>
#include <algorithm>
#include <map>

// time: 48ms, beat 5.9%
// RAM: 13.3MB, beat 5.08%
class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<std::string> result;
        // initialize the vector with size, not using square bracket
        std::vector<std::map<std::string, int> > dict_vector(words.size());   
        // assign every map to every word which contains frequencies of every character
        for (auto i = 0; i < words.size(); i++){
            for (auto j = 0; j < words[i].size(); j++){
                // convert the char to string
                std::string cha;
                cha.push_back(words[i][j]);
                dict_vector[i][cha]++;
            }
        }
        // dict_vector[j].count(cha) can only cout the number of keys, which is 1
        for (auto i = 0; i < words[0].size(); ++i){
            std::string cha;
            cha.push_back(words[0][i]);
            int min_length = 100;
            bool flag = true;
            for (auto j = 0; j < words.size(); ++j){
                // check if have same character
                if (dict_vector[j][cha] == 0){
                    flag = false;
                    break;
                }
                else{
                    if (dict_vector[j][cha] < min_length){
                        // std::cout << cha << ": " << dict_vector[j][cha] << std::endl;
                        min_length = dict_vector[j][cha];
                    }
                }
            }
            // check if the same vactor and it has not appeared in the result vector
            if (flag && std::find(result.begin(), result.end(), cha) == result.end()){
                for (auto k = 0; k < min_length; ++k){
                    // std::cout << min_length << std::endl;
                    result.push_back(cha);
                } 
            }
        }
        return result;
    }
};

class Test {
public:
    std::vector<char> commonChars(std::vector<std::string>& words) {
        std::vector<char> result;
        std::cout << words[0] << std::endl;
        // std::cout << words[0].begin() << std::endl;
        std::vector<char> word0(words[0].begin(), words[0].end()); // not working for string
        std::vector<char> word1(words[1].begin(), words[1].end());

        std::set_intersection(word0.begin(), word0.end(),
                              word1.begin(), word1.end(),
                              std::back_inserter(result));
        return result;
    }
};

class Test2 {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<std::string> result_str;
        std::vector<char> result_char;

        // convert the words to vector containing char
        std::vector<std::vector<char>> vec_words(words.size());
        for (auto i = 0; i < words.size(); i++){
            for (auto j = 0; j < words[i].size(); j++){
                vec_words[i].push_back(words[i][j]);
            }
        }
        
        std::set_intersection(vec_words[0].begin(), vec_words[0].end(),
                              vec_words[1].begin(), vec_words[1].end(),
                              std::back_inserter(result_char));

        // change the char to string
        for (char cha : result_char){
            std::string char_str(1, cha);
            result_str.push_back(char_str);
        }
        return result_str;
    }
};

// not working now, because it cannot find the freq of a character
class Solution2 {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<std::string> result_str;
        std::vector<char> result_char(words[0].begin(), words[0].end());
        std::vector<char> result_char_copy(words[0].begin(), words[0].end());

        // vector has no member find
        // vector erase element by index, cannot by value
        // vector remove can delete all the elments with sam value
    
        for (std::string word : words){
            for (auto i = 0; i < result_char.size(); i++){
                // string find: https://www.cplusplus.com/reference/string/string/find/
                // if we cannot find some cha in the word, remove it
                std::cout << i << std::endl;
                if (word.find(result_char[i]) == std::string::npos){
                    std::cout << "delete: " << result_char[i] << std::endl; 
                    result_char.erase(result_char.begin() + i);
                }
            }
        }

        // change the char to string
        for (char cha : result_char){
            std::string char_str(1, cha);
            result_str.push_back(char_str);
        }
        return result_str;
    }
};

int main(){
    Solution2 solution;

    std::vector<std::string> words1 = {"bella","label","roller"};
    info(solution.commonChars(words1));

    std::vector<std::string> words2 = {"cool","lock","cook"};
    info(solution.commonChars(words2));

    std::vector<std::string> words3 = {"ab","abb","abba"};
    info(solution.commonChars(words3));

    std::vector<std::string> words4 = {"abaa","abb","abba"};
    info(solution.commonChars(words4));
}