#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
#include <mutex> // для захисту вектора від одночасного доступу

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

// Глобальний вектор для зберігання траєкторії
vector<Point> trajectory;

// М'ютекс для синхронізації доступу до вектора trajectory
mutex trajectoryMutex;

// Функція для обчислення траєкторії у своєму потоці
void calculateTrajectory(int start, int end) {
    double omega = V / R; // кутова швидкість

    for (int t = start; t <= end; ++t) {
        double angle = omega * t; // поточний кут
        Point currentPosition;
        currentPosition.x = R * cos(angle); // координата x
        currentPosition.y = R * sin(angle); // координата y

        // Захист доступу до вектора trajectory за допомогою м'ютекса
        trajectoryMutex.lock();
        trajectory.push_back(currentPosition);
        trajectoryMutex.unlock();
    }
}

int main() {
    // Розділення часу симуляції між потоками
    const int numThreads = 2;
    int timePerThread = TOTAL_TIME / numThreads;

    // Створення потоків
    vector<thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        int start = i * timePerThread + 1;
        int end = (i + 1) * timePerThread;
        threads.emplace_back(calculateTrajectory, start, end);
    }

    // Очікування завершення потоків
    for (auto& thread : threads) {
        thread.join();
    }

    // Виведення результатів
    for (size_t i = 0; i < trajectory.size(); ++i) {
        cout << "Time: " << i + 1 << "s, Position: (" << trajectory[i].x << ", " << trajectory[i].y << ")\n";
    }

    return 0;
}
