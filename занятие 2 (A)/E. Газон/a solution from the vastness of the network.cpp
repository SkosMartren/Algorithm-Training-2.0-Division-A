// https://plusplusmustlive11.blogspot.com/2020/03/531-httpsacmp.html 

/*
Проблема задачи заключается в выборе оптимальной стратегии расчетов, поскольку решение «в лоб» ведет к вылету за дефицитом времени. 
Здесь нужно считать не число точек прямоугольника, попавших в круг, а наоборот, число точек круга, попавших в прямоугольник.
*/

#include <iostream>
#include <algorithm>

using namespace std;

long long x1, yy1, x2, yy2, x3, yy3;

long long kol(long long x, long long z1, long long z2) { // функция подсчета числа точек
// по вертикали
       long long min1, max1, k;
       if (x < x1 || x > x2 || z1 > yy2 || z2 < yy1) k = 0; // если точка вне прямоуг.
       else { // внутри прямоугольника
             min1 = yy1;
             if (z1 > yy1) min1 = z1; // двигаем границу снизу
             max1 = yy2;
             if (z2 < yy2) max1 = z2; // и сверху
             k = max1 - min1 + 1; // в зачет идет все между границами
       }
       return k;
}

int main() {
       long long k, r, y;
       cin >> x1 >> yy1 >> x2 >> yy2;
       cin >> x3 >> yy3 >> r;
       k = kol(x3, yy3 - r, yy3 + r); // определяем число точек напротив центра окр.
                                        // сверху и снизу
       y = r;
       for (long long x = 1; x <= r - 1; x++) { // смещение от центра до радиуса
             while (x * x + y * y > r * r) y--; // ищем второе смещение
             k = k + kol(x3 + x, yy3 - y, yy3 + y) + kol(x3 - x, yy3 - y, yy3 + y);
       }      // смещения х справа и слева, складываем суммы точек
             // а теперь точки справа и слева от центра
       k = k + kol(x3 + r, yy3, yy3) + kol(x3 - r, yy3, yy3);
       cout << k;
       return 0;
}
