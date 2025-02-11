#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex, mutex_odd;
void *odd(void *arg) {
	int i = 1;
	while(i < 100) {
		pthread_mutex_lock(&mutex_odd);
		sleep(1);
		printf("%d\n", i);
		i+=2;
		pthread_mutex_unlock(&mutex);
	}


}

void *even(void *arg) {
	int i = 0;

	while(i < 100) {
		pthread_mutex_lock(&mutex);
		printf("%d\n", i);
		i+=2;
		pthread_mutex_unlock(&mutex_odd);
	}

}

void main() {
	pthread_t tid1; 
	pthread_t tid2;
	pthread_mutex_init(&mutex, 0);
	pthread_mutex_init(&mutex_odd, 0);
	pthread_create(&tid1, NULL, odd, NULL);
	pthread_create(&tid2, NULL, even, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&mutex);
}
