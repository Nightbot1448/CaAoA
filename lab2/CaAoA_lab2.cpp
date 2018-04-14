#include "stdafx.h"

int main()
{
	Graph input_graph = read();
	print(input_graph);
	char first_vertex = 'e'; // can be 'a', .. ,'g'
	//std::cin >> first_vertex;
	try
	{
		Graph spanning_tree = find_spanning_tree(input_graph, first_vertex);
		std::cout << std::endl << "Spanning tree:" << std::endl;
		print(spanning_tree);
	}
	catch(std::logic_error &ex)
	{
		std::cout << ex.what();
	}
    return 0;
}

