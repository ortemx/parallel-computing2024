// Cuda.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

__global__ void isDiagonal(int* matrix, bool* result, int size) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    if (idx < size && matrix[idx * size + idx] != 0) {
        *result = false;
    }
}

int main() {
    const int size = 215;
    int matrix[size][size];
    bool* cudaResult;
    bool result = true;

    cudaMalloc((void**)&cudaResult, sizeof(bool));

    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = (i == j) ? rand() % 100 : rand() % 100 - 50;
        }
    }

    int* cudaMatrix;
    cudaMalloc((void**)&cudaMatrix, size * size * sizeof(int));
    cudaMemcpy(cudaMatrix, matrix, size * size * sizeof(int), cudaMemcpyHostToDevice);

    isDiagonal << <(size + 255) / 256, 256 >> > (cudaMatrix, cudaResult, size);

    cudaMemcpy(&result, cudaResult, sizeof(bool), cudaMemcpyDeviceToHost);

    if (result) {
        std::cout << "The matrix is diagonal." << std::endl;
    }
    else {
        std::cout << "The matrix is not diagonal." << std::endl;
    }

    cudaFree(cudaResult);
    cudaFree(cudaMatrix);

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
