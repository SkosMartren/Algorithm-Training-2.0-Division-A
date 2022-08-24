def getcnt(s):
    cnt = {}
    for c in s:
        if c not in cnt:
            cnt[c] = 0
        cnt[c] += 1
    return cnt

x = input()
y = input()
xsyms = getcnt(x)
ysyms = getcnt(y)
intersect = xsyms.keys() & ysyms.keys()
ans = []
while len(intersect) > 0:
    maxsym = max(intersect)
    usedmaxsyms = min(xsyms[maxsym], ysyms[maxsym])
    ans.append(usedmaxsyms * maxsym)
    x = x.replace(maxsym, '#', usedmaxsyms)
    x = x[x.rfind('#') + 1:]
    y = y.replace(maxsym, '*', usedmaxsyms)
    y = y[y.rfind('*') + 1:]
    xsyms = getcnt(x)
    ysyms = getcnt(y)
    intersect = xsyms.keys() & ysyms.keys()
print(''.join(ans))
