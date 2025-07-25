Y, M, D = map(int, input().split())

def is_yoon(year):
    if year % 4 != 0:
        return False
    elif year % 100 != 0:
        return True
    elif year % 400 == 0:
        return True
    else:
        return False

def season(M):
    if 3 <= M <= 5:
        return "Spring"
    elif 6 <= M <= 8:
        return "Summer"
    elif 9 <= M <= 11:
        return "Fall"
    else:
        return "Winter"

def func(Y, M, D):
    # 월별 최대 일수 정의
    days_in_month = [31, 29 if is_yoon(Y) else 28, 31, 30, 31, 30,
                     31, 31, 30, 31, 30, 31]

    # 월과 일이 유효한지 검사
    if M < 1 or M > 12 or D < 1 or D > days_in_month[M - 1]:
        print(-1)
    else:
        print(season(M))

func(Y, M, D)
