import re
class Solution:
    def __init__(self):
        self.regex = re.compile("[+-]?((\d+\.?\d*)|(\.\d+))([eE][+-]?\d+)?")

    def isNumber(self, s: str) -> bool:
        return not None == self.regex.fullmatch(s)


tests = [
    ("2", True),
    ("0089", True),
    ("-0.1" , True),
    ("+3.14", True),
    ("4.", True),
    ("-.9", True),
    ("2e10", True),
    ("-90E3", True),
    ("3e+7", True),
    ("+6e-1", True),
    ("53.5e93", True),
    ("-123.456e789", True),
    ("abc", False),
    ("1a", False),
    ("1e", False),
    ("e3", False),
    ("99e2.5", False),
    ("--6", False),
    ("-+3", False),
    ("95a54e53", False)
]

total = 0
s = Solution()

for args, exp in tests:
    print(f"Expected: {args} -> {exp}")
    res = s.isNumber(args)
    print(f"Actual: {args} -> {res}")
    print(res == exp)
    total += exp == res
    print("-" * 30)

print(f"Result: {total}/{len(tests)}")
