A = input()

# Please write your code here.
def is_palindrome(A):
    for i in range(len(A)):
        if A[i] != A[len(A) - i - 1]:
            return False
    return True

if is_palindrome(A):
    print("Yes")
else:
    print("No")