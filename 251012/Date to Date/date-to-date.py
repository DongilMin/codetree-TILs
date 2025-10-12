m1, d1, m2, d2 = map(int, input().split())

months = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

# 1. 시작일을 포함해야 하므로 1부터 카운트 시작
cnt_day = 1 

while True:
    # 2. 시작일과 종료일이 같으면 루프를 즉시 종료
    if m1 == m2 and d1 == d2:
        break
    
    # 3. 날짜를 하루 넘길 때마다 카운트
    cnt_day += 1
    d1 += 1

    if d1 > months[m1]:
        d1 = 1
        m1 += 1

print(cnt_day)