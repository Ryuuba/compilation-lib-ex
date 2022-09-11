# Proyecto de compilación de bibliotecas estáticas y dinámicas

Ejecuta los comandos que correspondan para que crear una biblioteca estática y una dinámica de tal forma que completes la estructura de directorios de abajo. Debes usar rutas relativas para tal efecto y no puedes usar el explorador de archivos para mover los archivos de lugar. Los archivos `main.cc` y `arith` requieren que agregues directivas de compilación, así como las implementaciones de las funciones declaradas en el archivo de cabecera.

## Estructura de directorios
```
C:.
│   README.md
│
├───app
│       main.cc
|       static.exe
|       dynamic.exe
│
├───include
│       arith
│
├───lib
│   ├───dll
│   │       arith.dll
│   │
│   └───static
│           arith.lib
│
├───obj
│       addition.o
│       division.o
│       modulo.o
│       multiplication.o
│       preinc.o
│       pstinc.o
│       subtraction.o
│
└───src
        addition.cc
        division.cc
        modulo.cc
        multiplication.cc
        preinc.cc
        pstinc.cc
        subtraction.cc
```

## Evaluación

Si el proyecto no puede ser compilado por el alumno, entonces se restan cinco puntos a la calificación que ya se tiene asignada en I7. Por cada error o requisito no satisfecho, se resta un punto de I7 hasta restar cinco puntos. Un posible error podría ser no agregar las directivas de compilación en donde corresponda. Un requisito no satisfecho puede ser, por ejemplo, el no crear uno de los archivos descritos en el estructura de directorio.

## Comandos para compilar la biblioteca

### Creación de objetos

Cada uno de los siguientes comandos crea el código máquina de la implementación de las funciones declaradas en el archivo `.\include\arith`.

```bash
g++ .\src\addition.cc -c -o .\obj\addition.o -I .\include\ -FPIC  
g++ .\src\subtraction.cc -c -o .\obj\subtraction.o -I .\include\ -FPIC
g++ .\src\multiplication.cc -c -o .\obj\multiplication.o -I .\include\ -FPIC
g++ .\src\division.cc -c -o .\obj\division.o -I .\include\ -FPIC
g++ .\src\modulo.cc -c -o .\obj\modulo.o -I .\include\ -FPIC
g++ .\src\preinc.cc -c -o .\obj\preinc.o -I .\include\ -FPIC
g++ .\src\pstinc.cc -c -o .\obj\pstinc.o -I .\include\ -FPIC
```

### Creación de biblioteca estática

El código máquina de la biblioteca estática se enlaza con el código máquina de la función `main` una vez que el ejecutable se crea.

```bash
ar crs .\lib\static\arith.lib .\obj\*.o 
```

### Creación de biblioteca dinámica

El código máquina de la biblioteca dinámica se enlaza con el código máquina de la función `main` una vez que el programa se ejecuta.

```bash
g++ --shared .\obj\*.o -o .\lib\dll\arith.dll
```

### Compilación de ejecutable

Para compilar el ejecutable mediante la biblioteca estática, se ejecuta el siguiente comando. El programa resultante del proceso de compilación contiene el código máquina de la biblioteca estática.

```bash
g++ .\app\main.cc -o .\app\static -I .\include -L .\lib\static\ -l arith 
```

Para compilar el ejecutable mediante la biblioteca dinámica, se ejecuta el siguiente comando. El programa que resulta del proceso de compilación **no** contiene el código máquina de las funciones de la biblioteca `arith`, sino que éste se enlaza hasta que el programa se ejecuta. El sistema operativo es quien se encarga de hacer el enlace. Es importante que el archivo DLL se encuentre en el mismo directorio que el ejecutable o que se encuentre alojado en el directorio SYSTEM32 para que el programa pueda ser correctamente ejecutado.

```bash
g++ .\app\main.cc -o .\app\dynamic -I .\include -L .\lib\dll\ -l arith 
```
