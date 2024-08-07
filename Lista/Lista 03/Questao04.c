/* Você foi contratado para desenvolver um programa em C que permita armazenar nomes completos e idades 
de várias pessoas. O programa deve solicitar ao usuário o número de pessoas e, em seguida, permitir que 
ele digite o nome completo e a idade de cada pessoa.

Seu programa deve alocar memória dinamicamente para armazenar os nomes em uma matriz de strings, 
enquanto as idades devem ser armazenadas em um vetor. Após a entrada de todos os nomes e idades, 
o programa deve exibir os nomes armazenados.

Aqui estão as especificações do programa:

- O programa deve começar solicitando ao usuário o número de pessoas que deseja armazenar.
- Em seguida, o programa deve pedir ao usuário que digite o nome completo de cada pessoa.
- Os nomes devem ser armazenados em uma matriz alocada dinamicamente.
- Após o nome, o programa deve solicitar a idade da pessoa.
- As idades devem ser armazenadas em um vetor alocado dinamicamente.
- Após a entrada de todos os nomes e idades, o programa deve exibir os nomes armazenados.
- Certifique-se de tratar adequadamente a alocação dinâmica de memória e liberar a memória alocada 
corretamente após o uso.

Observação: O programa deve ser capaz de armazenar até 100 nomes completos. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtdPessoas, count;
    char **nomes; 
    int *idades; 

    printf("Digite o número de pessoas que deseja armazenar: ");
    scanf("%d", &qtdPessoas);
    if (qtdPessoas <= 0 || qtdPessoas > 100) {
        printf("Número de pessoas inválido. Digite um número entre 1 e 100.\n");
    }

    while (qtdPessoas <= 0 || qtdPessoas > 100) {
        printf("Digite o número de pessoas que deseja armazenar: ");
        scanf("%d", &qtdPessoas);
        if (qtdPessoas <= 0 || qtdPessoas > 100) {
            printf("Número de pessoas inválido. Digite um número entre 1 e 100.\n");
        }
    }

    nomes = (char **)malloc(qtdPessoas*sizeof(char *));
    if (nomes == NULL) {
        printf("Falha na alocação de memória para nomes.\n");
        return 1;
    }

    idades = (int *)malloc(qtdPessoas*sizeof(int));
    if (idades == NULL) {
        printf("Falha na alocação de memória para idades.\n");
        free(nomes); 
        return 1;
    }

    for (count = 0; count < qtdPessoas; count++) {
        printf("\n Pessoa N-%d:\n", count+1);

        //100 : a quantidade definida como máxima de chars nos nomes
        nomes[count] = (char *)malloc(100*sizeof(char)); 

        if (nomes[count] == NULL) {
            printf("Falha na alocação de memória para nome.\n");
            free(nomes); 
            free(idades); 
            return 1;
        }

        printf("Digite o nome completo: ");
        scanf(" %[^\n]", nomes[count]); // Lerá a string completa com os espaços at

        printf("Digite a idade: ");
        scanf("%d", &idades[count]);
    }

    printf("\n Nomes armazenados: \n");
    for (count = 0; count < qtdPessoas; count++) {
        printf("%s \n", nomes[count]); 
    }

    for (count = 0; count < qtdPessoas; count++) {
        free(nomes[count]);
    }
    free(nomes);
    free(idades);

    return 0;
}