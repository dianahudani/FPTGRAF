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

void output(){
	system("cls");
	int flag=0;
	printf("HASIL : \n");
	for(int i=0;i<16;i++){
		if(awal[i]==1)setcolor(242);
		if(awal[i]==2)setcolor(245);
		if(awal[i]==3)setcolor(253);
		if(awal[i]==4)setcolor(252);
		printf("%d ",awal[i]);flag++;
		setcolor(240);
		if((flag/2)%2==1 and flag%2==0) printf("| ");
		if(flag%4==0) printf("\n");
		if(i==7) printf("---------\n");
	}
	printf("\n");
	Sleep(500);
}

void solping(){
	for(int i=0;i<16;i++){
		if(fix[i]==0){
			int tag=awal[i]+1;
			for(int j=0;j<16;j++){
				awal[i]=tag;
				if(ma[i][j]==1){
					if(awal[j]==tag){
						output();
						tag++;j=-1;
					}
				}
			}
			if(tag>4){
				awal[i]=0;
				while(1){
					if(fix[i-1]==1) i=i-1;
					else break;
				}
				i=i-2;
				output();
				continue;
			}
			
			output();
			awal[i]=tag;
		}
	}	
}

int main(){
	setcolor(240);
	system("cls");
	input();
	solping();
	output();
	printf("FINISH! \\0.0/");
return 0;
}
