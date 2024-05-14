#include"graph/graph.h"
#include"gtest/gtest.h"

using namespace graph;

TEST(Creating, First) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_edge(0, 2, 7);
	graph.add_edge(0, 5, 5);
	graph.add_edge(5, 4, 10);
	graph.add_edge(2, 3, 1);
	graph.add_edge(3, 4, 4);
	graph.add_edge(4, 1, 16);
	/*int from = 0;
	int to = 1;
	auto path = graph.shortest_path(from, to);
	for (auto& v : path) {
		std::cout << v.second << "(" << v.first << ")" << " ";
	}
	std::cout << std::endl;*/
	auto walk = graph.walk(0);
	for (auto& v : walk) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}
