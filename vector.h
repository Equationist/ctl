#include "templates.h"
#include <stdlib.h>
#include <string.h>

typedef struct
{
    size_t length;
    size_t size;
    T* data;
} TEMPLATE(T, vector);

int TEMPLATE(T, vector_init) (TEMPLATE(T, vector)* this)
{
    this->length = 0;
    this->data = malloc(sizeof(T));
    if (!(this->data)) return 0;
    this->size = 1;
    return 1;
}

int TEMPLATE(T, vector_append) (TEMPLATE(T, vector) *this, T entry)
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
    this->data[(this->length)++] = entry;
    return 1;
}

T TEMPLATE(T, vector_pop) (TEMPLATE(T, vector) *this)
{
    (this->length)--;
    if (this->length < (this->size / 4))
    {
        size_t newsize = this->size / 2;
        T *newdata = malloc(sizeof(T) * newsize);
        if (newdata)
        {
            this->size = newsize;
            memcpy(newdata, this->data, sizeof(T) * this->length);
            free(this->data);
            this->data = newdata;
        }
    }
    return this->data[this->length];
}