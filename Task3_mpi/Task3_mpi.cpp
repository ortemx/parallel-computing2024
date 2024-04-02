// Task3_mpi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "mpi.h"
#include <cstring>
#include <ctime>

double* c;

int main(int argc, char** argv) {
    int size, rank, i;
    double a, content, content_;

    srand(time(0));
    MPI_Status st;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    c = new double[size];
    for (int i = 0; i < size; i++) {
        c[i] = i;
    }

    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            content = c[i];
            MPI_Send(&content, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
        }

        content = c[0];
    }
    else {
        MPI_Recv(&content_, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &st);
        content = content_;
    }

    double time1, time2, dt;
    time1 = MPI_Wtime();

    if (rank != (size - 1)) {
        MPI_Send(&content, 1, MPI_DOUBLE, rank + 1, 0, MPI_COMM_WORLD);
    }

    if (rank != 0) {
        MPI_Recv(&content_, 1, MPI_DOUBLE, rank - 1, 0, MPI_COMM_WORLD, &st);
        content = content_;
    }

    time2 = MPI_Wtime();
    dt = time2 - time1;

    std::cout << "Vetv = " << rank << ";   sending " << content << std::endl;
    if (rank == (size - 1)) {
        std::cout << "\ntime = " << dt << "\n" << std::endl;
    }

    MPI_Finalize();
    return(0);
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
