# CAJERO TUANI

Cajero tuani no es nada mas que la implementacion del cajero pero con archivos csv para el lectura/escritura de informacion.

## Uso

El uso es sencillo, solo es seguir los pasos que te ofrece el cajero y su ejecucion no deberia tener ningun problema.

Pin debe ser de 4 digitos, sino es un mal uso.

Si quiere ejecutarse debe de poner los paths a los archivos csv, preferiblemente ponganlo en el mismo directorio para mas orden:
Usage: main.exe accounstsPath.csv movementsPath.csv tempPath.csv

Puede consultar segun la cuenta ingresada(cuentas en acconts.csv), depositar una cantidad cualquiera(entera) de dinero, retirar dependiendo de la cantidad de billetes en el cajero(default 10 billetes de cada nomina), y ver movimientos hechos en el cajero.

## Codigo

Los datos guardados son globales, asi que se guardan en los csv incluso de ejecuciones antiguas, se pueden modificar manualmente para cambiar cuentas y movimientos.

En main esta la ejecucion principal del programa y en cajero.c/.h estan los utilities utilizadas por el programa.

## Compilacion

Si se quiere compilar el programa ajustar el path de los utilities.h en cajero.h desde donde se utilizan un par de funciones (se puede ajustar tanto de forma absoluta como relativa al workspace). Y luego ejecutar este comando (yo uso gcc): gcc -o cajero.exe main.c cajero.c utilities.c
