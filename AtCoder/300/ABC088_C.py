import sys 
import numpy as np 

def main():
    input = sys.stdin.readline
    mat = []
    for i in range(3):
        mat.append(sum(list(map(int, input().split()))))
    
    print(mat)
    


if __name__ == "__main__":
    main()