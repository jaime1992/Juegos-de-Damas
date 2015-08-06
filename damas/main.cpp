/* JUEGO DE DAMAS (actualización #2.0.1)
 
 * Asignatura Ingeniería de Software
 * Integrantes:
 
 * Felipe Abarca Arias
 * Jaime Quiñelen Villar
 * Ignacio Ortega Bustamante
  
 * Profesor:
 
 * Sebastian Salazar 
 */
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>

//#define T 10

using namespace std;



//Se utilizarán las siguientes variables globales

char tablero[10][10];//define el tablero de damas con dimension 10x10
int i, j;// indices utilizados para recorrer los for que imprimen el tablero
int z; //  indice para mostrar coordenadas

/* Felipe, cambie el nombre de las variables x , y por i , j , ya que en la funcion moverFicha()
  utilizé variables x , y para poder moverme y hacer referencia al plano cartesiano
  y sea mas facil entender el algoritmo, fue el unico cambio que realize. 
 */
int entrar;
string blanco="░";//string para representar los casilleros blancos
string negro="█";//string para representar los casilleros negro
int turno =1;
int error ; 
int fichaProfe=15;//cantidad de piezas
int fichao=15;// Cantidad de piezas
int terminar=1;
int contador_x= 0; // contador fichas jugador humano
int contador_o= 0; // Contador fichas jugador maquina
int contador_s= 0 ;// Contador de sopladitas
int x; //Para simular coordenadas del plano cartesiano X
int y; //Para simular coordenadas del plano cartesiano y
char aux;
int muevete;
int a; // se utilizara para registrar el ultimo movimiento del jugador humano, y asi evitar una sopladita incorrecta
int b;// lo mismo que int a
int m;
int n;
int r;
int s;
int horror;
int p;
int q;
int ultimo1;
int ultimo2;
int noComio=0; //PARA SABER SI LA DAMA PUDO COMER ALGO, SI NO COME, SE ACTIVAN LOS PEONES



void rellenarTablero() //coloca las fichas en el tablero
{
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if( ( i<3)  && ((i+j)%2==0) )
            {
                tablero[i][j] = 'O' ; //Coloco fichas circulares---> O
            } 
            else 
            if ( ( i>=7 ) &&((i+j)%2==0))
            {
                tablero[i][j] = 'X' ; // Coloco fichas en forma de ---> X
            }
            else 
            {
                tablero[i][j] = ' ' ;
            }
        }
    }
}
void mostrarTablero()
{
    cout<<"\n ";
    
    for(z=0;z<10;z++)
    {
        cout << char (65 + z) <<"    ";
    } // utilizaré letras.
        cout<<endl;
        for(i=0;i<10;i++)
        {
          //cout<<"\t       ";
          cout<<i;
          for(j=0;j<10;j++)
          {
            if((tablero[i][j]=='X'||tablero[i][j]=='O'||tablero[i][j]=='C'||tablero[i][j]=='D')&&((j+i)%2==0))
            {
                cout<<blanco<<blanco<<tablero[i][j]<<blanco<<blanco; 
            }
            else 
                if (tablero[i][j]==' ' && (j+i)%2!=0)
            {
                cout<<negro<<negro<<negro<<negro<<negro;
            }
            else 
                if (tablero[i][j]==' ' &&(j+i)%2==0)
            {
                cout<<blanco<<blanco<<blanco<<blanco<<blanco; ;
            }
        }      cout<<endl;  
    }
}

int cambiarValor(int entrar)
{
    int salir;
    salir=entrar;
    int ct=65;
    for(int i=0;i<=9;i++) //recorre la vertical de 0 a 9 y las cambia a letras
    {
                            
      if(salir==i)
      {
        salir=ct;
      }
      ct++;
    }
 ct=0;
 return salir;
}


void comerMultiple() // funcion para que el jugador humano pueda comer mas de una ficha a la vez
// Se deben cumplir ciertas condiciones para que eso ocurra, espacios necesarios, quedar dentro del tablero, etc.

{
    
    
    int salir;
    char letra;
    int auxiliar;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            {
                
                    if(tablero[i][j]=='X'&& tablero[i-2][j-2]==' ' && (tablero[i-1][j-1]=='O'||tablero[i-1][j-1]=='C') && j!= 1 && j!=0 )
                    {
                        
                        
                        
                       if(r==i && s==j)
                       {
                           auxiliar=j;
                           auxiliar--;
                           letra=char(cambiarValor(auxiliar));
                           cout<<"\n";
                           cout<<"HAS COMIDO FICHA O EN--> "<<letra<<"-"<<i-1;
                           cout<<"\n";
                           tablero[i][j]=' ';
                           tablero[i-1][j-1]= ' ';
                           tablero[i-2][j-2]='X' ;
                           fichao=fichao-1;
                           turno=0;
                           r=i-2;
                           s=j-2;
                           contador_x++;
                       }    
                      
                    }
                else 
                    if (tablero[i][j]=='X' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='O'||tablero[i-1][j+1]=='C') && (j!= 8 || j!=9 ) )
                       {
                        
                       
                        //cout<<"habian dos opciones de comer";
                        if(r==i && s==j)
                        {
                       
                          auxiliar=j;
                          j++;
                          letra=char(cambiarValor(auxiliar));
                          cout<<"\n";
                          cout<<"HAS COMIDO FICHA O EN --->"<<letra<<"-"<<i-1;
                          cout<<"\n";
                          tablero[i][j]=' ';
                          tablero[i-1][j+1]=' ';
                          tablero[i-2][j+2]='X';
                          fichao=fichao-1;
                          turno=0;
                          r=i-2;
                          s=j+2;
                          contador_x++;
                        }
                    }
                        }
                    }

    
    
}

bool perteneceLaDiagonal4()
{
    int pertenece=0;
    int X;
    int Y;
    X=x;
    Y=y;
    for(i=0; i<=p ; i++ )
    {
      for(j=0; j<=q ; j++)
      {
        if(X==i && Y==j)
        {
         X++;
         Y++;
         if(X==p && Y==q)
         {
             
             j=10;
             i=10;
             pertenece=1;
             return true; 
             //si true ,  la casilla seleccionada si pertenece a la diagonal que se quiere mover
             
         }
                
                    
        }
       }    
    }
    if(pertenece==0) //si la nueva casilla no pertenece ala diagonal de la dama, return false
    {
        
        //horror=1;
        //cout<<"ERROR, no se puede mover a esa casilla !!";
        return false;
    }
}
            
bool hayFichaAmiga4()
{
    int X;
    int Y;
    X=x;
    Y=y;
    int pertenece=0;
    for(i=0; i<p ; i++ )
          {
            for(j=0; j<q ; j++)
            {
              if(X==i && Y==j)
              {
                       
                X++;
                Y++;
                
                if(tablero[X][Y]=='X' || tablero[X][Y]=='D')
                {
                    i=10;
                    j=10;
                    pertenece=1;
                    return true;
                           
                }
                
                    
               }
             }    
            }
    if(pertenece==0)
    {
        return false;
    }
}

bool sePuedeComer4()
{
    int X;
    int Y;
    int pertenece=0;
    X=x;
    Y=y;
    
    while(X!=p && Y!=q)
    {
       X++;
       Y++;
          
       if( (tablero[X][Y]=='O' || tablero[X][Y]=='C') && tablero[X+1][Y+1]==' ')
       {
         X=p;
         Y=q;
         pertenece=1;
         return true;
         
           
       }
       else
       if( (tablero[X][Y]=='O' || tablero[X][Y]=='C') && (tablero[X+1][Y+1]=='O'||tablero[X+1][Y+1]=='C'))
       {
               X=p;
               Y=q;
               return false;
       }
                       
    }
     
  
   
}

bool sePuedeMover4() //no se puede mover una sola casilla, solo eso me falta x arreglar.
{
    int X;
    int Y;
    int pertenece=0;
    X=x;
    Y=y;
    
    for(i=0; i<p ; i++ )
    {
      for(j=0; j<q ; j++)
      {
        
       if(X==i && Y==j)
       {
          X++;
          Y++;
         
          if( (tablero[X][Y]!=' '))
         {
            pertenece=1;
            i=10;
            j=10;
            return false;
           
         }
                       
       }
     }
   }
   if(pertenece==0)
   {
       return true;
   }
}

//Empieza el movimiento3

bool perteneceLaDiagonal3()
{
    int pertenece=0;
    int X;
    int Y;
    X=x;
    Y=y;
    for(i=0; i<=9 ; i++ )
    {
      for(j=0; j<=9 ; j++)
      {
        
        if(X==i && Y==j)
        {
         X++;
         Y--;
         
         if(X==p && Y==q)
         {
             
             j=10;
             i=10;
             pertenece=1;
             return true; 
             //si true ,  la casilla seleccionada si pertenece a la diagonal que se quiere mover
             
         }
                
                    
        }
       }    
    }
    if(pertenece==0) //si la nueva casilla no pertenece ala diagonal de la dama, return false
    {
        //horror=1;
        //cout<<"ERROR, no se puede mover a esa casilla !!";
        
        return false;
    }
}

bool hayFichaAmiga3()
{
    int X;
    int Y;
    X=x;
    Y=y;
    int pertenece=0;
    
    
    while(X!=p && Y!=q)
    {
                       
      X++;
      Y--;
      if(tablero[X][Y]=='X' || tablero[X][Y]=='D')
      {
        //horror=1;
         cout<<"\n";
        //cout<<" hay ficha amiga \n";
         pertenece=1;
         X=p;
         Y=q;
         return true;
       }
    } 
                
    if(pertenece==0)
    {
        return false;
    }
}

bool sePuedeComer3()
{
    int X;
    int Y;
    int pertenece=0;
    X=x;
    Y=y;
    
    while(X!=p && Y!=q)
    {
       X++;
       Y--;
          
       if( (tablero[X][Y]=='O' || tablero[X][Y]=='C') && tablero[X+1][Y-1]==' ')
       {
         X=p;
         Y=q;
         pertenece=1;
         return true;
           
       }
       else
       if( (tablero[X][Y]=='O' || tablero[X][Y]=='C') && (tablero[X+1][Y-1]=='O'||tablero[X+1][Y-1]=='C'))
       {
           X=p;
           Y=q;
           return false;
       }                
    }
     
   
   
}


bool sePuedeMover3()
{
    int X;
    int Y;
    int pertenece=0;
    X=x;
    Y=y;
    
   while(X!=p && Y!=q)
    {
                       
      X++;
      Y--;
      if(tablero[X][Y]!=' ')
      {
             
         pertenece=1;
         X=p;
         Y=q;
         return false;
       }
    }  
   
   if(pertenece==0)
   {
       return true;
   }
}

//de aqui para abajo

bool perteneceLaDiagonal2()
{
    int pertenece=0;
    int X;
    int Y;
    X=x;
    Y=y;
    for(i=9; i>=0 ; i-- )
    {
      for(j=9; j>=0 ; j--)
      {
        
        if(X==i && Y==j)
        {
         X--;
         Y++;
         //cout<<"lo xy son-> "<<X<<Y;
         
         if(X==p && Y==q)
         {
             
             j=-1;
             i=-1;
             pertenece=1;
             return true; 
             //si true ,  la casilla seleccionada si pertenece a la diagonal que se quiere mover
             
         }
                
                    
        }
       }    
    }
    if(pertenece==0) //si la nueva casilla no pertenece ala diagonal de la dama, return false
    {
        //horror=1;
        
        
        return false;
    }
}

bool hayFichaAmiga2()
{
    int X;
    int Y;
    X=x;
    Y=y;
    int pertenece=0;
    
    
    while(X!=p && Y!=q)
    {
                       
      X--;
      Y++;
      if(tablero[X][Y]=='X' || tablero[X][Y]=='D')
      {
        //horror=1;
         cout<<"\n";
         
         pertenece=1;
         X=p;
         Y=q;
         return true;
       }
    } 
                
    if(pertenece==0)
    {
        return false;
    }
}

bool sePuedeComer2()
{
    int X;
    int Y;
    int pertenece=0;
    X=x;
    Y=y;
    
    while(X!=p && Y!=q)
    {
       X--;
       Y++;
          
       if( (tablero[X][Y]=='O' || tablero[X][Y]=='C') && tablero[X-1][Y+1]==' ')
       {
         X=p;
         Y=q;
         pertenece=1;
         return true;
       }
       else
       if( (tablero[X][Y]=='O' || tablero[X][Y]=='C') && (tablero[X-1][Y+1]=='O'||tablero[X-1][Y+1]=='C'))
       {
           X=p;
           Y=q;
           return false;
           
       }
                       
    }
     
   
   
}

bool sePuedeMover2()
{
    int X;
    int Y;
    int pertenece=0;
    X=x;
    Y=y;
    
   while(X!=p && Y!=q)
    {
                       
      X--;
      Y++;
      if(tablero[X][Y]!=' ')
      {
             
         pertenece=1;
         X=p;
         Y=q;
         return false;
       }
    }  
   
   if(pertenece==0)
   {
       return true;
   }
}

//DE AQUI PARA ABAJO



bool perteneceLaDiagonal1()
{
    int pertenece=0;
    int X;
    int Y;
    X=x;
    Y=y;
    for(i=9; i>=0 ; i-- )
    {
      for(j=9; j>=0 ; j--)
      {
        
        if(X==i && Y==j)
        {
         X--;
         Y--;
         if(X==p && Y==q)
         {
             j=-1;
             i=-1;
             pertenece=1;
             return true; 
             //si true ,  la casilla seleccionada si pertenece a la diagonal que se quiere mover
         }
         
         }
       }    
    }
    if(pertenece==0) //si la nueva casilla no pertenece ala diagonal de la dama, return false
    {
        return false;
    }
}

bool hayFichaAmiga1()
{
    int X;
    int Y;
    X=x;
    Y=y;
    int pertenece=0;
    
    
    while(X!=p && Y!=q)
    {
                       
      X--;
      Y--;
      if(tablero[X][Y]=='X' || tablero[X][Y]=='D')
      {
        
         cout<<"\n";
         pertenece=1;
         X=p;
         Y=q;
         return true;
       }
    } 
                
    if(pertenece==0)
    {
        return false;
    }
}

bool sePuedeComer1()
{
    int X;
    int Y;
    int pertenece=0;
    X=x;
    Y=y;
    
    
    
      
    while(X!=p && Y!=q)
    {
       X--;
       Y--;
          
       if( (tablero[X][Y]=='O' || tablero[X][Y]=='C') && tablero[X-1][Y-1]==' ')
       {
         X=p;
         Y=q;
         pertenece=1;
         return true;
       }
       else
           if( (tablero[X][Y]=='O' || tablero[X][Y]=='C') && (tablero[X-1][Y-1]=='O'||tablero[X-1][Y-1]=='C'))
           {
               X=p;
               Y=q;
               return false;
           }
       
    }
     
   
}

bool sePuedeMover1()
{
    int X;
    int Y;
    int pertenece=0;
    X=x;
    Y=y;
    
   while(X!=p && Y!=q)
    {
                       
      X--;
      Y--;
      if(tablero[X][Y]!=' ')
      {
             
         pertenece=1;
         X=p;
         Y=q;
         return false;
       }
    }  
   
   if(pertenece==0)
   {
       return true;
   }
}

//De aqui para abajo son las validaciones de las jugadas de la MAQUINAS




bool sePuedeComer1Maquina(int X, int Y) //posiciones de la dama -C- (maquina)
{
    int AUX1=X; //GUARDAMOS LOS VALORES INICIALES PARA PODER DESPUES BORRAR LA FICHA
    int AUX2=Y;
    int cambiar=0;
    char letra;
    int aux2=0;
    ultimo1=0; //PARA SABER CUAL FUE LA ULTIMA POSICION ANTES DE RETORNAR FALSE !
    ultimo2=0;
      
       
    while((X-1)!=0  &&  (Y-1)!=0 )
    {
       X--;
       Y--;
       
       
       if( (tablero[X][Y]=='D' || tablero[X][Y]=='X') && tablero[X-1][Y-1]==' ')
       {
         
           fichaProfe--; //el profe perdio fichas
           tablero[X][Y]=' ';
           aux2=Y;
           letra=char (cambiarValor(aux2));
           cout<<"\n";
           cout<<"LA DAMA TE COMIO FICHA EN --- > "<<letra<<X;
           cout<<"\n";
           contador_o++;
           cambiar=1; // PARA SABER QUE REALIZO UNA COMIDA
           ultimo1=X-1; //ULTIMA POSICION EN COMER
           ultimo2=Y-1; //ULTIMA POSICION EN COMER
           
          
           
       }
       else
       if( (tablero[X][Y]=='D' || tablero[X][Y]=='X') && (tablero[X-1][Y-1]=='D'|| tablero[X-1][Y-1]=='X') ) // HAY DOS FICHAS PEGADAS
       {
   
           X=0;
           Y=0;
           return false;
           
       }
       else
       if((tablero[X][Y]=='C' || tablero[X][Y]=='O') && cambiar==0) //FICHA AMIGA EN EL CAMINO
       {
       
          X=0;
          Y=0;
          return false;
       }
    }
    if(cambiar==0) //SI LA DIAGONAL ESTA VACIA Y NO HAY FICHAS POR COMER , NO COMIO NADA ---> FALSE !
    {
        return false;
    }
    else
    if(cambiar==1) //SI LA MAQUINA COMIO FICHAS, ----> TRUE !!!
    {
       return true;
    }
    
}


bool sePuedeComer2Maquina(int X, int Y) //posiciones de la dama -C- (maquina)
{
    int AUX1=X; //GUARDAMOS LOS VALORES INICIALES PARA PODER DESPUES BORRAR LA FICHA
    int AUX2=Y;
    int cambiar=0;
    char letra;
    int aux2=0;
    ultimo1=0; //PARA SABER CUAL FUE LA ULTIMA POSICION ANTES DE RETORNAR FALSE !
    ultimo2=0;
      
       
    while((X-1)!=0  &&  (Y+1)!=9 ) //OJO ACA MODIFICA ALGO !
    {
       X--;
       Y++;
       
       
       if( (tablero[X][Y]=='D' || tablero[X][Y]=='X') && tablero[X-1][Y+1]==' ')
       {
         
           fichaProfe--; //el profe perdio fichas
           tablero[X][Y]=' ';
           aux2=Y;
           letra=char (cambiarValor(aux2));
           cout<<"\n";
           cout<<"LA DAMA TE COMIO FICHA EN --- > "<<letra<<X;
           cout<<"\n";
           contador_o++;
           cambiar=1; // PARA SABER QUE REALIZO UNA COMIDA
           ultimo1=X-1; //ULTIMA POSICION EN COMER
           ultimo2=Y+1; //ULTIMA POSICION EN COMER
           
          
           
       }
       else
       if( (tablero[X][Y]=='D' || tablero[X][Y]=='X') && (tablero[X-1][Y+1]=='D'|| tablero[X-1][Y+1]=='X') ) // HAY DOS FICHAS PEGADAS
       {
   
           X=0;
           Y=9;
           return false;
           
       }
       else
       if((tablero[X][Y]=='C' || tablero[X][Y]=='O') && cambiar==0) //FICHA AMIGA EN EL CAMINO
       {
       
          X=0;
          Y=9;
          return false;
       }
    }
    if(cambiar==0) //SI LA DIAGONAL ESTA VACIA Y NO HAY FICHAS POR COMER , NO COMIO NADA ---> FALSE !
    {
        return false;
    }
    else
    if(cambiar==1) //SI LA MAQUINA COMIO FICHAS, ----> TRUE !!!
    {
       return true;
    }
    
     
}

//DE AQUI PARA ABAJO

bool sePuedeComer3Maquina(int X, int Y) //posiciones de la dama -C- (maquina)
{
    int AUX1=X; //GUARDAMOS LOS VALORES INICIALES PARA PODER DESPUES BORRAR LA FICHA
    int AUX2=Y;
    int cambiar=0;
    char letra;
    int aux2=0;
    ultimo1=0; //PARA SABER CUAL FUE LA ULTIMA POSICION ANTES DE RETORNAR FALSE !
    ultimo2=0;
      
       
    while((X+1)!=9  &&  (Y-1)!=0 )
    {
       X++;
       Y--;
       
       
       if( (tablero[X][Y]=='D' || tablero[X][Y]=='X') && tablero[X+1][Y-1]==' ')
       {
         
           fichaProfe--; //el profe perdio fichas
           tablero[X][Y]=' ';
           aux2=Y;
           letra=char (cambiarValor(aux2));
           cout<<"\n";
           cout<<"LA DAMA TE COMIO FICHA EN --- > "<<letra<<X;
           cout<<"\n";
           contador_o++;
           cambiar=1; // PARA SABER QUE REALIZO UNA COMIDA
           ultimo1=X+1; //ULTIMA POSICION EN COMER
           ultimo2=Y-1; //ULTIMA POSICION EN COMER
           
          
           
       }
       else
       if( (tablero[X][Y]=='D' || tablero[X][Y]=='X') && (tablero[X+1][Y-1]=='D'|| tablero[X+1][Y-1]=='X') ) // HAY DOS FICHAS PEGADAS
       {
   
           X=9;
           Y=0;
           return false;
           
       }
       else
       if((tablero[X][Y]=='C' || tablero[X][Y]=='O') && cambiar==0) //FICHA AMIGA EN EL CAMINO
       {
       
          X=9;
          Y=0;
          return false;
       }
    }
    if(cambiar==0) //SI LA DIAGONAL ESTA VACIA Y NO HAY FICHAS POR COMER , NO COMIO NADA ---> FALSE !
    {
        return false;
    }
    else
    if(cambiar==1) //SI LA MAQUINA COMIO FICHAS, ----> TRUE !!!
    {
       return true;
    }
    
}
//DE AQUI PARA ABAJO
bool sePuedeComer4Maquina(int X, int Y) //posiciones de la dama -C- (maquina)
{
    int AUX1=X; //GUARDAMOS LOS VALORES INICIALES PARA PODER DESPUES BORRAR LA FICHA
    int AUX2=Y;
    int cambiar=0;
    char letra;
    int aux2=0;
    ultimo1=0; //PARA SABER CUAL FUE LA ULTIMA POSICION ANTES DE RETORNAR FALSE !
    ultimo2=0;
      
       
    while((X+1)!=9  &&  (Y+1)!=9 )
    {
       X++;
       Y++;
       
       
       if( (tablero[X][Y]=='D' || tablero[X][Y]=='X') && tablero[X+1][Y+1]==' ')
       {
         
           fichaProfe--; //el profe perdio fichas
           tablero[X][Y]=' ';
           aux2=Y;
           letra=char (cambiarValor(aux2));
           cout<<"\n";
           cout<<"LA DAMA TE COMIO FICHA EN --- > "<<letra<<X;
           cout<<"\n";
           contador_o++;
           cambiar=1; // PARA SABER QUE REALIZO UNA COMIDA
           ultimo1=X+1; //ULTIMA POSICION EN COMER
           ultimo2=Y+1; //ULTIMA POSICION EN COMER
        }
       else
       if( (tablero[X][Y]=='D' || tablero[X][Y]=='X') && (tablero[X+1][Y+1]=='D'|| tablero[X+1][Y+1]=='X') ) // HAY DOS FICHAS PEGADAS
       {
   
           X=9;
           Y=9;
           return false;
           
       }
       else
       if((tablero[X][Y]=='C' || tablero[X][Y]=='O') && cambiar==0) //FICHA AMIGA EN EL CAMINO
       {
       
          X=9;
          Y=9;
          return false;
       }
    }
    if(cambiar==0) //SI LA DIAGONAL ESTA VACIA Y NO HAY FICHAS POR COMER , NO COMIO NADA ---> FALSE !
    {
        return false;
    }
    else
    if(cambiar==1) //SI LA MAQUINA COMIO FICHAS, ----> TRUE !!!
    {
       return true;
    }
    
}



void moverFicha() //funcion para mover fichas del jugador humano, incluye validacion de movimientos.
{
    int ct=0;
    char letra;
    char validar1[30];
    int k;
    int kk;
    int ct2=1;
    do
    {
        do
        {
            do
            {
                
                do
                {
                    
                    if (tablero[x][y] == 'X')
                   {
                        
                            do{ //VALIDACION
                                cout<<"\n\n";
                                cout<<"¿Donde Desea Mover? \n\n";
                                cout<<"1) Izquierda arriba ?\n";
                                cout<<"2) Derecha Arriba?\n";
                                cout<<"opcion: ";
                      
                                cin>>validar1;
                                k=(int)validar1[0];
                                kk=strlen(validar1);
      
                                if((k!=49 && k!=50) || kk!=1 )
                                {
                                    cout<<"\n";
                                    cout<<"***ERROR AL INGRESAR NUMERO**\n";
                                    cout<<"SOLO SON PERMITIDOS NUMEROS DEL 1 AL 2\n";
                                }
                                }while((k!=49 && k!=50  )|| kk!=1);
                            
                            for(int ii=49 ; ii<=50 ;ii++) //TRANFORMACION DEL NUMERO EN ASCII , A HEXADECIMAL
                            {
                                if(k==ii)
                                {
                                    muevete=ct2;
                                }         
                                    ct2++;
                            }
                                ct2=1;
                            
                            error=0;
                            if(muevete>2||muevete<1)
                            {
                                cout<<"Se a detectado un ERROR\n";
                                cout<<"Solo 1) y 2) son opciones validas, jugue nuevamente"<<endl;
                            }
                        
                        if((y==9&&muevete==2)||(y==0&&muevete==1))
                        {
                          
                            cout<<"Se a detectado un ERROR\n";
                            cout<<"al parecer te sales del tablero, intente con otra jugada\n "<<endl ;
                        }
                    }
                     
                }while (muevete>4||muevete<1);
            }while((y==9&&muevete==2)||(y==0&&muevete==1)||(y==9&&muevete==4)||(y==0&&muevete==3)||(x==0&&muevete==1)||(x==0&&muevete==2)||(x==9&&muevete==3)||(x==9&&muevete==4));//Vlidacion para no salirte del tablero
           
            if (muevete == 1 && ( tablero[x-1][y-1]== 'X'||tablero[x-1][y-1]== 'D')  )
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"Casilla ya ocupada por una ficha"<<endl ;
            }
            else 
                if (muevete == 2 && (tablero[x-1][y+1]== 'X'||tablero[x-1][y+1]== 'D') )
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"Casilla ya ocupada por una ficha"<<endl;
                
            }
            else 
                if (muevete == 3 && (tablero[x+1][y-1]== 'X'||tablero[x+1][y-1]== 'D') )
            {
               cout<<"Se a detectado un ERROR\n";
               cout<<"Casilla ya ocupada por una ficha"<<endl ;
            }
            else 
                if (muevete == 4 && (tablero[x+1][y+1]== 'X'||tablero[x+1][y+1]== 'D') )
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"Casilla ya ocupada por una ficha"<<endl ;
            }
             
            
            
         }while((muevete==1&&(tablero[x-1][y-1]== 'X'||tablero[x-1][y-1]== 'D'))||(muevete==2&&(tablero[x-1][y+1]== 'X'||tablero[x-1][y+1]== 'D') )||(muevete == 3 && (tablero[x+1][y-1]== 'X'||tablero[x-1][y+1]== 'D') )||(muevete == 4 && (tablero[x+1][y+1]== 'X'||tablero[x+1][y+1]== 'D') ));//validacion
        
        if (muevete==1 && (tablero[x-1][y-1] == 'O'||tablero[x-1][y-1] == 'C') )
        {
            //Aqui comienzas las validaciones para comer , casillas ocupadas, fuera de tablero, etc
            if(y==1) //funciona
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"Al parecer te sales del tablero, intenta nuevamente\n "<<endl;
                error=1;
            }
            if(x==1) // funciona
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"Al parecer te sales del tablero, intenta nuevamente\n "<<endl ;
                error=1;
            }
            if(tablero[x-2][y-2] == 'X') //validacion por si no hay espacio al otro lado al comer
            {
                letra=char (cambiarValor(y));
                cout<<"Se a detectado un ERROR\n";
                letra=letra-2;
                cout<<"Casilla ya ocupada, no se puede comer, exite otra ficha en la casilla "<<letra<<"-"<<x-2;
                error=1;}
            if(tablero[x-2][y-2] == 'O' ) //funciona
            {
                letra=char (cambiarValor(y));
                letra=letra-2;
                cout<<"Se a detectado un ERROR\n";
                cout<<"Casilla ya ocupada, no se puede comer, exite otra ficha en la casilla "<<letra<<"-"<<x-2;
                error=1;
            }
            if(tablero[x-2][y-2] == 'D' ) 
            {
                letra=char (cambiarValor(y));
                letra=letra-2;
                cout<<"Se a detectado un ERROR\n";
                cout<<"Casilla ya ocupada, no se puede comer, exite otra ficha en la casilla "<<letra<<"-"<<x-2;
                error=1;
            }
            if(tablero[x-2][y-2] == 'C' )//al parecer esta demas
            {
                letra=char (cambiarValor(y));
                letra=letra-2;
                cout<<"Se a detectado un ERROR\n";
                cout<<"Casilla ya ocupada, no se puede comer, exite otra ficha en la casilla "<<letra<<"-"<<x-2;
                error=1;
            }
            }
         else 
             if (muevete==2 && (tablero[x-1][y+1] == 'O'||tablero[x-1][y+1] == 'C'))
         {
            if(y==8 || y==9) //Jaime aqui estaba el error !!! era y=8 y no y=6 !!!!
            {
                
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA!, al parecer te saliste del tablero\n"<<"Intenta nuevamente\n "<<endl ;
                error=1;
            }
            if(x==1 || x==0)
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA!, al parecer te saliste del tablero\n"<<"Intenta nuevamente\n "<<endl;                                      ;
                error=1;
            }
            if(tablero[x-2][y+2] == 'X')
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA, no se puede comer ficha, pocision ya ocupada\n"<<"Intente nuevamente\n"<<endl;
                error=1;
            }
            if (tablero[x-2][y+2] == 'O')
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA, no se puede comer ficha, posicion ya ocupada\n"<<"Intente nuevamente\n"<<endl;
                error=1;
            }
            if (tablero[x-2][y+2] == 'D')
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA, no se puede comer ficha, posicion ya ocupada\n"<<"Intente nuevamente\n"<<endl;
                error=1;
            }
            if (tablero[x-2][y+2] == 'C')
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA, no se puede comer ficha, posicion ya ocupada\n"<<"Intente nuevamente\n"<<endl;
                error=1;
            }
        }
         else 
             if (muevete==3 && (tablero[x+1][y-1] == 'O'||tablero[x+1][y-1] == 'C'))
            {
              if(y==1 || y==0)
              {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA!, al parecer te saliste del tablero\n"<<"Intenta nuevamente\n "<<endl;
                if(y==1)
               {
                
                 cout<<"Se a detectado un ERROR\n";
                 cout<<"VAYA!, al parecer te saliste del tablero\n"<<"Intenta nuevamente\n "<<endl ;
                 error=1;
               }
                error=1;
              }
             if(x==8 || x==9) //Aca estaba el otro error JAIIMEEE !!! :0 era 8 y no 6 !! :(
             {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA!, al parecer te saliste del tablero\n"<<"Intenta nuevamente\n "<<endl ;
                error=1;
             }
            if(tablero[x+2][y-2] == 'X')
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA, no se puede comer ficha, posicion ya ocupada\n"<<"Intente nuevamente\n"<<endl;
               
                error=1;
            }
            if (tablero[x+2][y-2] == 'O')
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA, no se puede comer ficha, posicion ya ocupada\n"<<"Intente nuevamente\n"<<endl;
                
                error=1;
            }
            if (tablero[x-2][y+2] == 'C')
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA, no se puede comer ficha, posicion ya ocupada\n"<<"Intente nuevamente\n"<<endl;
                
                error=1;
            }
            if (tablero[x-2][y+2] == 'D')
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA, no se puede comer ficha, posicion ya ocupada\n"<<"Intente nuevamente\n"<<endl;
                
                error=1;
            }
        }
         else 
             if (muevete==4 && (tablero[x+1][y+1] == 'O'||tablero[x+1][y+1] == 'C'))
        {
            if(y==8)
            {
                cout<<"Vaya!, se produjo un ERROR\n";
                cout<<"Al parecer te sales del tablero, intenta nuevamente\n"<<endl ;
                error=1;
            }
            if(x==8||x==9)
            {
                cout<<"Vaya!, se produjo un ERROR\n";
                cout<<"Al parecer te sales del tablero, intenta nuevamente\n"<<endl;
                error=1;
            }
            if(tablero[x+2][y+2] == 'X')
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA, no se puede comer ficha, posicion ya ocupada\n"<<"Intente nuevamente\n"<<endl;
                
                error=1;
            }
            if (tablero[x+2][y+2] == 'O')
            {
               cout<<"Se a detectado un ERROR\n";
               cout<<"VAYA, no se puede comer ficha, posicion ya ocupada\n"<<"Intente nuevamente\n"<<endl;
                
                error=1;
            }
            if (tablero[x+2][y+2] == 'D')
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA, no se puede comer ficha, posicion ya ocupada\n"<<"Intente nuevamente\n"<<endl;
                
                error=1;
            }
            if (tablero[x+2][y+2] == 'C')
            {
                cout<<"Se a detectado un ERROR\n";
                cout<<"VAYA, no se puede comer ficha, posicion ya ocupada\n"<<"Intente nuevamente\n"<<endl;
                
                error=1;
            }
        }
    }while(error==1);
    
    
    if(tablero[x][y]== 'D' && muevete==1 && tablero[x-1][y-1]== ' '  )
    {
        //tablero[x][y]= ' ';
        tablero[x][y]= 'D';
        a=x-1; //variables para la antiSopladita
        b=y-1; //variables, para la antiSopladita
    }
    else 
        if (tablero[x][y]=='D'&& muevete == 2 && tablero[x-1][y+1]== ' ' )
        {
        //tablero[x][y]=' ' ;
        tablero[x][y] = 'D';
        a=x-1; //variables para la antiSopladita
        b=y+1; //variables para la antiSopladita
    }
    else 
        if (tablero[x][y]=='D'&& muevete == 3  )
        {
        tablero[x][y]=' ' ;
        tablero[p][q] = 'D';
        a=x+1; //variables para la antiSopladita
        b=y-1; //variables para la antiSopladita
    }
    else 
        if (tablero[x][y]=='D'&& muevete == 4 && tablero[x+1][y+1]== ' ' )
    {
        //tablero[x][y]=' ' ;
        //tablero[x+1][y+1] = 'D';
        tablero[x][y]='D';
        a=x+1; //variables para la antiSopladita
        b=y+1; //variables para la antiSopladita
    }
    else 
        //ahora comienzan las validaciones para comer
        /*if(tablero[x][y]=='D'&& muevete== 1 &&( tablero [x-1][y-1] == 'O' || tablero [x-1][y-1] == 'C'))
    {
        tablero[x][y]=' ' ;
        tablero[x-1][y-1]=' ' ;
        tablero[x-2][y-2]= 'D' ;
        a=x-2; //variables para la antiSopladita
        b=y-2; //variables para la antiSopladita
        letra=char (cambiarValor(y));
        cout<<"\n";
        letra=letra-1;
        cout<<"Has comido ficha enemiga 'O' en la siguiente casilla "<<letra<<"-"<<x-1 ;
        fichao=fichao-1;
        contador_x= (contador_x)+3;
        
    }
    else 
        if(tablero[x][y]=='D'&& muevete==2 && (tablero [x-1][y+1] == 'O'||tablero [x-1][y+1] == 'C'))
    {
        tablero[x][y]=' ' ;
        tablero[x-1][y+1]=' ' ;
        tablero[x-2][y+2]= 'D' ;
        //cout<<"\a";
        cout<<"\n";
        letra=char (cambiarValor(y));
        letra=letra+1;
        cout<<"Has comido ficha enemiga 'O' en la siguiente casilla " <<letra<<"-"<<x+1 ;
        fichao=fichao-1;
        contador_x= (contador_x)+3;
        
        
    }
    else 
        if(tablero[x][y]=='D'&& muevete== 3 && (tablero [x+1][y-1] == 'O'||tablero [x+1][y-1] == 'C'))
    {
        tablero[x][y]=' ' ;
        tablero[x+1][y-1]=' ';
        tablero[x+2][y-2]= 'D';
        //cout<<"\a";
        cout<<"\n";
        letra=char (cambiarValor(y));
        letra=letra-1;
        cout<<"Has comido ficha enemiga 'O' en la siguiente casilla "<<letra<<"-"<<x-1 ;
        fichao=fichao-1;
        contador_x= (contador_x)+3;
        
    }
    else 
        if(tablero[x][y]=='D'&& muevete== 4 && (tablero [x+1][y+1] == 'O'||tablero [x+1][y-1] == 'C'))
    {
        tablero[x][y]=' ';
        tablero[x+1][y+1]=' ' ;
        tablero[x+2][y+2]= 'D' ;
        //cout<<"\a";
        cout<<"\n";
        letra=char (cambiarValor(y));
        letra=letra+1;
        cout<<"Has comido ficha enemiga 'O' en la siguiente casilla " <<letra<<"-"<<x+1 ;
        fichao=fichao-1;
        contador_x= (contador_x)+3;
    }
    
     
     else */ 
         
         if(tablero[x][y]== 'X' && muevete== 1 && tablero [x-1][y-1] == ' ')
    {
        tablero[x][y]=' ';
        tablero [x-1][y-1]= 'X';
        a=x-1; //variables para la antiSopladita
        b=y-1; //variables para la antiSopladita
    }
    
     
    
    else 
        if(tablero[x][y]=='X'&& muevete== 1 && (tablero [x-1][y-1] == 'O'||tablero [x-1][y-1] == 'C'))
    {
        tablero[x][y]=' ' ;
        tablero[x-1][y-1]=' ' ;
        tablero[x-2][y-2]= 'X' ;
        a=x-2; //variables para la antiSopladita
        b=y-2; //variables para la antiSopladita
        r=x-2;
        s=y-2;
        cout<<"\n";
        letra=char (cambiarValor(y));
        letra=letra-1;
        cout<<"Has comido ficha enemiga 'O' en la siguiente casilla " <<letra<<"-"<<x-1 ;
        fichao=(fichao)-1;
        comerMultiple();
        contador_x++;
        
    }
    else 
        if(tablero[x][y]== 'X' && muevete== 2 && tablero [x-1][y+1] == ' ')
    {
        tablero[x][y]=' ' ;
        tablero [x-1][y+1]= 'X' ;
        a=x-1; //variables para la antiSopladita
        b=y+1; //variables para la antiSopladita
        
    }
    else 
        if(tablero[x][y]== 'X' && muevete== 2 && (tablero [x-1][y+1] == 'O'||tablero [x-1][y+1] == 'C'))
    {
        tablero[x][y]=' ' ;
        tablero [x-1][y+1]= ' ' ;
        tablero[x-2][y+2]= 'X' ;
        a=x-2; //variables para la antiSopladita
        b=y+2;
        r=x-2;
        s=y+2;
        //variables para la antiSopladita
        //cout<<"\a";
        cout<<"\n";
        letra=char (cambiarValor(y));
        letra=letra+1;
        cout<<"Has comido ficha enemiga 'O' en la siguiente casilla " <<letra<<"-"<<x+1 ;
        fichao=fichao-1;
        comerMultiple();
        contador_x++;
    }
    
    turno = 0 ;
}

void moverMaquina()
{
    char letra;
    if (tablero[x][y]=='C' && muevete == 1 && tablero[x+1][y-1]== ' ' )
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y-1] = 'C' ;
            //system("clear");
            y--;
            letra=char (cambiarValor(y));
            
            cout<<"\n";
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA  "<<letra<<"-"<<x+1;
            cout<<"\n";
            
            
          }
        else 
            if (tablero[x][y]=='C' && muevete == 2 && tablero[x+1][y+1]== ' '  )
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y+1] = 'C' ;
            //system("clear");
            y++;
            letra=char (cambiarValor(y));
            
            cout<<"\n";
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA  "<<letra<<"-"<<x+1;
            cout<<"\n";
            
            
        }
        else 
            if (tablero[x][y]=='C' && muevete == 3 && tablero[x-1][y-1]== ' '  )
        {
            tablero[x][y]=' ' ;
            tablero[x-1][y-1] = 'C' ;
            //system("clear");
            y--;
            letra=char (cambiarValor(y));
            
            cout<<"\n";
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA  "<<letra<<"-"<<x-1;
            cout<<"\n";
          
        }
        else 
            if (tablero[x][y]=='C' && muevete == 4 && tablero[x-1][y+1]== ' '  )
        {
            tablero[x][y]=' ' ;
            tablero[x-1][y+1] = 'C' ;
            //system("clear");
            y++;
            letra=char (cambiarValor(y));
            
            cout<<"\n";
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA  "<<letra<<"-"<<x-1;
            cout<<"\n";
            
        }
        else 
            /*if(tablero[x][y]=='C' && muevete== 1 && (tablero [x+1][y-1] == 'X'||tablero [x+1][y-1] == 'D'))
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y-1]=' ' ;
            tablero[x+2][y-2]= 'C' ;
            y--;
            letra=char (cambiarValor(y));
             
             cout<<"\n";
             cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA "<<letra<<"-"<<x+1;
             cout<<"\n";
             fichaProfe=fichaProfe-1;
             contador_o= (contador_o)+3;
             
        }
            else 
            if(tablero[x][y]=='C' && muevete== 2 && (tablero [x+1][y+1] == 'X'||tablero [x+1][y+1] == 'D'))
        {
                tablero[x][y]=' ' ;
                tablero[x+1][y+1]=' ' ;
                tablero[x+2][y+2]= 'C' ;
                 cout<<"\a";
                 y++;
                 letra=char (cambiarValor(y));
                 
                 cout<<"\n";
                 cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA  "<<letra<<"-"<<x+1;
                 cout<<"\n";
                 fichaProfe=fichaProfe-1;
                 contador_o= (contador_o)+3;
                
         }
        else 
            if(tablero[x][y]=='C' && muevete== 3 && (tablero [x-1][y-1] == 'X'||tablero [x-1][y-1] == 'D'))
        {
                tablero[x][y]=' ' ;
                tablero[x-1][y-1]=' ' ;
                tablero[x-2][y-2]= 'C' ;
                 cout<<"\a";
                 y--;
                 letra=char (cambiarValor(y));
                 
                 cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<letra<<"-"<<x-1;
                 cout<<"\n";
                 fichaProfe=fichaProfe-1;
                 contador_o= (contador_o)+3;
              
        }
        else 
            if(tablero[x][y]=='C' && muevete== 4 && (tablero [x-1][y+1] == 'X'||tablero [x-1][y+1] == 'D'))
        {
                tablero[x][y]=' ' ;
                tablero[x-1][y+1]=' ' ;
                tablero[x-2][y+2]= 'C' ;
                 cout<<"\a";
                 y++;
                 letra=char (cambiarValor(y));
                 
                 cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<letra<<"-"<<x-1;
                 cout<<"\n";
                 fichaProfe=fichaProfe-1;
                 contador_o= (contador_o)+3;
                 
        }
        else*/ 
            if (tablero[x][y]=='O' && muevete == 1 && tablero[x+1][y-1]== ' ' )
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y-1] = 'O' ;
            y--;
            letra=char (cambiarValor(y));
            
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<letra<<"-"<<x+1;
            cout<<"\n";
           
        }
        if (tablero[x][y]=='O' && muevete == 2 && tablero[x+1][y+1]== ' ' )
         {
            tablero[x][y]=' ' ;
            tablero[x+1][y+1] = 'O' ;
            y++;
            letra=char (cambiarValor(y));
            
            cout<<"LA COMPUTADORA A MOVIDO UNA FICHA A LA CASILLA "<<letra<<"-"<<x+1;
            cout<<"\n";
         }
        /*else 
            if(tablero[x][y]=='O'&& muevete== 1 && (tablero [x+1][y-1] == 'X'||tablero [x+1][y-1] == 'D'))
         {
            tablero[x][y]=' ' ;
            tablero [x+1][y-1]= ' ' ;
            tablero[x+2][y-2]= 'O' ;
            cout<<"\a";
            y--;
            letra=char (cambiarValor(y));
            
            cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA  "<<letra<<"-"<<x+1;
            cout<<"\n";
            fichaProfe=fichaProfe-1;
            contador_o= (contador_o)+3;
           
         }
        else 
            if(tablero[x][y]=='O'&& muevete== 2 && ( tablero [x+1][y+1] == 'X'|| tablero [x+1][y+1] == 'D'))
        {
            tablero[x][y]=' ' ;
            tablero[x+1][y+1]=' ' ;
            tablero[x+2][y+2]= 'O' ;
            cout<<"\a";
            y++;
            letra=char (cambiarValor(y));
            
            cout<<"HAS COMIDO A LA FICHA CONTRARIA 'X' EN LA CASILLA   "<<letra<<"-"<<x+1;
            cout<<"\n";
            fichaProfe=fichaProfe-1;
            contador_o= contador_o+3;
           
         }
         */ 
          turno = 1 ;  
}


void estrategiaUno() // adelantar fichas de de fila i=2 a la fila i=3
{   
    entrar=0;
    for(i=2; i>=1; i--)
   {    
     for(j=9; j>=0; j--)
     {
       if(tablero[i][j]=='O' && i==2 && tablero[i+1][j+1]==' ' && tablero[i+2][j+2]!='X' )
        {
          muevete=2;
          x=2;
          y=j;
          j=-1;
          i=0;
          entrar=1;
         
        }
      
       else
       {
        if(tablero[i][j]=='O' && i==1 && tablero[i+1][j-1]==' ' && tablero[i+2][j-2]!='X' )
        {
         
         muevete=1;
         x=1;
         y=j;
         j=-1;
         i=0;
         entrar=1;
         
        }
        
       }
     }
    }
}

void estrategiaDos()
{
    entrar=0;
   for(j=0 ;j<=9; j++)
   {
     if(tablero[3][j]=='O' && j!=0 && tablero[5][j-2]!='X'&& tablero[5][j]!='X' &&tablero[4][j-1]==' '  )
     {
        muevete=1;
        x=3;
        y=j;
        j=10;
        entrar=1;
     }
     
      else
      {
          if(tablero[4][j]=='O' && j!=9 && tablero[6][j]!='X'&& tablero[6][j+2]!='X' &&tablero[5][j+1]==' '  )
         {
           muevete=2;
           x=4;
           y=j;
           j=10;
           entrar=1;
         }
          else
          {
             if(tablero[5][j]=='O' && j!=0 && tablero[7][j-2]!='X'&& tablero[7][j]!='X' &&tablero[6][j-1]==' '  )
            {
              muevete=1;
              x=5;
              y=j;
              j=10;
              entrar=1;
            }
            else
            {
                 if(tablero[6][j]=='O' && j!=9 && tablero[8][j]!='X'&& tablero[8][j+2]!='X' &&tablero[7][j+1]==' '  )
                {
                  muevete=2;
                  x=6;
                  y=j;
                  j=10;
                  entrar=1;
                }
                else
                {
                 if(tablero[7][j]=='O' && j!=0 && tablero[9][j-2]!='X'&& tablero[9][j]!='X' &&tablero[8][j-1]==' '  )
                 {
                  muevete=1;
                  x=7;
                  y=j;
                  j=10;
                  entrar=1;
                 }
                 
                }
            }
          }
      }
     }
}
                
    


void estrategiaTres() // si ya no hay mas opciones de mover, muevo la ultima fila
{
    entrar=0;
    
    for(j=9;j>=0;j--)
    {
        if(tablero[0][j]=='O' && j!=9 && tablero[1][j+1]==' ' && tablero[2][j+2]!='X' )
        {
            muevete=2;
            x=0;
            y=j;
            j=-1;
            entrar=1;
            cout<<"mover ultima fila , primer if";
        }
        else
        {
          if(tablero[0][j]=='O' && j!=0 && tablero[1][j-1]==' ' && tablero[2][j-2]!='X')
        {
            muevete=1;
            x=0;
            y=j;
            j=-1;
            entrar=1;
            cout<<"mover ultima fila, segundo if";
        }
        }    
    }
}

void estrategiaCuatro() //Estrategia CRITICA !:0 utilizada cuando ya no tengo mas opciones, y me van a comer una ficha si o si :(
{
    //cout<<"estrategia critica";
    entrar=0;
    for(i=9 ; i>=0 ; i--)
    {
        for(j=9 ; j>=0 ; j--)
        {
            if(tablero[i][j]=='O' && j!=9 && tablero[i+1][j+1]==' ')
            {
                muevete=2;
                x=i;
                y=j;
                i=-1;
                j=-1;
                entrar=1;
                cout<<"(no quedan mas opciones, tuve que sacrificar una ficha) ";
            }
            else
            {
                if(tablero[i][j]=='O' && j!=0 && tablero[i+1][j-1]==' ')
                {
                    muevete=1;
                    x=i;
                    y=j;
                    i=-1;
                    j=-1;
                    entrar=1;
                    cout<<"(no quedan mas opciones, tuve que sacrificar una ficha) ";
                }
            }
        }
    }
}

void estrategiaCinco() // estrategia que mueve fichas-PEON para convertir fichas en DAMAS 
{
    entrar=0;
    //cout<<"estretegia cinco, convertir dama";
        for(j=0 ; j<=9 ; j++)
        {
            if(tablero[8][j]=='O' && j!=0 && tablero[9][j-1]==' '  )
            {
                muevete=1;
                x=8;
                y=j;
                j=10;
                entrar=1;
                cout<<"primer if convertir dama";
                
            }
            else
            {
                if(tablero[8][j]=='O'  && j!=9 && tablero[9][j+1]==' ')
                {
                    muevete=2;
                    x=8;
                    y=j;
                    j=10;
                    entrar=1;
                    //cout<<"cinco segundo if";
                    
                }
            }
        }
}

void arrancar() // si una ficha rival tiene la opcion de comer una ficha, dicha ficha se arranca.
{ 
    //vendria siendo la estrategia 6
    
    entrar=0;
    
    for(i=0 ; i<=9 ; i++)
    {
        for(j=0 ; j<=9 ; j++)
        {
            if( (tablero[i][j]=='O'|| tablero[i][j]=='C') && j!=9 && tablero[i+1][j-1]=='X' && tablero[i-1][j+1]==' ' && tablero[i+1][j+1]==' ' )
            {
                muevete=2;
                x=i;
                y=j;
                i=10;
                j=10;
                entrar=1;
                cout<<"(arrancar) ";
            }
            
            else
            {
                if( (tablero[i][j]=='O'||tablero[i][j]=='C') && j!=0 && tablero[i+1][j+1]=='X' && tablero[i-1][j-1]==' ' && tablero[i+1][j-1]==' ' )
               {
                    muevete=1;
                    x=i;
                    y=j;
                    i=10;
                    j=10;
                    entrar=1;
                    cout<<"(arrancar)" ;
                    
               }
            }
        }
    }
}

void estrategiaSiete() // funcion para mover fichas de i=1, en caso de que no hayan mas opciones de mover.
{
    entrar=0;
    
    for(j=0 ; j<=9 ; j++)
    {
        if(tablero[1][j]=='O' && tablero[2][j+1]==' ' && j!=9 && tablero[3][j+2]!='X' && tablero[3][j]!='X' )
        {
            muevete=2;
            x=1;
            y=j;
            j=10;
            entrar=1;
            //cout<<"entro al primer i=1 critico";
        }
        else
        {
            if(tablero[1][j]=='O' && tablero[2][j-1]==' ' && j!=0 && tablero[2][j-2]!='X' && tablero[3][j]!='X')
            {
                muevete=1;
                x=1;
                y=j;
                j=10;
                entrar=1;
                //cout<<"entro al segundo i=1 critico";
            }
        }
    }
    
}

void cpu ()

{
    
    char letra;
    cout<<"\n";
    cout<<"___________________________________________________\n\n";   
    do{
        do{
           do{
                  
                  arrancar();
                          
                  if(entrar==0)
                  {
                  estrategiaCinco(); //tranformar dama
                  }          
                  
                  if(entrar==0)
                  {
                  estrategiaUno();
                  }
                  
                  if(entrar==0)
                  {
                  estrategiaDos();
                  }    
                  
                  if(entrar==0) //mover ultima fila
                  {
                    estrategiaTres();
                  }    
                  
                  if(entrar==0) //MOVER FILA i=1 , PARA VOLVER A FORMAR UN ZIG ZAG
                  {
                      estrategiaSiete();
                  }
                  
                  if(entrar==0) // estrategiaCritica
                  {
                  estrategiaCuatro();
                  }    
                    
                     
                   }while ((y==9&&muevete==2)||(y==0&&muevete==1)||(y==9&&muevete==4)||(y==0&&muevete==3)||(x==0&&muevete==4)||(x==0&&muevete==3)||(x==9&&muevete==1)||(x==9&&muevete==2));
           }while((muevete == 1 &&( tablero[x+1][y-1]== 'O'||tablero[x+1][y-1]== 'C') )||(muevete == 2 && (tablero[x+1][y+1]== 'O' || tablero[x+1][y+1]== 'C') )|| (muevete == 3 && (tablero[x-1][y-1]== 'O' || tablero[x-1][y-1]== 'C') )||(muevete == 4 && (tablero[x-1][y+1]== 'O' || tablero[x-1][y+1]== 'C') ));//VALIDACION PARA CASILLA OCUPADA POR UNA AMIGA
            
           //Aqui detecta todos lo errores de movimiento que realiza la maquina, si me sale del tablero, casillas ocupadas, etc
            if (muevete==1 &&( tablero[x+1][y-1] == 'X' || tablero[x+1][y-1] == 'D') )
            {
                
                if(y==1||y==0)
                {
                  error=1;
                }
                if(x==8 || x==9)
                {
                  error=1;
                }
                if(tablero[x+2][y-2] == 'X')
                {
                  error=1;
                }
                if(tablero[x+2][y-2] == 'O')
                {
                  error=1;
                }
                if(tablero[x+2][y-2] == 'C')
                {
                  error=1;
                }
                if(tablero[x+2][y-2] == 'D')
                {
                 error=1;
                }
              }
             if (muevete==2 && (tablero[x+1][y+1] == 'X'||tablero[x+1][y+1] == 'D'))
              {
                if( y==8 || y==9 )
                {
                   error=1;
                }
                if(x==8 || x==9)
                { 
                   error=1;
                }
                if(tablero[x+2][y+2] == 'X')
                {
                   error=1;
                }
                if( tablero[x+2][y+2] == 'O')
                {
                   error=1;
                }
                if( tablero[x+2][y+2] == 'C')
                {
                   error=1;
                }
                if( tablero[x+2][y+2] == 'D')
                {
                   error=1;
                }
              }
             if (muevete==3 && (tablero[x-1][y-1] == 'X'||tablero[x-1][y-1] == 'D'))
              {
                if(y==1 || y==0)
                { 
                    error=1;
                }
                if(x==1 || x==0)
                { 
                    error=1;
                }
                if(tablero[x-2][y-2] == 'X')
                {
                  error=1;
                }
                if( tablero[x-2][y-2] == 'O')
                {
                 error=1;
                }
                 if( tablero[x-2][y-2] == 'C')
                {
                 error=1;
                }
                
                if( tablero[x-2][y-2] == 'D')
                {
                 error=1;
                }
              }
             
              if (muevete==4 && (tablero[x-1][y+1] == 'X'||tablero[x-1][y+1] == 'D'))
              
              {
                if(y==8 || y==9)
                {
                    error=1;
                }
                if(x==1)
                {
                    error=1;
                }
                if(tablero[x-2][y+2] == 'X')
                {
                    error=1;
                }
                if( tablero[x-2][y+2] == 'O')
                {
                    error=1;
                }
                if( tablero[x-2][y+2] == 'D')
                {
                    error=1;
                }
                 if( tablero[x-2][y+2] == 'C')
                {
                    error=1;
                }
             
            
            } 
     }while(error==1);
     
     moverMaquina();
     //moverMaquina() mueve fichas de la maquina, si tiene la oportunidad de comer tambien lo hace.
} 

void sopladita()
{
    int salir;
    char letra;
    int auxiliar;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            {
                if (tablero[i][j]=='D' && tablero[i+2][j+2]==' ' && (tablero[i+1][j+1]=='O'||tablero[i+1][j+1]=='C') && j!= 8 && j!=9 && tablero[a][b]!='D' )
                    {
                        auxiliar=j;       
                        cout<<"\n\n";
                        letra=char (cambiarValor(auxiliar));
                        cout<<"**** SOPLADITA **** en la ficha --> "<<letra<<"-"<<i<<endl;
                        tablero[i][j]=' ';
                        fichaProfe=fichaProfe-1;
                        turno=0;
                        j=10;
                        i=10;
                        contador_s++;
                    }
                else 
                    if (tablero[i][j]=='D' && tablero[i+2][j-2]==' ' && (tablero[i+1][j-1]=='O'||tablero[i+1][j-1]=='C') && j!=0 && j!= 1 && tablero[a][b]!='D')
                    {
                        auxiliar=j;       
                        cout<<"\n\n";
                        letra=char (cambiarValor(auxiliar));
                        cout<<"**** SOPLADITA **** en la ficha --> "<<letra<<"-"<<i<<endl;
                        tablero[i][j]=' ';
                        fichaProfe=fichaProfe-1;
                        turno=0;
                        j=10;
                        i=10;
                        contador_s++;
                    }
                else 
                    if (tablero[i][j]=='D' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='O'||tablero[i-1][j+1]=='C')  && j!= 8 && j!=9 && tablero[a][b]!='D' )
                        {
                         auxiliar=j;       
                         cout<<"\n\n";
                         letra=char (cambiarValor(auxiliar));
                         cout<<"**** SOPLADITA **** en la ficha --> "<<letra<<"-"<<i<<endl;
                         tablero[i][j]=' ';
                         fichaProfe=fichaProfe-1;
                         turno=0;
                         j=10;
                         i=10;
                         contador_s++;
                        }
                else 
                    if(tablero[i][j]=='D'&& tablero[i-2][j-2]==' ' && (tablero[i-1][j-1]=='O'||tablero[i-1][j-1]=='C') && j!=1 && j!=0 && tablero[a][b]!='D' )
                    {
                      auxiliar=j;       
                      cout<<"\n\n";
                      letra=char (cambiarValor(auxiliar));
                      cout<<"**** SOPLADITA **** en la ficha --> "<<letra<<"-"<<i<<endl;
                      tablero[i][j]=' ';
                      fichaProfe=fichaProfe-1;
                      turno=0;
                      j=10;
                      i=10;
                      contador_s++;
                    }        
                else 
                    if(tablero[i][j]=='X'&& tablero[i-2][j-2]==' ' && (tablero[i-1][j-1]=='O'||tablero[i-1][j-1]=='C') && j!= 1 && j!=0 )
                    {
                       if(i==a && j==b)
                       {
                           cout<<"no hay sopladita";
                           //que no realize la sopladita, porque significa que que fue la ultima pieza en mover
                       }    
                       else
                       {    
                       auxiliar=j;       
                       cout<<"\n\n";
                       letra=char (cambiarValor(auxiliar));
                       cout<<"**** SOPLADITA **** en la ficha --> "<<letra<<"-"<<i<<endl;
                       tablero[i][j]=' ';
                       fichaProfe=fichaProfe-1;
                       turno=0;
                       j=10;
                       i=10;
                       contador_s++;
                       }
                    }
                else 
                    if (tablero[i][j]=='X' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='O'||tablero[i-1][j+1]=='C') && j!= 8 && j!=9  )
                       {
                        
                        if(i==a && j==b)
                        {
                            cout<<"no hay sopladita";
                            //que no haga nada
                        }
                        
                        else
                        {    
                        auxiliar=j;       
                        cout<<"\n\n";
                        letra=char (cambiarValor(auxiliar));
                        cout<<"**** SOPLADITA **** en la ficha --> "<<letra<<"-"<<i<<endl;
                        tablero[i][j]=' ';
                        fichaProfe=fichaProfe-1;
                        turno=0;
                        j=10;
                        i=10;
                        contador_s++;
                        }
                            }
                        }
                    }
}

void comerFicha() //la maquina come fichas del jugador humano, si esque puede y tiene la opcion
{
    m=0;
    n=0;
    char letra;
    int aux2;
    for(i=0;i<10;i++)
    {
      for(j=0;j<10;j++)
      {
        //validacion para movimiento hacia la derecha con y != de 1
        if(tablero[i][j]=='C'&& tablero[i+2][j+2]==' ' && (tablero[i+1 ][j+1]=='X'||tablero[i+1 ][j+1]=='D') && (i!=8) && (i!=9) && (j!=8) && (j!=9) ) // aca hay una corrrecion del tabblero del roberto debe ser con i y no con J
        {
          aux2=j;
          aux2++;
          letra=char (cambiarValor(aux2));
          cout<<"\n\n";
          cout<<"*** La maquina te comio una ficha  en *** ->  "<<letra<<"-"<<i+1<<endl;
          cout<<"\n\n";
          tablero[i][j]=' ';
          tablero[i+1][j+1]= ' ';
          tablero[i+2][j+2]='C' ;
          fichaProfe=fichaProfe-1;
          turno=1;
          contador_o++;
          
          
         }
         if (tablero[i][j]=='C' && tablero[i-2 ][j-2]==' ' && ( tablero[i-1][j-1]=='X'||tablero[i-1][j-1]=='D') && (j!=1) && (j!=0 ) && (i!=0) && (i!=1) )
         {
            aux2=j;
            aux2--;
            letra=char (cambiarValor(aux2));
            cout<<"\n\n";
            cout<<"*** La maquina te comio una ficha X en *** ->  "<<letra<<"-"<<i-1<<endl;
            cout<<"\n\n";
            tablero[i][j]=' ';
            tablero[i-1][j-1]= ' ';
            tablero[i-2][j-2]='C' ;
            fichaProfe=fichaProfe-1;
            turno=1;
            contador_o++;
            
            
         }
         else 
         if (tablero[i][j]=='C' && tablero[i-2][j+2]==' ' && (tablero[i-1][j+1]=='X'||tablero[i-1][j+1]=='D') && (j!=8) && (j!=9) && (i!=0) && (i!=1) )
         {
            aux2=j;
            aux2++;
            letra=char (cambiarValor(aux2));
            cout<<"\n\n";
            cout<<"*** La maquina te comio una ficha X en *** ->  "<<letra<<"-"<<i-1<<endl;
            cout<<"\n\n";
            tablero[i][j]=' ';
            tablero[i-1][j+1]= ' ';
            tablero[i-2][j+2]='C' ;
            fichaProfe=fichaProfe-1;
            turno=1;
            contador_o++;
            
        }
         else 
         if (tablero[i][j]=='C' && tablero[i+2][j-2]==' ' && (tablero[i+1][j-1]=='X'||tablero[i+1][j-1]=='D') && (j!=0) && (j!=1) && (i!=8) && (i!=9) )
        {
           aux2=j;
           aux2++;
           letra=char (cambiarValor(aux2));
           cout<<"\n\n";
           cout<<"*** La maquina te comio una ficha X en *** ->  "<<letra<<"-"<<i+1<<endl;
           cout<<"\n\n";
           tablero[i][j]=' ';
           tablero[i+1][j-1]= ' ';
           tablero[i+2][j-2]='C' ;
           fichaProfe=fichaProfe-1;
           turno=1;
           contador_o++;
          
          
        }
         else 
         if(tablero[i][j]=='O'&& tablero[i+2][j+2]==' ' &&( tablero[i+1][j+1]=='X'||tablero[i+1][j+1]=='D') && (j!=8) && (j!=9) && (i!=8) && (i!=9) )
           {
             
            
               aux2=j;
               aux2++;
               letra=char (cambiarValor(aux2));
               cout<<"\n\n";
               cout<<"*** La maquina te comio una ficha X en *** ->  "<<letra<<"-"<<i+1;
               cout<<"\n\n";
               tablero[i][j]=' ';
               tablero[i+1][j+1]= ' ';
               tablero[i+2][j+2]='O';
               fichaProfe=fichaProfe-1;
               turno=1;
               contador_o++;
             
            
            }
        
            else 
            if (tablero[i][j]=='O' && tablero[i+2 ][j-2 ]==' ' && (tablero[i+1][j-1]=='X' ||tablero[i+1][j-1]=='D' ) && (j!=1) && (i!=8) && (j!=0) && (i!=9) )
            {            
                  aux2=j;
                  aux2--;
                  letra=char (cambiarValor(aux2));
                  cout<<"\n\n";
                  cout<<"*** La maquina te comio una ficha X en *** ->  "<<letra<<"-"<<i+1<<endl;
                  cout<<"\n\n";
                  tablero[i][j]=' ';
                  tablero[i+1][j-1]= ' ';
                  tablero[i+2][j-2]='O' ;
                  fichaProfe=fichaProfe-1;
                  turno=1;
                  contador_o++;
                
             
            }
        }
   }
}


void preguntar()
{
    int ct=0;
    int ct1=0;
    char letra;
    char validar1[30];
    char validar2[30];
    int k;
    int kk;
    do
                {
                    cout<<"\n\n";
                    cout<<"Turno Profesor Salazar - FICHA --> X" <<endl ;
                    if(turno==1 )
                    {
                        //
                        
                        do{
                        cout<<"\n";
                        cout<<"INGRESE COORDENADA VERTICAL --> A a la J --> ";
                        cin>>validar1;
                        k=(int)validar1[0]; //valor numerico de la letra segun el codigo ascii
                        kk=strlen(validar1);
      
                        if((k!=65 && k!=66 && k!=67 && k!=68 && k!=69 && k!=70 && k!=71 && k!=72 && k!=73 && k!=74) || kk!=1 )
                        {
                            cout<<"\n";
                            cout<<"***ERROR***\n";
                            cout<<"AL INGRESAR LETRA - PERMITIDAS DE A - J\n";
                        }
                        }while( (k!=65 && k!=66 && k!=67 && k!=68 && k!=69 && k!=70 && k!=71 && k!=72 && k!=73 && k!=74) || kk!=1);
                        y=k;
                          
                        
                         do{
                                cout<<"\n";
                                cout<<"INGRESE COORDENADA HORIZONTAL --> 0 al 9 ---> ";
                                cin>>validar2;
                                k=(int)validar2[0]; //k = al numero ingresado pero en representacion ascii
                                kk=strlen(validar2);
                                if(( k!=48 && k!=49 && k!=50 && k!=51 && k!=52 && k!= 53 && k!=54 && k!=55 && k!=56 && k!=57) || kk!=1 )
                                {
                                    cout<<"\n";
                                    cout<<"***ERROR***\n";
                                    cout<<"AL INGRESAR NUMERO - SOLO PERMITIDOS DE 1 AL 9 !!!\n";
                                }
                            }while(( k!=48 && k!=49 && k!=50 && k!=51 && k!=52 && k!= 53 && k!=54 && k!=55 && k!=56 && k!=57) || kk!=1);
                            x=k;
                        for(int ii=65;ii<=74;ii++) //TRANFORMACION DE LA LETRA EN ASCII , A HEXADECIMAL
                        {
                            
                            if(y==ii)
                            {
                                y=ct;
                            }
                            ct++;
                        }
                            ct=0;
                     }
                    
                    for(int ii=48 ; ii<=57 ;ii++) //TRANFORMACION DEL NUMERO EN ASCII , A HEXADECIMAL
                    {
                      if(x==ii)
                     {
                        x=ct1;
                     } 
                      ct1++;
                   }
                   ct1=0;
                    
                  if  (tablero[x][y]!='X'&&tablero[x][y]!='D')
                        {
                          letra=char (cambiarValor(y));
                          cout<<"\n";
                          cout<<"ERROR! \nNo hay ficha en la casilla-->  " <<letra<<"-"<<x<<endl;
                          cout<<"Intente Nuevamente\n";
                        }
                }while (tablero[x][y]!='X'&&tablero[x][y]!='D');
}

int main() 
{
    int seleccion ;//REPRESENTA LA SELECCION DEL MENU
    int idioma;
    char letra;
    int aux2;
    int ct;
    int ct1=0;
    char validar[30];
    int k;
    int kk;
    char validar1[30];
    int ct2=1;
      do{ 
          do{ //VALIDACION
             cout<<"SELECCIONE IDIOMA\n\n\n";
             cout<<"1)Español\n";
             cout<<"2)Ingles\n";
             cout<<"3)Portugues\n";
             cout<<"4)salir\n";
             cout<<"Su opcion: ";
             cin>>validar;
            
             k=(int)validar[0];
             kk=strlen(validar);
      
             if((k!=49 && k!=50 && k!=51 && k!=52) || kk!=1 )
             {
              cout<<"\n";
              cout<<"***ERROR AL INGRESAR NUMERO**\n";
              cout<<"SOLO SON PERMITIDOS NUMEROS DEL 1 AL 4\n";
            }
            }while((k!=49 && k!=50 && k!=51 && k!=52 )|| kk!=1);


           for(int ii=49 ; ii<=52 ;ii++) //TRANFORMACION DEL NUMERO EN ASCII , A HEXADECIMAL
           {
                if(k==ii)
               {
                  idioma=ct2;
               } 
                  ct2++;
           }
                   ct2=1;
                   system("clear");
         
                   
          switch(idioma)
          {
              case 1:
              {
                 do{
                      do{ //VALIDACION
                      cout<<"\n\n";
                      cout<< "BIENVENIDO AL JUEGO DE DAMAS DE INGENIERÍA DE SOFTWARE (beta 2.0)\n\n";
                      cout<<"MENU:\n";
                      cout<<"1)Jugar contra la computadora\n";
                      cout<<"2)Leer reglas e instrucciones de juego\n";
                      cout<<"3)Obtener datos de los desarroladores\n";
                      cout<<"4)Salir\n\n";
                      cout<<"Opcion: ";
                      cin>>validar1;
                      k=(int)validar1[0];
                      kk=strlen(validar1);
      
                if((k!=49 && k!=50 && k!=51 && k!=52) || kk!=1 )
                {
                cout<<"\n";
                cout<<"***ERROR AL INGRESAR NUMERO**\n";
                cout<<"SOLO SON PERMITIDOS NUMEROS DEL 1 AL 4\n";
                }
                }while((k!=49 && k!=50 && k!=51 && k!=52 )|| kk!=1);
                        
                for(int ii=49 ; ii<=52 ;ii++) //TRANFORMACION DEL NUMERO EN ASCII , A HEXADECIMAL
                {
                    if(k==ii)
                   {
                     seleccion=ct2;
                   } 
                      ct2++;
                   }
                   ct2=1;
                
                system("clear");
                         switch (seleccion)
                         {
                            case 1:
                            {
                                rellenarTablero();
                                mostrarTablero();
                            do{
                    
                   
                                    if(turno==1)
                                    {    
                                        preguntar();
                                       
                                       
                                    }
                                
                                    for (x=0;x<10;x++)// PARA IDENTIFICAR UNA DAMA
                                   {
                                      if(tablero[0][x]== 'X' )
                                      {
                                         tablero[0][x]='D';
                                         cout<<"\n";
                                         cout<<"TU FICHA SE A CONVERTIDO EN DAMA SE USARA LA LETRA -D- PARA REPRESENTARLA\n ";
                            
                                      }
                                  }
                    //system("clear");
                    
                    mostrarTablero() ;
                    
                    if (fichao==0)
                    {
                        cout<<"\n\n";
                        cout<<"JUEGO TERMINADO - Ganador Profesor  " ;
                        cout<<"\n\n";
                        cout<<"ESTADISTICAS:\n\n";
                        cout<<"FICHAS COMIDAS POR EL JUGADOR HUMANO--> "<<contador_x<<"\n";
                        cout<<"FICHAS COMIDAS POR EL COMPUTADOR---> "<<contador_o<<"\n";
                        cout<<"FICHAS SOPLADAS AL JUGADOR HUMANO--> "<<contador_s<<"\n";
                        cout<<"FICHAS SOPLADAS AL COMPUTADOR--> 0\n\n";
                        
                        terminar=2;
                        break;
                    }
                    
                    
                     //comerFicha();
                     //sopladita();
                    sopladita();  
                    comerFicha();
                    
                    if(turno==0)
                    {
                        
                        
                        
                       
                     }
                    
                    for (x=0;x<10;x++)// PARA IDENTIFICAR UNA DAMA
                    {
                        if(tablero[9][x]== 'O' )
                        {
                            tablero[9][x]='C';
                            cout<<"\n";
                            cout<<"LA COMPUTADORA SE A CORONADO -C- PARA REPRESENTARLA\n";
                            
                        }
                    }// FIN DE DAMAS
                    //system("clear");
                    // aca !cout<<"\t\t         ";
                    for (x=0;x<10;x++)// PARA IDENTIFICAR UNA DAMA
                    {
                        if(tablero[9][x]== 'O' )
                        {
                            tablero[9][x]='C';
                        }
                    }// FIN DE DAMAS
                    mostrarTablero() ;
                    if(fichaProfe==0)
                    {
                        cout<<"\n\n";
                        cout<<"JUEGO TERMINADO LA COMPUTADORA A GANADO ESTA PARTIDA ";
                        cout<<"ESTADISTICAS:\n\n";
                        cout<<"FICHAS COMIDAS POR EL JUGADOR HUMANO--> "<<contador_x<<"\n";
                        cout<<"FICHAS COMIDAS POR EL COMPUTADOR---> "<<contador_o<<"\n";
                        cout<<"FICHAS SOPLADAS AL JUGADOR HUMANO--> "<<contador_s<<"\n";
                        cout<<"FICHAS SOPLADAS AL COMPUTADOR--> 0\n\n";
                        terminar=2;
                        break;
                    }
                }while(terminar==1);
                break;
            }//FIN CASE MODO CONTRA LA COMPUTADORA
        
        case 2:
        {
            cout<<"\n\n";
            cout<<"INSTRUCCIONES:\n";
            cout<<"1)Eltablero cuenta con dimenciones de 10x10\n\n";
            cout<<"2)Solo se puede avanzar en diagonal, una casilla por turno\n\n";
            cout<<"3)Al momento de llegar a la ultima linea vertical, se coronara con una D\n  la dama del jugar humano, y en el caso contrario con una C la dama del a maquina\n\n";
            cout<<"4)El tablero se divide en coordenadas verticales representadas por letras de la A a la J\n\n";
            cout<<"5)Las coordenadas horizontales se representa del 0 al 9 cada casilla\n\n";
            cout<<"6)Para efectuar un movimiento se debe colocar la coordenada VERTICAL - HORIZONTAL  \nComo por ejemplo B enter 7\n\n";
            cout<<"7)una vez seleccionada la ficha, debe elegir entre la opcion 1)mover izquierda arriba 2)Mover Derecha arriba\n\n";
            cout<<"8)Si se llega a coronar una dama, podra moverse con las opciones 1) 2) 3) 4) , que saldran en la pantalla\n\n";
            cout<<"9)BUENA SUERTE !\n";
            break;
        }
        case 3:
        {
        
            cout<<"\n\n";
            cout<<"INTEGRANTES:\n";
            cout<<"Felipe Abarca Arias\n";
            cout<<"Jaime Quiñelen Villar\n";
            cout<<"Ignacio Ortega Bustamante\n\n\n";
            break;
        }
        case 4:
        {
            cout<<"Gracias Por Jugar, Hasta Pronto\n";
            exit(0);
            break;
            
            
        }    
       }
            
       }while (seleccion<=4&&seleccion>=1); 
     }
              case 2:
              {
                  do{
                    cout<<"\n\n";
                    cout<< "WELCOME LADIES GAME SOFTWARE ENGINEERING (beta 2.0) \n";
                    cout<<"MENU:\n";
                    cout<<"1)Play against the computer\n";
                    cout<<"2)Read game rules and instructions\n";
                    cout<<"3)Get data from programmers\n";
                    cout<<"4)exit\n\n";
                    cout<<"Opcion: ";
                    cin>>seleccion;
                    system("clear");
                    switch (seleccion)
                    {
                        case 1:
                        {
                            //se hace al final
                        }
            
            
        
        case 2:
        {
            cout<<"\n\n";
            cout<<"INSTRUCTIONS:\n";
            cout<<"1)The board has 10x10 dimenciones\n\n";
            cout<<"2)You can only move diagonally , one square per turn\n\n";
            cout<<"3)Upon reaching the last vertical line , was crowned with a D \n the lady of the human play, and in the opposite case with the lady C Machine\n\n";
            cout<<"4)The board is divided into vertical coordinates represented by letters A through J\n\n";
            cout<<"5)The horizontal coordinates is shown from 0 to 9 each box\n\n";
            cout<<"6)For movement to place the vertical coordinate - HORIZONTAL \n As such B enter 7 \n \n";
            cout<<"7)After selecting the tab, you must choose between option 1 ) move up left 2) Move Right Up\n\n";
            cout<<"8)If you come to crown a lady, could move with options 1) 2) 3) 4) , which will come out on the screen\n\n";
            cout<<"9)GOOD LUCK !\n";
            break;
        }
        case 3:
        {
        
            cout<<"\n\n";
            cout<<"MEMBERS:\n";
            cout<<"Felipe Abarca Arias\n";
            cout<<"Jaime Quiñelen Villar\n";
            cout<<"Ignacio Ortega Bustamante\n\n\n";
            break;
        }
        case 4:
        {
            cout<<"Thanks for playing , you soon\n";
            exit(0);
            break;
            
            
        }    
       }
            
       }while (seleccion<=4&&seleccion>=1);
     }
              
              case 3:
              {
                
                  do{
                        cout<<"\n\n";
                        cout<< "BEM-VINDOS DAMAS ENGINEERING SOFTWARE DE JOGO (beta 2.0) \n";
                        cout<<"CARDÁPIO:\n\n";
                        cout<<"1)Jogar contra o computador\n";
                        cout<<"2)Leia as regras e instruções do jogo\n";
                        cout<<"3)Obter dados de programadores\n";
                        cout<<"4)opção\n\n";
                        cout<<"Opcion: ";
                        cin>>seleccion;
                        system("clear");
                         switch (seleccion)
                         {
                            case 1:
                            {
                                
                            }
        
        case 2:
        {
            cout<<"\n\n";
            cout<<"INSTRUÇÕES:\n";
            cout<<"1)A placa tem 10x10 dimenciones\n\n";
            cout<<"2)Você só pode se mover na diagonal , um quadrado por turno\n\n";
            cout<<"3)Ao chegar à última linha vertical, foi coroado com um D \n a senhora do jogo humano , e, no caso oposto, com a senhora C Máquina\n\n";
            cout<<"4)O tabuleiro é dividido em coordenadas verticais representados pelas letras A a J\n\n";
            cout<<"5)As coordenadas horizontais é mostrado 0-9 cada caixa\n\n";
            cout<<"6)Para o movimento para colocar a coordenada vertical - HORIZONTAL \n as tal B introduzir 7\n\n";
            cout<<"7)Depois de seleccionar o separador , você deve escolher entre a opção 1 ) mover para cima esquerdo 2) Mova Right Up\n\n";
            cout<<"8)Se você vem para coroar uma senhora , poderia mover-se com as opções 1 ) 2) 3) 4), que vai sair na tela\n\n";
            cout<<"9)BOA SORTE !\n";
            break;
        }
        case 3:
        {
        
            cout<<"\n\n";
            cout<<"MEMBROS:\n";
            cout<<"Felipe Abarca Arias\n";
            cout<<"Jaime Quiñelen Villar\n";
            cout<<"Ignacio Ortega Bustamante\n\n\n";
            break;
        }
        case 4:
        {
            cout<<"Obrigado por jogar , você em breve\n";
            exit(0);
            break;
            
            
        } 
        
        
       }
            
       }while (seleccion<=4&&seleccion>=1); 
                  
     }
              case 4:
              {
                  cout<<"ADIOS ";
                  exit(0);
                  break;
              }    
                          
    }
          
    
      
       }while(idioma<=4&&idioma>=1);   
       return 0;
 }
