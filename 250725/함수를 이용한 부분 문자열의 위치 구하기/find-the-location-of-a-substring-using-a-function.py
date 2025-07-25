text = input()
pattern = input()

def func():
    index = text.find(pattern)
    if index == -1:
        return -1
    else:
        return index

print(func())