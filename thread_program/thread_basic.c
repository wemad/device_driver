#include <stdio.h>
#include <pthread.h>

int ret = 1000;

void *thread_func(void *data) {
	printf("hello I am thread: %d\n", * (int*)data);
        pthread_exit(&ret);
}


void main(){
	pthread_t thread_id;
	int *ret;
	int value=10;
	if (pthread_create(&thread_id, NULL, &thread_func, &value)) {
		printf("thread failed\n");
		return;
	}	
	pthread_join(thread_id, (void **)&ret);
	printf("threa exit return value:%d\n", *ret);
}

