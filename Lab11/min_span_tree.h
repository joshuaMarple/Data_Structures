#ifndef _min_span_tree_h
#define _min_span_tree_h

#include <stdlib.h>
#include <queue>
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "disjoint_set.h"

class min_span_tree {
	struct edge {
		int cost;
		int a;
		int b;
		bool operator>(const edge& a){
			if(cost>a.cost){
				return true;
			}else{
				return false;
			}
		}
		bool operator<(const edge& a){
			if(cost<a.cost){
				return true;
			}else{
				return false;
			}
		}
	};

	struct compare{
		bool operator()(const edge& l, const edge& r){
			return l.cost > r.cost;
		}
	};

	private:
		int** adj_mat;
		int length = 0;
		std::priority_queue<edge, std::vector<edge>, compare> pq;
	public:
		min_span_tree(std::string filename);
		void kruskal();
		void build_queue();
};

#endif