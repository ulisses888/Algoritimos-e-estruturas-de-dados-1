#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int* assentos;
    int tamanho;
    int liberados;
    int reservados;
} SeatManager;

SeatManager* seatManagerCreate(int n) {
    SeatManager* lista = malloc(sizeof(SeatManager));
     if (lista == NULL) {
         printf("Erro alocar memoria");
         exit(1);
     }
    lista->assentos = malloc(n * sizeof(int));
    if (lista->assentos == NULL) {
        printf("Erro alocar memoria");
        free(lista);
        exit(1);
    }
    lista->tamanho = n;
    lista->liberados = 0;
    lista->reservados = 0;
    for (int i = 0; i < n; i++) {
        lista->assentos[i] = 0;
    }
    return lista;

}


int seatManagerReserve(SeatManager* obj) {
    if (obj->liberados > 0) {
        for (int i = 0; i < obj->tamanho; i++) {
            if (obj->assentos[i] == 0) {
                obj->assentos[i] = 1;
                obj->liberados = obj->liberados - 1;
                return i + 1;
            }
        }
    }
    else {
        for (int i = (0 + obj->reservados); i < obj->tamanho; i++) {
            if (obj->assentos[i] == 0) {
                obj->assentos[i] = 1;
                obj->reservados = obj->reservados + 1;
                return i + 1;
            }
        }
    }
    return 0;
}

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {
    obj->assentos[seatNumber - 1] = 0;
    obj->liberados++;
    return;
}

void seatManagerFree(SeatManager* obj) {
    free(obj->assentos);
    free(obj);
    return;
}

int main() {
    
    SeatManager* lista = seatManagerCreate(5);
    printf("%d ", seatManagerReserve(lista));
    printf("%d ", seatManagerReserve(lista));
    seatManagerUnreserve(lista, 2);
    printf("%d ", seatManagerReserve(lista));
    printf("%d ", seatManagerReserve(lista));
    printf("%d ", seatManagerReserve(lista));
    printf("%d ", seatManagerReserve(lista));
    seatManagerUnreserve(lista, 2);
    seatManagerFree(lista);


    return 0;
}
