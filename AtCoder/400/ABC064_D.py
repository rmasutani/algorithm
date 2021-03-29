import sys

def main():
    input = sys.stdin.readline
    N = int(input())
    S = input().rstrip()

    stack = []
    for s in S:
        if len(stack) == 0 or\
            s == '(' or\
            (s == ')' and stack[-1] == ')'):
            stack.append(s)
        else:
            stack.pop()
    
    ans = S
    for s in stack:
        if s == ')':
            ans = '(' + ans
        else:
            ans += ')'
    
    print(ans)


if __name__ == "__main__":
    main()