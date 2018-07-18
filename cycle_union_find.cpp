#include <bits/stdc++.h>
using namespace std;
/*
	Union-Find Implementation
*/

class Edge{
	public:
		int from;
		int to;
		Edge(int i, int j){
			this->from = i;
			this->to = j;
		}
		Edge(){
			
		}
};

class Graph{
	private:
		Edge* edge;
		int vertices;
		int k;
		int esize;
		int vsize;
	public:
		// Edges and Vertices count as input
		Graph(int sz, int ver){
			edge = new Edge[sz];
			k = 0;
			vertices = ver;
			esize = sz;
			vsize = ver;
		}
		void set(int i, int j){
			if(k >= esize){
			}
			else{
				edge[k].from = i;
				edge[k].to = j;
				k++;
			}
		}
		void showEdges(){
			for(int i = 0; i < esize; i++){
				cout<<edge[i].from<<" -> "<<edge[i].to<<endl;
			}
		}
		void showVertices(){
			for(int i = 0; i < vsize; i++){
				cout<<i<<"  ";
			}
		}
		void showArray(int* arr, int n){
			for(int i = 0; i < n; i++){
				cout<<arr[i]<<"  ";
			}
			cout<<endl;
		}
		bool isCycle(){
			int* temp = new int[vsize]; // shows the parent array
			for(int i =0; i < vsize; i++){
				temp[i] = -1;
			}
			for(int i = 0; i < esize; i++){
				int x = edge[i].from;
				int y = edge[i].to;
				// find operations using while loop
				while(temp[x] != -1){
					x = temp[x];
				}
				while(temp[y] != -1){
					y = temp[y];
				}
				/*cout<<"from: "<<edge[i].from<<", to: "<<edge[i].to<<endl;
				cout<<"x is "<<x<<", y is "<<y<<endl;*/
				if(x == y){
					return true;
				}
				temp[x] = y;
				/*cout<<"-------------------------------"<<endl;
				showVertices();cout<<endl;
				showArray(temp, vsize);
				cout<<"-------------------------------"<<endl;*/
			}
			return false;
		}
};

int main(){
	Graph g(5,5);
	g.set(0,1);
	g.set(1,2);
	g.set(2,3);
	g.set(3,4);
	g.set(4,1);
	g.showEdges();
	cout<<endl;
	g.showVertices();
	cout<<endl;
	if(g.isCycle()){
		cout<<"Cycle!"<<endl;
	}
	else{
		cout<<"No Cycle"<<endl;
	}
	return 0;
}
