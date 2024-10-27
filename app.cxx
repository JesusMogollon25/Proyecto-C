#include<stdlib.h>
#include<iostream>
#include<windows.h>
#include<cmath>
using namespace std;
struct structKey {
  int leftKey = 0;
  int rightKey = 0;
  int upKey = 0;
  int downKey = 0;
};
structKey KeyDef;
int clamp(int val, int min,int max);
bool checkKey(structKey& KeyStruct);
int main(){
	bool finished = false;
	int squareSize[] = {3,3};
	int cont = 0;
	int pos[] = {1,1}; 
	int actualPos = 0;
	bool passed = false;
	while(!finished){
	  for(int i = 0; i < squareSize[0];i++){
	    for(int j = 0; j < squareSize[1];j++){
	      cont++;
	      bool target = (i == pos[0] && j == pos[1]); 
	      if(target) cout<<"<";
	      else cout<<" ";
	      cout<<cont;
	      if(target) cout<<">";
	      else cout<<" ";  
	    }
	    cout<<'\n';
	  }
	while(!passed) passed = checkKey(KeyDef);
	pos[1] = clamp(pos[1] + (abs(KeyDef.rightKey) - abs(KeyDef.leftKey)),0,squareSize[1]-1);
	pos[0] = clamp(pos[0] + (abs(KeyDef.downKey) - abs(KeyDef.upKey)),0,squareSize[0]-1);
	cont = 0;
	passed = 0;
	Sleep(200);
	system("CLS");
	}
  }
int clamp(int _val, int _min,int _max){
  return max(_min,min(_val,_max));
}
bool checkKey(structKey& KeyStruct){
  KeyStruct.upKey = (GetKeyState('W') < 0);
  KeyStruct.leftKey = (GetKeyState('A') < 0);
  KeyStruct.downKey = (GetKeyState('S') < 0);
  KeyStruct.rightKey = (GetKeyState('D') < 0);
  return ((KeyStruct.upKey + KeyStruct.rightKey + KeyStruct.downKey + KeyStruct.leftKey)!=0);
}
