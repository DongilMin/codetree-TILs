A = input()

# Please write your code here.
def is_palindrome(A):
    return A == A[::-1]

if is_palindrome(A):
    print("Yes")
else:
    print("No")