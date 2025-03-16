#include <iostream>

// Една структура Point би ти била полезна!
struct Triangle {
  int x1;
  int y1;
  int x2;
  int y2;
  int x3;
  int y3;
};

// Подаваме по константна референция там където само ще четем!
// const Triangle& triangle
double findArea(Triangle triangle) {
//This is a formula.
  double result = 0.5 * ((triangle.x1 * triangle.y2 + triangle.y1 * triangle.x3 + triangle.x2 * triangle.y3 - triangle.y1 * triangle.x2 -  triangle.x1 * triangle.y3 - triangle.y2 * triangle.x3));
  if (result < 0) {
    result *= -1;
  }
  return result;
}

double findMinimum(double *area, unsigned &N) {
  double minimum = area[0];
  for (int i = 0; i < N; i++) {
    if (area[i] < minimum) {
      minimum = area[i];
    }   
  }
  return minimum;
}

// Това не се изисква по условие!
void deleteMember(double *area, double &minimum, unsigned &M){
  
  for (int i = 0; i < M; i++) {
    if (area[i] == minimum) {
      int j = i;
      for (j; j < M; j++) {
        area[j] = area[j + 1];
      } 
      M--;
    }
  }
}

int main(){
  unsigned N = 0;

  std::cout << "Enter the number of triangles: ";

  std::cin >> N;
  if (!(1 <= N && N <= 1000)) {
    std::cout << "N must be between 1 and 1000." << std::endl;;
    return 1;
  }
/*I need a copy of N for deleteMember*/
  unsigned M = N;
  Triangle *triangle = new(std::nothrow) Triangle[N];
  if (triangle == nullptr) {
    std::cout << "Couldn't allocate memory for triangle. Is N positive?" << std::endl;
    return 1;
  }

  // При всички последващи return-ове в if-овете, които са написани има memory leak!
  // Това е защото директния return не вика delete, за да освободи паметта!
  // Това се счита за голяма грешка и на контролно/изпит би се таксувало за всяка една поява!!!

  std::cout << "Enter coordinates like X1 Y1 X2 Y2 X3 Y3: " << std::endl;
  for (int i = 0; i < N; i++) {
    std::cin >> triangle[i].x1;
    if (!(-100 <= triangle[i].x1 && triangle[i].x1 <= 100)) {
      std::cout << "Xi and Yi must be between -100 and 100." << std::endl;
      return 0;
    }
    std::cin >> triangle[i].y1;
    if (!(-100 <= triangle[i].y1 && triangle[i].y1 <= 100)) {
      std::cout << "Xi and Yi must be between -100 and 100." << std::endl;;
      return 0;
    }
    std::cin >> triangle[i].x2;
    if (!(-100 <= triangle[i].x2 && triangle[i].x2 <= 100)) {
      std::cout << "Xi and Yi must be between -100 and 100." << std::endl;;
      return 0;
    }
    std::cin >> triangle[i].y2;
    if (!(-100 <= triangle[i].y2 && triangle[i].y2 <= 100)) {
      std::cout << "Xi and Yi must be between -100 and 100." << std::endl;;
      return 0;
    }
    std::cin >> triangle[i].x3;
    if (!(-100 <= triangle[i].x3 && triangle[i].x3 <= 100)) {
      std::cout << "Xi and Yi must be between -100 and 100." << std::endl;;
      return 0;
    }
    std::cin >> triangle[i].y3;
    if (!(-100 <= triangle[i].y3 && triangle[i].y3 <= 100)) {
      std::cout << "Xi and Yi must be between -100 and 100." << std::endl;;
      return 0;
    }
    
  }
  
  // По условие се искаше да направите и сортирате ТРИЪГЪЛНИЦИ спрямо лицата им, а не само лицата им.
  // Това е същото като да ти дам за задача да сортираш шишета на рафт спрямо височината им и ти се върнеш с един лист,
  // на който си написал височините в сортиран ред. Реално заобикаляш проблема.
  // За такива уточнения на контролно и изпит е напълно възможно да ти се анулира задачата, защото не е по условието.
  double *area = new(std::nothrow) double[N];
  if (area == nullptr) {
    std::cout << "Couldn't allocate memory for area. Is N positive?" << std::endl;
    return 1;
  }

  for (int i = 0; i < N; i++) {
    area[i] = findArea(triangle[i]);
    if (area[i] == 0) {
      std::cout << std::endl << "Triangle " << i + 1 << " has an area of zero. That means its three points lie on the same line." << std::endl;
    }
  }

  double *sortedArea = new(std::nothrow) double(N);
  if (sortedArea == nullptr) {
    std::cout << "Couldn't allocate memory for sorted area. Is N positive?" << std::endl;
    return 1;
  }

  for (int i = 0; i < N; i++) {
    double minimum = findMinimum(area, M);
    sortedArea[i] = minimum;
    deleteMember(area, minimum, M);
  }
  
  for (int i = 0; i < N; i++) {
    std::cout << std::endl;
    std::cout << sortedArea[i] << " ";
  }
  std::cout << std::endl;
  delete[] triangle;
  delete[] area;
  delete[] sortedArea;
  return 0;
}
