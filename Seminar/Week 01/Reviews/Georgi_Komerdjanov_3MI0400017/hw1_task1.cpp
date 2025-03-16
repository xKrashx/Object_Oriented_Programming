#include <iostream>
// Тази и всички останали stl библиотеки са забранени за употреба в курса,
// освен ако не ви е казано изрично в условието, че можете.
#include <vector>
#include <cmath>

// Това е много лоша практика, както обсъждахме на първият семинар.
// На контролно, изпит или проект със сигурност ще се таксува.
using namespace std;

double triangleAreaDeterminant(int x1, int y1, int x2, int y2, int x3, int y3) {

    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

void bubbleSort(vector<double>& arr) {

    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {

    // В случая си хванал проблемните стойности с валидацията отдолу.
    // Но като хубаво правило си слагай размерът на структури да ти е unsigned число.
    // За предпочитане даже може да използваш size_t, тъй като той е запазен за размери и индексация.
    int n;
    cin >> n;
    if (n < 1 || n > 1000) {

        cerr << "Error. N must be: 1 <= N <= 1000" << endl;
        return 1;
    }

    // В условието се изискваше да се създаде структура описваща триъгълник и да се сортират триъгълници, а не просто лица.
    // Това е същото като да ти дам за задача да сортираш шишета на рафт спрямо височината им и ти се върнеш с един лист,
    // на който си написал височините в сортиран ред. Реално заобикаляш проблема.
    // За такива уточнения на контролно и изпит е напълно възможно да ти се анулира задачата, защото не е по условието.
    vector<double> areas;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        if (x1 < -100 || x1 > 100 || y1 < -100 || y1 > 100 ||
            x2 < -100 || x2 > 100 || y2 < -100 || y2 > 100 ||
            x3 < -100 || x3 > 100 || y3 < -100 || y3 > 100) {

            cerr << "Error. xi,yi must be: -100 <= xi, yi <= 100" << endl;
            return 1;
        }

        double area = triangleAreaDeterminant(x1, y1, x2, y2, x3, y3);
        areas.push_back(area);
    }

    bubbleSort(areas);

    for (size_t i = 0; i < areas.size(); i++) {

        if (i > 0) cout << " ";
        cout << areas[i];
    }
    cout << endl;

    return 0;
}