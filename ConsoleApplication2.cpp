#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Константи
const double V = 1.0; // швидкість
const double R = 10.0; // радіус кола
const int TOTAL_TIME = 60; // загальний час симуляції (у секундах)
const double PI = 3.14159265358979323846; // значення числа PI

// Структура для зберігання координат
struct Point {
    double x, y;
};

int main() {
    vector<Point> trajectory; // Вектор для збереження траєкторії
    Point currentPosition = { R, 0 }; // Початкова позиція на колі (на осі x, y = 0)
    trajectory.push_back(currentPosition); // Додавання початкової позиції до траєкторії

    double omega = V / R; // кутова швидкість, обчислюється як швидкість поділена на радіус

    // Цикл, який проходить кожну секунду загального часу симуляції
    for (int t = 1; t <= TOTAL_TIME; ++t) {
        double angle = omega * t; // поточний кут, обчислюється як кутова швидкість помножена на час
        currentPosition.x = R * cos(angle); // нова координата x, обчислена як R * cos(кут)
        currentPosition.y = R * sin(angle); // нова координата y, обчислена як R * sin(кут)
        trajectory.push_back(currentPosition); // Додавання нової позиції до траєкторії

        // Виведення поточного часу і позиції
        cout << "Time: " << t << "s, Position: (" << currentPosition.x << ", " << currentPosition.y << ")\n";
    }

    return 0;
}
