// tests.cpp
#include "graph.h"
#include <gtest/gtest.h>
#include <list>

TEST(Graph, add1) {
    graph g(2);
    ASSERT_TRUE(g.addEdge(0,0));
}
TEST(Graph, add2) {
    graph g(3);
    g.addEdge(0,0);
    g.addEdge(0,1);
    g.addEdge(0,2);
    ASSERT_FALSE(g.addEdge(0,0));
}
TEST(Graph, remove1) {
    graph g(2);
    g.addEdge(0,0);
    ASSERT_FALSE(g.removeEdge(0,0));
}
TEST(Graph, remove2) {
    graph g(3);
    g.addEdge(0,1);
    g.addEdge(0,2);
    ASSERT_TRUE(g.removeEdge(0,0));
}
TEST(Graph, hasedge1) {
    graph g(2);
    g.addEdge(0,0);
    ASSERT_TRUE(g.hasEdge(0,0));
}
TEST(Graph, hasedge2) {
    graph g(3);
    g.addEdge(0,0);
    g.addEdge(1,1);
    g.addEdge(2,2);
    ASSERT_TRUE(g.hasEdge(2,2));
}
TEST(Graph, outEdges1) {
    graph g(2);
    std::list<int> x, y;
    x.push_back(0);
    x.push_back(1);
    g.addEdge(0,0);
    g.addEdge(0,1);
    y = g.outEdges(0);
    ASSERT_EQ(x, y);

}
TEST(Graph, outEdges2) {
    graph g(3);
    std::list<int> x, y;
    x.push_back(2);
    g.addEdge(0, 2);
    y = g.outEdges(0);
    ASSERT_EQ(x, y);
}
TEST(Graph, inEdges1) {
    graph g(2);
    std::list<int> x, y;
    x.push_back(0);
    x.push_back(1);
    g.addEdge(0,0);
    g.addEdge(1,0);
    y = g.inEdges(0);
    ASSERT_EQ(x, y);
}
TEST(Graph, inEdges2) {
    graph g(3);
    std::list<int> x, y;
    x.push_back(2);
    g.addEdge(2, 0);
    y = g.inEdges(0);
    ASSERT_EQ(x, y);
    
}
TEST(Graph, print1) {
    graph g(1);
    g.addEdge(0,0);
    g.PrintOutAdjacencyMatrix();

}
TEST(Graph, print2) {
    graph g(2);
    g.addEdge(1,0);
    g.addEdge(0,1);
    g.PrintOutAdjacencyMatrix();
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}