#include "stdafx.h"
#include "Depth_find.h"

void inverseSet(const std::set<char> &list, char prev_vertex,
				 std::stack<std::pair<char,char> > &st, const std::set<char> &used_vertex);

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
			it->second.emplace(incid_vertex);
		}
		else
		{
			std::set<char> incid_list;
			incid_list.emplace(incid_vertex);
			input_graph.emplace(vertex, incid_list);
		}

		it = input_graph.find(incid_vertex);
		if (it != input_graph.end())
		{
			it->second.emplace(vertex);
		}
		else
		{
			std::set<char> incid_list;
			incid_list.emplace(vertex);
			input_graph.emplace(incid_vertex, incid_list);
		}
	}
	for (auto &el_of_set : used_vertex)
	{
		if (input_graph.find(el_of_set) == input_graph.end())
		{
			std::set<char> incid_list;
			input_graph.emplace(el_of_set, incid_list);
		}
	}
	return input_graph;
}

Graph findSpanningTree(const Graph &input_graph, char first_vertex)
{
	std::stack<std::pair<char, char> > st;
	auto it = input_graph.begin();
	if (first_vertex != '\0')
	{
		it = input_graph.find(first_vertex);
		if (it == input_graph.end() || it->second.empty())
			throw std::logic_error("incorrect first vertex");
	}
	else
	{
		it = input_graph.begin();
		while (it->second.empty())
			it++;
	}
	std::set<char> used_vertex = { it->first };//???
	inverse_set(it->second, it->first, st, used_vertex);
	Graph spannig_tree;
	std::pair<char, char> curr_vertex; // first - previous_vertex, second - current_vertex
	while (!st.empty())
	{
		curr_vertex = st.top();
		st.pop();
		it = input_graph.find(curr_vertex.second);
		if (!it->second.empty())
			inverse_set(it->second, it->first, st, used_vertex);
		if ( used_vertex.find(curr_vertex.second) == used_vertex.end() )
		{
			it = spannig_tree.find(curr_vertex.first);
			if (it != spannig_tree.end())
			{
				spannig_tree.find(curr_vertex.first)->second.emplace(curr_vertex.second);
			}
			else
			{
				std::set<char> incid_list;
				incid_list.emplace(curr_vertex.second);
				spannig_tree.emplace(curr_vertex.first, incid_list);
			}

			it = spannig_tree.find(curr_vertex.second);
			if (it != spannig_tree.end())
			{
				spannig_tree.find(curr_vertex.second)->second.emplace(curr_vertex.first);
			}
			else
			{
				std::set<char> incid_list;
				incid_list.emplace(curr_vertex.first);
				spannig_tree.emplace(curr_vertex.second, incid_list);
			}
		}
		used_vertex.emplace(curr_vertex.second);
	}
	return spannig_tree;
}

void inverseSet(const std::set<char> &list, char prev_vertex,
				 std::stack<std::pair<char, char> > &st, const std::set<char> &used_vertex)
{
	auto el_of_set = list.end();
	auto begin_of_set = list.begin();
	auto end_of_used = used_vertex.end();
	do
	{
		el_of_set--;
		if(used_vertex.find(*el_of_set) == end_of_used)
			st.push(std::make_pair(prev_vertex, *el_of_set));
	} while (el_of_set != begin_of_set);
}

void print(Graph graph)
{
	for (auto &el_of_map : graph)
	{
		std::cout << el_of_map.first << ": ";
		for (auto &el_of_set : el_of_map.second)
		{
			std::cout << el_of_set << ' ';
		}
		std::cout << std::endl;
	}
}
