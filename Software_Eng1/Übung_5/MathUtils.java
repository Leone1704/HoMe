public class MathUtils {
    public static double roundTo(double x, int n){
        if (n < 0) {
            throw new IllegalArgumentException("Die Anzahl der Dezimalstellen muss größer oder gleich 0 sein.");
        } else {
        double faktor = Math.pow(10, n);
        return Math.round(x * faktor) / faktor; //Multipliziere die Zahl x mit 10 hoch n, runde das Ergebnis auf die nächste Ganzzahl und dividiere es dann wieder durch 10 hoch n, um die Zahl auf n Dezimalstellen zu runden.
        }
    }

    public static  double norm2(double x, double y){
        return Math.sqrt(x*x + y*y); //Berechnet die euklidische Norm (Länge) eines Vektors im 2D-Raum mit den Komponenten x und y. Basically Kreuzprodukt
    }

    public static boolean isLeapYear(int year) {
        if (year % 4 != 0) {
            return false; // Kein Schaltjahr, wenn nicht durch 4 teilbar
        } else if (year % 100 != 0) {
            return true; // Schaltjahr, wenn durch 4 teilbar, aber nicht durch 100
        } else if (year % 400 != 0) {
            return false; // Kein Schaltjahr, wenn durch 100 teilbar, aber nicht durch 400
        } else {
            return true; // Schaltjahr, wenn durch 400 teilbar
        }
    }


    public static void main(){
    double zahl = 3.14159;
    int stellen = 3;
    double laenge1 = 3.0;
    double laenge2 = 4.0;
    double gerundet = MathUtils.roundTo(zahl, stellen);
    System.out.println("Die Zahl " + zahl + " gerundet auf " + stellen + " Stellen ist: " + gerundet);
    double norm = MathUtils.norm2(laenge1, laenge2);
    System.out.println("Die euklidische Norm des Vektors mit den Komponenten " + laenge1 + " und " + laenge2 + " ist: " + norm);
    int jahr = 2020;
    boolean schaltjahr = MathUtils.isLeapYear(jahr);  
    System.out.println("Ist das Jahr " + jahr + " ein Schaltjahr? " + schaltjahr);
    }
    // Die meißten Werte haben hier eine Begrenzung (z.B. n >= 0 bei roundTo), um ungültige Eingaben zu vermeiden oder double kann auch nur eine bestimmte Menge an Nachkommastellen genau darstellen.
    //Erklären Sie auch die Bedeutung des static-Modifiers. --> Der static-Modifier bedeutet, dass die Methode oder Variable zur Klasse selbst gehört und nicht zu einer Instanz der Klasse. Das bedeutet, dass Sie auf statische Methoden und Variablen zugreifen können, ohne ein Objekt der Klasse zu erstellen. In diesem Fall können die Methoden in MathUtils direkt über den Klassennamen aufgerufen werden, z.B. MathUtils.roundTo(...), ohne dass eine Instanz von MathUtils erstellt werden muss.

}