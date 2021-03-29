import sys

def main():
    input = sys.stdin.readline
    path = sys.argv[1]

    with open(path) as f:
        nums = list(map(int, f.read().rstrip().split()))

    d = [0]*(len(nums)+1)
    
    for n in nums:
        d[n-1] += 1
    
    for i, c in enumerate(d):
        if c != 1:
            print(i+1)
            return
    

if __name__ == '__main__':
    main()
    