
/******************************************************************************
  FUNCIONES RECURSIVAS BÁSICAS en C/C++. Por: byDavid360
******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int producto(int a, int b);                                 //Funcion que hace el producto de dos numeros a partir de sumas sucesivas
int sumar_vector(int *v, int dim);                          //Funcion que suma los elementos de un vector de forma recursiva
void imprimir_vector(int *v, int dim);                      //Funcion que imprime un vector de forma recursiva
int sumar_n_primeros(int n);                                //Funcion que suma los n primeros numeros de forma recursiva
int binario(int n);                                         //Funcion que pasa un numero decimal a binario de forma recursiva
int invertir(int n);                                        //Funcion que invierte un numero (sus cifras)
int potencia(int n, int pot);                               //Funcion que calcula n^potencia a partir de multiplicaciones de forma recursiva
int division(int n, int divisor);                           //Funcion que divide dos numeros a partir de restas sucesivas de forma recursiva
int buscar(int *v, int dim, int elemen);                    //Funcion que busca un elemento dentro de un vector de forma recursiva
int cuentadigitos(int n);                                   //Funcion que cuenta las cifras de un numero de forma recursiva
int busquedabinaria(int *v, int ini, int fin, int elemen);  //Algoritmo de busqueda binaria en un vector a partir de "divide y vencerás" (el vector debe estar ordenado)
int suma_binaria(int *v, int ini, int fin);                 //Algoritmo que suma los elementos de un vector usando busqueda binaria
int suma_quitando_primero(int *v, int ini, int fin);        //Funcion que divide un vector ordenado y suma los valores de cada trozo exceptuando el primero de ellos en cada llamada recursiva
int suma_digitos(int n);                                    //Funcion que suma los digitos de un numero de forma recursiva

int main(){

    int n1, n2;
    int n_prim;
    int v[4] = {5,6,7,8};
    int dim = 4;

    cout<<"Introduce un numero: ";
    cin>> n1;
    cout<<"Introduce otro numero: ";
    cin>> n2;
    cout<< "El producto de "<< n1<< " * "<<n2<<" = "<<producto(n1,n2);
    cout<<endl<<endl;

    cout<<"La suma del vector {";
    imprimir_vector(v,dim);
    cout<<" } es: "<<sumar_vector(v,dim)<<endl<<endl;

    cout<<"Ingrese un limite n para sumar los n primeros numeros: ";
    cin>>n_prim;
    cout<<"La suma de los "<<n_prim<< " primeros numeros es "<< sumar_n_primeros(n_prim)<<endl<<endl;

    cout<<"Ingrese un numero que quiera convertir a binario : ";
    cin>>n1;
    cout<<"El numero  "<<n1<< " en binario es ";
    cout<<binario(n1)<<endl<<endl;

    cout<<"Ingrese un numero que quiera invertir : ";
    cin>>n1;
    cout<<"El numero  "<<n1<< " invertido es ";
    cout<<invertir(n1)<<endl<<endl;

    cout<<"Ingrese un numero: ";
    cin>>n1;
    cout<<"Ingrese el numero al que lo quiera elevar: ";
    cin>>n2;
    cout<<"El numero  "<<n1<< " ^ " <<n2<<" = ";
    cout<<potencia(n1,n2)<<endl<<endl;

    cout<<"Ingrese un dividendo: ";
    cin>>n1;
    cout<<"Ingrese un divisor: ";
    cin>>n2;
    cout<<"El numero  "<<n1<< " / " <<n2<<" = ";
    cout<<division(n1,n2)<<endl<<endl;

    cout<<"Ingrese un valor contenido que este contenido en el vector {";
    imprimir_vector(v,dim);
    cout<<"} para conocer su posicion: ";
    cin>>n1;
    cout<<"El valor "<<n1<<" se encuentra en la posicion "<<buscar(v,dim,n1)<<endl<<endl;

    cout<<"Ingrese un numero para contar sus digitos: ";
    cin>>n1;
    cout<<"El numero  "<<n1<< " tiene " <<cuentadigitos(n1)<<" digitos "<<endl<<endl;

    int vect[5] = {0,1,2,3,5};
    cout<<"Ingrese un valor contenido en el vector {";
    imprimir_vector(vect,5);
    cout<<"} para conocer su posicion";
    int valor;
    cin>>valor;
    cout<<"El valor"<<valor<< " esta en la posicion " <<busquedabinaria(vect,0,4,valor)<<endl<<endl;

    cout<<"La suma de las componentes del vector {";
    imprimir_vector(vect,5);
    cout<<"} es igual a "<<suma_binaria(vect,0,4)<<endl<<endl;


    cout<<"La suma de las componentes del vector {";
    imprimir_vector(vect,5);
    cout<<"} quitando la primera en cada llamada recursiva es igual a "<<suma_quitando_primero(vect,0,4)<<endl<<endl;

    cout<<"Ingrese un valor para sumar sus digitos: ";
    cin>>n1;
    cout<<"La suma de los digitos de "<<n1<<" es igual a "<<suma_digitos(n1);

    system("PAUSE");
    return 0;
}


int producto(int a, int b){

    //caso base o trivial
    if(a == 0 || b == 0)
        return 0;

    //caso general
    int suma = 0;
    return a + producto(a, b-1);
}


int sumar_vector(int *v, int dim){

    //caso base o trivial
    if(dim == 0)
        return 0;

    //caso general
    return v[dim-1] + sumar_vector(v,dim-1);
}


void imprimir_vector(int *v, int dim){

    //caso base o trivial
    if(dim == 0)
        return;

    //caso general
    imprimir_vector(v,dim-1);
    cout<<" "<<v[dim-1];
}


int sumar_n_primeros(int n){

    //caso base o trivial
    if(n == 0)
        return 0;

    //caso general
    int suma = 0;
    return suma+n+sumar_n_primeros(n-1);
}


int binario(int n){

    //caso base o trivial
    if (n < 2)
        return n;

    //caso base
    int resto = n%2;
    int cociente = n/2;
    return resto + 10*binario(cociente);
}


int invertir(int n){

    //caso base o trivial
    if(n <10)
        return n;

    //caso general
    int resto = n%10;
    int cociente = n/10;
    cout<<resto;
    return invertir(cociente);
}


int potencia(int n, int pot){

    //caso base o trivial
    if (pot == 0)
        return 1;

    //caso general
    return n*potencia(n,pot-1);
}


int division(int n, int divisor){

    //caso base o trivial
    if(n == 0)
        return 0;

    //caso general
    return 1 + division(n-divisor, divisor);
}


int buscar(int *v, int dim, int elemen){

    //caso base o trivial
    if(dim == 0)
        return -1; //retorna -1 si no está el valor en el vector o si tiene dimension 0

    //caso general
    if(v[dim-1] == elemen)
        return dim-1;
    return buscar(v,dim-1,elemen);
}


int cuentadigitos(int n){

    //caso base o trivial
    if (n <10)
        return 1;

    //caso general
    return 1 + cuentadigitos(n/10);
}


int busquedabinaria(int *v, int ini, int fin, int elemen){

    //caso base o trivial
    if(ini>fin)
        return -1;

    //caso general
    int medio = (ini+fin)/2;

    if(elemen == medio)
        return medio;
    else if(elemen<v[medio])
        return busquedabinaria(v,ini,medio-1,elemen);
    else
        return busquedabinaria(v,medio+1,fin,elemen);
}


int suma_binaria(int *v, int ini, int fin){

    //caso base o trivial
    if(ini>fin)
        return 0;

    //caso general
    int medio = (ini+fin)/2;
    int suma1 = v[medio];
    int suma2 = suma_binaria(v,medio+1,fin);
    int suma3 = suma_binaria(v,ini,medio-1);
    int sumatotal = suma1+ suma2 + suma3;
    return sumatotal;
}


int suma_quitando_primero(int *v, int ini, int fin){

    //caso base o trivial
    if(ini>fin)
        return 0;

    //caso general
    int medio = (ini+fin)/2;
    int suma1 = v[medio];
    int suma2 = suma_quitando_primero(v,medio+1+1,fin);
    int suma3 = suma_quitando_primero(v,ini+1,medio-1);
    int sumatotal = suma1 + suma2 + suma3;
    return sumatotal;
}


int suma_digitos(int n){

    //caso base
    if(n < 10)
        return n;

    //caso general
    int resto = n%10;
    int suma = resto;
    return suma + suma_digitos(n/10);;
}
