#include <sdtdio.h>

int main(){
    int age = 30;
    int * pAge = &age;
    double gpa = 3.4;
    double * pGpa = &gpa;
    char grade = 'A';
    char * pGrade = &grade;

    printf("La direccion de memoria de la edad es: %p\n", &age);
    return 0;
}