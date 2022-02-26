#include<iostream>
using namespace std;
int main(){

	for(int i=1;i<=100;i++){
		for(int j=1;j<=20;j++)
			printf("%d X %d = %d\n",i,j,(i*j));
		printf("\n\n***********************************\n\n");
	}
	return 0;
}
