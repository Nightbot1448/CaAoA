#include "stdafx.h"


int main()
{
	Graph input_graph = read();
	try
	{
		char source = findSource(input_graph);
		numberingOfVertexWidth(input_graph, source);
		print(input_graph);
		std::cout << std::endl << std::endl;
		numberingOfVertexDepth(input_graph, source);
		print(input_graph);
	}
	catch (std::logic_error &ex)
	{
		std::cout << ex.what() << std::endl;
	}
    return 0;
}

