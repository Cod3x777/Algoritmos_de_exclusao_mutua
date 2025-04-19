# Algoritmos de exclusão mútua

Este repositório contém implementações simples de algoritmos de exclusão mútua,
utilizados para resolver problemas de concorrência entre processos e threads. Aqui,
apresentarei soluções clássicas, que, embora não seja recomendado seus usos em projetos reais,
é importante conhece-los para entender sobre concorrência

## Algoritmos implementados

- **Variáveis tipo trava**
  Utiliza uma variável para indicar se a região crítica está ocupada;

- **Alternância explícita**
  Os processos ou threads se alternam para entrar na região crítica, usando uma variável 'turn' para indicar de quem é a vez

- **Algoritmo de Peterson**
  Uma das soluções mais clássicas que garantem exclusão mútua, progresso e espera ocupada entre dois processos ou threads

## Como testar

1. Clone o repositório:

 ``bash

 git clone https://github.com.Cod3x777/Algoritmos_de_exclusao_mutua.git
 
 cd Algoritmos_de_exclusao_mutua

2. Compile o algoritmo desejado:

  gcc peterson_algoritm.c -o peterson_algoritm
  
  ./peterson_algoritm

3. Saída esperada:

  Thread A entrou
  
  Thread A saiu
  
  Thread B entrou
  
  Thread B saiu

## Estrutura

  /Algoritmo_de_Peterson -> Implementação do algoritmo de Peterson
  
  /Variaveis_trava       -> Algoritmo tipo trava
  
  /Alternancia_explicita -> Alternância explícita com variável de turno

## Objetivo

  Este projeto tem fins didáticos e visa facilitar o entendimento de como diferentes algoritmos resolvem o problema da exclusão mútua em sistemas concorrentes.
  Vale ressaltar que não recomendo o uso desses algoritmos em projetos reais devido a suas limitações técnicas para os dias de hoje
