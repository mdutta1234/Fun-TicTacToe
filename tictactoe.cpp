//here if u finish the code with ur last move that fills last box and u win in ur last move it will come as tie pls correct
#include<iostream>
//here if u finish the code with ur last move that fills last box and u win in ur last move it will come as tie pls correct
using namespace std;
int TIE=0;
bool tie(int x[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x[i][j]==-4){
            
            return false;
            
            }
        }

    }
    TIE=1;
    return true;
}
bool chk(int x[][3]){
    int s=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            s+=x[i][j];
        }
        if(s==3 || s==0)
        return true;
        s=0;
    }  
        for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            s+=x[j][i];
        }
        if(s==3 || s==0)
        return true;
        s=0;
    }  
    if(x[0][0]+x[1][1]+x[2][2]==3||x[0][0]+x[1][1]+x[2][2]==0)
    return true;
    if(x[2][0]+x[1][1]+x[0][2]==3||x[2][0]+x[1][1]+x[0][2]==0)
    return true;
    return false;
}
void boardgenerator(int x[][3]){
    cout<<"\t  0   1   2  \n";
    for(int j=0;j<7;j++){
        if(j%2==0){
            cout<<"\t ___ ___ ___\n";
        }
        else{
            cout<<((j-1)/2);
            cout<<"\t";
            for(int i=0;i<13;i++){
                if(i%2==1)
                cout<<" ";
                else if(i%4==0)
                cout<<"|";
                else{
                    if(x[(j-1)/2][(i-2)/4]==-4)
                        cout<<" ";
                    else if(x[(j-1)/2][(i-2)/4]==0)
                    cout<<"O";
                    else
                    cout<<"X";
                }
            }
            cout<<'\n';
        }
    }
}
int main(){
    int x[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            x[i][j]=-4;
        }
    }
    cout<<"Choose what you want to go first with X or O(i.e. player ones choice)  ";
    char c;
    cin>>c;
    int t;
    int h,v;
    if(c=='X'){
        t=1;
    }
    else{
        t=0;
    }
    while(!chk(x)&&!(tie(x))){
        if(t==1){
            cout<<"\n\n\n\n";
            boardgenerator(x);
            cout<<"\nPlease tell the coordinates of the box where u want to keep X ";
            cin>>h>>v;
            x[h][v]=1;
            t=1-t;
        }
        else{
            cout<<"\n\n\n\n";
            boardgenerator(x);
            cout<<"\nPlease tell the coordinates of the box where u want to keep O ";
            cin>>h>>v;
            x[h][v]=0;
            t=1-t; 
        }

    }
    if(t==0 && TIE==0){ //here if u finish the code with ur last move that fills last box and u win in ur last move it will come as tie pls correct
    cout<<"\n\n X wins!!!\n";
    boardgenerator(x);
    }
    else if(t==1 && TIE==0){
    cout<<"\n\n O wins!!!\n";
    boardgenerator(x);
    }    
    else{
    cout<<"\n\n\nTie!!\n";
    boardgenerator(x);
    }
}