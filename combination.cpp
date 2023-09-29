#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>

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


vector<char> alfabeto = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 
                         'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 
                         's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void permutacoes(vector<char> &v, int n, int k, int tamanho) {
  // Se k for igual ao tamanho do alfabeto, então todas as permutações foram geradas
  if (k == tamanho) {
    // Imprime a permutação atual
    for (int i = 0; i < tamanho; i++) {
      cout << v[i];
    }
    cout << endl;
    return;
  }

  // Para cada letra do alfabeto
  for (char c : alfabeto) {
    // Adiciona a letra atual à permutação
    v[k] = c;

    // Chama a função recursivamente para gerar as permutações das letras restantes
    permutacoes(v, n, k + 1, tamanho);

    // Remove a letra atual da permutação
    v[k] = ' ';
  }
}


int main()
{

    //char arr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                    //'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //int r = 4;
    //int n = sizeof(arr) / sizeof(arr[0]);
    //printCombination(arr, 26, 3);


    Timer timer;
    timer.start();

    int n = alfabeto.size();

    // Vetor para armazenar a permutação atual
    vector<char> a(1);
    vector<char> b(2);
    vector<char> c(3);
    vector<char> d(4);


    #pragma omp parallel
    {
        permutacoes(a, n, 0, 1);
        permutacoes(b, n, 0, 2);
        permutacoes(c, n, 0, 3);
        permutacoes(d, n, 0, 4);
    }

    
    
    

    




    timer.stop();
    cout << "\nSeconds: " << timer.elapsedSeconds() << "\n";
    cout << "Milliseconds: " << timer.elapsedMilliseconds() << "\n";
}