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

int main(){
    Solution solution;

    std::vector<std::string> words1 = {"bella","label","roller"};
    info(solution.commonChars(words1));

    std::vector<std::string> words2 = {"cool","lock","cook"};
    info(solution.commonChars(words2));

    std::vector<std::string> words3 = {"ab","abb","abba"};
    info(solution.commonChars(words3));
}