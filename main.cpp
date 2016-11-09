/******************************************************************************
 *genereaza un cuvant acceptat, de lungime data
 *starile sunt numerotate de la 0
 *starile > nefin sunt finale

 *Autor: Ioana-Sofia Pascu
 *Creat: 08/03/2016
 ******************************************************************************/

#include <iostream>
#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int n, nr, i, x, y, mat[100][100], j, nefin, z, a[100][100];
char cif;
ifstream f ("date.txt");

struct Nod {
    int parent, state, letter, level;
} c[100]; //coada in care vom retine pentru fiecare nod din arbore starea pe care o contine, tatal, litera cu care s-a ajuns la ea, nivelul din arbore pe care se afla

void BFS (int n)
{
    int i, p, u, v;
    stack <char> temp; //stiva ajutatoare pentru ca literele cuvantului vor fi afisate in ordine inversa
    c[1].state = 0; c[1].level = 0; c[1].parent = 0; c[1].letter = 0; //pornim din starea initiala q0, care va fi radacina arborelui
    p = 1; u = 1;
    while (true)
    {
        if (c[p].level == n) break; //iesim din bfs atunci cand am ajuns la nivelul n
        v = c[p].state;
        p++;
        for (i = 0; i < nr; i++)
            if (mat[v][i] != -1)
            {
                u++;
                c[u].state = i;
                c[u].letter = mat[v][i];
                c[u].parent = p - 1;
                c[u].level = c[p - 1].level + 1;
            }
    }
    //cautam in starile de pe nivelul n pana gasim una care este finala
    i = u;
    while (c[i].level == n && c[i].state <= nefin)
        i--;
    //daca am gasit o stare finala pornim de la ea si refacem drumul pana la radacina
    //cuvantul va fi obtinut cu literele in ordine inversa prima data
    if (c[i].stare > nefin)
    {
        while (i != 1)
        {
            cif = c[i].letter + 'a';
            temp.push (cif);
            i = c[i].parent;
        }
        //am pus literele intr-o stiva si ne folosim de ea pentru a le scrie in ordinea buna
        while (!temp.empty())
        {
            cout << temp.top();
            temp.pop();
        }
    }
    //daca nu am gasit o stare finala atunci nu avem solutie
    else cout << "IMPOSIBIIL";
    cout << endl;
}

void afisare_mat (int mat[100][100])
{
    for (i = 0; i < nr; i++)
    {
        for (j = 0; j < nr; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void initialize (int x, int a[100][100])
{
    for (int i = 0; i < nr; i++)
        for (int j = 0; j < nr; j++)
            a[i][j] = x;
}

int main()
{
    f >> nr >> nefin; // nr de stari, ultima stare nefinala

    initialize (-1, a);
    while (!f.eof())
    {
        f >> x >> cif >> y;
        z = cif - 'a';
        a[x][z] = y;
    }

    initialize(-1, mat);
    for (i = 0; i <= nr - 1; i++)
        for (j = 0; j <= nr - 1; j++)
            if (a[i][j] != -1) mat[i][a[i][j]] = j; //cream matricea de adiacenta (graf orientat) cu semnificatia pentru mat[i][j] : din starea i ajungem in starea j cu litera corespunzatoare a[i][j]

    cout << "n = "; cin >> n; //citim numarul de cuvinte din cuvantul ce urmeaza a fi generat
    if (n == 0)
        {
            if (nefin == 0) cout << "lambda";
            else cout << "IMPOSIBIL";
        }
    else BFS(n);

    return 0;
}
