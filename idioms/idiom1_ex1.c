#include <stdio.h>
#include <pthread.h>

int global1 = 0;
int global2 = 0;
int global3 = 0;

void *func1(void *arg) {
	int local1 = 45;
	if (global1 == 2) {
		printf("idiom1 bug1 manifests!\n");
	}
	int local2 = 34;
	global2 = 10;
	int local6 = 45;
	global3 = 100;
	return NULL;
}

void *func2(void *arg) {
	int local3 = 34;
	global1 = 2;
	int local4 = 23;
	if (global2 == 10) {
		printf("idiom1 bug2 manifests\n");
	}
	int local5 = 343;
	global3 = 100;
	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, func1, NULL);
	pthread_create(&t2, NULL, func2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	// printf("Final value of a is %d.\n", a);

	return 0;
}