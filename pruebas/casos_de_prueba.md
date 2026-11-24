# Casos de prueba

| N.º | Caso | Entrada | Resultado esperado | Resultado obtenido | Evidencia |
|---|---|---|---|---|---|
| 1 | settickets válido | settickets(10) | Retorna 0 | Retorna 0 | pruebas/capturas/06_ticketstest.png |
| 2 | settickets inválido | settickets(0), settickets(-5) | Retorna -1 | Retorna -1 | pruebas/capturas/06_ticketstest.png |
| 3 | Dos procesos 1:3 | lotterytest 10 30 | ~25% y ~75% | 23% y 76% | pruebas/capturas/02_prueba_1_3.png |
| 4 | Tres procesos 3:2:1 | lotterytest 30 20 10 | ~50%, ~33%, ~17% | 53%, 31% y 15% | pruebas/capturas/03_prueba_3_2_1.png |
| 5 | Herencia en fork | hijo de proceso con 20 boletos | Hijo con 20 boletos | Hijo con 20 boletos | pruebas/capturas/06_ticketstest.png |
| 6 | Sin inanición | lotterytest 1 100 | Proceso de 1 boleto con ticks > 0 | Proceso de 1 boleto con ticks = 2 | pruebas/capturas/04_prueba_1_100.png |
| 7 | Boletos iguales | lotterytest 10 10 10 | ~33% cada uno | 34%, 33% y 32% | pruebas/capturas/05_prueba_10_10_10.png |
