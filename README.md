# Proyecto de compilación de bibliotecas estáticas y dinámicas

Ejecuta los comandos que correspondan para que crear una biblioteca estática y una dinámica de tal forma que completes la estructura de directorios de abajo. Debes usar rutas relativas para tal efecto y no puedes usar el explorador de archivos para mover los archivos de lugar. Los archivos `main.cc` y `arith` requieren que agregues directivas de compilación.

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