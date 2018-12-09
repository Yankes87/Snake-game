#include <conio.h>
#include <windows.h>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;
char a[50][50];
char history[100000];
int score=0;
int speed=5;
int counter=-1;
int length=3;
int test=1;
int c_time=0;
time_t seconds;
char direction='d';
void print();
void vanish();
void fruit();
void change();
void wipe();
void menu();
void settings();
void maps();
void deathscreen();
void movesnake(char direction);
int xp=11, yp=11, xk=11, yk=11;

int check_fruit(){
	
		 for(int x=1; x<22;x++){
        for(int y=1;y<22;y++){
            a[x][y]=='@';
            return 0;
        }
    }
	fruit();
}

int score_update(){
	
	a[9][39]=(char)48+(score%100000)/10000; a[9][40]=(char)48+(score%10000)/1000; a[9][41]=(char)48+(score%1000)/100; a[9][42]=(char)48+(score%100)/10; a[9][43]=(char)48+score%10;
        
        if(score==0){
        	a[9][39]=' '; a[9][40]=' '; a[9][41]=' '; a[9][42]=' ';}
        else
        if(score<1000){
        	a[9][39]=' '; a[9][40]=' ';}
        else
        if(score<10000)
        	a[9][39]=' ';
	
	return 0;
}

int main(){

	
		 for(int x=1; x<22;x++){
        for(int y=1;y<22;y++){
            a[x][y]=' ';
        }
    }
	
	for(int x=0;x<23;x++){
        a[x][0]='#';
        a[x][22]='#';
        a[0][x]='#';
        a[22][x]='#';
    }
    
    for(int x=30;x<=45;x++){
        a[7][x]='-';
        a[13][x]='-';
        
    }
    
    for(int x=8;x<=12;x++){
        a[x][45]='|';
        a[x][30]='|';
        
    }
    a[9][32]='S'; a[9][33]='c'; a[9][34]='o'; a[9][35]='r'; a[9][36]='e'; a[9][37]=':';		a[9][39]=(char)48+(score%100000)/10000; a[9][40]=(char)48+(score%10000)/1000; a[9][41]=(char)48+(score%1000)/100; a[9][42]=(char)48+(score%100)/10; a[9][43]=(char)48+score%10; 
    a[11][32]='T'; a[11][33]='i'; a[11][34]='m'; a[11][35]='e'; a[11][36]=':';	a[11][41]=':';	
	
	menu();
}

void game(){

   c_time=time(NULL);
   
    srand((unsigned int)time(0));
    
score_update();

a[11][43]=(char)48+(seconds-c_time)%10;
a[11][42]=(char)48+((seconds-c_time)%60)/10;
a[11][40]=(char)48+((seconds-c_time)%60);

fruit();

    while(test>0){
    	
    	seconds= time(NULL);
    	
    		a[11][43]=(char)48+(seconds-c_time)%10;
			a[11][42]=(char)48+((seconds-c_time)%60)/10;
			a[11][40]=(char)48+((seconds-c_time)/60)%10;
			a[11][39]=(char)48+((seconds-c_time)/600);
			
			if(seconds-c_time<600)
			a[11][39]=' ';
         
        check_fruit();
        
        print();
        change();
		counter++;
        history[counter]=direction;
        movesnake(direction);

        Sleep(219-19*speed);
        system("CLS");
       
       

    }
 deathscreen();  
}
void print(){
    for(int x=0;x<23;x++){
        for(int y=0;y<50;y++){
            cout<<a[x][y]<<"";
        }
        cout<<endl;
    }
}

void movesnake(char direction){
    int asdf=0;
    switch(direction){
            case 'w':
                if(a[yp-1][xp]=='#'||a[yp-1][xp]=='1'){
                    asdf=1;
                }
                if(a[yp-1][xp]=='@'){
                    length++;
                    score+=100;
                    score_update();
                wipe();
                fruit();
                }
                vanish();
                
                yp-=1;
                a[yp][xp]='1';
            break;
            case 'a':
                if(a[yp][xp-1]=='#'||a[yp][xp-1]=='1'){
                    asdf=1;
                }
                if(a[yp][xp-1]=='@'){
                    length++;
                    score+=100;
                    score_update();
                wipe();
                fruit();
                }
                vanish();
                
                xp-=1;
                a[yp][xp]='1';
            break;

            case 's':
                if(a[yp+1][xp]=='#'||a[yp+1][xp]=='1'){
                    asdf=1;
                }
                if(a[yp+1][xp]=='@'){
                    length++;
                    score+=100;
                    score_update();
                wipe();
                fruit();
                }
                vanish();
                
                yp+=1;
                a[yp][xp]='1';
            break;

            case 'd':
                if(a[yp][xp+1]=='#'||a[yp][xp+1]=='1'){
                    asdf=1;
                }
                if(a[yp][xp+1]=='@'){
                   length++;
                   score+=100;
                   score_update();
                wipe();
                fruit();
                }
                vanish();
                
                xp+=1;
                a[yp][xp]='1';
            break;
    }
    if(asdf==1){
        test--;
    }
}

void vanish(){
    char b=history[counter-length];
        switch(b){
            case 'w':
                yk-=1;
                a[yk][xk]=' ';
            break;
            case 'a':
                xk-=1;
                a[yk][xk]=' ';
            break;

            case 's':
                yk+=1;
                a[yk][xk]=' ';
            break;

            case 'd':
                xk+=1;
                a[yk][xk]=' ';
            break;
    }
}

void wipe(){
	
	char b=history[counter-length];
        switch(b){
            case 'w':
                yk+=1;
              //   a[yk][xk]=' ';
            break;
            case 'a':
                xk+=1;
              //  a[yk][xk]=' ';
            break;

            case 's':
                yk-=1;
              //  a[yk][xk]=' ';
            break;

            case 'd':
                xk-=1;
              //  a[yk][xk]=' ';
            break;
    }
	
	
}

void change(){
	if (_kbhit()) {
	    char c=_getch();
	    
	    

    switch((int)c) {
        case 72:
            c='w';
            break;
        case 75:
            c='a';
            break;
        case 80:
			c='s';
	        break;
        case 77:
            c='d';
            break;
    
}
	    
        if((c=='w'&&direction!='s')||(c=='s'&&direction!='w')||(c=='a'&&direction!='d')||(c=='d'&&direction!='a')){
            direction = c;
        }
	}
}
void fruit()
{
    int xf=0;
    int yf=0;

    while(a[yf][xf]!=' ')
    {
    xf=rand()%21+1;
    yf=rand()%21+1;
    }
    a[yf][xf]='@';
}

void menu(){
	
c_time=time(0);
	
	puts("\n\n\n\n\n\n        ====SNAKE====");
	puts("        1. Start game");
	puts("        2. Settings");
	puts("        3. Quit");
	puts("        =============");
	
	char choice=_getch();
	if(choice!='1' && choice!='2' && choice!='3'){
		system("CLS");

		
		menu();
	}
	switch(choice){
		case '1':{
			system("CLS");
			game();
			break;
		}
		case '2':{
			system("CLS");
			settings();
			break;
		}
		case '3':{
			exit(0);
			break;
		}
	}
}

void settings(){
	
	puts("\n\n\n\n\n\n        ===SETTINGS===");
	puts("        1. Speed");
	puts("        2. Maps");
	puts("        3. Back");
	puts("        ==============");
	
	char choice=_getch();
	if(choice!='1' && choice!='2' && choice!='3'){
		system("CLS");

		
		settings();
	}
	switch(choice){
		case '1':{
			
			do{
				system("CLS");
				printf("\n\n\n\n\n\n\n         Select speed (1-10): ");
				cin>>speed;
			}
			while(speed<1||speed>10);
	
			system("CLS");
			
			settings();
			
			
			break;
		}
		case '2':{{
			system("CLS");
			maps();
			break;
		}
		case '3':
			system("CLS");
			menu();
			break;
		}
	}
}

void maps(){
	
	puts("\n\n\n\n\n\n        =====MAPS=====");
	puts("        1. Empty field");
	puts("        2. Castle");
	puts("        3. Tunnels");
	puts("        4. Maze");
	puts("        ==============");
	
	char choice=_getch();
	if(choice!='1' && choice!='2' && choice!='3' && choice!='4'){
		system("CLS");

		
		maps();
	}
	switch(choice){
		case '1':{
			
		for(int x=1; x<22;x++){
        for(int y=1;y<22;y++){
            a[x][y]=' ';
        }
}
    system("CLS");
    settings();
			
			break;
		}
		case '2':{
			
			for(int x=1; x<22;x++){
        for(int y=1;y<22;y++){
            a[x][y]=' ';
        }
    }
			
			for(int x=5;x<=17;x++){
        a[x][5]='#';
        a[x][17]='#';
        a[5][x]='#';
        a[17][x]='#';
    }
    
    	for(int x=10;x<=12;x++){
        a[x][5]=' ';
        a[x][17]=' ';
        a[5][x]=' ';
        a[17][x]=' ';
    }
    
	system("CLS");
    settings();
			
			break;
		}
		case '3':{
			
			for(int x=1; x<22;x++){
        for(int y=1;y<22;y++){
            a[x][y]=' ';
        }
    }
    
    		for(int x=5;x<=17;x++){
        a[5][x]='#';
        a[9][x]='#';
        a[13][x]='#';
        a[17][x]='#';
    }
			
		system("CLS");
    settings();
			
			break;
		}
		case '4':{
			
				for(int x=1; x<22;x++){
        for(int y=1;y<22;y++){
            a[x][y]=' ';
        }
    }
			
		for(int x=1;x<=17;x++){
        a[5][x]='#';
        a[13][x]='#';
    }	
	
	for(int x=5;x<=21;x++){
        a[9][x]='#';
        a[17][x]='#';
    }			
		
			system("CLS");
    settings();
			
			break;
		}
	}
}

void deathscreen(){
	puts("\n\n\n\n\n\n\n        =============");
	puts("         *GAME OVER* ");
	puts("        =============");
	Sleep(1500);
	test++;
	xp=11; yp=11; xk=11; yk=11;
	counter=-1;
	length=3;
	score=0;
	direction='d';
	system("CLS");
	
		 for(int x=1; x<22;x++){
        for(int y=1;y<22;y++){
            a[x][y]=' ';
        }
    }
	
	for(int x=0;x<23;x++){
        a[x][0]='#';
        a[x][22]='#';
        a[0][x]='#';
        a[22][x]='#';
    }
	
	menu();
	
	
	
}
