//
//  main.cpp
//  git_Graph_Prim
//
//  Created by Bonan Yang on 11/13/19.
//  Copyright © 2019 Bonan Yang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;
static const int MAX_V_NUM = 100;
static  const int MAX_W_NUM = 10000;


string s = "abcdefghijklmnopqrstuvwxyz";



class Prim
{
private:
    
    int MAX_W_NUM = 66666;
    int mapa[MAX_V_NUM] [MAX_V_NUM];
    int dist[MAX_V_NUM];
    bool visited[MAX_V_NUM];
    int vn,en;
    int start;
    int st;
    int sum;
    int non1,non2,non3;
    map<int,char> letter;
public:
    void prim();
    void init();
    void showProcess();
    void showshort();
    
};


void Prim::init()
{
    int u,v,w;
    
    for(int i = 1; i<=26; i++)
    {
        letter[i] =s[i-1];
    }
    
   
    cout<<"*********************************"<<endl;
    
    cout<<"how many vertex?"<<endl;
    cin>>vn;
    cout<<"how many edge?"<<endl;
    cin>>en;
    for(int i = 1; i<=vn; i++)
    {
        for(int j = 1; j<= vn; j++)
            mapa[i][j] = MAX_W_NUM;
    }
    cout<<"initialized"<<endl;
    cout<<"now,input edge"<<endl;
    for(int i = 0; i<en;i++)
    {
        cin>>u>>v>>w;
        mapa[u][v] = min(w,mapa[u][v]);
         mapa[v][u] = min(w,mapa[v][u]);
    }
    
    for(int i = 1 ;i<=vn;i++)
    {
        visited[i] =false;
        dist[i] = MAX_W_NUM;
    }
    
    cout<<"input start"<<endl;
    cin>>start;
    cout<<"start is "<<letter[start]<<endl;
    cout<<"$%$%$%$%$%$%$%$%$%%$%$%$%$%$%%"<<endl;

}

void Prim::prim()
{
    
    sum = 0;
    visited[start] = true;
    st = start;
    for(int i = 1; i<=vn-1;i++)
    {
        
        int min = MAX_W_NUM;
        
        for(int j = 1; j<=vn;j++)
        {
            if(visited[j] == false && mapa[st][j]<dist[j])
            {
                dist[j] = mapa[st][j];
            }
        }
        
        for(int k = 1; k<=vn;k++)
        {
            if(dist[k]<min&&!visited[k])
            {
                min = dist[k];
                st = k;
            }
            cout<<" "<<dist[k] <<" ";
            
        }
        cout<<"st= "<<st<<endl;
        
        visited[st] = true;
        cout<<letter[st]<<endl;
        sum = sum+min;
        cout<<"sum = "<<sum<<endl;
        
        if(st == start)return;
        
       
        
      
    }
    
      cout<<"MST weight is"<<sum<<endl;
    
}

int main()
{
    Prim p;
    p.init();
    p.prim();
}
