n, k = map(int, input().split())
s = input()
pairs = {}
for i in range(k):
  pair = input()
  if pair[0] not in pairs:
    pairs[pair[0]] = []
  pairs[pair[0]].append(pair[1])
cnt = {}
ans = 0
for i in range(len(s) - 1, -1, -1):
  if s[i] in pairs:
    for next in pairs[s[i]]:
      if next in cnt:
        ans += cnt[next]
  if s[i] not in cnt:
    cnt[s[i]] = 0
  cnt[s[i]] += 1
print(ans)
