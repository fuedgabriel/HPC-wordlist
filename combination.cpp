#include <stdio.h>
#include <iostream>
#include <chrono>


using namespace std;
void combinationUtil(char arr[26], char data[], int start, int end, int index, int r)
{
    int i, j;

    if (index == r)
    {
        for (j = 0; j < r; j++)
            //cout << data[j];
            cout << "";
            //printf("%i ", data[j]);
        //printf("\n");
        return;
    }

    for (i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i + 1, end, index + 1, r);
    }
}

void printCombination(char arr[26], int n, int r)
{
    char data[r];
    //printf("%s", arr[0]);
    std::cin.get();
    combinationUtil(arr, data, 0, n - 1, 0, r);
}

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    char arr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                    'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int r = 4;
    //int n = sizeof(arr) / sizeof(arr[0]);
    printCombination(arr, 26, 1);
    printCombination(arr, 26, 2);
    printCombination(arr, 26, 3);
    printCombination(arr, 26, 4);
    printCombination(arr, 26, 5);
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "\n\nelapsed time: " << elapsed_seconds.count() << "s\n";
}