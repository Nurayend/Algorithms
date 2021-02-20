stack = []
s = input().split()
for i in range(len(s)):
    if s[i] >= '0' and s[i] <= '9': 
        stack.append(int(s[i]))
    elif s[i] == ' ':
        continue
    else:
        right = stack[len(stack) - 1]
        stack.pop()
        left = stack[len(stack) - 1]
        stack.pop()
        if s[i] == '+':
            stack.append(left + right)
        elif s[i] == '-':
            stack.append(left - right)
        elif s[i] == '*':
            stack.append(left * right)
print(stack[len(stack) - 1])