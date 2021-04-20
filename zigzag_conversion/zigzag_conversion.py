class Solution:
    def convert(self, s: str, numRows: int) -> str:
        rows = [[] for x in range(numRows)]
        pattern = self.getPattern(len(s), numRows)
        print(pattern)

        for i in range(len(s)):
            rows[pattern[i]].append(s[i])
        result = ""
        for row in rows:
            rowStr = "".join(row)
            result += rowStr
        return result

    def getPattern(self, length: int, numRows: int) -> [int]:
        unit = -1
        value = 0
        array = [0 for x in range(length)]

        if (numRows == 1):
            return array

        for i in range(length):
            array[i] = value
            if value == 0 or value == numRows - 1:
                unit *= -1
            value += unit
        return array


s = Solution()

print(s.convert("PAYPALISHIRING", 2))
print(s.convert("PAYPALISHIRING", 3))
print(s.convert("PAYPALISHIRING", 4))
print(s.convert("AB", 1))