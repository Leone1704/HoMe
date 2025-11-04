public class Basic {
    public static void main() {
        byte fensterOffenAnzahl;    fensterOffenAnzahl = 2;
        short AnzahlLampen = 14;
        int verbrauchHeuteWh = 3260;
        long  gesamtVerbrauchWh = 124875L;
        float temperaturInnen = 21.5f;
        double temperaturAussen = 16.73;
        char modusSymbol = 'h';
        boolean  bewegungErkannt = true;
        String raumName = "Wohnzimmer";
        double TempDifferenz = temperaturInnen - temperaturAussen;
        long NewGesamtVerbrauchWh = gesamtVerbrauchWh + verbrauchHeuteWh;
        int uhrzeit = 19;
        if (temperaturInnen > 22.0) {
            System.out.println("Temperatur innen ist zu hoch!\n");
        } else {
            System.out.println("Temperatur innen ist in Ordnung oder zu niedrig.\n");
        }
        if (temperaturAussen > temperaturInnen) {
            System.out.println("Es ist draussen wärmer als drinnen.\n");
        } else {
            System.out.println("Es ist draussen kälter als drinnen.\n");
        }
        if (temperaturInnen < 20 && fensterOffenAnzahl == 0) {
            System.out.println("Heizung an\n");
        }   else {
            System.out.println("Es ist warm genug!\n");
        }
        if (bewegungErkannt = true || uhrzeit >= 18 ) {
            System.out.println("Heureka, es werde Licht\n");
        }   else {
            System.out.println("Es ist noch hell genug\n!");
        }
        System.out.println("Raum: " + raumName + ", Innen:" + temperaturInnen + " °C, Außen: " + temperaturAussen + " °C\nBrrr, es ist zu kalt, mach bitte die Heizung an " + modusSymbol + " Jetzt ist sie an\n");
    }
}