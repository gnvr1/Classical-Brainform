#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <fstream>
using namespace std;  unsigned char vars[4096][4096];  long long CaM[257][256];  long long mtds[4096][256];  unsigned short d=0; 
long long queue[2560][6]; unsigned short p[4]; int loop; int loop2; short queue_id=-1; unsigned short k=0; bool setup=true; int i=0; unsigned char a[64]; unsigned char c[64]; unsigned short b[5]={0,0,0,0}; 
int why(int toPurify){if(toPurify>=0){return toPurify%4096; }else{return(4096+toPurify)%4096; }}
void save_to_queue(){queue_id++; queue[queue_id][0]=i; queue[queue_id][1]=p[0]; queue[queue_id][2]=p[1]; queue[queue_id][3]=p[2]; queue[queue_id][4]=p[3]; queue[queue_id][5]=k; }
void get_from_queue(){if(i>=0){i=queue[queue_id][0]; /*p[0]=queue[queue_id][1]; p[1]=queue[queue_id][2]; p[2]=queue[queue_id][3]; p[3]=queue[queue_id][4]; */k=queue[queue_id][5]; }queue_id--; }
void create_obj(unsigned char klasa,unsigned short obiekt,string urBf);
void process (char znak,string urBf){switch(znak){
case '+':if(setup==false){for(loop=0; loop<=d; loop++){vars[why(p[0]-loop)][p[1]]+=1; if(vars[why(p[0]-loop)][p[1]]!=0)loop=d+1; }}break;
case '-':if(setup==false){for(loop=0; loop<=d; loop++){vars[why(p[0]-loop)][p[1]]-=1; if(vars[why(p[0]-loop)][p[1]]!=255)loop=d+1; }}break;
case '.':if(setup==false){for(loop=d; loop>=0; loop--){cout<<vars[why(p[0]-loop)][p[1]]; }}break;
case ',':if(setup==false){vars[p[0]][p[1]]=_getch(); }break;
case '>':if(setup==false){p[k]++; if(k<2)p[k]%=4096; else p[k]%=256; }break;
case '<':if(setup==false){p[k]--; if(k<2)p[k]=(p[k]+4096)%4096; else if(k==2)p[k]=(p[k]+256)%256; }break; 			
case '[':if(setup==false){int temp=0; for(loop=0; loop<=d; loop++){if(vars[why(p[0]-loop)][p[1]]!=0)temp++; }if(temp==0){loop=1; while(loop!=0){i++; if(urBf[i]=='[')loop++; if(urBf[i]==']')loop--; }}}break; 				
case ']':if(setup==false){int temp=0; for(loop=0; loop<=d; loop++){if(vars[why(p[0]-loop)][p[1]]!=0)temp++; }if(temp>0){loop=1; while(loop!=0){i--; if(urBf[i]=='[')loop--; if(urBf[i]==']')loop++; }}}break; 
case '|':p[3]++; CaM[256][p[3]]=i; p[2]=0; break;
case '{':CaM[p[2]][p[3]]=i; p[2]++; break;
case '^':if(setup==false){k++; k=k%4; }break;
case 'v':if(setup==false){k--; k=(k+4)%4; }break;
case '!':if(setup==false){save_to_queue(); i=mtds[p[1]][p[2]]; k=0; }break;
case '}':if(setup==false){get_from_queue(); }break;
case '&':if(setup==false){create_obj(p[3],p[1],urBf); }break;
case 'P':if(setup==false){p[k]=vars[p[0]][p[1]]; if(d>0)p[k]+=256*vars[why(p[0]-1)][p[1]]; if(k<2)p[k]%=4096; else p[k]%=256; }break;
case '?':if(setup==false){cout<<"\n"; for(int e=0; e<4096; e++)if(vars[e][p[1]]!=0)cout<<e<<" - "<<int(vars[e][0])<<", "; cout<<"\n";}break;		
case '(':if(setup==false){int temp=0; for(loop=0; loop<=d; loop++){if(vars[why(p[0]-loop)][p[1]]!=0)temp++; }if(temp==0){loop=1; while(loop!=0){i++; if(urBf[i]=='(')loop++; if(urBf[i]==')')loop--; }}}break;
case 'c':if(setup==false){for(loop=0; loop<=d; loop++)a[63-loop]=vars[why(p[0]-loop)][p[1]];}break;
case 'p':if(setup==false){for(loop=0; loop<=d; loop++)vars[why(p[0]-loop)][p[1]]=a[63-loop];}break;
case 'r':if(setup==false){p[k]=0;}break;
case 'A':if(setup==false){int temp2=0; int temp=0; for(loop=0; loop<=d; loop++){temp2=(a[63-loop]+vars[why(p[0]-loop)][p[1]]+temp)/256; vars[why(p[0]-loop)][p[1]]+=a[63-loop]+temp; temp=temp2;}}break;
case 'S':if(setup==false){int temp2=0; int temp=0; for(loop=0; loop<=d; loop++){temp2=1-(256-a[63-loop]+vars[why(p[0]-loop)][p[1]]-temp)/256; vars[why(p[0]-loop)][p[1]]-=a[63-loop]+temp; temp=temp2;}}break;
case 39:if(setup==false){while(urBf[i+1]!=39){i++; cout<<urBf[i]; }i++; }break;
case 't':if(setup==false){vars[p[0]][p[1]]+=10; }break;
//case'g':if(setup==false){p[k]+=a; if(k < 2)p[k]%=4096; else p[k]%=256; }break;
case 'M':if(setup==false){int temp2=0; int temp=0; unsigned char tab[64]; for(loop2=0; loop2<64; loop2++)tab[loop2]=0; for(loop2=0; loop2<=d; loop2++){temp=0; for(loop=0; loop<=d-loop2; loop++){temp2=(a[63-loop2] * vars[why(p[0]-loop)][p[1]] + temp)/256; unsigned char uwu; uwu = tab[63-loop-loop2];
tab[63-loop-loop2] += vars[why(p[0]-loop)][p[1]] * a[63-loop2] + temp; if(uwu + (vars[why(p[0]-loop)][p[1]] * a[63-loop2] + temp)%256 > 256){tab[62-loop-loop2]+=1; for(int loop3=loop+1+loop2; loop3<=d; loop3++)
if(tab[63-loop3]==0)tab[62-loop3]+=1; else loop3=d+1;}
//cout<<"\nIteration "<<loop<<" of "<<d<<"; outer iteration "<<loop2<<" of "<<d<<"; "<<int(vars[why(p[0]-loop)][p[1]])<<" * "<<int(a[63-loop2])<<" + "<<temp<<" = "<<vars[why(p[0]-loop)][p[1]] * a[63-loop2] + temp<<" from which "<<(vars[why(p[0]-loop)][p[1]] * a[63-loop2] + temp)/256<<" overflowed, and "<<(vars[why(p[0]-loop)][p[1]] * a[63-loop2] + temp)%256<<" was added to tab["<<63-loop<<"] which was "<<int(uwu)<<" making "<<(uwu + (vars[why(p[0]-loop)][p[1]] * a[63-loop2] + temp))%256<<" with "<<(uwu + (vars[why(p[0]-loop)][p[1]] * a[63-loop2] + temp)%256)/256<<" overflow";
 temp=temp2;}}for(loop=0; loop<=d; loop++)vars[why(p[0]-loop)][p[1]] = tab[63-loop];}break;
//case'b':if(setup==false){p[k]-=a; if(k<2)p[k]=(p[k]+4096)%4096; else if(k==2)p[k]=(p[k]+256)%256; }break;
case 'C':if(setup==false){for(loop=0; loop<=d; loop++)c[63-loop]=vars[why(p[0]-loop)][p[1]];}break;
case 'V':if(setup==false){for(loop=0; loop<=d; loop++)vars[why(p[0]-loop)][p[1]]=c[63-loop];}break;
case 'd':if(setup==false && d<63)d++; break;
case '0':if(setup==false)d=0; break;
//case'D':if(setup==false){int temp1=0; int temp2=0; for(loop=d; loop>=0; loop--){temp1=(vars[why(p[0]-loop)][p[1]]+256*temp2)%a; vars[why(p[0]-loop)][p[1]]=(vars[why(p[0]-loop)][p[1]]+256*temp2)/a; temp2=temp1; }}break; 
case 's':if(setup==false){b[k]=p[k];}break; 
case 'l':if(setup==false)p[k]=b[k]; break; 
case '#':if(setup==false){long long temp; long long temp2; temp=1; temp2=0; for(loop=0; loop<=d; loop++){temp2+=(vars[why(p[0]-loop)][p[1]])*temp; temp*=256; }cout<<temp2; }break; 
case '@':if(setup==false){save_to_queue(); int temp1=0; int temp2=0; for(p[2]=0; p[2]<256; p[2]++)if(CaM[p[2]][p[3]]!=-3)temp1++; for(p[2]=0; p[2]<256; p[2]++)if(mtds[p[1]][p[2]]!=-3)temp2++; 
if(temp1+temp2>256)i=-5; else{for(; temp2>=0; temp2--)mtds[p[1]][temp2+temp1]=mtds[p[1]][temp2]; for(i=0; i<temp1; i++)mtds[p[1]][i]=CaM[i][p[3]]; p[0]=0; p[2]=0; k=0; for(i=CaM[256][p[3]]+1; urBf[i]!='|'&&urBf[i]!=';'&&i>-1; i++)
{if(urBf[i]=='{'){while(urBf[i]!='}'){i++; }}else process(urBf[i],urBf); }get_from_queue(); }}break; }}
void create_obj(unsigned char klasa,unsigned short obiekt,string urBf){save_to_queue(); for(i=0; i<256; i++)mtds[obiekt][i]=CaM[i][klasa]; 
for(p[0]=0; p[0]<4096; p[0]++){vars[p[0]][p[1]]=0; }p[0]=0; p[2]=0; k=0; for(i=CaM[256][klasa]+1; urBf[i]!='|'&&urBf[i]!=';'&&i>-1; i++){if(urBf[i]=='{'){while(urBf[i]!='}'){
i++; }}else process(urBf[i],urBf); }get_from_queue(); }
void debrainfuckify(string urBf){if(setup==true){for(i=0; i<256; i++){for(int j=0; j<256; j++)CaM[i][j]=-3; }for(i=0; i<4096; i++){for(int j=0; j<256; j++)mtds[i][j]=-3; }i=0; }for(i=0; i<256; i++)CaM[256][i]=-5; CaM[256][0]=-1; 
do{p[0]=0; p[1]=0; p[2]=0; p[3]=0; k=0; if(setup==false){i=-10; create_obj(0,0,urBf); }if(setup==true){i=0; while(urBf[i]!=';'&&i>=-1){process(urBf[i],urBf); i++; }setup=false; }else setup=true; }while(setup==false); 
switch(i){case -3:cout<<"\nProgram tried to use a class that isn't defined!"; break; case -2:cout<<"\nProgram tried to execute a method that isn't defined!"; break; case -4:cout<<"Object doesn't have enough free method slots to 'inherit' from the class!"; break; }}
int main(int argc, char* argv[]){string code = ""; string cos = ""; ifstream f(argv[1]); while(getline(f, cos)){code+=cos; code+=char(10); }code+=';'; debrainfuckify(code); f.close(); 
cout<<"\n\n-------------------------------------\nPress anything to continue..."; _getch(); 
return 0;}
