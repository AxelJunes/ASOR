/*
Escribir un programa que consulte y muestre en pantalla el estado del
cerrojo sobre un fichero. El proceso mostrará el estado del cerrojo. Además:
- Si está bloqueado, fijará un cerrojo de escritura y escribirá la hora actual.
Después suspenderá la ejecución durante 30 segundos y liberará el cerrojo.
- Si el cerrojo está bloqueado terminará el proceso.
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	int fd;
	fd = open(argv[1], O_CREAT | O_RDWR, 0777);
	if (fd == -1) {
		printf("Error opening file, %i - %s\n", errno, strerror(errno));
		return -1;
	}
	struct flock fl;

	fl.l_type = F_WRLCK; // Default lock
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len= 0;
	fl.l_pid= getpid();

	if (fcntl(fd, F_GETLK, &fl) == -1) {
		printf("Error getting lock, %i - %s\n", errno, strerror(errno));
		exit(-1);
	}
	if(fl.l_type == F_WRLCK){ // If process lock type is a write lock
		printf("Process %d has a write lock already!\n", fl.l_pid);
		printf("%i - %s\n", errno, strerror(errno));
		exit(-1);
	} else if (fl.l_type == F_RDLCK) { // If process lock type is a read lock
		printf("Process %d has a read lock already!\n", fl.l_pid);
		printf("%i - %s\n", errno, strerror(errno));
		exit(-1);
	}
	else{ // fl.l_type == F_UNLCK
		printf("Process is unlocked!\n");
		if (fcntl(fd, F_SETLK, &fl) == -1) {
			perror("Error getting lock");
			exit(-1);
		} else {
			int length = 100;
			time_t curtime;
			time(&curtime);
			write(fd, ctime(&curtime), length);
			// Sleep for 30 seconds
			sleep(30);
			// Unlock file
			fl.l_type = F_UNLCK;
			fl.l_whence = SEEK_SET;
			fl.l_start = 0;
			fl.l_len = 0;
			if (fcntl(fd, F_SETLK, &fl) == -1){
				printf("Error removing lock, %i - %s\n", errno, strerror(errno));
				exit(-1);
			}
		}
	}
	exit(EXIT_SUCCESS);
}
