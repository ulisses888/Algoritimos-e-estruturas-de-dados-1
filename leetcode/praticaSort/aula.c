typedef struct {
    int dificuldade;
    int lucro;
} emprego;

int compare(const void *a, const void *b) {
  
    emprego *empregoA = (emprego *)a;
    emprego *empregoB = (emprego *)b;
  
    return (empregoA->lucro - empregoB->lucro);
}

//CODIGO LENTO DE MAIS
/*int lucroMaximo = 0;


    for(int i = 0; i < workerSize; i++){
        int lucroTrabalhador = 0;
        for(int j = 0; j < difficultySize; j++){
            if(difficulty[j] <= worker[i] && profit[j] > lucroTrabalhador){
                lucroTrabalhador = profit[j];
            }
        }
        lucroMaximo += lucroTrabalhador;
    }
    return lucroMaximo;
}*/

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {

emprego empregos[difficultySize];

for(int i = 0; i < difficultySize; i++){
    empregos[i].lucro = profit[i];
    empregos[i].dificuldade = difficulty[i];
    printf(" lucro: %d dificuldade: %d\n",empregos[i].lucro,empregos[i].dificuldade);
}


qsort(empregos, difficultySize, sizeof(emprego), compare);

printf("ORDENADO \n");
for(int i = 0; i < difficultySize; i++){
    printf(" lucro: %d dificuldade: %d\n",empregos[i].lucro,empregos[i].dificuldade);
}



int lucroMaximo = 0;
    for(int i = 0; i < workerSize; i++){
        int lucroTrabalhador = 0;
        for(int j = difficultySize - 1; j >= 0; j--) {
            if(worker[i] >= empregos[j].dificuldade) {
                lucroTrabalhador = empregos[j].lucro;
                break;
            }
        }
        lucroMaximo += lucroTrabalhador;
    }

    return lucroMaximo;
}
