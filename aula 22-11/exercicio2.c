int singleNumber(int* nums, int numsSize) {
    int numeroUnico = nums[0];
    

    for (int i = 0; i<numsSize ;i++){
        if(numeroUnico + numeroUnico != numeroUnico + nums[i]){
            numeroUnico = nums[i];
        }


        }
        return numeroUnico;
    }



  //Exercicio SingleNumber Leetcode
  //Corrigir em casa pois não está funcionando

