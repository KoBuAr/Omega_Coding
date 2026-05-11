import java.util.function.*;
import java.util.*;

public class j1 {

    // Excepción ligera para simular break
    // "noinspection" le dice al IDE que no marque esto como error de estilo
    @SuppressWarnings("serial")
    private static final class BreakException extends RuntimeException {
        // fillInStackTrace() en false = más rápido, no necesitamos el rastro de error
        BreakException() { super(null, null, true, false); }
    }

    // Token que pasas en vez de un valor para hacer break
    public static final Object BREAK    = new Object();
    public static final Object CONTINUE = new Object();

    // ── fore con break/continue ──────────────────────────────────────────────
    // Usamos Function<Integer, Object> para que la lambda pueda devolver
    // BREAK o CONTINUE como señales, o null para "sigue normal"
    public static void fore(int inicio, int fin, Function<Integer, Object> accion) {
        try {
            for (int i = inicio; i < fin; i++) {
                Object señal = accion.apply(i);
                if      (señal == BREAK)    throw new BreakException();
                else if (señal == CONTINUE) continue;
            }
        } catch (BreakException e) {
            // break detectado, salimos limpiamente
        }
    }

    // ── Sobrecarga simple (sin break/continue, más limpia para casos simples) ─
    public static void fore(int inicio, int fin, IntConsumer accion) {
        for (int i = inicio; i < fin; i++) {
            accion.accept(i);
        }
    }

    // ── pf: print flexible con salto de línea al final ───────────────────────
    public static void pf(Object... cosas) {
        for (Object c : cosas) System.out.print(c);
        System.out.println();
    }

    // ── main de prueba ────────────────────────────────────────────────────────
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();

        pf("Número: ", n, " Cuadrado: ", n * n);
        System.out.println();

        // Ejemplo con break y continue
        fore(0, n + 1, i -> {
            int a = cin.nextInt();

            if (a == 0)  return BREAK;    // sale del for completo
            if (a != 2)  return CONTINUE; // salta a la siguiente iteración
            
            pf("give me a two, i = ", i);
            return null; // sigue normal
        });

        cin.close();
    }
}