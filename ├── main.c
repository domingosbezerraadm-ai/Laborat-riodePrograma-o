#include <stdio.h>

int main() {
    //Declaração de variáveis
    char placa[6];
    int tipo;
    float horas, valorHora = 0, valorBase, desconto = 0, multa = 0, valorFinal=0;

    printf("Digite a placa(5 caracteres): ");
    scanf("%5s", placa);
    //Criação do menu de opções
    printf("Tipo de veiculo (1-Carro, 2-Moto, 3-Caminhonete): ");
    scanf("%d", &tipo);

    printf("Tempo de permanencia (horas): ");
    scanf("%f", &horas);

    // Definição do valor por hora
    switch(tipo) {
        case 1:
            valorHora = 5;
            break;
        case 2:
            valorHora = 3;
            break;
        case 3:
            valorHora = 8;
            break;
        default:
            printf("Tipo invalido.\n");
            return 0;
    }

    // Regra de mínimo
    if (horas < 1) {
        horas = 1;
    }

    valorBase = horas * valorHora;

    // Desconto
    if (horas > 5) {
        desconto = valorBase * 0.10;
    }

    // Calculo da multa
    if (horas > 10) {
        multa = 20;
    }

    valorFinal = valorBase - desconto + multa;

    printf("\n--- RESULTADO ---\n");
    printf("Placa: %s\n", placa);

    switch(tipo) {
        case 1: printf("Tipo: Carro\n"); 
        break;
        case 2: printf("Tipo: Moto\n"); 
        break;
        case 3: printf("Tipo: Caminhonete\n"); 
        break;
    }
    //Mostrando os resultados na tela
    printf("Horas: %.2f\n", horas);
    printf("Valor Base: R$ %.2f\n", valorBase);
    printf("Desconto: R$ %.2f\n", desconto);
    printf("Multa: R$ %.2f\n", multa);
    printf("Valor Final: R$ %.2f\n", valorFinal);

    return 0;
} 
