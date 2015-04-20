#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std; 


int main(int argc, char **argv){
	for(int i = 0; i < argc; i++){
		cout << i << ": " <<  argv[i] << endl;
	}



	return 0; 
}
