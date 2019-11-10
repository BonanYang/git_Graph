//
//  graph.h
//  git_Graph
//
//  Created by Bonan Yang on 11/6/19.
//  Copyright © 2019 Bonan Yang. All rights reserved.
//

#ifndef graph_h
#define graph_h
#include <iostream>
using namespace std;


#define N 4

typedef char vextype;
typedef float adjtype;

typedef struct
{
    vextype vexs[N];
    adjtype adjs[N][N];
} graph;

void Creat_Graph(graph *g);

#endif /* graph_h */
