    int romanToInt(char* s) {
        // I = 1, V = 5, X = 10, L = 50, C = 100, D = 500 , M = 1000
        char romanos[] = {'I','V','X','L','C','D','M'};
        int valor[] = {1,5,10,50,100,500,1000};
        int soma = 0;
        int temp = 0;

        for(int i = strlen(s);i >= 0; i--){
            for(int j = 0; j<7 ; j++){
                if( romanos[j] == s[i] && valor[j] >= temp){
                    soma+=valor[j];
                    temp = valor[j];
                } else if (romanos[j] == s[i] && valor[j] <= temp){
                    soma-=valor[j];
                    temp = valor[j];
                }
            }
        }
        return soma;
    }
