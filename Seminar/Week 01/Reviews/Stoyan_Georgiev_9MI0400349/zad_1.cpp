#include <iostream>
#include <cmath>

// Този ред е лоша практика!
using namespace std;

// Липсва употреба на структури, както се изискваше по условие.
// На контролно/изпит това най-вероятно би довело до анулиране на задачата!

// Тази функция изглежда напълно безсмислена!
// Ако ще я ползваме за един cin, по-добре да си го напишем в main-а.
// function to enter the points
void enterPoints(int &x1, int &y1, int &z1, int &x2, int &y2, int &z2) {
    cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
    //x1,x2,y1,y2,z1,z2 cant be lower than -100 and higher than 100
    // Това само ще изкара съобщението, но няма по никакъв начин да ни попречи да продължим нататък!
    if (x1 < -100 || x1 > 100 || x2 < -100 || x2 > 100 || y1 < -100 || y1 > 100 || y2 < -100 || y2 > 100 || z1 < -100 || z1 > 100 || z2 < -100 || z2 > 100)
    {
        cout << "The coordinates must be between -100 and 100" << endl;
    }
    
}

// function to find the area of triangle
double findAreaOfTrinagle(int x1, int y1, int z1, int x2, int y2, int z2) {
    double distance1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double distance2 = sqrt(pow(x2 - x1, 2) + pow(z2 - z1, 2));
    double distance3 = sqrt(pow(y2 - y1, 2) + pow(z2 - z1, 2));

    double p = (distance1 + distance2 + distance3) / 2;
    double S = sqrt(p * (p - distance1) * (p - distance2) * (p - distance3));

    return S;
}

//sort the array
void sortArray(double *array, int N) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N - 1; j++) {
            if (array[j] > array[j + 1]) {
                double temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(){

int N;

int x1, y1, z1;
int x2, y2, z2;      

// enter the number of points
cin >> N;

// Липсва валидация за N!


// По условие се искаше да направите и сортирате ТРИЪГЪЛНИЦИ спрямо лицата им, а не само лицата им.
// Това е същото като да ти дам за задача да сортираш шишета на рафт спрямо височината им и ти се върнеш с един лист,
// на който си написал височините в сортиран ред. Реално заобикаляш проблема.
// За такива уточнения на контролно и изпит е напълно възможно да ти се анулира задачата, защото не е по условието.
// Също така липсва std::nothrow като аргумент на оператора new, което може да доведе до crash и се води като голяма грешка!
//create a custom array with dedicated memory
double *array = new double[N];

// Тази валидация трябва да е преди да заделим масива!!!!!!
// validate the number of points
if (N < 1 || N > 1000) {
    cout << "The number of points must be between 1 and 1000" << endl;
    return 1;
}

// enter the points and find the area of the triangle
for (size_t i = 0; i < N; i++){
     enterPoints(x1, y1, z1, x2, y2, z2);
    array[i] = findAreaOfTrinagle(x1, y1, z1, x2, y2, z2);
}
  
// sort the array
sortArray(array, N);

// print the area of the triangle
for (size_t i = 0; i < N; i++){
    cout << array[i] << endl;
}

// Не освобождаваме паметта, която сме заделили, което също се води голяма грешка!

}