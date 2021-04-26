class Solution:
    def myAtoi(self, s: str) -> int:
        result = 0
        #! Step 1: ignore all whitespaces 
        index = 0
        while index < len(s):
            if s[index] == " ":
                index += 1
            else:
                break

        #! Step 2: check for symbol
        if index < len(s):
            if s[index] == "+":
                symbol = 1
                index += 1
            elif s[index] == "-":
                symbol = -1
                index += 1
            else:
                symbol = 1
        else:
            return result

        #! Step 3: read all sequential digits
        while index < len(s):
            try:
                digit = int(s[index])
                result *= 10
                result += digit
                index += 1
            except:
               break

        result *= symbol

        if result > 2**31 - 1:
            result = 2**31 - 1

        if result < -2**31:
            result = -2**31

        return result

tests = [
    ("42", 42),
    ("   -42", -42),
    ("4193 with words", 4193),
    ("words and 987", 0),
    ("-91283472332", -2147483648),
    ("     ", 0),
    ("", 0)
]

s = Solution()

total = 0
for arg, exp in tests:
    print(f"Expected: {arg} -> {exp}")
    res = s.myAtoi(arg)
    print(f"Expected: {arg} -> {res}")
    print(exp == res)
    print("-" * 30)
    total += exp == res

print(f"result: {total}/{len(tests)}")
