#include <stdio.h>



int main() { 


    double raio = 0;
    double comprimento;
    const double PI = 3.1415;
    
    printf("Adicione o raio da sua circunferencia: ");
    scanf("%lf", &raio);

    comprimento = 2 * PI * raio;
    double area = PI * raio * raio;

    printf("O comprimento da circunferencia eh: %0.2lf e a sua área eh: %0.2lf", comprimento, area);

    return 0;
}
