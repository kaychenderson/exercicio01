/* Questão 4: Crie um programa para calcular a área e o perímetro de um hexágono. O seu
programa deve implementar uma função chamada calcula_hexagono que calcula a área e o
perímetro de um hexágono regular de lado l. A função deve obedecer ao seguinte protótipo:
void calcula_hexagono(float l, float *area, float *perimetro); A área e o perímetro de um
hexágono regular são dados, respectivamente, por:

            A = (3(L^2)sqrt(3)) / 2
            P = 6L

Obs: Para os cálculos, utilize as funções sqrt e pow do módulo math da biblioteca 
padrão de C. Em seguida, crie a função principal do programa e utilize a função 
calcula_hexagono para calcular a área e o perímetro de um hexágono de lado l 
informado pelo usuário. */

// Resposta:

#include <stdio.h>
#include <math.h>

// Protótipo:
void calcs_pa_hex(float l, float *area, float *perimetro);

void calcs_pa_hex(float l, float *area, float *perimetro) {
    *area = ((3*pow(l,2))*sqrt(3)/2);
    *perimetro = 6*l;
}

int main(void) {

    float area = 0, perimetro = 0, lado;
    float *parea = &area, *pperimetro = &perimetro;

    printf("Informe o tamanho dos lados do hexagono: \n");
    scanf("%f", &lado);
    calcs_pa_hex(lado, parea, pperimetro);
    printf("A área é: %.2f, e e seu perimetro é: %.2f", area, perimetro);

    return 0;
}