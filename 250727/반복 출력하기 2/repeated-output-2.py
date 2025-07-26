n = int(input())

def a():
    print("HelloWorld")

def func(n):
    if n == 0:
        return

    func(n - 1)
    print("HelloWorld")

func(n)