/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *resultado = malloc(sizeof(int) *2);
    
    
    for(int contador1 = 0; contador1<numsSize; contador1++){
        for(int contador2 = 1; contador2<numsSize; contador2++){
            if( nums[contador1] + nums[contador2] == target && contador1 != contador2){
                resultado[0] = contador1;
                resultado[1] = contador2;
                *returnSize = 2;
                return resultado;
            }
            
        }
        
    }

        return 0;

    }
 
// TWO SUN LEETCODE
// UMA DAS PIORES SOLUÇÕES JÁ FEITAS
