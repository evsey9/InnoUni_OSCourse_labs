#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>

int is_prime(int n)
{
	if (n <= 1)
		return 0;
	for (int d = 2; d * d <= n; d++)
		if (n % d == 0)
			return 0;
	return 1;
}

int primes_count_in_interval(int start, int finish)
{
	int ret = 0;
	for (int i = start; i < finish; i++)
		if (is_prime(i) != 0)
			ret++;
	return ret;
}

// The structure that will be passed to the threads, corresponding to an interval to count the number of primes in.
typedef struct prime_counter_request
{
	int start, finish;
} prime_counter_request;

void *prime_counter(void *arg)
{
	prime_counter_request* convArg = (prime_counter_request*)(arg);
	int start = convArg->start;
	int finish = convArg->finish;
	int baseResult = primes_count_in_interval(start, finish);
	int* result = malloc(sizeof(int));
	*result = baseResult;
	return (void *)result;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]), n_threads = atoi(argv[2]);
	int segment_size = n / n_threads + (n % n_threads == 0 ? 0 : 1);

	pthread_t *threads = malloc(n_threads * sizeof(pthread_t));

	prime_counter_request *requests = malloc(n_threads * sizeof(prime_counter_request));

	void **results = malloc(n_threads * sizeof(void *));

	for (int i = 0; i < n_threads; i++)
	{
		requests[i].start = segment_size * i;
		requests[i].finish = segment_size * (i + 1);
		if (requests[i].finish > n) {
			requests[i].finish = n;
		}
		pthread_create(&threads[i], NULL, prime_counter, &requests[i]);
	}

	for (int i = 0; i < n_threads; i++)
	{
		pthread_join(threads[i], &results[i]);
	}

	int total_result = 0;
	for (int i = 0; i < n_threads; i++)
		total_result += *(int *)results[i];

	for (int i = 0; i < n_threads; i++) {
		free(results[i]);
	}
	free(results);
	free(threads);
	free(requests);

	printf("%d\n", total_result);

	exit(EXIT_SUCCESS);
}