#include"graph/graph.h"
#include"gtest/gtest.h"

using namespace graph;

TEST(Creating, First) {
	Graph<int> graph;
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_vertex(6);
	auto vertices = graph.vertices();
	for (auto& v : vertices)
	{
		std::cout << v << ' ';
	}
	graph.add_edge(1, 2, 5.5);
}
