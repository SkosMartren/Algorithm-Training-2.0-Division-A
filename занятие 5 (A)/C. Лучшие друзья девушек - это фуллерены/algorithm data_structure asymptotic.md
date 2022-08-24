An array of integers is given. Output all triples of elements
https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

Если квадрат наибольшей стороны меньше суммы квадратов двух других сторон: с² < a²+b² треугольник остроугольный.  
Если квадрат наибольшей стороны больше суммы квадратов двух других сторон: с² > a²+b² – треугольник тупоугольный.  
Если квадрат наибольшей стороны равен сумме квадратов двух других сторон: с² = a²+b² – треугольник прямоугольный.


Denis Paukaev, [8/24/2022 6:48 PM]
[In reply to First name Last name]
я могу конечно гениальный вариант предложить, но это прям так себе

    std::string s = "12345";
    std::sort(s.begin(), s.end());

    int k = 3;

    std::set<std::string> perms;

    do {
        perms.emplace(s.substr(0, k));
    } while (std::next_permutation(s.begin(), s.end()));

    for(const auto& perm: perms) {
        std::cout << perm << '\n';
    }

Till Schneider, [8/24/2022 7:36 PM]
[In reply to First name Last name]
https://godbolt.org/z/eahfsE3Tq
