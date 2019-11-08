//
//  git_Tsort.cpp
//  git_TopSort
//
//  Created by Bonan Yang on 11/7/19.
//  Copyright © 2019 Bonan Yang. All rights reserved.
//
#include <iostream>
#include <stack>
#define maxnum 20
using namespace std;

struct node
{
    int vex;
    node * next;
};

struct vernode
{
    int vex;
    node* first;
    int indegree;
};

struct graph
{
    vernode v[maxnum];
    int vnums;
    int enums;
};

void createGraph(graph &g,int v,int e)
{
    int i,j,k;
    g.vnums = v;
    g.enums = e;
    for(int i = 1; i<=g.vnums;i++)
    {
        cin>>g.v[i].vex;
        g.v[i].first = NULL;
        g.v[i].indegree = 0;
    }
    cout<<"finish vertex input"<<endl;
    
    for(int i = 1 ; i<=g.enums;i++)
    {
        cin>>i>>j;
        node* p;
        p = new node();
        p->vex = j;
        p->next = g.v[i].first;
        g.v[i].first = p;
    }
}

void Tpsort(graph &g)
{
    stack<int> s;
    int i , j ,k;
    int count = 0;
    node* p;
    for(int i = 1; i <= g.vnums; i++)
    {
        p = g.v[i].first;
        while(p)
        {
            g.v[p->vex].indegree++;
            p = p->next;
        }
    }
    
    for(int i = 0 ;i <= g.vnums; i++)
    {
        if(g.v[i].indegree == 0)
        {
            s.push(i);
        }
        while (!s.empty())
        {
            j = s.top();
            s.pop();
            cout<<"#"<<g.v[j].vex<<endl;
            count++;
            p = g.v[j].first;
            while(p)
            {
                g.v[p->vex].indegree--;
                if(g.v[p->vex].indegree == 0)
                {
                    s.push(p->vex);
                }
                p = p->next;
            }
            
            
        }
    }
    if(count<g.vnums)
    {
        cout<<"circle exist"<<endl;
    }
}

int main()
{
    graph g;
    createGraph(g, 6, 8);
    Tpsort(g);
    return 0;
}


