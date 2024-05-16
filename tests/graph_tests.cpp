#include"graph/graph.h"
#include"gtest/gtest.h"
#include<functional>

using namespace graph;

TEST(vertexes, first) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.print();
	ASSERT_TRUE(graph.order() == 3);
	ASSERT_TRUE(graph.has_vertex(0));
	ASSERT_TRUE(graph.remove_vertex(0));
	ASSERT_TRUE(graph.order() == 2);
	ASSERT_FALSE(graph.has_vertex(0));
	ASSERT_FALSE(graph.has_vertex(4));
}

TEST(vertices, first) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.print();
	auto vertices = graph.vertices();
	for (auto& v: vertices)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

TEST(adding_edges, first) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_edge(0, 2, 7);
	graph.add_edge(0, 5, 5);
	graph.add_edge(0, 5, 50);
	graph.add_edge(5, 4, 10);
	graph.add_edge(2, 3, 1);
	graph.add_edge(3, 4, 4);
	graph.add_edge(4, 1, 16);
	graph.print();
	ASSERT_TRUE(graph.has_edge(0, 2));
	ASSERT_TRUE(graph.has_edge(0, 5));
	ASSERT_TRUE(graph.has_edge(0, 5, 50));
}

TEST(edges, first) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_edge(0, 2, 7);
	graph.add_edge(0, 5, 5);
	graph.add_edge(0, 5, 50);
	graph.add_edge(5, 4, 10);
	graph.add_edge(2, 3, 1);
	graph.add_edge(3, 4, 4);
	graph.add_edge(4, 1, 16);
	ASSERT_TRUE(graph.has_edge(0, 5));
	ASSERT_TRUE(graph.remove_edge(0, 5));
	ASSERT_FALSE(graph.has_edge(0, 5));
	ASSERT_FALSE(graph.has_edge(0, 5, 5));
	ASSERT_FALSE(graph.has_edge(0, 5, 50));
	ASSERT_TRUE(graph.has_edge(4, 1, 16));
}

TEST(vector_edges, first) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_edge(0, 2, 7);
	graph.add_edge(0, 5, 5);
	graph.add_edge(0, 5, 50);
	graph.add_edge(0, 4, 1);
	graph.add_edge(5, 4, 10);
	graph.add_edge(2, 3, 1);
	graph.add_edge(3, 4, 4);
	graph.add_edge(4, 1, 16);
	ASSERT_TRUE(graph.degree(0) == 4);
	auto edges = graph.edges(0);
	for (auto& e: edges)
	{
		std::cout << e.first << "(" << e.second << ")" << " ";
	}
	std::cout << std::endl;
}

TEST(walk, first) {
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
	auto walk = graph.walk(0);
	for (auto& v : walk)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
}

TEST(shortest_path, first) {
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
	int from = 0;
	int to = 1;
	auto path = graph.shortest_path(from, to);
	for (auto& v : path) {
		std::cout << v.first << "(" << v.second << ")" << " ";
	}
	std::cout << std::endl;
}

TEST(shortest_path, second) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_edge(1, 0, 5);
	graph.add_edge(1, 5, 6);
	graph.add_edge(1, 4, 6);
	graph.add_edge(1, 3, 7);
	graph.add_edge(1, 2, 8);
	graph.add_edge(2, 1, 1);
	graph.add_edge(2, 0, 1);
	graph.add_edge(0, 3, 2);
	graph.print();
	int from = 2;
	int to = 3;
	auto path = graph.shortest_path(from, to);
	for (auto& v : path) {
		std::cout << v.first << "(" << v.second << ")" << " ";
	}
	std::cout << std::endl;
}

TEST(optimal_point, first) {
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
	auto warehouse = graph.optimal_point();
	std::cout << "Warehouse: " << warehouse << std::endl;
}

TEST(optimal_point, second) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_vertex(5);
	graph.add_edge(0, 1, 4);
	graph.add_edge(0, 2, 3);
	graph.add_edge(0, 3, 4);
	graph.add_edge(0, 4, 5);
	graph.add_edge(0, 5, 1);
	graph.add_edge(5, 0, 1);
	graph.add_edge(5, 1, 1);
	graph.add_edge(5, 2, 1);
	graph.add_edge(5, 3, 1);
	graph.add_edge(5, 4, 1);
	auto warehouse = graph.optimal_point();
	std::cout << "Warehouse: " << warehouse << std::endl;
}