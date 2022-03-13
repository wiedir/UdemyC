#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

/**********************/
/* DEFINES AND TYPES  */
/**********************/
typedef struct Vector
{
    float *data;
    size_t length;
} Vector;

/**********************/
/*   MAIN FUNCTIONS   */
/**********************/

Vector *createVector(const size_t length, const float value);

Vector *freeVector(Vector *vector);

/**********************/
/*  I/O FUNCTIONS     */
/**********************/

void printVector(const Vector *vector);

/**********************/
/*  MATH. FUNCTIONS   */
/**********************/

Vector *addVectors(const Vector *vec1, const Vector *vec2);

Vector *subVectors(const Vector *vec1, const Vector *vec2);

float multiplyVectors(const Vector *vec1, const Vector *vec2);

Vector *multiplyScalar(const Vector *vec, const float scalar);

Vector *divideScalar(const Vector *vec, const float scalar);

float meanVector(const Vector *vector);

float minVector(const Vector *vector);

float maxVector(const Vector *vector);

#endif // VECTOR_H
