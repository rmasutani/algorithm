import sys

def area(points):
    xs = [p[0] for p in points]
    ys = [p[1] for p in points]

    return abs(max(xs) - min(xs)) * abs(max(ys) - min(ys))

def main():
    input = sys.stdin.readline
    N, K = map(int, input().rstrip().split())
    points = []
    for i in range(N):
        x, y = map(int, input().rstrip().split())
        points.append((x, y))

    points = sorted(points, key=lambda x: x[0]**2 + x[1]**2)
        
    print(area(points[:K]))
    


if __name__ == '__main__':
    main()
    