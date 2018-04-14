// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <utility>
#include <exception>
#include <stack>
#include <queue>

typedef std::map< char, std::pair<std::set<char>, size_t> > Graph;
typedef std::map< char, std::set<char> > Graph_without_numbers;

// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы

#include "Numbering_of_vertex.h"