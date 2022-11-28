//main.cpp
#include "graph.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>

using namespace std;

void printlist(std::list<int> list) {
    for (std::list<int>::iterator i = list.begin(); i != list.end(); i++) {
        cout << *i << " ";
        cout << "\n";
    }
}
//Test comment for Lab11 
int main() {
    graph g(10);

    int com, v, e;
    std::list<int> outE, inE;

    cout << "Hello User! Here are the list of available commands: \n\n";
    cout << "Press 1 to add an edge to graph.\n";
    cout << "Press 2 remove an edge from graph.\n";
    cout << "Press 3 Find an edge in the graph.\n";
    cout << "Press 4 Find the out edges of a vertices.\n";
    cout << "Press 5 Find the in edges of a vertices.\n";
    cout << "Press 6 To Print out Adjacency Matrix.\n";
    cout << "Press 7 to quit.\n\n";
    cout << "Enter the command you would like to execute: ";
    cin >> com;

    ifstream input("graphInput.txt");
    while (input >> v >> e)
    {
        g.addEdge(v, e);
    }

    switch (com) {
        case 1:
            cout << "Enter the edge you would like to add: \n";
            cin >> v >> e;
            if (g.addEdge(v, e) == true) {
            cout << "Graph with added edge: \n";
            g.PrintOutAdjacencyMatrix();
            }
            break;
        case 2:
            cout << "Enter the edge you would like to remove: \n";
            cin >> v >> e;
            if (g.removeEdge(v, e) == false) {
            cout << "Graph with removed edge: \n";
            g.PrintOutAdjacencyMatrix();
            }
            break;
        case 3:
            cout << "Enter the edge you would like to find: \n";
            cin >> v >> e;
            if (g.hasEdge(v, e) == true) {
                cout << "Edge " << v << " " << e << " exists.\n";
            }
            else {
                cout << "Edge " << v << " " << e << " does not exist.\n";
            }
            break;
        case 4:
            cout << "Enter the vertex for the outer edges: \n";
            cin >> v;
            outE = g.outEdges(v);
            cout << "Outer edges: ";
            printlist(outE);
            break;
        case 5:
            cout << "Enter the vertex for the inner edges: \n";
            cin >> v;
            inE = g.inEdges(v);
            cout << "Inner edges: ";
            printlist(inE);
            break;
        case 6:
            g.PrintOutAdjacencyMatrix();
            break;
        case 7:
            cout << "Quitting program...\n";
            break;
    }
    return 0;
}

