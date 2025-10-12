m1, d1, m2, d2 = map(int, input().split())

months = [0, 31, 30, 31, 30 ,31 ,30, 31, 31, 30, 31, 30, 31]
cnt_day = 1
while True:

    if m1 == m2 and d1 == d2:
        print(cnt_day)
        break
    
    d1 += 1
    cnt_day += 1

    if months[m1] < d1:
        m1 += 1
        d1 = 1