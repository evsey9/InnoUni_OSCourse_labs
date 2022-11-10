#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
	// Directory in which we look
	const char dirName[] = "tmp";
	DIR* dirp = opendir( dirName);
	if (dirp == NULL) {
		printf("Can't open directory\n");
		return (1);
	}
	struct dirent* entry;
	int fileCount = 0;
	unsigned long processedInodes[1024];  // The inodes we have already counted as linked
	int processedCount = 0;  // How many inodes we have counted as linked
	char fileNames[1024][1024];  // Filenames
	unsigned long fileInodes[1024];  // Inodes of the corresponding filenames
	while ((entry = readdir(dirp)) != NULL) {
		struct stat statResult;
		char strPath[1024];
		fileInodes[fileCount] = entry->d_ino;
		strcpy(fileNames[fileCount], entry->d_name);
		sprintf(strPath, "%s/%s", dirName, entry->d_name);
		stat(strPath, &statResult);
		if (statResult.st_nlink >= 2) {
			// Check if we have already processed this inode or not
			int alreadyProcessedFlag = 0;
			for (int i = 0; i < processedCount; i++) {
				if (entry->d_ino == processedInodes[i]) {
					alreadyProcessedFlag = 1;
					break;
				}
			}
			if (!alreadyProcessedFlag) {
				// Mark this inode in the array
				processedInodes[processedCount] = entry->d_ino;
				processedCount++;
			}
		}
		fileCount++;
	}
	closedir(dirp);
	for (int i = 0; i < processedCount; i++) {
		char outStr[1024];
		sprintf(outStr, "file%d - ", i + 1);
		// Check what files have the same inode
		for (int j = 0; j < fileCount; j++) {
			if (fileInodes[j] == processedInodes[i]) {
				sprintf(outStr, "%s%s, ", outStr, fileNames[j]);
			}
		}
		// Get rid of the comma at the end
		outStr[strlen(outStr) - 2] = '\0';
		printf("%s\n", outStr);
	}
	return(0);
}