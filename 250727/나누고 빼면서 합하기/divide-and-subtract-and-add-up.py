n, m = map(int, input().split())
A = list(map(int, input().split()))

def get_answer():
    global m

    result = 0
    while m:
        result += A[m - 1]  # m은 1-based, A는 0-based이므로 -1 필요

        if m % 2 == 0:
            m //= 2
        else:
            m -= 1

    return result

print(get_answer())
