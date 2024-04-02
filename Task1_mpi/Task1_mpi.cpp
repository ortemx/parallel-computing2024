// Task1_mpi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<stdio.h>
#include<mpi.h>

/*
* task 1.1
*/
//int main(int argc, char** argv) {
//    int size, rank;
//    MPI_Init(&argc, &argv);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    printf("SIZE = %d   RANK = %d\n", size, rank);
//    MPI_Finalize();
//    return(0);
//}

/*
* task 1.2
*/

//int main(int argc, char** argv) {
//    int size, rank, a, b;
//    MPI_Status st;
//    MPI_Init(&argc, &argv);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    if (rank == 0) {
//        a = 10;
//        MPI_Send(&a, 1, MPI_INT, 3, 15, MPI_COMM_WORLD);
//    }
//    else {
//        if (rank == 3) {
//            MPI_Recv(&b, 1, MPI_INT, 0, 15, MPI_COMM_WORLD, &st);
//            printf("Vetv = %d   b = %d\n", rank, b);
//        }
//    }
//
//    MPI_Finalize();
//    return(0);
//}

/*
* task 1.3
*/
//int main(int argc, char** argv) {
//    int size, rank, a, b;
//    MPI_Status st;
//    MPI_Init(&argc, &argv);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    if (rank == 0) {
//        a = 10;
//        MPI_Send(&a, 1, MPI_INT, size - 1, 15, MPI_COMM_WORLD);
//    }
//    else {
//        if (rank == size - 1) {
//            MPI_Recv(&b, 1, MPI_INT, 0, 15, MPI_COMM_WORLD, &st);
//            printf("Vetv = %d   b = %d\n", rank, b);
//        }
//    }
//
//    MPI_Finalize();
//    return(0);
//}
/*
* task 1.4
*/
int main(int argc, char** argv) {
    int size, rank, a;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        a = 10;
        MPI_Bcast(&a, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else {
        MPI_Bcast(&a, 1, MPI_INT, 0, MPI_COMM_WORLD);
        printf("Vetv = %d   a = %d\n", rank, a);
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
