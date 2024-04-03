#include <math.h>
#include <stdio.h>

#include "complex_number.h"

Complex complex_create(float real, float img) {
    Complex c;
    c.real = real;
    c.image = img;
    return c;
}

float get_real(Complex c) {
    return c.real;
}

float get_imag(Complex c) {
    return c.image;
}

void set_real(Complex* c, float real) {
    c->real = real;
}

void set_imag(Complex* c, float imag) {
    c->image = imag;
}

Complex complex_conjugate(Complex c) {
    Complex conjugate;
    conjugate.real = c.real;
    conjugate.image = -c.image;
    return conjugate;
}

Complex complex_add(Complex c1, Complex c2) {
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.image = c1.image + c2.image;
    return sum;
}

Complex complex_subtract(Complex c1, Complex c2) {
    Complex difference;
    difference.real = c1.real - c2.real;
    difference.image = c1.image - c2.image;
    return difference;
}

Complex complex_multiply(Complex c1, Complex c2) {
    Complex product;
    product.real = c1.real * c2.real - c1.image * c2.image;
    product.image = c1.real * c2.image + c1.image * c2.real;
    return product;
}

Complex complex_division(Complex c1, Complex c2) {
    Complex quotient;
    float denominator = c2.real * c2.real + c2.image * c2.image;
    quotient.real = (c1.real * c2.real + c1.image * c2.image) / denominator;
    quotient.image = (c1.image * c2.real - c1.real * c2.image) / denominator;
    return quotient;
}

void complex_scalar_multiply(Complex* c, float scalar) {
    c->real *= scalar;
    c->image *= scalar;
}

bool complex_equal(Complex c1, Complex c2) {
    return c1.real == c2.real && c1.image == c2.image;
}

float complex_mag(Complex c) {
    return sqrt(c.real * c.real + c.image * c.image);
}

float complex_phase(Complex c) {
    return atan2(c.image, c.real);
}

void complex_to_polar(Complex c, float* r, float* theta) {
    *r = complex_mag(c);
    *theta = complex_phase(c);
}

void complex_display(Complex c) {
    printf("%f + %fi", c.real, c.image);
}