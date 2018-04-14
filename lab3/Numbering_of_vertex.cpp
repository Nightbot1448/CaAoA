#include "stdafx.h"
#include "Numbering_of_vertex.h"

Graph read()
{
	std::ifstream fin("input.txt");
	Graph input_graph;
	std::set<char> used_vertex;
	char vertex, incid_vertex; //vertexs

	while (fin >> vertex)
	{
		fin >> incid_vertex;
		used_vertex.emplace(vertex);
		used_vertex.emplace(incid_vertex);
		auto it = input_graph.find(vertex);
		if (it != input_graph.end())
		{
			it->second.first.emplace(incid_vertex);
		}
		else
		{
			std::set<char> incid_list;
			incid_list.emplace(incid_vertex);
			size_t sz = 0;
			input_graph.emplace(vertex, std::make_pair(incid_list,sz));
		}
	}
	for (auto &el_of_set : used_vertex)
	{
		if (input_graph.find(el_of_set) == input_graph.end())
		{
			std::set<char> incid_list;
			size_t sz = 0;
			input_graph.emplace(el_of_set, std::make_pair(incid_list, sz));
		}
	}
	return input_graph;
}

char findSource(const Graph &graph)
{
	Graph_without_numbers inverse_graph;
	for (auto &el_of_map : graph)
	{
		for (auto &el_of_set : el_of_map.second.first)
		{
			auto it = inverse_graph.find(el_of_set);
			if (it != inverse_graph.end())
			{
				it->second.emplace(el_of_map.first);
			}
			else
			{
				std::set<char> incid_list;
				incid_list.emplace(el_of_map.first);
				inverse_graph.emplace(el_of_set, incid_list);
			}
		}
	}
	for (auto &el : graph)
		if (inverse_graph.find(el.first) == inverse_graph.end())
			return el.first;
	throw std::logic_error("graph have no source");
}

//char findEffluent(const Graph_without_numbers &graph)
//{
//	std::stack<char> st;
//	std::set<char> used_vertex;
//	st.push(graph.begin()->first);
//	char curr_vertex;
//	while (!st.empty())
//	{
//		curr_vertex = st.top();
//		st.pop();
//		auto it = graph.find(curr_vertex);
//		if (it->second.empty())
//		{
//			while (!st.empty())
//				st.pop();
//			used_vertex.clear();
//			return curr_vertex;
//		}
//		used_vertex.emplace(curr_vertex);
//		for (auto &el : it->second)
//			if (used_vertex.find(el) == used_vertex.end())
//				st.push(el);
//	}
//	throw std::logic_error("graph have no effluent");
//}

void numberingOfVertexWidth(Graph &graph, char source)
{
	std::queue<char> q;
	std::set<char> used_vertex;
	q.push(source);
	size_t counter = 0;
	char curr_vertex;
	while (!q.empty())
	{
		curr_vertex = q.front();
		q.pop();
		auto it = graph.find(curr_vertex);
		auto end_of_used_vertex = used_vertex.end();
		for (auto &el : it->second.first)
		{
			if (used_vertex.find(el) == end_of_used_vertex)
				q.push(el);
		}
		if (used_vertex.find(curr_vertex) == used_vertex.end())
			graph.find(curr_vertex)->second.second = counter++;
		used_vertex.emplace(curr_vertex);
	}
}
void numberingOfVertexDepth(Graph &graph, char source)
{
	std::stack<char> st;
	std::set<char> used_vertex;
	st.push(source);
	size_t counter = 0;
	char curr_vertex;
	while (!st.empty())
	{
		curr_vertex = st.top();
		st.pop();
		auto it = graph.find(curr_vertex);
		auto end_of_used_vertex = used_vertex.end();
		for (auto &el : it->second.first)
		{
			if (used_vertex.find(el) == end_of_used_vertex)
				st.push(el);
		}
		if (used_vertex.find(curr_vertex) == used_vertex.end())
			graph.find(curr_vertex)->second.second = counter++;
		used_vertex.emplace(curr_vertex);
	}
}

void print(const Graph &graph)
{
	for (auto &el_of_map : graph)
	{
		std::cout << el_of_map.first << '[' << el_of_map.second.second << "]: ";
		for (auto &el_of_set : el_of_map.second.first)
		{
			std::cout << el_of_set << ' ';
		}
		std::cout << std::endl;
	}
}