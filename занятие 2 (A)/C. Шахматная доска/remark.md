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



\
\
First name Last name, [8/9/2022 9:28 PM]
Задача: https://contest.yandex.ru/contest/28736/problems/C/

Можно ли ее пропустить, если я готовлюсь только к собесу?

Slava Muravjev, [8/9/2022 11:29 PM]
ну я бы сказал, что идеи  
- посчитаем ответ как сумму по отдельным частям  
- сохраним список переходов вместо копипасты   
может помочь на собесе
