//
//  graph.cpp
//  git_Graph
//
//  Created by Bonan Yang on 11/6/19.
//  Copyright © 2019 Bonan Yang. All rights reserved.
//

#include <stdio.h>
#include  "graph.h"
#include  <iostream>
#include <queue>
#include <map>
using namespace std;

void Creat_Graph(graph *g)
{
    char temp_char;
    for(int i = 0 ; i < N; ++i)
    {
        cout<<"input a vertex"<<endl;
        cin >> temp_char;
        g->vexs[i] = temp_char;
    }
    
    for(int i = 0; i < N ; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            g->adjs[i][j] = 0;
        }
    }

    int vex1,vex2;
    float w;
    for(int k = 0; k < 14; k++)
    {
        cout<<"input index of 2 vertex and the weight"<<endl;
        cout<<"index 1:"<<endl;
        cin >> vex1;
        cout<<"index 2:"<<endl;
        cin >> vex2;
        cout<<"w:"<<endl;
        cin >> w;
        g->adjs[vex1][vex2] = w;
        g->adjs[vex2][vex1] = w;
    }
}

int visited [N];
  graph *g = new graph;

void BFS(int k)
{
    map<int,char> m;
    m[0] = 'A';
    m[1] = 'B';
    m[2] = 'C';
    m[3] = 'D';
    m[4] = 'E';
    m[5] = 'F';
    m[6] = 'G';
    m[7] = 'H';
    m[8] = 'I';
    m[9] = 'J';
    queue<int> q;
    int i,j;
    cout<<"visit start vertex: "<< k <<endl;
    visited[k] = 1;
    q.push(k);
    
    while(!q.empty())
    {
        i = q.front();
        q.pop();
        cout<<":"<<m[i]<<endl;
        
        for(j = 0 ; j<N;j++)
        {
            if(g->adjs[i][j]==1&&visited[j] == 0)
            {
                //cout<<"k's adj"<<endl;
                visited[j] = 1;
                q.push(j);
            }
            
        }
    }
}


void DFSA(int i)
{
    cout<<"访问出发顶点序号: "<<i<<endl;
    visited[i] = 1;
    cout<<g->vexs[i]<<" "<<endl;
    for (int j = 0; j < N; ++j)//依次遍历i顶点的邻接点
    {
        if ((g->adjs[i][j]==1) && (visited[j]==0))//与i相连且未被访问过
        {
            DFSA(j);
        }
    }
}

int main()
{
  
    Creat_Graph(g);
    for(int i = 0 ; i< N; i++)
    {
        cout<<g->vexs[i]<<" "<<endl;
    }
    cout<<endl;
    
    BFS(0);
    delete g;
    return 0;
    
    
}


