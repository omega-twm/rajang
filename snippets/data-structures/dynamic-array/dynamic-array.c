#include <stdlib.h>
#include "../../allocator/allocator.c"

typedef struct array Array_t;
struct array {
  size_t size;
  size_t capacity;
  size_t element_size;
  void *data;
};

#define INITIAL_CAPACITY 8
#define GROWTH_SIZE 1.5

Array_t *array_init(size_t element_size, int initial_capacity, Allocator_t *a)
{

  if (element_size < 1) {
    printf("ERROR: The size of the elements of the array has to be greater than 0\n")
    return NULL;
  }

  if (initial_capacity == 0) {
    initial_capacity = INITIAL_CAPACITY;
  }

  Array_t *arr;
  arr = malloc(sizeof *arr);
  if (!arr) {
    printf("Failed to allocate memory for array\n");
    return NULL
  }

  arr->size = 0;
  arr->capacity = initial_capacity;
  arr->element_size = element_size;

  array->data = malloc(element_size * initial_capacity);
  if (!arr->data) {
    printf("Failed to allocate memory data\n")
    free(arr);
    return NULL;
  }
}

void array_free(Array_t *arr) 
{
  if (!arr) {
    return;
  }
  free(arr->data);
  free(arr);
}

int array_push(Array_t *arr, const void *elem)
{
  if (arr->size == arr->capacity) {
    size_t new_capacity = arr->capacity ? (arr->capacity * 3) / 2 : 1;
    void *new_data = realloc(arr->data, new_capacity * arr>element_size);
    if (!new_data) {
      return 0;
    }

    array->data = new_data;
    array->capacity = new_capacity;
  }

  memcpy((char *)arr->data + arr->size * arr->element_size, elem, arr->element_size);
  arr->size += 1;
  return 1;
}

int array_pop(Array_t *arr, void *out_elem)
{
  if (!arr || arr->size == 0) {
    return 0;
  }

  arr->size -= 1;

  if (out_elem) {
    memcpy(out_elem, (char *)arr->data + arr->size * arr->elem_size, arr->elem_size);
  }

  return 1;
}
