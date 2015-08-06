# Damas
Juegos de damas en C++

MANUAL DE INSTRUCCIONES PARA EJECUTAR "JUEGO DE DAMAS"

1.- Clonar el proyecto con: git clone https://github.com/Software2015/Damas.git
2.- Dejarlo en el escritorio (o algun lugar facil de recordar)
3.- Dentro de la carpeta descargada abra otra llamada, "main.cpp"
4.- Abrir la terminal y ejecutar los siguientes comandos
    - cd Escritorio (en caso de que haya sido guardado en el escritorio)
    - cd Damas
    -cd damas
    Luego en la carpeta, colocar:
    - g++ main.cpp -o ejecutable 
    - luego:
    - ./ejecutable
    - Listo, ya podra jugar el juego de Damas Chilenas
    
    
    INSTRUCCIONES DE JUEGO
     1.-Una vez ejecutado el juego, debera elegir el idioma a jugar, los cuales son ingles y español
     2.-Luego se desplegara un menu con 4 opciones:
        
        1)Jugar
        2)Instrucciones
        3)Obtener nombres de programadores
        4)Salir
      
      3.- Usted parte jugando, y las fichas X son las que le pertenecen
      4.- El tablero esta dividido en coordenadas verticales, representadas por letras 
          mayusculas de la A a la J y coordenadas horizontales representadas del 0 al 9
      5.- Para seleccionar una ficha debe primero ingresar la coordenada vertical 
          con una letra MAYUSCULA , de la A a la J, de lo contrario le mostrara un error.
      6.- Posteriormente debe presionar la tecla enter
      7.- Luego debe seleccionar la coordenada horizontal, con un numero del 0 al 9
      8.- Si la ficha selecionada existe, le pedira seleccionar la direccion
          1)Izquierda
          2)Derecha
      9.-Luego de eso viene el turno de la computadora
     10.-Trascurrido el juego, si logra llegar a la ultima linea horizontal contraria a su punto de partida
        la computadora lo coronara con una dama, se usara a letra D para damas de las fichas X y con una C
        para damas de la ficha O
    11.-Si usted selecciona una dama, se desplegara un menu con 4 opciones para poder mover
        1)Izquierda - Arriba
        2)Derecha - Arriba
        3)Izquierda - Abajo
        4)Derecha -  Abajo
        
    12.-Debe presionar una opción
    13.-Posteriormente la computadora le pedira ingresar con la nueva coordenada de la Dama
    14.-Si todo sale bien, la dama se movera a su nueva casilla.
    15.-El juego termina cuando ya no hay mas fichas por comer
    16.-Una vez terminado el juego, se mostraran las estadisticas de juego, como:
        1)fichas ganadas
        2)fichas perdidas
        3)ficha sopladas
        4)etc
        
