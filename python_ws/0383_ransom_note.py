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