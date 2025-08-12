n = int(input())
visited = [False] * (n + 1)
answer = []

def print_answer():
    for elem in answer:
        print(elem, end=" ")
    print()

def choose_num(curr):
    if curr == 0:
        print_answer()
        return
    else:
        for i in range(n , 0, -1):
            if visited[i]:
                continue
            
            visited[i] = True
            answer.append(i)
            choose_num(curr - 1)
            answer.pop()
            visited[i] = False

choose_num(n)
