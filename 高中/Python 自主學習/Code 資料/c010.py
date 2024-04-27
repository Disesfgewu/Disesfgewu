
import bisect
Interval = []
while 1:
    try:
        x = int(input(""))
    except:
        break
    bisect.insort(Interval, x)
    if len(Interval) % 2 == 0:
        print((Interval[len(Interval)//2-1] + Interval[len(Interval)//2]) // 2)
    else:
        print(Interval[len(Interval)//2])
