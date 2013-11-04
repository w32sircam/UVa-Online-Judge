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
	int a,b,out=0;
	initSet(100010);
	while(scanf("%d",&a)!=EOF){
		if(a==-1){
			printf("%d\n",out);
			out=0;
			initSet(100010);
			continue;
		}
		scanf("%d",&b);
		if(!isSameSet(a,b))
			unionSet(a,b);
		else
			out++;
	}
	
	return 0;
}