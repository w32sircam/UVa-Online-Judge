#include<stdio.h>
#include<string.h>
using namespace std;

int main(void){
	int casos,fuerza,n,escalones[100000];
	scanf("%d",&casos);
	for(int t=1;t<=casos;t++){
		fuerza=0;
		scanf("%d",&n);
		memset(escalones,0,sizeof(escalones));
		for(int i=0;i<n;i++)
			scanf("%d",&escalones[i+1]);
		for(int i=n;i>=0;i--)
			if(escalones[i+1]-escalones[i]==fuerza)
				fuerza++;
			else if(escalones[i+1]-escalones[i]>fuerza)
				fuerza=escalones[i+1]-escalones[i];
		printf("Case %d: %d\n",t,fuerza);
	}
	return 0;
}