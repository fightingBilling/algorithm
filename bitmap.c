#include<stdio.h>

void sort(int[],int);

int main(){
	int n,i;
	int a[]={6610086,6635006,8090451,9000140,8924438,2046254,2524258,8379818,5769947,2509660};
	n=10;
	sort(a,n);
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}

void sort(int a[],int n){
	int bmap[10000000/16]={};
	int i,j,m;
	for(i=0;i<n;i++)
		bmap[a[i]/16] = bmap[a[i]/16] | (1 << a[i] % 16);
	m=0;
	for(i=0;i<10000000/16;i++)
		if(bmap[i]>0)
			for(j=0;j<16;j++)
				if(bmap[i] & ( 1<<j))	
					a[m++] = i*16 +j;
}
