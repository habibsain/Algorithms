#include<iostream>
#include<vector>
#include"Graph.h"

using namespace std;

void printGraph(const  vector<vector<int>>& adjlist){
    for(int i = 0; i < adjlist.size(); i++){
        cout << i << ": ";
        for(auto vertex: adjlist[i]){
            cout << vertex << " ";
        }
        cout << endl;
    }
}
void printEdges(const vector<vector<int>>& edgelist){
    for(auto edge: edgelist){
        cout << edge[0] << " " << edge[1] << endl;
    }
}

int main()
{
    Graph g(5);
    vector<vector<int>> edgelist = {{0,1},{0,3},{1,2},{2,3},{3,4},{4,0},{0,2},{1,3}, {2,4}};
    g.addEdges(edgelist);
    printGraph(g.getAdjList());

    cout << "\ntranspose graph" << endl;
    printGraph(g.transposeGraph());

    return 0;
}