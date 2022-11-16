#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
	// Directory in which we look
	const char dirName[] = "/";
	DIR* dirp = opendir( dirName);
	if (dirp == NULL) {
		printf("Can't open directory\n");
		return (1);
	}
	struct dirent* entry;
	while ((entry = readdir(dirp)) != NULL) {
		if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
			printf("%s ", entry->d_name);
		}
	printf("\n");
	closedir(dirp);
	return(0);
}