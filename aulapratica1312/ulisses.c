#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//EXERCICIO CAN PLACE FLOWERS LEETCODE

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);

int main()
{
int flowerbed[7] = {1,0,0,0,1,0,0};
int size = 7;
int numero = 2;

if(canPlaceFlowers(flowerbed, size, numero) == false){
    printf("\nFalso\n");
} else {
    printf("\nVerdadeiro\n");
}



return 0;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int contadorFlores = 0;
    
    for(int i = 0; i < flowerbedSize ; i++){
        if(i!=0 && i+1 < flowerbedSize && flowerbed[i] == 0){
            if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                contadorFlores++;
                flowerbed[i] = 1;
            }            
        } else if(i == 0 && (i+1) < flowerbedSize && flowerbed[i] == 0){
            if(flowerbed[i+1] == 0){
                contadorFlores++;
                flowerbed[i] = 1;
            }
        } else if((i+1) == flowerbedSize && flowerbed[i] == 0){
            if(flowerbedSize == 1){
                contadorFlores++;
            } else if(flowerbed[i-1] == 0)
            {
                contadorFlores++;
                flowerbed[i] = 1;
            }
        }
        
        }

    
   return n <= contadorFlores; 
}
