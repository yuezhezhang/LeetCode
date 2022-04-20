# time: 28ms, beat 22.89%
# RAM: 12.8MB, beat 94.48%
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # print(self.sum_square_digit(n))n
        appear_list = [n]
        while n != 1:
            n = self.sum_square_digit(n)
            if n in appear_list:
                return False
            else:
                appear_list.append(n)

        return True

    def sum_square_digit(self, n):
        square_sum = 0
        while  n != 0 :
            square_sum += (n%10)**2 
            n = int (n/10)
        return square_sum
    
if __name__ == "__main__":
    solution = Solution()

    print(solution.isHappy(2)) # False

    print(solution.isHappy(19)) # True