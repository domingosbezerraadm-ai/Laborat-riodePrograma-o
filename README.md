# Laboratorio de Programacao
Atividade Avaliativa 01

# Sistema de Estacionamento Rotativo
## Aluno: Domingos Bezerra Silva Filho
## Matricula: 2023046514

 **- Parte 1 – Modelagem**
   **- Objetivo:**
     Este projeto tem como objetivo desenvolver um sistema de gerenciamento de estacionamento rotativo, similares aos utilizados em shoppings e lojas em centros comerciais.
     O sistema calcula o valor a ser pago com base no tipo de veículo e no tempo de permanência, aplicando regras como valor mínimo, descontos e multas.
     
 **1 Análise do Problema:**
     No Estacionamento rotativo, o tempo de permanência determina o valor a ser pago pelo cliente, assim como o tipo de veículo. Sendo o sistema precisa receber as seguintes informações:
     * Tipo do veículo;
     * Tempo de permanência;
     * Identificação do tipo do veiculo;
     * Calculo do valor base;
     * Verificar se há desconto;
     * Verificar se há multa;
     * Exibir o valor final ao usuário

**2.Definição das Variáveis:**
     * Placa	char[]: 	Armazena a placa do veículo;
     * tipo	int: 	Identifica o tipo do veículo;
     *  horas	float: 	Tempo de permanência;
     * valorHora	float: 	Valor cobrado por hora;
     * valorBase	float: Valor inicial calculado;
     * desconto	float	: Valor do desconto aplicado;
     * multa	float:	Valor da multa aplicada;
     * valorFinal	float:	Valor total a ser pago;
     
**3.Regras de Negócio:**
   - Tipos de Veículos
      1 - Carro: R$ 5,00 por hora
      2 - Moto: R$ 3,00 por hora
      3 - Caminhonete: R$ 8,00 por hora
   -Regras Gerais:
    - Até 1 hora → cobrança mínima de 1 hora
    - Acima de 5 horas → desconto de 10%
    - Acima de 10 horas → acréscimo de multa de R$ 20,00
        
**4. Fluxogramadoprocessamento:**
     ## 🔀 Fluxograma do Sistema

```mermaid
flowchart TD

A[Início] --> B[Ler placa]
B --> C[Ler tipo do veículo]
C --> D[Ler horas]

D --> E{Tipo de veículo?}

E -->|1 - Carro| F[valorHora = 5]
E -->|2 - Moto| G[valorHora = 3]
E -->|3 - Caminhonete| H[valorHora = 8]

F --> I
G --> I
H --> I

I{Horas < 1?}
I -->|Sim| J[horas = 1]
I -->|Não| K[Manter horas]

J --> L
K --> L

L[valorBase = horas * valorHora]

L --> M{Horas > 5?}
M -->|Sim| N[desconto = 10%]
M -->|Não| O[sem desconto]

N --> P
O --> P

P{Horas > 10?}
P -->|Sim| Q[multa = 20]
P -->|Não| R[sem multa]

Q --> S
R --> S

S[valorFinal = valorBase - desconto + multa]

S --> T[Exibir resultados]

T --> U[Fim]

 **- Parte 2 – Implementação em C**
 - Lógica do Programa:
   1 - Ler a placa do veículo;
   2 - Ler o tipo do veículo;
   3 - Ler o tempo de permanência;
   4 - Definir o valor da hora (usando switch-case);
   5 - Garantir tempo mínimo de 1 hora (if);
   6 - Calcular o valor base;
   7 - Verificar e aplicar desconto (if);
   8 - Verificar e aplicar multa (if)
   9 - Calcular o valor final;
   10 - Exibir os resultados;

├── main.c
#include <stdio.h>

int main() {
    char placa[10];
    int tipo;
    float horas;
    float valorHora = 0;
    float valorBase, desconto = 0, multa = 0, valorFinal;

    printf("Digite a placa: ");
    scanf("%s", placa);

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

    // Multa
    if (horas > 10) {
        multa = 20;
    }

    valorFinal = valorBase - desconto + multa;

    printf("\n--- RESULTADO ---\n");
    printf("Placa: %s\n", placa);

    switch(tipo) {
        case 1: printf("Tipo: Carro\n"); break;
        case 2: printf("Tipo: Moto\n"); break;
        case 3: printf("Tipo: Caminhonete\n"); break;
    }

    printf("Horas: %.2f\n", horas);
    printf("Valor Base: R$ %.2f\n", valorBase);
    printf("Desconto: R$ %.2f\n", desconto);
    printf("Multa: R$ %.2f\n", multa);
    printf("Valor Final: R$ %.2f\n", valorFinal);

    return 0;
}


