arr = list(map(int, input().split()))
a = arr[0]
b = arr[1]
c = arr[2]
total = a+b+c
mean = int(total / 3)
print(f"{total}\n{mean}\n{total - mean}")