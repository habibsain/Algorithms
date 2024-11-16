#pragma once
#include"Graph.h"
#include<vector>

using namespace std;

class Dfs{
    private:
        Graph g;
    public:
        Dfs(Graph g){
            this->g = g;
        }
        void dfs(int u){
            vector<bool> visited(g.getAdjList().size(), false);
            vector<int> stack;
            stack.push_back(u);
            visited[u] = true;
            while(!stack.empty()){
                u = stack.back();
                stack.pop_back();
                for(auto v: g.getAdjVertices(u)){
                    if(!visited[v]){
                        stack.push_back(v);
                        visited[v] = true;
                    }
                }
            }
        }
};