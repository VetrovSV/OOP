// Разбор аргументов командной строки
// Вычислить Пи методом Монте-Карло
import scala.util.Random;
import scala.io.StdIn.readLine;

def calc_pi( n: Int) =
  var inside: Int = 0
  val rnd:Random = Random();
  for ( i <- 1 to n)
      val x = rnd.nextFloat()
      val y = rnd.nextFloat()
      if (x*x + y*y <= 1.0)
          inside+=1

  1.0*inside/n*4

@main
def main(args: String): Unit = {
  val USAGE = "help...";
//  if (args.length == 0) println(USAGE)
  
  println(args);
  println( calc_pi(1_000_000) )
}