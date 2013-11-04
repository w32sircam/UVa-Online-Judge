#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

vi pset(1000), set_size(1000); int disjointSetsSize;
void initSet(int N) { disjointSetsSize = N; set_size.assign(N, 1); pset.assign(N, 0); FOR (i, 0, N - 1) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); } 
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) { if (!isSameSet(i, j)) { disjointSetsSize--; set_size[findSet(j)] += set_size[findSet(i)]; pset[findSet(i)] = findSet(j); } } int numDisjointSets() { return disjointSetsSize; }
int sizeOfSet(int i) { return set_size[findSet(i)]; }

int main(void){
	int casos,n,m,w,cont;
	string a,b;
	scanf("%d",&casos);
	for(int t=0;t<casos;t++){
		if(t)
			printf("\n");
		cont=0;
		priority_queue<pair<int,ii> >pq;
		map<string,int> ciudades;
		scanf("%d\n%d",&n,&m);
		while(m--){
			cin >> a >> b >> w;
			if(ciudades.find(a)==ciudades.end())
				ciudades[a]=cont++;
			if(ciudades.find(b)==ciudades.end())
				ciudades[b]=cont++;
			pq.push(make_pair(-w,make_pair(ciudades[a],ciudades[b])));
		}
		int cost=0;
		initSet(n);
		while(!pq.empty()){
			ii ciudades = pq.top().second;
			int w = pq.top().first;
			pq.pop();
			if(!isSameSet(ciudades.first,ciudades.second)){
				unionSet(ciudades.first,ciudades.second);
				cost-=w;
			}
		}
		printf("%d\n",cost);
	}
	return 0;
}