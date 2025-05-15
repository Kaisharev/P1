#include "buffer.h"
#include <stdbool.h>

BUFFER form_buffer(void) {
    BUFFER buffer;
    buffer.front = 0;
    buffer.rear = 0;
    return buffer;
}

bool is_empty(BUFFER *buffer) {
    return buffer->front == buffer->rear;
}

bool is_full(BUFFER *buffer) {
    return (buffer->rear + 1) % BUFFER_SIZE == buffer->front;
}

bool put(BUFFER *buffer, int element) {
    if (is_full(buffer)) {
        return false;
    }
    
    buffer->elements[buffer->rear] = element;
    buffer->rear = (buffer->rear + 1) % BUFFER_SIZE;
    return true;
}

bool get(BUFFER *buffer, int *element) {
    if (is_empty(buffer)) {
        return false;
    }
    
    *element = buffer->elements[buffer->front];
    buffer->front = (buffer->front + 1) % BUFFER_SIZE;
    return true;
}