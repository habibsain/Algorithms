#include<iostream>
#include<vector>
#include"Graph.h"

using namespace std;

void printGraph(Graph &g){
    vector<vector<int>> adjlist = g.getAdjList();
    for(int i = 0; i < adjlist.size(); i++){
        cout << i << ": ";
        for(auto vertex: adjlist[i]){
            cout << vertex << " ";
        }
        cout << endl;
    }
}

int main()
{
    Graph g(5);
    vector<vector<int>> edgelist = {{0,1},{1,2},{2,3},{3,4},{4,0}};
    g.addEdges(edgelist);
    g.addEdge(0,3);
    printGraph(g);
    return 0;
}