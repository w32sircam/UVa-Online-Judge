#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

int main(void){
	map<char,int> letras;
	int n;
	string cad;
	scanf("%d",&n);
	while(n--){
		cin >> cad;
		for(int i=0;i<cad.size();i++)
			letras[cad[i]]++;
		int cont=0;
		while(letras['M']>=1 && letras['A']>=3 && letras['R']>=2 && letras['G']>=1 && letras['I']>=1 && letras['T']>=1){
			cont++;
			letras['M']--;
			letras['A']-=3;
			letras['R']-=2;
			letras['G']--;
			letras['I']--;
			letras['T']--;
		}
		printf("%d\n",cont);
		letras.clear();
	}
	return 0;
}