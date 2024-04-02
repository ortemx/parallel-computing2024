// Task2_mpi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "mpi.h"
#include <cstring>

int main(int argc, char** argv) {
    int size, rank, a, content, content_;

    MPI_Status st;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double time1, time2, dt;
    time1 = MPI_Wtime();

    for (int i = 0; i < size; i++) {
        if ((rank == i) && (i < (size - 1))) {
            content = 22;
            MPI_Send(&content, 1, MPI_INT, i + 1, 0, MPI_COMM_WORLD);
        }
        else {
            if (rank == (i + 1)) {
                MPI_Recv(&content_, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &st);
                std::cout << "iteration = " << i << "   Vetv = " << rank << ";   sending " << content_ << std::endl;
                content = content_;
            }
        }

        if ((i == (size - 1)) && (rank == (size - 1))) {
            MPI_Send(&content, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }

    if (rank == 0) {
        MPI_Recv(&content_, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, &st);
        time2 = MPI_Wtime();
        dt = time2 - time1;
        std::cout << "iteration = " << size - 1 << "   Vetv = " << rank << ";   sending " << content_ << std::endl;
        std::cout << "\ntime = " << dt << std::endl;
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
