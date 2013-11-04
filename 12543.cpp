#include<stdio.h>
#include<sstream>
#include<cstdio>
#include<iostream>
using namespace std;

int main(void){
	int max=0;
	string cads,cad,res;
	while(cin >> cads){
		if(cads=="E-N-D")
			break;
		for(int i=0;i<cads.size();i++){
			cads[i]=tolower(cads[i]);
			if(!(cads[i]>='a' && cad[i]<='z' || cads[i]=='-'))
				cads[i]=' ';
		}
		istringstream in(cads);
		while(in >> cad){
			int l=cad.size();
			if(l>max){
				max=l;
				res=cad;
			}
		}
	}
	printf("%s\n",res.c_str());
	return 0;
}