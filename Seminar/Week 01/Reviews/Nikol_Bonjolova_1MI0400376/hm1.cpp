// STL библиотеки(като vector и algorithm) са ви забранени за използване,
// освен ако не ви е казано изрично, че можете.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Лоша практика е употребата на този ред.
using namespace std;

// Това е изцяло материал, който предстои да учим.
// Нека не избързваме с употребата на неща, които не са взети, защото е възможно да се таксуват на контролно/изпит.
class Triangle {
public:
    int x1, y1, x2, y2, x3, y3;

    Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
    }

    double area() const {
        return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    }
};

int main() {
    int N;
    cin >> N;
    // Нямаш валидация за N.
    // Какво ще стане ако въведа отрицателно число?
    vector<Triangle> triangles;

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        triangles.push_back(Triangle(x1, y1, x2, y2, x3, y3));
    }

    // По условие се искаше да направите и сортирате ТРИЪГЪЛНИЦИ спрямо лицата им, а не само лицата им.
    // Това е същото като да ти дам за задача да сортираш шишета на рафт спрямо височината им и ти се върнеш с един лист,
    // на който си написал височините в сортиран ред. Реално заобикаляш проблема.
    // За такива уточнения на контролно и изпит е напълно възможно да ти се анулира задачата, защото не е по условието.
    vector<double> areas;
    // auto ви е строго забранена ключова дума!
    for (const auto& t : triangles) {
        areas.push_back(t.area());
    }

    sort(areas.begin(), areas.end());

    for (size_t i = 0; i < areas.size(); i++) {
        cout << areas[i];
        if (i != areas.size() - 1) cout << " ";
    }

    return 0;
}
