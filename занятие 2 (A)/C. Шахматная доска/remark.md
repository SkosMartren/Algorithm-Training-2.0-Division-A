раздел solution можно сократить до
```objectivec
vector<pair<int, int» steps = { { -1, 0 } , { 1, 0 } , { 0, 1 }, { 0, - 1 }
...
for (auto& [x, y] : cells) {
 for (auto& [dx, dy] : steps) {
  int nx = x + dx, ny = y + dy;
  if (!used[nx][ny]) ++perimeter;
 }
}
```
