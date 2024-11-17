#include <iostream>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>
#include <list>
int n;
using namespace std;
class Hamiltonian
{
    int* path, v, x;
public:
    Hamiltonian(int n) { v = 0; x = 0; path = new int[n]; }
    bool isSafe(bool graph[][10], int pos);
    bool hamCycleUtil(bool graph[][10], int pos, int i);
    bool hamCycle(bool graph[][10]);
    void printSolution();
};
bool Hamiltonian::isSafe(bool graph[][10], int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}
bool Hamiltonian::hamCycleUtil(bool graph[][10], int pos, int i)
{
    if (pos == n)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
        {
            x = 1;
        }
        else
            return true;
    }
    for (v = 0; v < n; v++)
    {
        if (v == i)
            continue;
        if (isSafe(graph, pos))
        {
            path[pos] = v;

            if (hamCycleUtil(graph, pos + 1, i) == true)
                return true;

            path[pos] = -1;
        }
    }
    return false;
}
bool Hamiltonian::hamCycle(bool graph[][10])
{
    for (int i = 0; i < n; i++)
        path[i] = -1;

    for (int i = 0; i < n; i++)
    {
        path[0] = i;
        if (hamCycleUtil(graph, 1, i) == true)
        {
            printSolution();
            return true;
        }
    }
    return false;
}
void Hamiltonian::printSolution()
{
    for (int i = 0; i < n - 1; i += 2)
        cout << path[i] << "-" << path[i + 1] << " ";
    cout << "\n";
}
int main()
{
    int i, j, v1, v2, Edges;
    cin >> n;
    Hamiltonian g2(n);
    int* a;
    a = new int[n];
    bool graph1[10][10];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            graph1[i][j] = 0;
    cin >> Edges;
    for (i = 1; i <= Edges; i++)
    {

        cin >> v1 >> v2;
        graph1[v1][v2] = 1;
        graph1[v2][v1] = 1;
        a[v1]++;
        a[v2]++;
    }
    g2.hamCycle(graph1);
    cout << "°õ¦æ®É¶¡" << (double)clock() / CLOCKS_PER_SEC << "S" << endl;
    return 0;
}