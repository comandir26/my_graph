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
			for (auto& v: _data) {
				std::cout << v.first << ": ";
				for (auto& e: v.second)
				{
					std::cout << e.first << "(" << e.second << ") ";
				}
				std::cout << std::endl;
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

		bool remove_edge(const Vertex& from, const Vertex& to) {
			if (!has_vertex(from) || !has_vertex(to)) return false;
			auto it = _data[from].begin();
			while (it != _data[from].end() && it->first != to) ++it;
			if (it == _data[from].end()) return false;
			_data[from].erase(it);
			return true;
		}

		bool has_edge(const Vertex& from, const Vertex& to) const {
			if (!has_vertex(from) || !has_vertex(to)) return false;
			auto it = _data.at(from).begin();
			while (it != _data.at(from).end() && it->first != to) ++it;
			return it != _data.at(from).end();
		}
		std::vector<std::pair<Vertex, Distance>> edges(const Vertex& v) const{
			std::vector<std::pair<Vertex, Distance>> edges;
			for (auto& e : _data.at(v)) {
				edges.push_back(e);
			}
			return edges;
		}
		size_t degree(const Vertex& v) const {
			return _data.at(v).size();
		}
		size_t order() const {//порядок - кол-во вершин
			return _data.size();
		}
	private:
		std::unordered_map<Vertex, std::vector<std::pair<Vertex, Distance>>> _data;
	};
}