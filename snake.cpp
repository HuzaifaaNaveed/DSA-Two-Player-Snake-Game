#include<iostream>
#include<windows.h>
#include<conio.h>
#include <queue>
using namespace std;
int height=25;
int width=100;
int gameover=0,counter,gameover2=0,choice,counter2;
int lflag=0,rflag=0,uflag=0,dflag=0;
int lflag2=0,rflag2=0,uflag2=0,dflag2=0;
short fcount;
class Snake{
    int x,y,fx,fy,x2,y2;
    char playername[50],playername2[50];
    queue<pair<int, int>> foodQueue;
    struct node{
    int nx,ny;
    struct node *next;
    struct node *back;
    };
    struct node *head=NULL;
    struct node *head2=NULL;
    void gotoxy(int x,int y){
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    }
    void nameandscore(){
    gotoxy(102,0);
    textcolour(10);
    cout<<"";
    textcolour(7);
    gotoxy(102,2);
    cout<<playername<<"'s SCORE = "<<counter*100;
    if(choice==2){
    gotoxy(102,4);
    cout<<playername2<<"'s SCORE = "<<counter2*100;
    gotoxy(102,6);
    cout<<"Remained Fruit :";
    gotoxy(117,6);
    cout<<" ";
    gotoxy(117,6);
    cout<<fcount;
    }
    }
        void textcolour(int k){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,k);
    }
    public:
    void hideCursor() {
            CONSOLE_CURSOR_INFO cursorInfo;
            cursorInfo.dwSize = 1;
            cursorInfo.bVisible = FALSE;
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
        }
        // Function to show the cursor
        void showCursor() {
            CONSOLE_CURSOR_INFO cursorInfo;
            cursorInfo.dwSize = 1;
            cursorInfo.bVisible = TRUE;
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
        }
    void window(){ //setting the boundaries of the game
    /*if(choice==1)
        textcolour(4);
    else
        textcolour(1);*/
    textcolour(3);
    for(int i=0;i<=width;i++){
    gotoxy(i,0);
    cout<<"||";
    gotoxy(i,height);
    cout<<"||";
    }
    for(int i=1;i<=height;i++){
    gotoxy(0,i);
    cout<<"||";
    gotoxy(width,i);
    cout<<"||";
    }
    }
    void setup(){
    counter=0;
    gameover=0;
    window();
    resetflag();
    nameandscore();
    head=new node;
    head->nx=width/2;
    head->ny=height/2;
    head->next=NULL;
    head->back=NULL;
    x=width/2;
    y=height/2;
    generateFruit();
    label1:
    fx=rand()%width;
    if(fx==0||fx==width)
        goto label1;
    label2:
    fy=rand()%height;
    if(fy==0||fy==height)
        goto label2;
    }
    void setup2(){
    resetflag2();
    gameover2=0;
    counter2=0;
    fcount=25;
    head2=new node;
    head2->nx=width/2+5;
    head2->ny=height/2+5;
    head2->next=NULL;
    head2->back=NULL;
    x2=width/2+5;
    y2=height/2+5;
    generateFruit();
    }
    void drawlist(struct node *h,int k){
    textcolour(k);
    struct node *ptr;
    ptr=h;
    while(ptr!=NULL){
    gotoxy(ptr->nx,ptr->ny);
    cout<<"O";
    ptr=ptr->next;
    }
    }
    void destroylist(struct node *h){
    struct node *ptr;
    ptr=h;
    while(ptr!=NULL){
    gotoxy(ptr->nx,ptr->ny);
    cout<<" ";
    ptr=ptr->next;
    }
    }
    void draw() {
            drawlist(head, 2);
            drawlist(head2, 5);
            if (!foodQueue.empty()) {
                pair<int, int> fruit = foodQueue.front();
                int fruitX = fruit.first;
                int fruitY = fruit.second;
                gotoxy(fruitX, fruitY);
                textcolour(4);
                cout << "*";
            }
            Sleep(70);
            destroylist(head);
            destroylist(head2);
        }
    void resetflag(){
    uflag=0;
    dflag=0;
    lflag=0;
    rflag=0;
    }
    void resetflag2(){
    uflag2=0;
    dflag2=0;
    lflag2=0;
    rflag2=0;
    }
    void play(){
    int h;
    char ch;
    if(kbhit()){
    ch=getch();
    h=ch;
    switch(h){
        case 72:
            if(dflag!=1){
                resetflag();uflag=1;
        }
            break;
        case 80:
            if(uflag!=1){
            resetflag();dflag=1;
        }
            break;
        case 75:
            if(rflag!=1){
            resetflag();lflag=1;
        }
            break;
        case 77:
            if(lflag!=1){
            resetflag();rflag=1;
        }
            break;
        case 119:
            if(dflag2!=1){
            resetflag2();uflag2=1;
        }
            break;
        case 115:
            if(uflag2!=1){
            resetflag2();dflag2=1;
        }
            break;
        case 97:
            if(rflag2!=1){
            resetflag2();lflag2=1;
        }
            break;
        case 100:
            if(lflag2!=1){
            resetflag2();rflag2=1;
        }
            break;
        default:break;
    }
    }
    }
    void box(int m1,int n1,int m2,int n2){
    for(int i=m1;i<m2;i++){
    gotoxy(i,n1);
    cout<<"__";
    gotoxy(i,n2);
    cout<<"__";
    }
    for(int i=n1+1;i<=n2;i++){
    gotoxy(m1,i);
    cout<<"|";
    gotoxy(m2,i);
    cout<<"|";
    }
    }
    void welcome(){
    textcolour(5);
    box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
    textcolour(10);
    gotoxy(width/2-20,height/2-10);
    cout<<"*** WELCOME TO SNAKE GAME *** ";
    textcolour(9);
    gotoxy(width/2-16,height/2-3);
    cout<<"Press 1 For Single player \n";
    gotoxy(width/2-16,height/2-1);
    cout<<"Press 2 For Multiplayer \n";
    gotoxy(width/2-16,height/2);
    cin>>choice;
    system("cls");
    }
    void welcome1(){
    textcolour(5);
    box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
    textcolour(6);
    gotoxy(width/2-18,height/2-3);
    cout<<"WELCOME TO SNAKE GAME SINGLE PLAYER MODE ";
    textcolour(8);
    gotoxy(width/2-13,height/2);
    cout<<"Enter Your Name : ";
    cin>>playername;
    system("cls");
    }
    void welcome2(){
    textcolour(5);
    box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
    textcolour(6);
    gotoxy(width/2-18,height/2-3);
    cout<<"WELCOME TO SNAKE GAME MULTIPLAYER MODE ";
    textcolour(8);
    gotoxy(width/2-13,height/2);
    cout<<"Enter Player1 Name : ";
    gotoxy(width/2-13,height/2+2);
    cout<<"Enter Player2 Name : ";
    gotoxy(width/2+7,height/2);
    cin>>playername;
    gotoxy(width/2+7,height/2+2);
    cin>>playername2;
    system("cls");
    }
    char end(){
    char c;
    gotoxy(width/2-5,height/2-4);
    cout<<"GAME OVER \n";
    textcolour(5);
    box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
    textcolour(1);
    gotoxy(width/2-15,height/2-2);
    cout<<playername<<" You Scored : "<<counter*100;
    if(choice==2){
    gotoxy(width/2-15,height/2);
    cout<<playername2<<" You Scored : "<<counter2*100;
    textcolour(4);
    if(gameover!=0){
        gotoxy(width/2-15,height/2+2);
        cout<<playername<<" has lost !";
    }
    else{
        gotoxy(width/2-15,height/2+2);
        cout<<playername2 <<" has lost !";
    }
    if(fcount==0){
        textcolour(4);
        gotoxy(width/2-15,height/2+2);
        if(counter>counter2){
        cout<<playername<<" has WON !";
        }
        else{
        cout<<playername2<<" has WON !";
        }
    }
    }
    textcolour(6);
    gotoxy(width/2-15,height/2+4);
    cout<<"Want To Play Again ? (Y/N) : ";
    cin>>c;
    system("cls");
    return c;
    }
    void run(){
    if(uflag==1)
        y--;
    else if(dflag==1)
        y++;
    else if(lflag==1)
        x--;
    else if(rflag==1)
        x++;
    if(uflag2==1)
        y2--;
    else if(dflag2==1)
        y2++;
    else if(lflag2==1)
        x2--;
    else if(rflag2==1)
        x2++;
    }
    void dolist(struct node *h,int pp,int qq){
    struct node *ptr,*prev;
    ptr=h;
    prev=h;
    while(ptr->next!=NULL){
    prev=ptr;
    ptr=ptr->next;
    }
    while(prev!=h){
    ptr->nx=prev->nx;
    ptr->ny=prev->ny;
    prev=prev->back;
    ptr=ptr->back;
    }
    ptr->nx=prev->nx;
    ptr->ny=prev->ny;
    prev->nx=pp;
    prev->ny=qq;
    }
    void drawagain(){
    if(x==width){
    x=1;
    }
    if(x==0){
    x=width-1;
    }
    if(y==0){
    y=height-1;
    }
    if(y==height){
    y=1;
    }
    }
    void drawagain2(){
    if(x2==width){
    x2=1;
    }
    if(x2==0){
    x2=width-1;
    }
    if(y2==0){
    y2=height-1;
    }
    if(y2==height){
    y2=1;
    }
    }
    void generateFruit(){
            label1:
            int fx = rand()%width;
            int fy = rand()%height;
            if(fx==0 || fx==width || fy==0 || fy==height){
                goto label1;
            }
            // Enqueue the coordinates to the food queue
            foodQueue.push(make_pair(fx, fy));
        }
        void checkfcount(){
            if(!foodQueue.empty()){
                pair<int, int> fruit = foodQueue.front();
                int fruitX = fruit.first;
                int fruitY = fruit.second;
                if(x==fruitX && y==fruitY){
                    foodQueue.pop();
                    // Generate new fruit when eaten
                    generateFruit();
                }
            }
        }
    void checkup(){
            if(choice==1){
            if(x==width || x==0)
                    gameover = 1;
                if(y==height || y==0)
                    gameover = 1;
            }
            drawagain();
            struct node* h;
            h = head->next;
            while(h!=NULL){
                if(x==h->nx && y==h->ny){
                    gameover = 1;
                    break;
                }
                h = h->next;
            }
            if(x==foodQueue.front().first && y==foodQueue.front().second){
                foodQueue.pop();
                generateFruit();
                struct node* t = new node;
                t->next = NULL;
                t->back = NULL;
                struct node* ptr = head;
                struct node* prev = head;
                while (ptr->next != NULL) {
                    prev = ptr;
                    ptr = ptr->next;
                }
                ptr->next = t;
                t->back = ptr;
                counter++;
                nameandscore();
            }
            dolist(head, x, y);
        }
        void checkup2(){
            drawagain2();
            struct node* h;
            h = head2->next;
            while(h!= NULL){
                if(x2==h->nx && y2==h->ny){
                    gameover2 = 1;
                    break;
                }
                h = h->next;
            }
            if(x2==foodQueue.front().first && y2==foodQueue.front().second){
                foodQueue.pop();
                generateFruit();
                struct node* t = new node;
                t->next = NULL;
                t->back = NULL;
                struct node* ptr = head2;
                struct node* prev = head2;
                while(ptr->next!=NULL){
                    prev = ptr;
                    ptr = ptr->next;
                }
                ptr->next = t;
                t->back = ptr;
                counter2++;
                nameandscore();
            }
            dolist(head2, x2, y2);
        }
    void game1(){
    char ch;
    welcome1();
    do{
    setup();
    window();
    hideCursor();
    while(!gameover){
        draw();
        play();
        run();
        checkup();
    }
    showCursor();
    ch=end();
    }while(ch=='y'||ch=='Y');
    }
    void game2(){
    char ch;
    welcome2();
    do{
            setup2();
    setup();
    window();
    hideCursor();
        while(gameover!=1&&gameover2!=1){
        draw();
        play();
        run();
        checkup();
        checkup2();
    }
    showCursor();
    ch=end();
    }while(ch=='y'||ch=='Y');
    }
    };
    int main(){
    Snake s;
    s.welcome();
    if(choice==1){
    s.game1();
    }
    if(choice==2){
    s.game2();
    }
    system("exit");
}
  
