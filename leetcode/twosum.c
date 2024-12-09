/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* resultado = malloc(sizeof(int) * 2);

    for(int i = 0;i<numsSize;i++){
        for (int j = i+1;j<numsSize;j++){
            if(nums[i] + nums[j] == target && i != j){
                resultado[0] = i;
                resultado[1] = j;
                *returnSize = 2;
                return resultado;

            }
        }
    }
    *returnSize = 0;
    return 0;



}
