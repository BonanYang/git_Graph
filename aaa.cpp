//
//  main.cpp
//  HashCS516
//
//  Created by Bonan Yang on 11/20/19.
//  Copyright © 2019 Bonan Yang. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <fstream>
#include <map>
#include <stack>
//#include <bit>
using namespace std;

struct name
{
    int index;
    int next;
    string name;
    string binary;
};

void HashTranslate(string a)
{
    
}


void insert();

void InitName(name * n)
{
    for(int i = 1; i <=2240; i++)
    {
        n[i].index = i;
    }
    
}

string change(char c)
{
    string data;
    for(int i=0;i<8;i++)
    {
        //  data+=c&(0x01<<i);
        if ( ( c >>(i-1) ) & 0x01 == 1 )
        {
            data+="1";
        }
        else
        {
            data+="0";
        }
    }
    for(int a=1;a<5;a++)
    {
        char x=data[a];
        data[a]=data[8-a];
        data[8-a]=x;
    }
    return data;
}


string XOR(string s1,string s2)
{
    char final_key[100];
    for(int i = 0; i<s1.length(); i++)
    {
        final_key[i] = ((s1[i]-'0') ^ (s2[i]-'0')) + '0';
    }
    string s(final_key);
    return s;
}

int BintoDec(string a)
{
    int d = 0;
    int count = a.size();
    for(int i = 0; i <count;i++)
    {
        d = (a[i]-'0')*(pow(2,count-i-1))+d;
        
    }
    d = pow(d,2);
    return d;
}

string dec2bin(int num){
    stack<char> bin;
    int j = 0;
    while(num!=0)
    {
        char a ;
        a = (num%2) + 48;
        bin.push(a);
        j++;
        num /= 2;
    }
   // cout<<"j= "<<j<<endl;
    char b[32];
    int k = 0;
        for(int i = 0; i< 32; i++)
        {
            
            k++;
            b[i] = {'0'};
            //cout<<"i = "<<i<<endl;
        }
    //cout<<"k= "<<k<<endl;
  
    int l = k-j+1;
    
    while(!bin.empty())
    {
        
        b[l] = bin.top();
        bin.pop();
        l++;
    }
    string c(b);
    //cout<<"c(b).size"<<c.length()<<endl;
    return c;
}


string cutEffective(string a)
{
    string s1;
    int s = 32;
   // cout<<"s = "<<s<<endl;
    int i = 22;
    int j = 21;
    s1 = a.substr(j,i);
    cout<<"cutF: ";
    cout<<s1<<endl;
    return s1;
    
    
    
}

string binGet()
{
    map<char,string> charbT;
    map<int,string> buffer;
    string test;
    string little = "abcdefghijklmnopqrstuvwxyz";
    string caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string num = "0123456789";
    string space = " ";
    for(int i = 0; i<26; i++)
    {
        charbT[little[i]] = change(little[i]);
    }
    for(int i = 0; i<26; i++)
    {
        charbT[caps[i]] = change(caps[i]);
    }
    for(int i = 0; i<10; i++)
    {
        charbT[num[i]] = change(num[i]);
    }
    charbT[' '] = change(' ');
    cin>>test;
    for(int i = 0; i< test.length();i++)
    {
        //cout<<charbT[test[i]]<<endl;
        buffer[i] =charbT[test[i]];
    }
   
    int count = 0;
    for(int i = 1; i<buffer.size();i++)
    {
          count++;
        buffer[i] = XOR(buffer[i-1], buffer[i]);
      
    }
    //cout<<"here"<<endl;
    //cout<< buffer[count].substr(0,8)<<endl;
    return buffer[count].substr(0,8);
}

    
int main()
{
 
    
    while (true)
    {
        string bin;
        string s;
        cout<<"**"<<endl;
        bin = binGet();
       int D = BintoDec(bin);
       // cout<<"^^"<<endl<<D<<endl;
        s = dec2bin(D);
        cout<<"here"<<s<<endl;
        cutEffective(s);
        //cout<<"%%%%"<<endl;
        cout<<s<<endl;
        
  
    }
  
    /*name n[2240];
    InitName(n);
    ifstream file;
    file.open("names.dat");
    if(file.is_open())
    {
        string str;
        while(file.eof() == 0)
        {
            getline(file,str);
            
        }
    }*/
    
    
}


