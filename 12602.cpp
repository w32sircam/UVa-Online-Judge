#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int main(void){
	string cad;
	int n;
	scanf("%d",&n);
	while(n--){
		cin >> cad;
		if(abs((cad[0]-'A')*676 + (cad[1]-'A')*26 + (cad[2]-'A') - ((cad[4]-'0')*1000 + (cad[5]-'0')*100 + (cad[6]-'0')*10 + cad[7]-'0'))<=100)
			printf("nice\n");
		else
			printf("not nice\n");
	}
	return 0;
}