#include "helper.cpp"
#include <set>
#include <cmath>

// time: 4ms, beat 45.68%
// RAM: 6.3MB, beat 6.83%
class Solution {
public:
    int square_sum_digit(int n) {
        int square_sum = 0;
        while (n != 0){
            square_sum += pow(n%10, 2); 
            n = int (n/10);
        }
        return square_sum;
    }

    // the definition of square_sum_digit must be put above
    bool isHappy(int n) {
        // std::cout << square_sum_digit(n) << std::endl;
        // std::cout << pow(n%10, 2) << std::endl;

        std::set<int> appear_set = {n};
        while (n != 1){
            n = square_sum_digit(n);
            if (appear_set.find(n) != appear_set.end())
                return false;
            else
                appear_set.insert(n);
        }
        return true;
    }
};

int main(){
    Solution solution;
    
    std::cout << solution.isHappy(1) <<std::endl;
    std::cout << solution.isHappy(2) <<std::endl;
    std::cout << solution.isHappy(19) <<std::endl;

    return 0;
}