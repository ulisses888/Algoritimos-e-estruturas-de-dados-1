bool isPalindrome(int x) {
    
    int resto;
    long long invertido = 0;

    for( int numero = x; numero > 0 ;numero = numero / 10 ){
        resto = numero % 10;
        invertido = invertido*10+resto;
    }

    return invertido == x;    
}
