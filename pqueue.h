#include "templates.h"
#include <stdlib.h>
#include <string.h>

typedef struct
{
    size_t length;
    size_t size;
    T* data;
} TEMPLATE(T, pqueue);

int TEMPLATE(T, pqueue_init) (TEMPLATE(T, pqueue)* this)
{
    this->length = 0;
    this->data = malloc(sizeof(T));
    if (!(this->data)) return 0;
    this->size = 1;
    return 1;
}

int TEMPLATE(T, pqueue_insert) (TEMPLATE(T, pqueue) *this, T entry)
{
    if (this->length == this->size)
    {
        size_t newsize = (this->size) * 2;
        T* newdata = malloc(sizeof(T)*newsize);
        if (!newdata) return 0;

        memcpy(newdata, this->data, sizeof(T)*this->length);
        this->size = newsize;
        free(this->data);
        this->data = newdata;
    }

    size_t i = this->length;
    this->length++;
    this->data[i] = entry;
    while (i > 0)
    {
        if (TEMPLATE(T, compare)(entry, this->data[(i-1)/2]) > 0)
        {
            this->data[i] = this->data[(i-1)/2];
            this->data[(i-1)/2] = entry;
            i = (i-1)/2;
            continue;
        }
        break;
    }
    return 1;
}

T TEMPLATE(T, pqueue_peek) (TEMPLATE(T, pqueue) *this)
{
    return this->data[0];
}

T TEMPLATE(T, pqueue_pop) (TEMPLATE(T, pqueue) *this)
{
    T result = this->data[0];
    (this->length)--;
    T entry = this->data[0] = this->data[this->length];
    /* need to do re-heapify */
    int i = 0;
    int left, right;
    while ((left=(i*2+1)) < this->length)
    {
        int swap = 0;
        right = left + 1;
        if (right < this->length)
        {
            if (TEMPLATE(T, compare) (this->data[right], entry) > 0)
            {
                if (TEMPLATE(T, compare) (this->data[left], this->data[right]) > 0)
                {
                    swap = left;
                }
                else swap = right;
            }
        }
        else if (TEMPLATE(T, compare) (this->data[left], entry) > 0) swap = left;
        if (swap)
        {
            this->data[i] = this->data[swap];
            this->data[swap] = entry;
            i = swap;
            continue;
        }
        break;
    }
    if (this->length < (this->size / 4))
    {
        T* newdata = malloc(sizeof(T) * (this->size / 2));
        if (newdata)
        {
            memcpy(newdata, this->data, sizeof(T)*(this->length));
            free(this->data);
            this->data = newdata;
        }
    }
    return result;
}