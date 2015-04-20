#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>


using namespace std; 


int main(int argc, char **argv){
	for(int i = 0; i < argc; i++){
		cout << i << ": " <<  argv[i] << endl;
	}
	
	string input; 
	getline(cin, input);
	char *str = new char[UCHAR_MAX];
	strcpy(str, input.c_str());
	
	string output[UCHAR_MAX];
	int i = 0;
	char *tokchar = strtok(str, " ");
	while(tokchar){
		output[i] = tokchar;
		tokchar = strtok(NULL, " ");
		i++;

	}


	pid_t pid; 
	pid = fork();
	if(pid == -1){
		perror("fork() failed.");
	}
	if(pid == 0){
		//child
		//execvp(output[0], output[1]);
		perror("execcp() failed");
		exit(1);
	}else {
		//parent
		wait(0);
		cout << "hello world\n";

		char hostname[64];
		gethostname(hostname, sizeof(hostname));
		cout << getlogin() << "@" << hostname << ":" << endl;
	}
	
	//while(1){}
	

	return 0; 
}
