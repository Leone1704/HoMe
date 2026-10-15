

public class Aufgabe2 {
    public static void main(String[] n) {

        int z = Integer.parseInt(n[0]);
        if(z < 2){
            System.out.println("---- Falsche Eingabe ----");
            return;
        }

        boolean[] markiert = new boolean[z + 1];

        for (int p = 2; p * p <= z; p++) {
            if (!markiert[p]) {
                for (int k = 2 * p; k <= z; k += p) {
                    markiert[k] = true;
                }
            }
        }

        System.out.print("Primzahlen bis " + z + ": ");
        for (int i = 2; i <= z; i++) {
            if (!markiert[i]) {
                System.out.print(i + " ");
            }
        }
        System.out.println();

        
    }
}
