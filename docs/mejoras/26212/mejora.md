# Propuesta de mejora

Propuesta de mejora elaborada por: Romeo Ramos

**Matrícula:** 26212
**Título de la propuesta:** Lista del grupo con promedio y estado

## 1. Impacto

Es una mejora. Hoy la opción "Mostrar lista" solo imprime las tres calificaciones de cada alumno. Para saber si un alumno va aprobado, el maestro tiene que calcular el promedio a mano y revisar las tres materias. Con esta mejora, la lista muestra además el promedio y el estado (Aprobado o Reprobado) de cada alumno, y al final cuántos aprobaron. Beneficia al maestro, que ve la situación de todo el grupo en una sola pantalla.

## 2. Qué implica en el diseño

- **Función `mostrarLista` (en `registro.h`):** cambia. Se agregan dos columnas, `Prom` y `Estado`. Se justifica porque la lista es lo que más se consulta y ahí es donde el dato es útil.
- **Arreglos:** no cambian. El promedio se calcula al momento con las tres calificaciones; guardarlo en un quinto arreglo duplicaría información.
- **Constantes:** no se agregan. Se usa `CALIFICACION_APROBATORIA`, que ya existe, para no repetir el 7.0 en el código.
- **Contador nuevo `aprobados`:** inicia en 0 y suma 1 por cada alumno que aprueba las tres materias, para imprimir un resumen al final.
- **Menú:** no cambia. La opción sigue siendo "Mostrar lista".

## 3. Receta

```
INICIO mostrarLista(nombres, espanol, matematicas, disenoProgramas, total)
  SI total == 0 ENTONCES
      imprimir "No hay alumnos registrados."
      regresar
  FIN SI
  imprimir "--- LISTA DEL GRUPO ---"
  imprimir encabezado: Nombre, Esp, Mat, DP, Prom, Estado          [CAMBIA]
  aprobados = 0                                                    [NUEVO]
  PARA i desde 0 hasta total-1
      promedio = (espanol[i] + matematicas[i] + disenoProgramas[i]) / 3      [NUEVO]
      SI espanol[i] >= CALIFICACION_APROBATORIA
         Y matematicas[i] >= CALIFICACION_APROBATORIA
         Y disenoProgramas[i] >= CALIFICACION_APROBATORIA ENTONCES          [NUEVO]
          estado = "Aprobado"                                                [NUEVO]
          aprobados = aprobados + 1                                          [NUEVO]
      SINO
          estado = "Reprobado"                                               [NUEVO]
      FIN SI
      imprimir (i+1), nombres[i], espanol[i], matematicas[i], disenoProgramas[i], promedio, estado   [CAMBIA]
  FIN PARA
  imprimir "Aprobados: " aprobados " de " total                    [NUEVO]
FIN
```
