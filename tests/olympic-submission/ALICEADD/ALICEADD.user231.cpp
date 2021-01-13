#include <iostream>

int T ;
unsigned long int a,b ;
int main() {
    std::cin >> T ;
    unsigned long int arr[T];
    for ( int i =  0  ; i < T ; i++ ){
        std::cin >> a >>  b ;
        arr[i] = a+b ;
    }
    for ( int i =0 ; i< T ; i++)
        std::cout<<arr[i]<< std::endl;
    return 0;
}