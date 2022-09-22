#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main(){
	while (1) {
		char input[256];
		fgets(input, 256, stdin);
		// system(input);
		pid_t pid = fork();
		if (pid == 0) {
			char *args[256];
			int arg_count = 0;
			int i = 0;
			int arg_i = 0;
			// allocate memory for the first arg
			args[0] = malloc(sizeof(char) * 256);
			// split the input line into arguments
			while (1) {
				// check that the symbol is not a split/line break/EOF
				if (input[i] != ' ' && input[i] != '\n' && input[i] != EOF) {
					args[arg_count][arg_i] = input[i];
					arg_i++;
				} else {
					// processing split
					args[arg_count][arg_i] = '\0';
					arg_count++;
					arg_i = 0;
					// end if line break/EOF
					if (input[i] != ' ')
						break;
					// allocate memory for next argument
					args[arg_count] = malloc(sizeof(char) * 256);
				}
				i++;
			}
			// args have to end with a null pointer for execv
			args[arg_count] = NULL;
			if(execvp(args[0], args) == -1) {
				perror("Could not execvp");
			};
			// free the memory for the arguments and exit if execvp did not work
			for (int i = 0; i < arg_count; i++) {
				free(args[i]);
			}
			exit(0);
		}
	}
	return EXIT_SUCCESS;
}