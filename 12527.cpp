#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

int main(void){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int cont=0,usados[10];
		for(int i=n;i<=m;i++){
			memset(usados,0,sizeof(usados));
			int temp=i;
			while(temp>0){
				if(usados[temp%10]==1)
					break;
				usados[temp%10]=1;
				temp/=10;
			}
			if(temp==0)
				cont++;
		}
		printf("%d\n",cont);
	}
	return 0;
}