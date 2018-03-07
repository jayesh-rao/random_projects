/*
given a set of words, try to find the alphabetical sequence out of it.

i/p: {caa, aaa, aab}
the correct logical sequence is {c, a, b}
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Graph {

private:
	int v; // there are v vertices
	vector<vector<int>> adj;

public:
	explicit Graph(int n) : v(n) {
		for (int i = 0; i < n; i++) {
			v.push_back(vector<int>());
		}
	}

	void add_edge(int u, int w) {
		adj[u].push_back(w);
	}



};

std::vector<char> generate_seqnece(vector<string> words) {
    vector<vector<char>> *g = build_graph(words);
    
    auto start_point = g->pick_point();
    
    set<char> processed;
    
    stack<char> dep_stack;
    dep_stack.push(start_point);
    
    // process function
    {
        while(!s.empty()) {
            auto dep_list = g->get_dep(s.top);
            for (auto ele: dep_list) {
                dep_stack.push(ele);
            }
            if (dep_list.size() == 0) // there are no deps
            {
                processed.push()
            }
        }
    
    }

}
/*
caa
^
aaa

aab
*/
int parse_unique_alphabets(vector<string> words) {

	unordered_set<char> s;
	for (int i = 0; i < words.size(); i++) {
		auto word = word[i];
		for (int j = 0; j < word.size(); j++) {
			s.insert({word[j]});
		}
	}

	return s.size();

}


Graph *build_graph(vector<string> words) {
	Graph *g = new Graph(parse_unique_alphabets(words)); // This has to change

	for (int i = 0; i < words.size(); i++) {
		auto w1 = words[i];
		auto w2 = words[i+1];
		for (int j = 0; j < std::min(w1.size(), w2.size()); j++) {
			if (w1[j] != w2[j]) {
				g->add_edge(w1[j] - 'a', w2[j] - 'a');
			}
		}
	}

}