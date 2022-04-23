# time: 160ms, beat 13.39%
# RAM: 12.8 MB, beat 99.92%
class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        for i in ransomNote:
            if ransomNote.count(i) > magazine.count(i):
                return False

        return True

# time: 56ms, beat 54.45%
# RAM: 13.1MB, beat 72.77%
class Solution2(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        dict = {}
        for i in magazine:
            dict[i] = dict.get(i, 0) + 1
        for j in ransomNote:
            dict[j] = dict.get(j, 0) - 1
            if dict[j] < 0:
                return False

        return True
# use array to store the frequency of character saves more space, since 
# it will not need to store the key
# time: 44ms, beat 79.43%
# RAM: 13MB, beat 91.4%
class Solution3(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        array = [0] * 26
        # ord function to transform the char to ascii
        for i in magazine:
            array[ord(i) - ord('a')] += 1
        for j in ransomNote:
            array[ord(j) - ord('a')] -= 1
            if array[ord(j) - ord('a')] < 0:
                return False

        return True

if __name__ == "__main__":
    solution = Solution()

    ransomNote = "a"
    magazine = "b"
    print(solution.canConstruct(ransomNote, magazine))

    ransomNote = "a"
    magazine = "ba"
    print(solution.canConstruct(ransomNote, magazine))

    ransomNote = "ab"
    magazine = "abbb"
    print(solution.canConstruct(ransomNote, magazine))

    ransomNote = "aab"
    magazine = "baa"
    print(solution.canConstruct(ransomNote, magazine))