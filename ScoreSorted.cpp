#include "ScoreSorted.h"
using namespace std;
int scores[26];

int main(){
  
  for (int i = 1; i <= 26; i++)
      scores[i-1] = i;
      
  
  string fileName = "abc.txt";
  
  ScoreSorted ss;
  ss.read_and_calculate(fileName);
}

int ScoreSorted::calculateScore(string word){
	int score = 0;
    for (int i = 0; i < word.size(); i++)	
       score += scores[(int)tolower(word[i]) % 97];
       
    return score;
}

void ScoreSorted::add_to_map(int score, string word){
	if (score_map.find(score) == score_map.end())
	  score_map[score] = word;
	  
	else
	   score_map[score].append(" " + word);
	   
} 

void ScoreSorted::read_and_calculate(string fileName){
	ifstream file(fileName.c_str());
	string line;
	while( getline(file, line)){
		add_to_map(calculateScore(line), line);
	}
	  
	for(map<int, string>::iterator it = score_map.begin(); it != score_map.end(); ++it) {
  		cout << it->first << " " << it->second << endl;
	}	  
	
	file.close();
}

