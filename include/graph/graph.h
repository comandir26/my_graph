#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>

namespace graph {
	template<class Vertex, class Distance = double>
	class Graph {
	public:
		Graph() {
			_data = std::unordered_map<Vertex, std::vector<std::pair<Vertex, Distance>>>();
		}
		bool has_vertex(const Vertex& v) const {
			return _data.contains(v);
		}
		void add_vertex(const Vertex& v) {
			_data.insert({ v, std::vector<std::pair<Vertex, Distance>>() });
		}
		bool remove_vertex(const Vertex& v) {
			return _data.erase(v);
		}
		void print() const {
			for (auto& elem: _data) {
				std::cout << elem.first << ' ';
			}
			std::cout << std::endl;
		}
		std::vector<Vertex> vertices() const {
			std::vector<Vertex> vertices;
			for(auto& elem: _data) {
				vertices.push_back(elem.first);
			}
			return vertices;
		}
		void add_edge(const Vertex& from, const Vertex& to, const Distance& d) {
			if (!has_vertex(from) || !has_vertex(to)) return;
			_data[from].push_back(std::make_pair(to, d));
		}

	private:
		std::unordered_map<Vertex, std::vector<std::pair<Vertex, Distance>>> _data;
	};
}