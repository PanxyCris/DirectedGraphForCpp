#include<iostream>
#include<vector>
using namespace std;

class DirectedGraph{
public:
	DirectedGraph(int** graph,int length){
		this->graph = graph;
		this->length = length;
		hasCircle = false;
	}
	~DirectedGraph(){ delete graph; }
	bool isCircleExist(){ return hasCircle; }
	int size(){ return length; }
	void findCircle(int n);
private:
	int **graph;
	int length;
	vector<int> trace;
	bool hasCircle;
};


void DirectedGraph::findCircle(int n){
	int index = -1;
	for (int i = 0; i < trace.size(); i++)
		if (trace[i] == n)
			index = i;
	if (index != -1){
		hasCircle = true;
		cout << "Circle:";
		while (index < trace.size()){
			char value = 'A' + trace[index];
			cout << value << " ";
			index++;
		}
		cout << endl;
		return;
	}
	trace.push_back(n);
	for (int i = 0; i < length; i++){
		if (graph[n][i] == 1)
			findCircle(i);
	}
	if (!trace.empty())
	trace.pop_back();
}

void main(){
	int n = 6;
	int** graph = new int*[n];
	for (int i = 0; i < n; i++)
		graph[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = 0;
	graph[0][1] = 1;
	graph[0][3] = 1;
	graph[1][2] = 1;
	graph[1][4] = 1;
	graph[2][5] = 1;
	graph[3][1] = 1;
	graph[3][4] = 1;
	graph[4][2] = 1;
	graph[4][5] = 1;
	graph[5][0] = 1;
	DirectedGraph *directedGraph = new DirectedGraph(graph, n);
	directedGraph->findCircle(0);
	if (!directedGraph->isCircleExist())
		cout << "No circle" << endl;
	delete directedGraph;
}