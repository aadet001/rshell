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
	
	pid_t pid; 
	pid = fork();
	if(pid == 0){
		//child
		execvp("ls", argv);
		exit(0);
	}else {
		wait(0);
		cout << "hello world\n";

	}
	


	return 0; 
}
