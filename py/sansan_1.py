import sys
from collections import defaultdict

def step_1():
    M = int(input())
    menus = {}
    for i in range(M):
        D, S, P = map(int, input().rstrip().split()) # [D, S, P]
        menus[D] = [S, P]
    
    order_info = []
    for line in sys.stdin.readlines():
        order, T, D, N = line.rstrip().split()
        T = int(T)
        D = int(D)
        N = int(N)
        # print(menus)
        if N > menus[D][0]:
            print("sold out", T)
        else:
            menus[D][0] -= N
            for i in range(N):
                print("received order", T, D)
        

def step_2():
    M, K = map(int, (input().rstrip().split()))
    menus = {}
    for i in range(M):
        D, S, P = map(int, input().rstrip().split()) # [D, S, P]
        menus[D] = [S, P]
    
    queue = defaultdict(int)
    wait = []
    for line in sys.stdin.readlines():
        info = line.rstrip().split()

        if len(info) == 4: # received order
            if sum(list(queue.values())) < K:
                queue[info[-1]] += 1
                print(info[-1])
            else:
                wait.append(info[-1])
                print("wait")
        
        else: # complete
            if  queue[info[1]] == 0:
                print("unexpected input")
                del queue[info[1]]
                continue
                
            del queue[info[1]]
            if len(wait) != 0:
                queue[wait[0]] += 1 # add top of the wait list
                print("ok", wait[0])
                wait.pop(0)
            else:
                print("ok")

def step_3():
    M = int(input())
    menus = {}
    for i in range(M):
        D, S, P = map(int, input().rstrip().split()) # [D, S, P]
        menus[D] = [S, P]
    
    queue = []
    for line in sys.stdin.readlines():
        info = line.rstrip().split()

        if len(info) == 4: # receive order
            queue.append((info[-2], info[-1]))
        else:
            for i, o in enumerate(queue):
                if o[1] == info[1]:
                    print("ready", o[0], o[1])
                    queue.pop(i)
                    break

    
def step_4():
    M = int(input())
    menus = {}
    for i in range(M):
        D, S, P = map(int, input().rstrip().split()) # [D, S, P]
        menus[D] = [S, P]
    
    order_p = defaultdict(int)
    
    queue = []
    for line in sys.stdin.readlines():
        info = line.rstrip().split()

        if len(info) == 4: # receive order
            queue.append((info[2], info[3]))

            # acc the price
            order_p[info[-2]] += menus[int(info[-1])][1]
        
        elif len(info) == 3: # ready
            for i, o in enumerate(queue):
                if o[0] == info[1] and o[1] == info[2]:
                    queue.pop(i)
                    break
        
        else: # check
            # have to wait if any of the orders are still in the queue
            found = False
            for o in queue:
                if o[0] == info[1]:
                    found = True
                    print("please wait")
                    break
                
            if not found:
                print(order_p[info[-1]])
                order_p[info[-1]] = 0

    
    




def main():
    input = sys.stdin.readline

    # step 1
    step = int(input()) # 1
    if step == 1:
        step_1()
    if step == 2:
        step_2()
    if step == 3:   
        step_3()
    if step == 4:
        step_4()



    return

if __name__ == '__main__':
    main()
    