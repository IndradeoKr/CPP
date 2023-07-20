#include <bits/stdc++.h>
using namespace std;

struct graph
{
    int v;
    int e;
    struct adj* array;
};

void createGraph(graph g)
{

}

int main()
{
    graph *g = new graph;
    cout << "Enter number of vertex and edges\n";
    cin >> g->v >> g->e;
    graph **arr = new graph*[g->v];
    for(int i = 0; i < g->v; i++)
    {
        arr[i] = NULL;
    }
    return 0;
}