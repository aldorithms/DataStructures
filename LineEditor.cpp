#include <iostream>
#include <string>
#include <ofstream>
#include "LList.h"
using namespace std;

int main(){
	string mE, mF, Entry;
	LList<string> text1, tempTxt;
	int n, m, line = 1;
	ofstream file;
	
	//Start the program with entering the commands "myEdit myFile"...
	cin >> mE >> mF;
	
	if(mE == "myEdit" && mF == "myFile") {
		file.open("myFile.txt")
		do{
			cin << Entry << n << m;
			cout << text1.currPos() << ">";
			switch(Entry){
				
				case I: //Insert
					if(n != NULL) {
						for(int i = 1; i < n; i++){
							text2.moveToPos(i)
							text1.insert(text2.remove());
						}
					} else {
						text2.prev();
						text1.insert(text2.remove())
					}
					
				case D: //Delete
					if(n != NULL || m != NULL){ //two numbers n and m
						text1.moveToPos(n);
						for(int i = n; n <= m; i++){
							text1.remove();
						}
					} if(m == NULL) {
						if(n == NULL){
							text1.moveToPos(n);
						}
						text1.remove();
					}
						
				case L: //Listing Lines
					text1.print();
					break;
				case A: //Append
					for(int i = 1; i <= text2.length; i++){
						text1.append(text2.remove())
					}
				case E: //Exit
					for(int i = 1)
					file.close();
					break;
				default:
					text2.append(Entry);
					break;
			}
		}while(Entry != E)
	}
}