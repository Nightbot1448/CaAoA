#ifndef kmp_h
#define kmp_h

#include <vector>
#include <string>

using namespace std;

vector<int> prefix(string temp);
vector<int> kmp(string text, string temp, const vector<int>& pi);

#endif //kmp_h