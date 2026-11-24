# xv6 Lottery Scheduler

Planificador por lotería con boletos ponderados sobre xv6-riscv, con las llamadas al sistema `settickets` y `getpinfo`.

Proyecto final del curso de Sistemas Operativos.

## Requisitos
- Ubuntu o WSL2 con Ubuntu
- git, make, gcc-riscv64-linux-gnu, qemu-system-misc

## Instalación
    sudo apt install -y git make gcc-riscv64-linux-gnu qemu-system-misc
    git clone https://github.com/J0N4T4N1508/xv6-lottery-v2.git
    cd xv6-lottery-v2

## Compilación y ejecución
    make clean
    make qemu CPUS=1

Para salir de QEMU: Ctrl+A y luego X.

## Uso (dentro de xv6)
    lotterytest 30 20 10
    ticketstest

`lotterytest t1 t2 ...` crea un proceso por cada número de boletos y muestra el porcentaje de CPU recibido por cada uno.

## Pruebas
Ver `pruebas/casos_de_prueba.md` y las capturas en `pruebas/capturas/`.

## Documentación
Informe y presentación en `docs/`.

## Integrantes
- Jonatan Rony Huaman Palomino – @J0N4T4N1508 – LinkedIn: www.linkedin.com/in/jonatan-rony-huaman-palomino-90b62b39b
- Michael Walter Pacheco Quispe – @micha10110 – LinkedIn: www.linkedin.com/in/michael-walter-pacheco-quispe-ba461739b
