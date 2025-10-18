N, C, G, H = map(int, input().split())
ranges = [tuple(map(int, input().split())) for _ in range(N)]
max_val =
def get_score(a, b, t):
    if t < a:
        return C
    elif a <= t and t <= b:
        return G
    else:
        return H
