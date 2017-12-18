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
		scanf("%d",&awal[i]); //menginput 16 x
		if(awal[i]!=0) fix[i]=1; //kalau input awal[] bukan 0, masuk ke fix[]
		else fix[i]=0; // kalau input awal[] 0, fix [] = 0 
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
		if(fix[i]==0){ //yang diubah adalah yang 0
			int tag=awal[i]+1; //yang tadinya 0 ditambah 1 dimasukkin ke tag
			for(int j=0;j<16;j++){
				awal[i]=tag; 
				if(ma[i][j]==1){ //kalau hasil matrix adjacency 1 alias bertetangga
					if(awal[j]==tag){ // jika awal sama dengan tag
						output();
						tag++;j=-1; //tag ditambah, j=-1 agar saat masuk loop diulang jadi 0
					}
				}
			}
			if(tag>4){ //jika tag melebihi 4
				awal[i]=0; // awal direset jadi 0
				while(1){ //biar jalan terus
					if(fix[i-1]==1) i=i-1; //mengecek kalau sebelumnya soal, jika iya mundur 1x
					else break;
				}
				i=i-2; // ini yg kedua kali buat yg fix, yang engga baru sekali
				output();
				continue;
			}
			
			output(); //ini buat yang <4
			awal[i]=tag; //hasil akhirnya adalah tag
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
