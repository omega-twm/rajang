#include <stdlib.h>


typedef struct allocator Allocator_t;
struct allocator {
  void *(*alloc)(size_t bytes, void *context);
  void *(*free)(size_t bytes, void *ptr, void *context);
  void *context;
};


void *my_alloc(size_t bytes, void *context)
{
  (void)context;
  return malloc(bytes);
}

void *my_free(size_t bytes, void *ptr, void *context)
{
  (void)ptr; (void)context;
  free(ptr);
}

Allocator_t my_allcoator = {my_alloc, my_free, 0};
