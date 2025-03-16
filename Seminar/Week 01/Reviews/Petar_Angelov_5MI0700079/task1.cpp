// STL библиотеки(като vector и algorithm) са ви забранени за използване,
// освен ако не ви е казано изрично, че можете.
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

// Този ред е много лоша практика!
using namespace std;
 
double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return fabs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0;
}
 
int main(){
    int n;
    cin >> n;
    // Нямаш валидация за n.
    // Какво става ако въведа отрицателно число?

    
    // По условие се искаше да направите и сортирате ТРИЪГЪЛНИЦИ спрямо лицата им, а не само лицата им.
    // Това е същото като да ти дам за задача да сортираш шишета на рафт спрямо височината им и ти се върнеш с един лист,
    // на който си написал височините в сортиран ред. Реално заобикаляш проблема.
    // За такива уточнения на контролно и изпит е напълно възможно да ти се анулира задачата, защото не е по условието.
    vector<double> areas(n);
    for (int i = 0; i < n; i++){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        areas[i] = triangleArea(x1, y1, x2, y2, x3, y3);
    }
    sort(areas.begin(), areas.end());
    for (int i = 0; i < n; i++){
        cout << areas[i];
        if(i < n-1) cout << " ";
    }
    return 0;
}
