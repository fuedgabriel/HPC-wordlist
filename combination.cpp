#include <stdio.h>
#include <iostream>
#include <chrono>


using namespace std;


class Timer
{
public:
    void start()
    {
        m_StartTime = std::chrono::system_clock::now();
        m_bRunning = true;
    }
    
    void stop()
    {
        m_EndTime = std::chrono::system_clock::now();
        m_bRunning = false;
    }
    
    double elapsedMilliseconds()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime;
        
        if(m_bRunning)
        {
            endTime = std::chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }
        
        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
    }
    
    double elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000.0;
    }

private:
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    bool                                               m_bRunning = false;
}; 


void permute(char *data, int n)
{
    int n = sizeof(*data);
    cout << n;
    cin.get();
}
void combinationUtil(char arr[26], char data[], int start, int end, int index, int r)
{
    int i, j;

    if (index == r)
    {
        for (j = 0; j < r; j++)
            cout << data[j];
            permute(&data[j], r);
            //cout << "";
            //printf("%i ", data[j]);
        printf("\n");
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
    combinationUtil(arr, data, 0, n - 1, 0, r);
}



int main()
{
    Timer timer;

    timer.start();


    char arr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                    'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int r = 4;
    //int n = sizeof(arr) / sizeof(arr[0]);
    printCombination(arr, 26, 3);


    timer.stop();
    cout << "\nSeconds: " << timer.elapsedSeconds() << "\n";
    cout << "Milliseconds: " << timer.elapsedMilliseconds() << "\n";
}