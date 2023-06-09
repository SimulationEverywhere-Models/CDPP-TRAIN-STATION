Todos los procesadores tienen tproc=0.25 pero se han dejado habilitadas sólo 2 boleterías y 2 molinetes. Para lograr esto se inicializaron las poblaciones de los distribuidores en [0,0,100000,100000]. De esta manera se garantiza que las salidas 3 y 4 nunca son escogidas.
Además se introdujeron 2 ports de salida en los modelos: procesador de flujo de molinetes, moderador de flujo y top, para poder observar por separado la salida de cada uno de los molinetes.
Se observa que se cumple las reglas:
Demora (desfase) de la fase activa = tproc1 + tproc2
Caudal (dilatacion) de la fase activa Cd = n * 1/max(tproc1, tproc2)
Duración fase activa = Dp * Cp / Cd = Dp * Cp * max(tproc1, tproc2) / n

Demora = 0.5
En este caso el Caudal = 8
Duración fase activa = 12.5