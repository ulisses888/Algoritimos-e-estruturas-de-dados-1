typedef struct {
    int dificuldade;
    int lucro;
} emprego;

int compare(const void *a, const void *b) {
  
    emprego *empregoA = (emprego *)a;
    emprego *empregoB = (emprego *)b;
  
    return (empregoA->lucro - empregoB->lucro);
}

int compare2(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {

emprego empregos[difficultySize];

for(int i = 0; i < difficultySize; i++){
    empregos[i].lucro = profit[i];
    empregos[i].dificuldade = difficulty[i];
}

qsort(empregos, difficultySize, sizeof(emprego), compare);
qsort(worker,workerSize,sizeof(int),compare2);
for(int i = 0; i < workerSize; i++){
printf("trabalhadores: %d\n",worker[i]);
}

int lucroMaximo = 0;
int j = difficultySize - 1;
   /* for(int i = 0; i < workerSize; i++){
        int lucroTrabalhador = 0;
        for(int j = difficultySize - 1; j >= 0; j--) {
            if(worker[i] >= empregos[j].dificuldade) {
                lucroTrabalhador = empregos[j].lucro;
                break;
            }
        }
        lucroMaximo += lucroTrabalhador;
    }*/

    for(int i = 0; i < workerSize; i++){
       
     while(worker[i] < empregos[j].dificuldade && j != 0) {
        j--;
    }
    if(j == 0 && empregos[j].dificuldade > worker[i]){
        break;
    } else {
        lucroMaximo += empregos[j].lucro;
    }
    }

    return lucroMaximo;
}
