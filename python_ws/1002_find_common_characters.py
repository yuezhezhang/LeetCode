class Solution(object):
    def commonChars(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        # get the intersection characters
        intersection_set = set(words[0])
        for word in words:
            intersection_set = intersection_set & set(word)
        common_chars = []
        for char in intersection_set:
            num = 100
            for word in words:
                if list(word).count(char) < num:
                    num = list(word).count(char)
            for i in range(num):
                common_chars.append(char)
        
        return common_chars

class Solution2(object):
    def commonChars(self, A):
        """
        :type A: List[str]
        :rtype: List[str]
        """
        res=[]
        if not A:
            return res
        key=set(A[0])
        for k in key:
            minnum=min(a.count(k) for a in A)
            res+=minnum*k
        return res



if __name__ == "__main__":
    solution = Solution()

    words_1 = ["bella","label","roller"]
    print(solution.commonChars(words_1))

    words_2 = ["cool","lock","cook"]
    print(solution.commonChars(words_2))
