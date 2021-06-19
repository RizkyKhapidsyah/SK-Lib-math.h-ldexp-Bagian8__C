#pragma warning(disable:4996)
#pragma fenv_access (on)

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <fenv.h>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main(void) {
    printf("ldexp(7, -4) = %f\n", ldexp(7, -4));
    printf("ldexp(1, -1074) = %g (minimum positive subnormal double)\n", ldexp(1, -1074));
    printf("ldexp(nextafter(1,0), 1024) = %g (largest finite double)\n", ldexp(nextafter(1, 0), 1024));
    // special values
    printf("ldexp(-0, 10) = %f\n", ldexp(-0.0, 10));
    printf("ldexp(-Inf, -1) = %f\n", ldexp(-INFINITY, -1));
    //error handling
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("ldexp(1, 1024) = %f\n", ldexp(1, 1024));

    if (errno == ERANGE) {
        perror("    errno == ERANGE");
    }

    if (fetestexcept(FE_OVERFLOW)) {
        puts("    FE_OVERFLOW raised");
    }

    _getch();
    return 0;
}