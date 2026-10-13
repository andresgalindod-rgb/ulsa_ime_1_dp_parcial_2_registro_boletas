# Documentación del bloque

## 1. Autor

**Nombre:** Romeo Ramos
**Matrícula:** 26212
**Bloque y opción elegida:** [Número de bloque] - Cuadro de honor
**Archivo de código:** `include/honor.h`

## 2. Propósito

Mi bloque muestra el cuadro de honor del grupo: la lista de alumnos cuyo promedio es 9.0 o más, cada uno con su categoría (Excelencia si tiene 9.5 o más, Honor si tiene de 9.0 a 9.4) y al final cuántos alumnos entraron. Le sirve al maestro para saber de un vistazo quiénes son los mejores del grupo sin tener que calcular promedios a mano.

## 3. Entradas y salidas

**Entradas (parámetros):** los cuatro arreglos paralelos (`nombres`, `espanol`, `matematicas`, `disenoProgramas`) y `total`, el número de alumnos registrados. No lee nada del teclado.

**Salidas (lo que imprime):**
- Si la lista está vacía: `No hay alumnos registrados.`
- Si hay alumnos: un encabezado, una línea por cada alumno del cuadro con su nombre, promedio (1 decimal) y categoría, y al final `Alumnos en el cuadro de honor: N`.
- Si hay alumnos pero ninguno llega al umbral: `Ningun alumno alcanzo el cuadro de honor.`

No devuelve nada (`void`).

## 4. Decisiones de diseño

**¿Qué funciones tiene tu bloque y qué hace cada una?**

Una sola función, `cuadroDeHonor`, que recibe los cuatro arreglos y el total, calcula el promedio de cada alumno e imprime a los que entran al cuadro. Recibe los arreglos como `const` porque solo los lee y así el compilador impide modificarlos por error.

**¿Qué ciclo usaste y por qué ese?**

Un `for` de `0` a `total - 1`, porque sé exactamente cuántas veces se repite: una vez por alumno registrado. Uso `total` y no `MAX_ALUMNOS` para no leer posiciones vacías del arreglo.

**¿Qué acumuladores o contadores usaste y con qué valor inician?**

- `suma` (acumulador): junta las tres calificaciones de cada alumno. Se calcula de nuevo en cada vuelta del ciclo.
- `enCuadro` (contador): inicia en `0` y aumenta en 1 cada vez que un alumno entra al cuadro de honor.

**¿Dónde está tu decisión múltiple y qué casos cubre?**

Dentro del ciclo, un `if / else if`:
1. Promedio de 9.5 o más → Excelencia.
2. Promedio de 9.0 a 9.4 → Honor.
3. Menos de 9.0 → no se imprime.

El orden importa: primero pregunto por el umbral más alto. Si preguntara primero por 9.0, un alumno con 9.8 caería en Honor y nunca llegaría a Excelencia.

**¿Qué constantes definiste y por qué son constantes?**

- `UMBRAL_HONOR = 9.0`: promedio mínimo para entrar al cuadro.
- `UMBRAL_EXCELENCIA = 9.5`: promedio mínimo de la categoría más alta.
- `NUMERO_MATERIAS = 3`: entre cuánto se divide la suma.
- `ANCHO_NOMBRE_HONOR = 10`: ancho de la columna de nombres.

Son constantes porque su valor no cambia mientras corre el programa. Si el criterio cambia (por ejemplo, cuadro desde 8.5), se modifica en un solo lugar.

**¿Qué casos de rechazo maneja tu bloque y qué mensaje muestra en cada uno?**

- Lista vacía: `No hay alumnos registrados.` y regresa al menú.
- Ningún alumno llega al umbral: `Ningun alumno alcanzo el cuadro de honor.`

## 5. Receta

```
INICIO cuadroDeHonor(nombres, espanol, matematicas, disenoProgramas, total)
  SI total == 0 ENTONCES
      imprimir "No hay alumnos registrados."
      regresar
  FIN SI
  imprimir encabezado
  enCuadro = 0
  PARA i desde 0 hasta total-1
      suma = espanol[i] + matematicas[i] + disenoProgramas[i]
      promedio = suma / NUMERO_MATERIAS
      SI promedio >= UMBRAL_EXCELENCIA ENTONCES
          imprimir nombre, promedio, "Excelencia"
          enCuadro = enCuadro + 1
      SINO SI promedio >= UMBRAL_HONOR ENTONCES
          imprimir nombre, promedio, "Honor"
          enCuadro = enCuadro + 1
      FIN SI
  FIN PARA
  SI enCuadro == 0 ENTONCES
      imprimir "Ningun alumno alcanzo el cuadro de honor."
  SINO
      imprimir "Alumnos en el cuadro de honor: " enCuadro
  FIN SI
FIN
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Inserta aquí tu respuesta: cuando el equipo defina los 6 alumnos, calcula el promedio de cada uno y anota quiénes entran al cuadro.]

## 6. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | Al principio puse el `if` de 9.0 antes que el de 9.5, y nadie salía como Excelencia. | Cambié el orden: primero se pregunta por el umbral más alto. |
| 2 | El umbral se imprimía como `9` y no como `9.0`. | Puse `fixed` y `setprecision(1)` antes de imprimir el encabezado. |
| 3 | Con decimales como `9.1 + 8.9 + 9.0` la suma puede dar `26.9999...` y el alumno no entra aunque se vea `9.0`. | Lo anoté como regla en el README y en el escenario usamos calificaciones que no causan este problema. |
