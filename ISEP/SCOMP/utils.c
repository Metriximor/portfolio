//
// Created by metriximor on 01/04/20.
//
#include "utils.h"

void clean_buffer(void) {
	while ((getchar()) != '\n');
}

long read_line(char *str) {
	clean_buffer();
	str = NULL;
	size_t n = 0;
	ssize_t nchr = 0;
	if ((nchr = getline(&str, &n, stdin)) != -1) {
		str[nchr - 1] = 0;
	}
	return nchr - 1;
}

int input(char *string, int length) {
	clean_buffer();
	int x = 0;
	fgets(string, length, stdin);
	while (*string) {
		if (*string == '\n') {
			*string = '\0';
			return x;
		}
		x++;
		if (x == length) {
			*string = '\0';
			return x;
		}
		string++;
	}
}

void *open_shared_memory(char *name, size_t size) {
	int fd;
	fd = shm_open(name, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
	if (fd < 0) {
		perror("Não conseguiu alocar memória para partilhar");
		exit(0);
	}
	ftruncate(fd, size);
	void *pointer;
	pointer = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED,
				   fd, 0);
	if (pointer == NULL) {
		perror("Pointer não aponta para nada");
		exit(0);
	}
	return pointer;
}

sem_t *open_exclusive_semaphore(char *semaphore_name, unsigned int initial_val) {
	sem_t *semaphore = sem_open(semaphore_name, O_CREAT | O_EXCL, 0644, initial_val);
	if (semaphore == SEM_FAILED) {
		perror("No sem_open()");
		exit(EXIT_FAILURE);
	}
	return semaphore;
}

sem_t *open_semaphore(char *semaphore_name, unsigned int initial_val) {
	sem_t *sem = sem_open(semaphore_name, O_CREAT, 0644, initial_val);
	if (sem == SEM_FAILED) {
		perror("No sem_open()");
		exit(EXIT_FAILURE);
	}
	return sem;
}

void close_semaphore(sem_t *sem) {
	if (sem_close(sem) < 0) {
		perror("error closing semaphore");
		exit(EXIT_FAILURE);
	}
}

void close_and_unlink_semaphore(char *sem_name, sem_t *sem) {
	close_semaphore(sem);
	if (sem_unlink(sem_name) < 0) {
		perror("error unlinking semaphore");
		exit(EXIT_FAILURE);
	}
}

void close_shm(void *shm, size_t size_shm) {
	if(munmap(shm, size_shm)<0) {
		perror("error munmapping shm");
		exit(EXIT_FAILURE);
	}
}

void close_and_unlink_shm(char *shm_name, void *shm, size_t size_shm) {
	close_shm(shm, size_shm);
	if(shm_unlink(shm_name)<0) {
		perror("error shm unlinking");
		exit(EXIT_FAILURE);
	}
}

int gettid() {
	return pthread_self();
}
