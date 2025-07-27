A = input()

def run_length_encoding(target):
    encoded = ""
    curr_char = target[0]
    num_char = 1
    for target_char in target[1:]:
        if target_char == curr_char:
            num_char += 1
        else:
            encoded += curr_char + str(num_char)
            curr_char = target_char
            num_char = 1
    encoded += curr_char + str(num_char)
    return encoded

n = len(A)
ans = len(run_length_encoding(A))

for _ in range(n):
    # 문자열 회전: A = A[1:] + A[0]
    A = A[1:] + A[0]
    ans = min(ans, len(run_length_encoding(A)))

print(ans)
