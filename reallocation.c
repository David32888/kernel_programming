#include <malloc.h>
#include <string.h>

#include <stdio.h>

void* reallocation(void *ptr, size_t size) {
	if (size > malloc_usable_size(ptr))
		size = malloc_usable_size(ptr);

	void *new_ptr = malloc(size);
	memcpy(new_ptr, ptr, size);

	free(ptr);

	return new_ptr;
}

int main()
{
	void* ptr = malloc(1);

	const int test_cases_count = 1000000;

	for (int i = 0; i < test_cases_count; ++i)
		ptr = reallocation(ptr, i);

	for (int i = test_cases_count; i >= 0; --i)
		ptr = reallocation(ptr, i);	

	return 0;
}
