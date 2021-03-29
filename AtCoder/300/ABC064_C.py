import sys

def main():
    input = sys.stdin.readline
    N = int(input())
    a = map(int, input().rstrip().split())

    NUM_COLORS = 8
    colors = [0]*(NUM_COLORS+1)

    for i in a:
        if 1 <= i <= 399:
            colors[0] += 1
        elif 400 <= i <= 799:
            colors[1] += 1
        elif 800 <= i <= 1199:
            colors[2] += 1
        elif 1200 <= i <= 1599:
            colors[3] += 1
        elif 1600 <= i <= 1999:
            colors[4] += 1
        elif 2000 <= i <= 2399:
            colors[5] += 1
        elif 2400 <= i <= 2799:
            colors[6] += 1
        elif 2800 <= i <= 3199:
            colors[7] += 1
        else:
            colors[8] += 1
    
    none_zeros = 0
    for i in range(NUM_COLORS):
        if colors[i] != 0:
            none_zeros += 1

    if none_zeros != 0 or colors[-1] == 0: 
        min_ans = none_zeros
    else:
        min_ans = none_zeros + 1
 
    max_ans = none_zeros + colors[-1]

    

    print(min_ans, max_ans)


if __name__ == "__main__":
    main()