#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

using namespace std; 


int main(int argc, char **argv){
	for(int i = 0; i < argc; i++){
		cout << i << ": " <<  argv[i] << endl;
	}
	
	pid_t pid; 
	pid = fork();
	if(pid == 0){
		//child
		execvp(argv[1], argv);
		exit(0);
	}else {
		//parent
		wait(0);
		cout << "hello world\n";
		size_t buff;
		char hostname[128];
		gethostname(hostname, sizeof(hostname));
		cout << getlogin() << "@" << hostname << ":" << endl;
	}
	


	return 0; 
}
