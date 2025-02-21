
typedef struct {
    int *assentos;
    int tamanho;
    int liberados;
    int reservados;
} SeatManager;



SeatManager* seatManagerCreate(int n) {
    SeatManager *lista = malloc(sizeof(SeatManager));
    lista->assentos = malloc(n * sizeof(int));
    lista->tamanho = n;
    lista->liberados = 0;
    lista->reservados = 0;
    for (int i = 0; i < n; i++) {
        lista->assentos[i] = 0;
    }
    return lista;

}
    

int seatManagerReserve(SeatManager* obj) {
    if(obj->liberados > 0){
        for(int i =0; i < obj->tamanho; i++){
            if(obj->assentos[i] == 0){
                obj->assentos[i] = 1;
                obj->liberados = obj->liberados-1;
                return i + 1;
            }
        }
    } else {
        for(int i = (0 + obj->reservados); i < obj->tamanho; i++){
            if(obj->assentos[i] == 0){
                obj->assentos[i] = 1;
                obj->reservados = obj->reservados + 1;
                return i + 1;
            }
        }
    }
    return 0;
}

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {
    obj->assentos[seatNumber-1] = 0;
    obj->liberados++;
    return;
}

void seatManagerFree(SeatManager* obj) {
    free(obj);
    return;
}

/**
 * Your SeatManager struct will be instantiated and called as such:
 * SeatManager* obj = seatManagerCreate(n);
 * int param_1 = seatManagerReserve(obj);
 
 * seatManagerUnreserve(obj, seatNumber);
 
 * seatManagerFree(obj);
*/
