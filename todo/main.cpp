#include <string>
#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

string print(vector<pair<int, int>> source1)
{
	string res = "";
	for(pair<int, int> pair : source1)
	{
		res += "{" + to_string(pair.first) + ", " + to_string(pair.second) + "}";
	}
	return res;
}
void print(vector<string> source)
{
	for(string item : source) cout << item << " ";
}
vector<string> findCycle(vector<pair<int, int>>);

int main()
{
	vector<pair<int, int>> table = { 
		{1, 2}, {1, 6}, {2, 3}, {2, 5}, {2, 6}, 
		{3, 4}, {3, 5}, {3, 6}, {4, 5}, {5, 6}
	};
	print(findCycle(table));
}
pair<int, int> twist(pair<int, int> source)
{
	int temp;
	temp = source.first;
	source.first = source.second;
	source.second = temp;
	return source;
}


vector<string> findCycle(vector<pair<int, int>> source)
{
	int point, fpoint;
	vector<pair<int, int>> copy_source;
	vector<pair<int, int>> vault;
	vector<pair<int, int>> main_source = source;
	int breaker = source.size();
	pair<int, int> pairMain;
	pair<int, int> pairSub;
	int counter = 0;
	string cycle;
	vector<string> cycles;
	while(!main_source.empty())
	{
		point = 0;
		cycle = "";
		vault.clear();
		pairMain = main_source.front();
		fpoint = pairMain.first; point = pairMain.second;
		cycle = to_string(pairMain.first) + to_string(pairMain.second);
		main_source.erase(remove(main_source.begin(), main_source.end(), pairMain), main_source.end());
		copy_source = source;
		copy_source.erase(remove(copy_source.begin(), copy_source.end(), pairMain), copy_source.end());
		while(true)
		{
			if(!copy_source.empty())
			{
				pairSub = copy_source.front();
				counter++;
				if(point == pairSub.first)
					{
						cycle += to_string(pairSub.second);
						point = pairSub.second;
						copy_source.erase(remove(copy_source.begin(), copy_source.end(), pairSub), copy_source.end());
					}
				else
					{
						if(point == pairSub.second)
						{
							cycle += to_string(pairSub.first);
							point = pairSub.first;
							copy_source.erase(remove(copy_source.begin(), copy_source.end(), pairSub), copy_source.end());
						}
						else
						{
							vault.push_back(pairSub);
							copy_source.erase(remove(copy_source.begin(), copy_source.end(), pairSub), copy_source.end());
						}
					}
				if(cycle.front() == cycle.back())
				{
					cycles.push_back(cycle);
					cycle = "";
					break;
				}
			}
			else
			{
				if(!vault.empty())
				{
					copy_source = vault;
					vault.clear();
				}	
			}
		}
	}
	return cycles;
}