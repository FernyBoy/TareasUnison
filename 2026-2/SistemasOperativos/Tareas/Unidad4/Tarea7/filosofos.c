/* Filósofos comiendo con archivos y locks (fcntl) en Linux.
 *   - Cada palillo es un archivo:  palillo0.dat ... palillo4.dat
 *   - Tomar un palillo = obtener un lock exclusivo (F_WRLCK) sobre su archivo
 *   - Cada filósofo es un proceso (fork)
 * Solución: orden jerárquico de recursos. Cada filósofo toma primero el
 * palillo de número menor y después el de número mayor.
 *
 * Compilar:  gcc -Wall -o filosofos filosofos.c
 * Ejecutar:  ./filosofos [rondas]
 * Para ver el deadlock (sin orden):  gcc -DSIN_ORDEN -o filosofos_sin_orden filosofos.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/wait.h>

#define N 5                 /* número de filósofos y de palillos */
#define RONDAS_DEFECTO 3    /* veces que come cada filósofo */

static long t0;             /* instante de inicio (milisegundos) */

/* Milisegundos transcurridos desde el inicio, para el registro. */
long ms(void) {
   struct timespec ts;
   clock_gettime(CLOCK_MONOTONIC, &ts);
   return ts.tv_sec * 1000L + ts.tv_nsec / 1000000L - t0;
}

void report_and_exit(const char* msg) {
   perror(msg);
   exit(-1);
}

/* Abre (o crea) el archivo que representa al palillo i. */
int abrir_palillo(int i) {
   char nombre[32];
   sprintf(nombre, "palillo%d.dat", i);
   int fd = open(nombre, O_RDWR | O_CREAT, 0666);
   if (fd < 0)
      report_and_exit("falló la apertura del palillo...");
   return fd;
}

/* Pone (F_WRLCK) o quita (F_UNLCK) el lock sobre todo el archivo.
 * F_SETLKW BLOQUEA al proceso hasta que el lock esté disponible. */
void cerrojo(int fd, short tipo) {
   struct flock lock;
   lock.l_type = tipo;
   lock.l_whence = SEEK_SET;
   lock.l_start = 0;
   lock.l_len = 0;           /* 0 = hasta el EOF (todo el archivo) */
   lock.l_pid = getpid();
   while (fcntl(fd, F_SETLKW, &lock) < 0)
      if (errno != EINTR)    /* si solo nos interrumpió una señal, reintenta */
         report_and_exit("fcntl falló al manejar el lock...");
}

/* Código de un filósofo (corre en su propio proceso). */
void filosofo(int id, int rondas) {
   int izq = id, der = (id + 1) % N;   /* palillos a su izquierda y derecha */
#ifdef SIN_ORDEN
   int primero = izq, segundo = der;   /* siempre izquierdo primero: hay ciclo */
#else
   int primero = izq < der ? izq : der;   /* el de menor número primero */
   int segundo = izq < der ? der : izq;
#endif
   int fd1 = abrir_palillo(primero);
   int fd2 = abrir_palillo(segundo);
   srand(getpid());

   for (int r = 1; r <= rondas; r++) {
      printf("[%5ld ms] Filósofo %d piensa\n", ms(), id);
      usleep(rand() % 300000);

      printf("[%5ld ms] Filósofo %d tiene hambre\n", ms(), id);
      cerrojo(fd1, F_WRLCK);                  /* toma el 1er palillo (espera si está ocupado) */
      printf("[%5ld ms] Filósofo %d tomó el palillo %d\n", ms(), id, primero);
      usleep(100000);                         /* tiempo entre tomar uno y el otro */
      cerrojo(fd2, F_WRLCK);                  /* toma el 2do palillo */
      printf("[%5ld ms] Filósofo %d tomó el palillo %d\n", ms(), id, segundo);

      printf("[%5ld ms] Filósofo %d COME (comida %d)\n", ms(), id, r);
      usleep(200000 + rand() % 200000);       /* sección crítica: come */
      printf("[%5ld ms] Filósofo %d TERMINA de comer\n", ms(), id);

      cerrojo(fd2, F_UNLCK);                  /* suelta los palillos */
      cerrojo(fd1, F_UNLCK);
   }
   close(fd1);
   close(fd2);
}

int main(int argc, char* argv[]) {
   int rondas = (argc > 1) ? atoi(argv[1]) : RONDAS_DEFECTO;
   struct timespec ts;
   clock_gettime(CLOCK_MONOTONIC, &ts);
   t0 = ts.tv_sec * 1000L + ts.tv_nsec / 1000000L;
   setvbuf(stdout, NULL, _IOLBF, 0);           /* una línea completa por escritura */

   for (int i = 0; i < N; i++)                 /* crea los archivos-palillo */
      close(abrir_palillo(i));

   for (int i = 0; i < N; i++) {               /* un proceso por filósofo */
      pid_t pid = fork();
      if (pid < 0)
         report_and_exit("falló fork...");
      if (pid == 0) {
         filosofo(i, rondas);
         exit(0);
      }
   }
   for (int i = 0; i < N; i++)                 /* espera a que todos terminen */
      wait(NULL);

   printf("[%5ld ms] Todos los filósofos terminaron.\n", ms());
   return 0;
}
