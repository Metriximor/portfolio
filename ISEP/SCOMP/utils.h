//
// Created by metriximor on 01/04/20.
//
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <semaphore.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

/**
 * Abre uma memória partilhada e retorna um apontador void *
 * O apontador void * têm que ser cast
 * @param name o nome do processo partilhado
 * @param size o tamanho do processo a abrir
 * @return um apontador void que tem ser cast
 * @throws 0 se por alguma razão não conseguir abrir a memória partilhada
 */
void* open_shared_memory(char * name, size_t size);

/**
 * Cleans the buffer from any left-over input
 */
void clean_buffer(void);

/**
 * Reads a string to a pre-memory allocated array
 * @param string the array we want to read the string to
 * @param length the maximum length of the string we want to read
 * @return the size of the read string
 */
int input(char *string, int length);

/**
 * Inicializa um semaforo exclusivo com as flags O_CREAT | O_EXCL e as permissões 0644<br>
 * Verifica automáticamente se há algum problema ao criar o semáforo e envia um perror no caso
 * de existir algum problema
 * @param semaphore_name o nome do semáforo a ser criado
 * @param initial_val o valor do semaforo(e.g. 0 ou 1)
 * @return um semaforo
 */
sem_t* open_exclusive_semaphore(char* semaphore_name, unsigned int initial_val);

/**
 * Inicializa um semaforo com as flags O_CREAT e as permissoes 0644<br>
 * Se o semáforo já existir, o valor colocado no initial_val é irrelevante
 * @param semaphore_name o nome do semáforo
 * @param initial_val o valor do semáforo, se o semáforo já existir, o initial_val é irrelevant
 * @return um semáforo
 */
sem_t *open_semaphore(char *semaphore_name, unsigned int initial_val);

/**
 * Closes and deletes shared memory from the OS
 * @param shm_name the name of the shared memory
 * @param shm the pointer to the shared memory
 * @param size_shm the size of the shared_memory
 */
void close_and_unlink_shm(char* shm_name, void* shm, size_t size_shm);

/**
 * Closes and deletes a semaphore from the OS
 * @param sem_name the name of the semaphore
 * @param sem the pointer to the semaphore
 */
void close_and_unlink_semaphore(char *sem_name, sem_t *sem);

/**
 * Frees the pointer to the shared memory
 * @param shm the pointer to the shared memory
 * @param size_shm the size of the shared memory
 */
void close_shm(void* shm, size_t size_shm);

/**
 * Frees the pointer to the semaphore
 * @param sem the pointer to the semaphore
 */
void close_semaphore(sem_t *sem);

/**
 * Similar to getpid() but for threads
 * @return the thread id of the caller thread
 */
int gettid();
