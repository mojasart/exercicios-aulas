#include <stdio.h>
#include <math.h>

int main() {

double valorMensal = 0;
int anos = 0;
double taxaMensal = 0;

do{
    printf("Coloque o valor mensal: ");
    scanf("%lf", &valorMensal);
    if(valorMensal < 1)
    {
        printf("valor nao pode ser abaixo de 0\n");
    }
}while (valorMensal < 1);

do{
    printf("Coloque os anos de investimento: ");
    scanf("%d", &anos);
    if(anos < 1)
    {
        printf("valor nao pode ser abaixo de 0\n");
    }
}while (anos < 1);

do{
    printf("Coloque a taxa mensal: ");
    scanf("%lf", &taxaMensal);
    if(taxaMensal < 0)
    {
        printf("valor nao pode ser abaixo de 0\n");
    }
}while (taxaMensal < 0);


int meses = anos * 12;
int totalDiasUteis = meses * 30; //22 dias uteis nesse caso
double taxaDiaria = pow((1 + taxaMensal/100), (1.0 / 30)) - 1;


double montante = valorMensal;

while (totalDiasUteis >= 0){
    montante *=(1 + taxaDiaria);
    
    if (totalDiasUteis %30 == 0){
        montante += valorMensal;
    }
    totalDiasUteis --;
}

double montante1 = montante - valorMensal;
printf("O valor Total após %d é %.2lf", anos, montante1);
    return 0;
}
