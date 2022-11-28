#include "graph.h"
#include <list>
#include <array>
#include <iostream>
#include <iomanip>

using namespace std;

graph::graph(int num_v) {
    this->num_v = num_v;
    adjM = new bool*[num_v];
    for (int i = 0; i < num_v; i++) {
       adjM[i] = new bool[num_v];
       for (int j = 0; j < num_v; j++) 
        adjM[i][j] = false;
    }

}

bool graph::addEdge(int i, int j) {
    if (i > num_v || j > num_v) {
        cout << "Please enter a number less than " << num_v << ".\n";
        return false;
    }
    else if (i < 0 || j < 0) {
        cout << "Please enter a number greater than or equal to 0.\n";
        return false;
    }
    else if (adjM[i][j] == true) {
        cout << "Edge already exists! Did you mean remove?\n";
        return false;
    }
    else {
    adjM[i][j] = true;
    return adjM[i][j];
    }
}

bool graph::removeEdge(int i, int j) {
    if (i > num_v || j > num_v) {
        cout << "Please enter a number less than or equal to " << num_v << ".\n";
        return true;
    }
    else if (i < 0 || j < 0) {
        cout << "Please enter a number greater than or equal to 0.\n";
        return true;
    }
    else if (adjM[i][j] == false) {
        cout << "No edge exists here. Did you mean add?\n";
        return true;
    }
    else {
    adjM[i][j] = false;
    return adjM[i][j];
    }
}

bool graph::hasEdge(int i, int j) {
    if (adjM[i][j] == true) {
        return true;
    }
    return false;
}

std::list<int> graph::outEdges(int i) {
    std::list<int> outEdges;
    for (int j = 0; j < num_v; j++) {
        if (adjM[i][j] == true) {
            outEdges.push_back(j);
        }
    }
    return outEdges;
}

std::list<int> graph::inEdges(int i) {
    std::list<int> inEdges;
    for (int j = 0; j < num_v; j++) {
        if (adjM[j][i] == true) {
            inEdges.push_back(j);
        }
    }
    return inEdges;
}

void graph::PrintOutAdjacencyMatrix() {
	cout << endl;
    for(int i = 0; i < num_v; i++)
	{
		for(int j = 0; j < num_v; j++)
		{
			cout << setw(4) << adjM[i][j];
		}
		cout << "\n\n";
	}
}

graph::~graph() {
    for (int i = 0; i < num_v; i++)
      delete[] adjM[i];
    delete[] adjM;
}