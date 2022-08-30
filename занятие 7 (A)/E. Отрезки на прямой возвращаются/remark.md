```objectivec
events = []
n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    events.append((b, b - a, a, i))
events.sort()
ans = [0] * n
nowsegs = []
for send, slen, sstart, snum in events:
    while len(nowsegs) > 0 and sstart <= nowsegs[-1][0]: 
        start, pnum = nowsegs.pop()
        ans[pnum] = snum + 1
    nowsegs.append((sstart, snum))

print(" ".join(map(str, ans)))
```


Slava Muravjev, [8/31/2022 12:16 AM]
попробуй print(" ".join(map(str, ans)))

First name Last name, [8/31/2022 12:22 AM]
[In reply to Slava Muravjev]
а как так получилось, что такой вывод чуть меньше времени жрет??

Slava Muravjev, [8/31/2022 12:22 AM]
да это фигня

Slava Muravjev, [8/31/2022 12:22 AM]
чуть меньше

Slava Muravjev, [8/31/2022 12:22 AM]
ну принт - не самая быстрая операция

Slava Muravjev, [8/31/2022 12:22 AM]
почитай по sys.readline

Slava Muravjev, [8/31/2022 12:22 AM]
или что-то такое

Slava Muravjev, [8/31/2022 12:22 AM]
sys.readlines()
