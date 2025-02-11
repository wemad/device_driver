#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem,sem1;

void *even(void *arg) {
	int i = 0; 
	while(i <=10) {
		sem_wait(&sem);
		printf("%d ", i);
		i = i + 2;
		sem_post(&sem1);
	}
}

void *odd(void *arg) {
	int i = 1;
	while (i <=10) {
		sem_wait(&sem1);	
		printf("%d ", i);
		i = i + 2;
		sem_post(&sem);
	}

}

void main() {
	pthread_t tid1, tid2;
	sem_init(&sem, 0, 1);
	sem_init(&sem1, 0, 0);
	pthread_create(&tid1, NULL, &even, NULL);
	pthread_create(&tid2, NULL, &odd, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

}
