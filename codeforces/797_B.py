import sys


def main():
    input = sys.stdin.readline

    t = int(input())
    broke = False
    broke_2 = False

    for i in range(t):
        count = int(input())
        A = list(map(int, input().split()))
        B = list(map(int, input().split()))

        max_d = 0
        for j in range(count):
            if A[j] < B[j]:
                print("NO")
                broke = True
                break

            max_d = max(max_d, A[j] - B[j])

        if not broke:
            for k in range(count):
                if A[k] - max_d < B[k] and B[k] != 0:
                    print("NO")
                    broke_2 = True
                    break

            if not broke_2:
                print("YES")

        broke = False
        broke_2 = False

    return


if __name__ == '__main__':
    main()
