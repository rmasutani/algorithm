import sys
from collections import Counter, defaultdict
from itertools import combinations

def num_combination(n, k):
    if k == 0 or n == k:
        return 1
    
    return num_combination(n-1, k) + num_combination(n-1, k-1)

def main():
    input = sys.stdin.readline
    N = int(input())
    S = []
    for i in range(N):
        S.append(input())
    
    letters = ["M", "A", "R", "C", "H"]
    counter = defaultdict(int)
    for s in S:
        if s[0] in letters:
            counter[s[0]] += 1

    if len(counter) < 3:
        print(0)
        return
    
    cmb = list(combinations(counter.keys(), 3))
    ans = 0

    for c in cmb:
        ans += (counter[c[0]] * counter[c[1]] * counter[c[2]])
    
    print(ans)
    

if __name__ == '__main__':
    main()
    