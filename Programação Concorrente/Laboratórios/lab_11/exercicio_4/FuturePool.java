/* Disciplina: Programacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Laboratório: 11 */
/* Atividade 4: Retornando a quantidade de numeros primos no intervalo de 1 a N */
/* -------------------------------------------------------------------*/

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import java.util.ArrayList;
import java.util.List;


//classe runnable
class MyCallable implements Callable<Long> {
  //construtor
  MyCallable() {}
 
  //método para execução
  @Override
  public Long call() throws Exception {
    long s = 0;
    for (long i=1; i<=100; i++) {
      s++;
    }
    return s;
  }
}

class Primo implements Callable<Long>{
  private final long numero;
  public Primo(long n){ this.numero = n; }
  private boolean ehPrimo(long n){ 
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long i = 3; i < Math.sqrt(n) + 1; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
  }
  public Long call() throws Exception{
    long aux = 0;
    if (ehPrimo(numero)) aux++;
    return aux;
  }
  //private Integer run() throws Exception{}
}

//classe do método main
public class FuturePool  {
  private static final int N = 1000001;
  private static final int NTHREADS = 10;

  @SuppressWarnings("CallToPrintStackTrace")
  public static void main(String[] args) {
    //cria um pool de threads (NTHREADS)
    ExecutorService executor = Executors.newFixedThreadPool(NTHREADS);
    //cria uma lista para armazenar referencias de chamadas assincronas
    List<Future<Long>> list = new ArrayList<>();

    for (int i = 1; i <= N; i++) {
      Callable<Long> primo = new Primo(i);
      /*submit() permite enviar tarefas Callable ou Runnable e obter um objeto Future para acompanhar o progresso e recuperar o resultado da tarefa
       */
      Future<Long> submit = executor.submit(primo);
      list.add(submit);
    }

    System.out.println(list.size());
    //pode fazer outras tarefas...

    //recupera os resultados e faz o somatório final
    long sum = 0;
    for (Future<Long> future : list) {
      try {
        sum += future.get(); //bloqueia se a computação nao tiver terminado
      } catch (InterruptedException | ExecutionException e) {
        e.printStackTrace();
      }
    }
    System.out.println(sum);
    executor.shutdown();
  }
}
