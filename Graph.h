/*
*
*vectors to store adj list
*Input edgelist
*Save the edgelist in the form of an adjointlist
*
*/
#pragma once

#include<iostream>
#include<vector>

using namespace std;

class Graph
{
    vector<vector<int>> adjlist;

    bool search(const vector<int>& list, int v)
    {
        for(auto vertex: list)
        {
            if(vertex == v){
                return true;
            }
        }
        return false;
        
    }
    public:
    Graph(int vertices)
    {
        adjlist.resize(vertices);
    }
    void addEdges(vector<vector<int>> edgelist)
    {
        for(auto edge: edgelist)
        {
            if(!search(adjlist[edge[0]], edge[1])){
                adjlist[edge[0]].push_back(edge[1]);
            }
        }
    }
    void addEdge(int u, int v)
    {
        if(!search(adjlist[u], v)){
            adjlist[u].push_back(v);
        }
    }
    vector<int> getAdjVertices(int u){
        return adjlist[u];
    }

    vector<vector<int>> getAdjList(){
        return adjlist;
    }

    vector<vector<int>> reverseGraph(){
        vector<vector<int>> revlist;
        for(int i = 0; i < adjlist.size(); i++){
            for(auto vertex: adjlist[i]){
                vector<int> edge = {vertex, i};
                revlist.push_back(edge);
            }
        }
        return revlist;
    }

    vector<vector<int>> transposeGraph(){
        vector<vector<int>> translist(adjlist.size());
        for(int i = 0; i < adjlist.size(); i++){
            for(auto vertex: adjlist[i]){
                translist[vertex].push_back(i);
            }
        }
        return translist;
    }

};
