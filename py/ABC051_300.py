import sys

def main():
    input = sys.stdin.readline
    sx, sy, tx, ty = map(int, input().rstrip().split())

    horiz = tx - sx
    vert = ty - sy

    first_move = "U"*vert + "R"*horiz + "D"*vert + "L"*horiz
    second_move_go = "L" + "U"*(vert+1) + "R"*(horiz+1) + "D"
    second_move_back = "R" + "D"*(vert+1)+ "L"*(horiz+1) + "U" 
    print(first_move + second_move_go + second_move_back)

if __name__ == "__main__":
    main()