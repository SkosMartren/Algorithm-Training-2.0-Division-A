n = int(input())
events = []
for i in range(n):
    s, e = map(int, input().split())
    events.append((s, i + 1)) 
    events.append((e, -(i + 1))) 

events.sort()
nowcivs = set()
minintersect = events[-1][0] - events[0][0] + 1
for event in events:
    if event[1] > 0:
        nowcivs.add(event[1]) 
        prevstart = event
    else:
        if event[0] - prevstart[0] < minintersect:
            if prevstart[1] != -event[1]:
                ans = prevstart[1], -event[1]
                minintersect = event[0] - prevstart[0]
            else:
                if len(nowcivs) > 1:
                    setit = iter(nowcivs) 
                    bigciv = next(setit)
                    if bigciv == -event[1]:
                        bigciv = next(setit)
                    minintersect = event[0] - prevstart[0] 
                    ans = bigciv, -event[-1] 
        nowcivs.discard(-event[1])

if minintersect == events[-1][0] - events[0][0] + 1: 
    print(0)
else:
    print(*ans)


