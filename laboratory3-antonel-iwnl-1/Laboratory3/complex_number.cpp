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
    // returns the real part of the complex number
    return c.real;
}

float get_imag(Complex c) {
    // returns the imaginary part of the complex number
    return c.image;
}

void set_real(Complex* c, float real) {
    // sets the real part
    c->real = real;
}

void set_imag(Complex* c, float imag) {
    // sets the imaginary part
    c->image = imag;
}

Complex complex_conjugate(Complex c) {
    // returns the conjugate of the complex number
    Complex conjugate;
    conjugate.real = c.real;
    conjugate.image = -c.image;
    return conjugate;
}

Complex complex_add(Complex c1, Complex c2) {
    // adds the real and imaginary parts of 2 complex numbers
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.image = c1.image + c2.image;
    return sum;
}

Complex complex_subtract(Complex c1, Complex c2) {
    // subtracts the real and imaginary parts of 2 complex numbers
    Complex difference;
    difference.real = c1.real - c2.real;
    difference.image = c1.image - c2.image;
    return difference;
}

Complex complex_multiply(Complex c1, Complex c2) {
    // multiplies two complex numbers together by using the formula
    Complex product;
    product.real = c1.real * c2.real - c1.image * c2.image;
    product.image = c1.real * c2.image + c1.image * c2.real;
    return product;
}

Complex complex_division(Complex c1, Complex c2) {
    // divides two complex numbers
    Complex quotient;
    float denominator = c2.real * c2.real + c2.image * c2.image;
    quotient.real = (c1.real * c2.real + c1.image * c2.image) / denominator;
    quotient.image = (c1.image * c2.real - c1.real * c2.image) / denominator;
    return quotient;
}

void complex_scalar_multiply(Complex* c, float scalar) {
    // multiplies the imaginary and real parts of a complex number with a scalar
    c->real *= scalar;
    c->image *= scalar;
}

bool complex_equal(Complex c1, Complex c2) {
    // checks if two complex numbers are equal
    return c1.real == c2.real && c1.image == c2.image;
}

float complex_mag(Complex c) {
    // return the modulo of the complex number |z| = sqrt(x^2 + y^2)
    return sqrt(c.real * c.real + c.image * c.image);
}

float complex_phase(Complex c) {
    // returns the angle of a complex number from the origin
    return atan2(c.image, c.real);
}

void complex_to_polar(Complex c, float* r, float* theta) {
    // returns the polar coordinates of the complex numbers
    *r = complex_mag(c);
    *theta = complex_phase(c);
}

void complex_display(Complex c) {
    // displays the complex number
    printf("%f + %fi", c.real, c.image);
}