#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Константи
const double V = 1.0; // швидкість руху
const int N = 5; // інтервал зміни напрямку (у секундах)
const int TOTAL_TIME = 60; // загальний час симуляції (у секундах)
const double M_PI = 3.14159265358979323846; // визначення константи M_PI

// Структура для зберігання координат
struct Point {
    double x, y; // координати точки
};

// Функція для генерації випадкового напрямку (у радіанах)
double getRandomDirection() {
    return ((double)rand() / RAND_MAX) * 2 * M_PI; // генерація випадкового напрямку від 0 до 2*PI
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел за поточним часом

    vector<Point> trajectory; // Вектор для збереження траєкторії
    Point currentPosition = { 0, 0 }; // Початкова позиція (0, 0)
    trajectory.push_back(currentPosition); // Додавання початкової позиції до траєкторії

    // Цикл, що проходить кожні N секунд до загального часу симуляції
    for (int t = 0; t < TOTAL_TIME; t += N) {
        double direction = getRandomDirection(); // Отримати новий випадковий напрямок
        double deltaX = V * N * cos(direction); // Зміна по x, обчислена як V * N * cos(напрямок)
        double deltaY = V * N * sin(direction); // Зміна по y, обчислена як V * N * sin(напрямок)

        // Оновити поточну позицію
        currentPosition.x += deltaX; // додати зміщення по x до поточної позиції
        currentPosition.y += deltaY; // додати зміщення по y до поточної позиції
        trajectory.push_back(currentPosition); // Додавання нової позиції до траєкторії

        // Виведення поточного часу і позиції
        cout << "Time: " << t + N << "s, Position: (" << currentPosition.x << ", " << currentPosition.y << ")\n";
    }

    return 0;
}
