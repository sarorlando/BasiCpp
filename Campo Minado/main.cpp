#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#define BOMBA 9
int matriz_campo[16][16];
//bool matriz_estado[16][16];

int random_number()
{
    return rand()%16;
}
// contando a quantidade de vizinhos que possuem bombas
int bombed_neighbours(int i, int j /*int matriz[16][16]*/)
{
    int bneigh = 0;
    int vet_i[8], vet_j[8];
    vet_i[0] = vet_i[1] = vet_i[2] = i-1;
    vet_i[3] = vet_i[4] = i;
    vet_i[5] = vet_i[6] = vet_i[7] = i+1;
    vet_j[0] =  vet_j[3] = vet_j[5] = j-1;
    vet_j[1] = vet_j[6] = j;
    vet_j[2] = vet_j[4] = vet_j [7] = j+1;

    for (int n=0;n<8;n++)
    {
        if ((vet_i[n]>=0)&&(vet_i[n]<=15)&&(vet_j[n]>=0)&&(vet_j[n]<=15)){
            if (matriz_campo[vet_i[n]][vet_j[n]] == BOMBA){
                bneigh++;
            }
        }
    }
    /*0 northwest
    1 north
    2 northeast
    3 west
    4 east
    5 southwest
    6 south
    7 southeast*/

    return bneigh;
}


inline bool is_death_click(int linha, int coluna)
{
    return (matriz_campo[linha][coluna] == 9);
}

int main()
{
    srand(time(0));

    int bomba, contador, linha, coluna;

    // Zerar a matriz, pois quando vc inicializa qualquer matriz
    // em c e c++, as coisa são só lixo de memória.
    for (linha=0;linha<16;linha++)
    {
        for (coluna=0;coluna<16;coluna++)
        {
            matriz_campo[linha][coluna] = 0;
        }
    }


    // colocando as bombas em lugares aleatórios
    for (int i=0;i<40;i++)
    {
        do {
            linha = random_number();
            coluna = random_number();
        } while(matriz_campo[linha][coluna] == BOMBA);
        matriz_campo[linha][coluna] = BOMBA;
    }

    // colocando em cada célula o número de bombas nas vizinhança
    for (linha=0;linha<16;linha++)
    {
        for (coluna=0;coluna<16;coluna++)
        {
            if (matriz_campo[linha][coluna]!=9)
                matriz_campo[linha][coluna] = bombed_neighbours(linha,coluna);
        }
    }

    for (linha=0;linha<16;linha++)
    {
        cout << '|' << ' ';
        for (coluna=0;coluna<16;coluna++)
        {
            if(matriz_campo[linha][coluna] == 9)
                cout << '*';
            else if(matriz_campo[linha][coluna] == 0)
                cout << ' ';
            else cout << matriz_campo[linha][coluna];
            cout << ' ';
        }
        cout << '|' << endl;
    }


    return 0;
}
