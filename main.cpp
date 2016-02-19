#include <iostream>


using namespace std;

//PROTOTIPOS DE FUNCIONES
void suma(int (*arraya)[100], int m, int n, int (*arrayb)[100], int o, int p);
void multplicacion(int (*arraya)[100], int m, int n, int (*arrayb)[100], int o, int p);

void imprimirformas(int (*arraya)[100], int, int);
void transpuesta(int (*arraya)[100], int, int);

int main()
{
    cout << "Menu de Opciones" << endl;
    cout << "1 Suma de Matrices" << endl;
    cout << "2 Imprimir Matriz diagonal, triangular superior, triangular inferior" << endl;
    cout << "3 Imprimir Matriz transpuesta" << endl;
    cout << "4 Multiplicar Matriz" << endl;

    int opcion, m, n, o, p;

    cout << "Seleccione una operacion de las opciones" << endl;
    cin >>opcion;

    cout << "Introduce el tamaño de la matriz a separado por un espacio" << endl;
    cin>>m>>n;

    int array1[100][100];
    int array2[100][100];

    cout << "\n Introduce los valores de la matriz a" << endl;
    for( int i=1;i<=m;i++){
         for(int j=1;j<=n;j++){
                cout<<"ARREGLO A["<<i<<"]["<<j<<"]:";
                cin>>array1[i][j];
          }
      }

    if( opcion == 1 | opcion == 4){
        cout << "Introduce el tamaño de la matriz b separado por un espacio" << endl;
        cin>>o>>p;


        cout << "\n Introduce los valores de la matriz b" << endl;
        for( int i=1;i<=o;i++){
             for(int j=1;j<=p;j++){
                    cout<<"ARREGLO B["<<i<<"]["<<j<<"]:";
                    cin>>array2[i][j];
              }
        }
    }

    if(opcion == 1){
        suma(array1, m, n, array2, o, p);
    }

    if(opcion == 2){
        imprimirformas(array1, m, n);
    }

    if(opcion == 3){
        transpuesta(array1, m, n);
    }

    if(opcion == 4){
        multplicacion(array1, m, n, array2, o, p);
    }

    int salida;
    cout<<"Si desea continuar 1 si desea finalizar 0"<<endl;
    cin>>salida;
    if(salida == 1){
        main();
    }else
    return 0;
}

void imprimirformas(int (*arraya)[100], int m, int n){
    cout<<"Diagonal"<<endl;
           for (int i=1;i<=m;i++){
               for (int j=1;j<=n;j++){
                    if(i == j)
                        cout<<arraya[i][j]<<" ";
                    else
                        cout << "  ";
                }
                cout <<endl;
            }
    cout<<"Triangular superior"<<endl;
           for (int i=1;i<=m;i++){
               for (int j=1;j<=n;j++){
                    if(i <= j)
                        cout<<arraya[i][j]<<" ";
                    else
                        cout << "  ";
                }
                cout <<endl;
            }

        cout<<"Triangular inferior"<<endl;
           for (int i=1;i<=m;i++){
               for (int j=1;j<=n;j++){
                    if(i >= j)
                        cout<<arraya[i][j]<<" ";
                    else
                        cout << "  ";
                }
                cout <<endl;
            }
}

void transpuesta(int (*arraya)[100], int m, int n){
         int tmp[m][n];

         for( int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                tmp[j][i]= arraya[i][j];
                }
        }

    cout<<"La matriz transpuesta es:" <<endl;
           for (int i=1;i<=m;i++){
               for (int j=1;j<=n;j++){
                    cout<<tmp[i][j]<<" ";
                }
                cout<<endl;
            }
}

void suma(int (*arraya)[100], int m, int n, int (*arrayb)[100], int o, int p){
    if( m == o && n == p){
         int tmp[m][n];

         cout<<"El resultado de la matriz es: " <<endl;
         for( int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                tmp[i][j]= arraya[i][j] + arrayb[i][j];
                cout << tmp[i][j] <<" ";
            }
            cout << endl;
        }
    }else{
        cout<<"Las Matrices no se pueden sumar ya que no tienen el mismo orden"<<endl;
    }
}

void multplicacion(int (*arraya)[100], int m, int n, int (*arrayb)[100], int o, int p){
    if( n == o ){
         int tmp[100][100];


 for (int i=1;i<=m;i++){
        for (int j=1;j<=p;j++){
            tmp[i][j]=0;
             for (int k=1;k<=n;k++){
                tmp[i][j]=tmp[i][j] + arraya[i][k] * arrayb[k][j];
          }
       }
    }

         cout<<"El resultado de la matriz es: " <<endl;
           for (int i=1;i<=m;i++){
               for (int j=1;j<=p;j++){
                    cout<<tmp[i][j];
                }
                cout <<endl;
            }

    }else{
        cout<<"Las Matrices no se pueden multplicar"<<endl;
        cout<<"debido a que el numero de columnas de la"<<endl;
        cout<<"matriz A es diferente al numero de filas"<<endl;
        cout<<"de la matriz B, !Vuelva a intentarlo!  "<<endl;
    }
}
