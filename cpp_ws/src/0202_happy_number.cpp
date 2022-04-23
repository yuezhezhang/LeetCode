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

// We can use fast iterator and slow iterator to find the cycle.
// The fast iterator goes two steps every iteration and slow iterator goes one step 
// every iteration, when they are equal, then it is a cycle. Now we need to determine 
// if the cycle is yielded by 1, if so then it is a happy number, oherwise it is not.
// It should be mentioned that it is not advisable to use set or recursion to represent 
// the cycle, since the set might be too large to store.
// time: 0ms, beat 100%
// RAM: 5.8MB, beat 90.04%
class Solution2 {
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
        int slow = n, fast = n;
        do{
            slow = square_sum_digit(slow);
            fast = square_sum_digit(fast);
            fast = square_sum_digit(fast);
            std::cout << "Slow iterator: " << slow << std::endl;
            std::cout << "Fast iterator: " << fast << std::endl;
        }while (slow != fast);

        return slow == 1;
    }
};


int main(){
    Solution2 solution;
    
    std::cout << solution.isHappy(1) <<std::endl;
    std::cout << solution.isHappy(2) <<std::endl;
    std::cout << solution.isHappy(19) <<std::endl;

    return 0;
}