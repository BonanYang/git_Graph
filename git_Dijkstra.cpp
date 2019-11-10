#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
//#include <math>
using namespace std;
static const int MAX_V_NUM = 100;
static  const int MAX_W_NUM = 10000;

//vector<int> arr;
//vector<char> letter;
string s = "abcdefghijklmnopqrstuvwxyz";



class Dj
{
private:
 
    int MAX_W_NUM = 10000;
    int mapa[MAX_V_NUM] [MAX_V_NUM];
    int dist[MAX_V_NUM];
    int path[MAX_V_NUM];
    bool visited[MAX_V_NUM];
    int vn,en;
    int start;
    int non1,non2,non3;
    map<int,char> letter;
public:
    void dj();
    void init();
    void showProcess();
    void showshort();
    
};


void Dj::init()
{
    int u,v,w;
    cout<<"initialized"<<endl;
    for(int i = 1; i<=26; i++)
    {
        letter[i] =s[i-1];
    }
    
    cout<<"now test letter"<<endl;
    cin>>non1>>non2>>non3;
    cout<<letter[non1]<<letter[non2]<<letter[non3]<<endl;
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
    cout<<"now,input edge"<<endl;
    for(int i = 0; i<en;i++)
    {
        cin>>u>>v>>w;
        mapa[u][v] = min(w,mapa[u][v]);
    }
    
    for(int i = 1 ;i<=vn;i++)
    {
        visited[i] =false;
        
    }
    
    cout<<"input start"<<endl;
    cin>>start;
    cout<<"start is "<<letter[start];
    
}

void Dj::dj()
{
   
    for(int i = 1; i <= vn;i++)
    {
        dist[i] = mapa[start][i];
        if(dist[i]!=MAX_W_NUM)
        {
            path[i] = start;
        }
        else
        {
            path[i] = -1;
        }
    }
    
    dist[start] = 0;
    visited[start] = true;
    for(int i = 1; i<=vn ; i++)
    {
        int MIN = 10000; int t = start;
        for(int j =1; j<= vn;j++)
        {
            if(dist[j]<MIN &&!visited[j])
            {
                MIN = dist[j];
                t = j;
            }
        }
        
        if(t == start)return;
        visited[t] = true;
        for(int j = 1; j<= vn;j++)
        {
            if(mapa[t][j]<=MAX_W_NUM && !visited[j] )
            {
                if(dist[j]>dist[t]+mapa[t][j])
                {
                    dist[j] = dist[t]+mapa[t][j];
                    path[j] = t;
                }
            }
        }
    }
}

void Dj::showshort()
{
    std::cout << "start " << start << std::endl;
    for (int i = 1; i <= vn; ++i)
    {
        std::cout << "st: " << letter[start] << "dest: " << letter[i];
        if (dist[i] == MAX_W_NUM)
            std::cout << "no way" << std::endl;
        else
            std::cout << "shortest path " << dist[i] << std::endl;
    }
}

int main()
{
    Dj dij;
    dij.init();
    dij.dj();
    dij.showshort();
}

