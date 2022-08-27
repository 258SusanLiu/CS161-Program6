/* *Program: connectFour.cpp is the sixth assignment
 *Author: Susan Liu
 *Date: 12/7/18
 *Description: This is a connect 4 game where the user can change the bound of the board. There are 2 modes player vs computer and player vs player.
 *Input: Numbers
 *Output: Changes the area taken in board
 * */

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <string.h>
#include <string>

using namespace std;

int tab[10][10];
int choice, player;
bool end = false;
int a=0;
int draw(int row, int column);

//Asks if user wants to play again
int playagain(){
  string input;
  int players=0;
  int row;
  int column;
  ag:
    cout<<"Do you want to play again?"<<endl;
    cin>>input;
    while(input == "Yes" || input == "yes" ||input == "No" || input == "no"){
      if (input == "Yes" || input == "yes") {
        cout<<"We'll play again"<<endl;
        cout<<endl;
        cout<<"How many players?"<<endl;
        cin>>players;
        cout<<"How many rows?"<<endl;
        cin>>row;
        cout<<"How many columns?"<<endl;
        cin>>column;
        //goto replay;
        for(int i = 0; i<column; i++){
        	for(int j = 0; j<row; j++){
            	tab[i][j]=0;
            }
        }
        draw(column,row);
        return 0;
      }
      else if (input == "No" || input == "no") {
        end = true;
        cout<<"Bye"<<endl;
        return 1;
      }
    }
  goto ag;
}

//checks if the user wins
int win_check(){
  int is_win = 0;
  for(int i = 0; i<9; i++){
    for(int j = 0; j<9; j++){
      if(tab[j][i]==1 && tab[j+1][i+1]==1 && tab[j+2][i+2]==1 && tab[j+3][i+3]==1){
        cout << "PLAYER 1 WIN!" << end;
        is_win=1;
      }
      else if(tab[j][i]==1 && tab[j+1][i-1]==1 && tab[j+2][i-2]==1 && tab[j+3][i-3]==1){
        cout << "PLAYER 1 WIN!" << endl;
        is_win=1;
      }
      else if(tab[j][i]==2 && tab[j+1][i-1]==2 && tab[j+2][i-2]==2 && tab[j+3][i-3]==2){
        cout << "PLAYER 2 WIN!" << endl;
        is_win=1;
      }
      else if(tab[j][i]==2 && tab[j-1][i-1]==2 && tab[j-2][i-2]==2 && tab[j-3][i-3]==2){
        cout << "PLAYER 2 WIN!" << endl;
        is_win=1;
      }
      else if(tab[j][i]==1 && tab[j][i-1]==1 && tab[j][i-2]==1 && tab[j][i-3]==1){
       cout << "PLAYER 1 WIN!" << endl;
        is_win=1;
      }
      else if(tab[j][i]==1 && tab[j-1][i]==1 && tab[j-2][i]==1 && tab[j-3][i]==1){
       cout << "PLAYER 1 WIN!" << endl;
        is_win=1;
      }
      else if(tab[j][i]==2 && tab[j][i-1]==2 && tab[j][i-2]==2 && tab[j][i-3]==2){
        cout << "PLAYER 2 WIN!" << endl;
        is_win=1;
      }
      else if(tab[j][i]==2 && tab[j-1][i]==2 && tab[j-2][i]==2 && tab[j-3][i]==2){
        cout << "PLAYER 2 WIN!" << endl;
        is_win=1;
      }
      if (is_win == 1) { 
        return playagain();
      }
   
    }
  }
  return 0;
}

//checks if user inputed the right number inside colum bounds used for player vs player
void check(int x, int column){
  if(tab[x-1][a]!=0 && a<=column){
    a++;
    check(x,column);
  }
  else if (player==1 && a<=column){
    tab[x-1][a]=1;
    a=0;
  }
  else if (player==2 && a<=column){
    tab[x-1][a]=2;
    a=0;
  }
  else{
    cout << "WRONG!" << endl;
    a=0;
    player++;
  }
}

//checks if user inputed the right number inside colum bounds used for player vs computer
void check2(int x, int column){
  if(tab[x-1][a]!=0 && a<=column){
    a++;
    check(x,column);
  }
  else if (player==1 && a<=column){
    tab[x-1][a]=1;
    a=0;
  }
  else if (player==2 && a<=column){
    tab[x-1][a]=2;
    a=0;
  }
  else{
    cout << "WRONG!" << endl;
    a=0;
    player++;
  }
}

//draws the 7 x 6 board
int draw(int row, int column){
  //system("clear");
  for(int i = 0; i<row; i++){
    cout<<"--"<<(i+1)<<"--";
  }
  cout << endl;
  //int i = 0; i<6; i++)
  for(int i = column; i>=0; i--){
    for(int j = 0; j<row; j++){
      if(tab[j][i]!=0){
        if(tab[j][i]==1){
        cout<<"| X |";
        }
        else cout<<"| O |";
      }
      else cout<<"|   |";
    } cout<<endl;
  }
  for(int i = 0; i<5*row; i++){
    cout<<"=";
  }
  cout<<endl;
}

//checks the choice of the players is valid this is used in player vs player
int p_choice(int players, int row, int column){
  while (players == 2){
    player = 1;
    while(end!=true){
      cout << "PLAYER " << player << ": ";
      cin >> choice;
      if (choice>0 && choice<=column){
        check(choice, column);
        draw(row, column);
        if (player == 1){
          player++;
        }
        else{
          player--;
        }
      }
      else{
        cout << "WRONG CHOICE!" << endl;
      }
      if (win_check() == 1)
        return 1;
    }
  }
  return 0;
}

//checks the choice of the players is valid this is used in player vs computer
int p_choice2(int players, int row, int column){
  while (players == 1) {
    player = 1;
    while(end!=true){
      cout << "PLAYER " << player << ": ";
      cin >> choice;
      if (choice>0 && choice<=column){
        check2(choice, column);
        draw(row, column);
        if (player == 1){
          //changes to computer
          player++;
        }
        if (player ==2){
          srand(time(NULL));;
          choice = rand() % (column + 1);
          check2(choice, column);
          cout<<endl;
          draw(row, column);
          player--;
        }
        else{
          //stays at player because of mistake
          player--;
        }
      }
      else{
        cout << "WRONG CHOICE!" << endl;
      }
      if (win_check() == 1)
          return 1;
    }
  }
  return 0;
}

int main(int argc, char *argv[]){
  int players;
  int row;
  int column;
  char *playerPointer = argv[1];
  players = atoi(playerPointer);
  
  char *rows = argv[2];
  row = atoi(rows);
  
  char *columns = argv[3];
  column = atoi(columns);

cout << players << endl << row << endl << column << endl;
  //cout <<"Hi"<<endl;
  //cin >> players;
  //cout << "Input is " << players << endl;
  if(players == 1){
    cout<<"WELCOME IN CONNECT 4 Player vs Computer"<<endl;
    oneplayer:
    draw(row,column);
    p_choice2(players,row,column);
  }
  else if(players == 2){
    cout<<"WELCOME IN CONNECT 4 Player vs Player"<<endl;
    draw(row,column);
    p_choice(players,row,column);
  }
  else{
    cout<<"You did not put in 1 or 2 players"<<endl;
    cout<<"Bye!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Just kidding!"<<endl;
   // replay:
    int is_win = 0;
    do {
      cout<<"How many players are playing?"<<endl;
      cin>>players;
      if (players == 1) {
        cout<<"Rows?"<<endl;
        cin>>row;
        cout<<"Colums?"<<endl;
        cin>>column;
        draw(row,column);
        is_win = p_choice2(players,row,column);
      }
      else if (players == 2){
        cout<<"Rows?"<<endl;
        cin>>row;
        cout<<"Colums?"<<endl;
        cin>>column;
        draw(row,column);
        is_win = p_choice(players,row,column);
      }
    } while (is_win != 1);
  }
  return 0;
}