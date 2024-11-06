# Algoritmos de Ordenação
Um breve estudo em C++ sobre os algoritmos de ordenação BubbleSort, InsertSort, SelectionSort, ShellSort, MergeSort, QuickSort, HeapSort e RadixSort.

## Explicação do estudo

### Objetivo do código 
<small> O usuário deve escolher uma opção para cada uma das perguntas feitas pelo programa. Em seguida, o código ordenará ou verificará a ordenação dos dados conforme a escolha do usuário e imprimirá o tempo, em segundos, que a operação levou para ser concluída.

- `main`: a main propõe-se em armazenar o menu que guia o usuário até o tipo de arquivo, quantidade de dados e algoritmo utilizado e também chama as funções para criação de arquivos (na biblioteca "arquivos.h") e ordenação de dados (na biblioteca "executar_ordenacao.h").
- `arquivos txt`: as arquivos txt utilizados para comparar o desempenho dos algoritmos de ordenação foram os mesmos para manter consistência no estudo. Foram, ao todo, gerados 12 arquivos. Estes deram-se em três tipos: Ordenado, Aleatório e Invertido; e também, com quatro quantidades de dados: 500 mil, 750 mil, 1 milhão e 5 milhões.
- `algoritmos`: cada algoritmo está somente dividido em biblioteca, para a declaração de suas funções, e em arquivo cpp, que aplica a lógica do algoritmo em si a fim de manter a organização e modularização do estudo.

---

*2024 - Amabilly B. Russo*
