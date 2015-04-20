#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

using namespace std;


int main(int argc, char **argv){
        cout << "argc: " << argc << endl;
        for(int i = 0; i < argc; i++){
                cout << "argv["<< i << "] = " << argv[i] << endl;
        }
	
	string input; //= "hello darkness my old friend";
	getline(cin, input);
	//cin >> input;
	char *str = new char[UCHAR_MAX];
	strcpy(str,input.c_str());
	//char str[UCHAR_MAX]= input.c_str();
	//"Hello darkness my old friend";
	char *tokchar;
 	
	int i = 0; 
	
	string output[UCHAR_MAX];
	
	tokchar = strtok(str, " ");
	
	while(tokchar){
		output[i] = tokchar; 
		tokchar = strtok(NULL, " ");
		
		i++;
	}
	
	cout << output[2] << " ";
	cout << output[4] << endl;
	
	delete[] str;	
	
        return 0;
}

