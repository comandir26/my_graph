#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

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
			for (auto& v : _data) {
				std::cout << v.first << ": ";
				for (auto& e : v.second)
				{
					std::cout << e.first << "(" << e.second << ") ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		std::vector<Vertex> vertices() const {
			std::vector<Vertex> vertices;
			for (auto& elem : _data) {
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
		/*
		bool remove_edge(const std::pair<Vertex, Distance>& e) {//c учетом расстояния
			return true;
		}*/
		bool has_edge(const Vertex& from, const Vertex& to) const {
			if (!has_vertex(from) || !has_vertex(to)) return false;
			auto it = _data.at(from).begin();
			while (it != _data.at(from).end() && it->first != to) ++it;
			return it != _data.at(from).end();
		}
		/*
		bool has_edge(const std::pair<Vertex, Distance>& e) const {//c учетом расстояния в Edge
			return true
		}*/
		std::vector<std::pair<Vertex, Distance>> edges(const Vertex& v) const {
			std::vector<std::pair<Vertex, Distance>> edges;
			for (auto& e : _data.at(v)) {
				edges.push_back(e);
			}
			return edges;
		}
		size_t degree(const Vertex& v) const {
			return _data.at(v).size();
		}
		size_t order() const {
			return _data.size();//порядок - кол-во вершин
		}

		std::vector<Vertex> walk(const Vertex& start_vertex){
			std::unordered_map<Vertex, bool> visited;
			std::vector<Vertex> walk;
			/*for (size_t i = 0; i < _data.size(); ++i)
			{
				visited[i] = false;
			}*/
			std::queue<Vertex> queue;
			queue.push(start_vertex);
			while (!queue.empty()) {
				Vertex u = queue.front();
				walk.push_back(u);
				queue.pop();
				for (const auto& v : _data[u]) {
					if (!visited[v.first]) {
						visited[v.first] = true;
						queue.push(v.first);
					}
				}
			}
			return walk;
		}

		std::vector<std::pair<Vertex, Distance>> shortest_path(const Vertex& from, const Vertex& to)  {
			std::unordered_map<Vertex, std::pair<Distance, Vertex>> dist_pred;
			std::vector<std::pair<Distance, Vertex>> path;
			std::vector<Vertex> vertices = this->vertices();
			for (auto& e : vertices) {
				dist_pred[e] = std::make_pair(1e9, -1);
			}
			dist_pred[from] = std::make_pair(0, -1);
			std::stack<int> stack;
			stack.push(from);
			while (!stack.empty()) {
				Vertex u = stack.top();
				stack.pop();
				for (auto& v: _data.at(u)){
					stack.push(v.first);
					relax(u, v.first, dist_pred);
				}
			}
			Vertex finish = to;
			std::pair<Distance, Vertex> pred = dist_pred.at(finish);
			while (finish != from) {
				path.insert(path.begin(), std::make_pair(pred.first, finish));
				finish = pred.second;
				pred = dist_pred.at(finish);
			}
			path.insert(path.begin(), std::make_pair(0, from));
			return path;
		}
	private:
		void relax(const Vertex& u, const Vertex& v, std::unordered_map<Vertex, 
			std::pair<Distance, Vertex>>& dist_pred) {
			auto from_u = _data.at(u).begin();
			while (from_u->first != v) ++from_u;
			if (dist_pred.at(v).first > dist_pred.at(u).first + from_u->second) {
				dist_pred.at(v).first = dist_pred.at(u).first + from_u->second;
				dist_pred.at(v).second = u;
			}
		}
		std::unordered_map<Vertex, std::vector<std::pair<Vertex, Distance>>> _data;
	};
}