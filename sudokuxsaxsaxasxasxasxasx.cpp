#include <stdio.h>
#include <conio.h>
#include <windows.h>

int i,ma[16][16]={0,1,1,1,1,1,0,0,1,0,0,0,1,0,0,0,
				  1,0,1,1,1,1,0,0,0,1,0,0,0,1,0,0,
				  1,1,0,1,0,0,1,1,0,0,1,0,0,0,1,0,
				  1,1,1,0,0,0,1,1,0,0,0,1,0,0,0,1,
				  1,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,
				  1,1,0,0,1,0,1,1,0,1,0,0,0,1,0,0,
				  0,0,1,1,1,1,0,1,0,0,1,0,0,0,1,0,
				  0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,1,
				  1,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,
				  0,1,0,0,0,1,0,0,1,0,1,1,1,1,0,0,
				  0,0,1,0,0,0,1,0,1,1,0,1,0,0,1,1,
				  0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,1,
				  1,0,0,0,1,0,0,0,1,1,0,0,0,1,1,1,
				  0,1,0,0,0,1,0,0,1,1,0,0,1,0,1,1,
				  0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,1,
				  0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,0};
int awal[16];
int fix[16];


void setcolor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}


void input(){
	for(int i=0;i<16;i++){
		scanf("%d",&awal[i]);
		if(awal[i]!=0) fix[i]=1;
		else fix[i]=0;
	}
}


void cek(int p,int j){
	for(int i=0;i<16;i++){
		if(ma[p-1][i]==1){
			if(awal[i]==j){
				fix[p-1]=3;
			}
		}
	}
}



void output(){
	int flag=0;
	for(int i=0;i<16;i++){
		if(fix[i]==3)setcolor(12);
		if(fix[i]==1)setcolor(11);
		printf("%d ",awal[i]);flag++;
		setcolor(8);
		if((flag/2)%2==1 and flag%2==0) printf("| ");
		if(flag%4==0) printf("\n");
		if(i==7) printf("---------\n");
	}
}

int main(){
	int posisi,value,a;
	input();
	while(1){
		system("cls");
		cek(posisi,value);
		output();
		printf("Masukan Posisi 	: ");
		scanf("%d",&posisi);
		printf("Masukan Nilai	: ");
		scanf("%d",&value);
		if (value>4 || fix[posisi-1]==1) {
		printf("Input Salah\n");
		getchar();
		getchar();
		continue;
		}
		awal[posisi-1]=value;
		fix[posisi-1]=0;
	}
return 0;
}
