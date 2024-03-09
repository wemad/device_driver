#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int max = 100;
int count = 0;

void *odd_print(void *data) {
	while (count < max) {
		pthread_mutex_lock(&mutex);
		if ((count % 2) != 1)
			pthread_cond_wait(&cond, &mutex);

		printf("%d ", count++);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);

	}
	pthread_exit(0);
}

void *even_print(void *data) {

	while(count < max) {
		pthread_mutex_lock(&mutex);
		if ((count % 2) != 0)
			pthread_cond_wait(&cond, &mutex);

		printf("%d ", count++);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
	}
	pthread_exit(0);
}

void main() {
	pthread_t tid_1, tid_2;
	pthread_mutex_init(&mutex, 0);
	pthread_cond_init(&cond, 0);
	pthread_create(&tid_1, 0, &odd_print, NULL);
	pthread_create(&tid_2, 0, &even_print, NULL);
	pthread_join(tid_1, 0);
	pthread_join(tid_2, 0);
	printf("exit\n");
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
}
