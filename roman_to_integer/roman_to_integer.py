class Solution:

    def __init__(self):
        self.conversionChart = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

    def convertChar(self, chr: str) -> int:
        return self.conversionChart.get(chr)

    def romanToInt(self, s: str) -> int:
        numArray = [self.convertChar(x) for x in s]
        num = 0
        iterator = 0

        while iterator < len(numArray):
            if iterator == len(numArray) - 1:
                num += numArray[iterator]
                iterator += 1
            elif numArray[iterator] < numArray[iterator + 1]:
                num += numArray[iterator + 1] - numArray[iterator]
                iterator += 2
            else:
                num += numArray[iterator]
                iterator += 1

        return num

s = Solution()


tests = [
    ("III", 3),
    ("IV", 4),
    ("LVIII", 58),
    ("MCMXCIV", 1994),
    ("I", 1),
    ("XX", 20),
    ("XIX", 19)
    ]

total = 0
for args, exp in tests:
    res = s.romanToInt(args)
    print(f"Expected: {args} -> {exp}")
    print(f"Actual:   {args} -> {res}")
    print(res == exp)
    total += res == exp
    print("-" * 30)

print(f"{total} / {len(tests)}") 
