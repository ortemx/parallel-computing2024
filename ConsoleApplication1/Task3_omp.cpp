// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<omp.h>
#include<stdio.h>

const int N = 30;
double** a, ** b, ** c;

int main() {
    int i, j, k, num_threads, p, n;

    a = new double* [N];
    b = new double* [N];
    c = new double* [N];

    for (i = 0; i < N; i++) {
        a[i] = new double[N];
        b[i] = new double[N];
        c[i] = new double[N];
        for (j = 0; j < N; j++) {
            a[i][j] = 1;
            b[i][j] = 2;
        }
    }

    std::cout << "Матрица А:" << std::endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            std::cout << a[i][j] << "  ";
        std::cout << "\n";
    }

    std::cout << "\nМатрица B:" << std::endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            std::cout << b[i][j] << "  ";
        std::cout << "\n";
    }

    std::cout << "\n";

#pragma omp parallel shared(a, b, c) private(i, j, k, num_threads, p, n)
    {
        num_threads = omp_get_num_threads();
        p = omp_get_thread_num();
        n = N / num_threads;

        for (i = p * n; i < n * (p + 1); i++) {
            for (j = 0; j < N; j++) {
                c[i][j] = 0.0;
                for (k = 0; k < N; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }

    std::cout << "\nРезультирующая матрица С:" << std::endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            std::cout << c[i][j] << "  ";
        std::cout << "\n";
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
