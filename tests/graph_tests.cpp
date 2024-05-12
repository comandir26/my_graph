#include"graph/graph.h"
#include"gtest/gtest.h"

using namespace graph;

TEST(Creating, First) {
	Graph<int, int> graph;
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_vertex(6);
	graph.add_edge(1, 2, 10);
	graph.add_edge(1, 3, 11);
	graph.add_edge(4, 6, 12);
	/*auto edges = graph.edges(1);
	for (auto& e: edges)
	{
		std::cout << e.first << "(" << e.second << ")" << " ";
	}*/
	std::cout << graph.order() << std::endl;
}
