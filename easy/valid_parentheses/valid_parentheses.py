class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for char in s:
            #print(f'char: {char}')
            if char in ['(', '[', '{']:
                stack.append(char)

            else:
                if len(stack) == 0:
                    return False

                topStack = stack.pop()
                
                #! break conditions
                if ord(char) - ord(topStack) > 2:
                    return False
        return len(stack) == 0



tests = [
    ("()", True),
    ("()[]{}", True),
    ("(]", False),
    ("([)]", False),
    ("{[]}", True),
    ("(", False),
    (")", False),
    ("(){[]}()", True),
    ("(())", True),
    ("(([))]", False),
    ("(([{}]))", True)
]

s = Solution()
total = 0
for args, exp in tests:
    res = s.isValid(args)
    print(f"Expected: {args} -> {exp}")
    print(f"Actual: {args} -> {res}")
    print(res == exp)
    print('-' * 30)
    total += res == exp

print(f'Score: {total} / {len(tests)}')