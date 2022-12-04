import sys


def main():
    input = sys.stdin.readline

    t = int(input())
    n = []

    for i in range(t):
        n.append(int(input()))

    for j in n:
        if j % 3 == 0:
            print(str(j//3) + " " + str(j // 3 + 1) + " " + str(j//3-1))
        elif j % 3 == 1:
            print(str(j//3) + " " + str(j // 3 + 2) + " " + str(j//3-1))
        else:
            print(str(j//3 + 1) + " " + str(j // 3 + 2) + " " + str(j//3-1))

    return


if __name__ == '__main__':
    main()
