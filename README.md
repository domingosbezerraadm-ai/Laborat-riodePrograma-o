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


