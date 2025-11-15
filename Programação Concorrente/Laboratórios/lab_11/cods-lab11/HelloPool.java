/* Disciplina: Programacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Laboratório: 11 */
/* Codigo: usando um pool de threads em Java com a interface ExecutorService e a classe Executors */

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

//--PASSO 1: criar uma classe que implementa a interface Runnable 
class Hello implements Runnable {
   String msg;
   public Hello(String m) { msg = m; }

   //--metodo executado pela thread
   public void run() {
      System.out.println(msg); 
   }
}

//--classe do metodo main
class HelloPool {
   private static final int NTHREADS = 10;

   public static void main(String[] args) {
      //--PASSO 2: criar o pool de threads
      ExecutorService pool = Executors.newFixedThreadPool(NTHREADS);

      //--PASSO 3: disparar a execução dos objetos runnable usando o pool de threads
      for (int i = 0; i < 25; i++) {
        final String m = "Hello da tarefa " + i;
        Runnable r = new Hello(m);
        pool.execute(r);
      }
      //--PASSO 4: encerrar o pool de threads
      //termina a execução das threads no pool (não permite que o executor aceite novos objetos)
      pool.shutdown();
      //espera todas as threads terminarem
      while (!pool.isTerminated()) {}
      System.out.println("Terminou");
   }
}
