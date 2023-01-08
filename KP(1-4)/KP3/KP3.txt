{\rtf1\ansi\ansicpg1251\cocoartf1561
{\fonttbl\f0\fnil\fcharset0 HelveticaNeue;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red255\green255\blue255;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;\cssrgb\c100000\c100000\c100000;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sl360\partightenfactor0

\f0\fs32 \cf2 \cb3 \expnd0\expndtw0\kerning0
#include <stdio.h> \
#include \cf2 \cb3 <float.h> \
\cf2 \cb3 #include\cf2 \cb3  <stdint.h> \
\cf2 \cb3 #include \cf2 \cb3 <math.h> \
\
long double Taylor(uint64_t n, long double x) \{\
    long double res = 0;\
    for (int i = 0; i < n; ++i) \{\
        res += (pow(x, 4 * i)/(pow(4, i + 1)));\
    \}\
    return res;\
\}\
\
long double function(long double x) \{\
    return 1/(4 - pow(x, 4));\
\}\
\
int main() \{\
\
    long double a = 0.0;\
    long double b = 1.0;\
    \
    uint64_t n; \
 \
    scanf("%ld", &n); \
    printf("n = %ld\\n", n); \
    printf("Machine epsilon is equal to: %Lg\\n\\n", LDBL_EPSILON); \
 \
    printf("        Table of values of Taylor series and standard function\\n"); \
    printf("___________________________________________________________________________\\n"); \
    printf("|  x  | sum of Taylor series | f(x) function value | number of iterations |\\n"); \
    printf("___________________________________________________________________________\\n"); \
    \
    long double x = 0;\
    long double step = (b - a)/n;\
    long double f = 1;\
    int i = 0;\
    \
    while (fabsl(f) > LDBL_EPSILON && (i < 100) && (i < n)) \{ \
        i += 1; \
        x += step; \
        f = function(x); \
 \
        printf("|%.5llf|%.20llf|%.20llf|           %d          |\\n", x, Taylor(i, x), f, i); \
    \} \
 \
    printf("___________________________________________________________________________\\n"); \
 \
    return 0; \
\}}