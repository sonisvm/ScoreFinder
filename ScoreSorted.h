#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;
class ScoreSorted {
	public:
	void read_and_calculate (string);
	private:
		map<int, string> score_map;
		int calculateScore (string word);
	    void add_to_map (int, string);
};
