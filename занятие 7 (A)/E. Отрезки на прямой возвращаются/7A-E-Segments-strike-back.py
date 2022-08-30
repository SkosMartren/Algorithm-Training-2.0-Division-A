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

print(*ans)

