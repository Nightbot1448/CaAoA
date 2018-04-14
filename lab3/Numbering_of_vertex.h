#pragma once

Graph read();
char findSource(const Graph &graph);
//char findEffluent(const Graph_without_numbers &graph);
Graph_without_numbers deleteNumbers(const Graph &input_graph);
void numberingOfVertexWidth(Graph &graph, char source);
void numberingOfVertexDepth(Graph &graph, char source);
void print(const Graph &graph);