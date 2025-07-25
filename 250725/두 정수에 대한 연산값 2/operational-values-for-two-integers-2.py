a, b = map(int, input().split())

# Please write your code here.
def func(a, b):
    a = a + 10 if a < b else a * 2
    b = b + 10 if b < a else b * 2
    return a, b

a, b = func(a, b)
print(a, b, end=" ")