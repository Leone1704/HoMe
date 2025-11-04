

public class Main {
    public static void main(String[] args) {
        // Test Point2D

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
        Point2D p1 = new Point2D(2.0, 3.0);
        Point2D p2 = p1.translate(1.0, -1.0);
        System.out.println("p1 = " + p1);
        System.out.println("p2 = p1.translate(1,-1) = " + p2);
        System.out.printf("distance p1->p2 = %.3f%n", p1.distanceTo(p2));

        // Test Rectangle
        Rectangle r = new Rectangle(new Point2D(0, 0), new Point2D(3, 2));
        System.out.println(r);
        System.out.println("width=" + r.width() + ", height=" + r.height());

        Rectangle r2 = Rectangle.fromCenter(new Point2D(1,1), 2.0, 4.0);
        System.out.println("r2 from center: " + r2);

        // Shapes: Circle and RectShape
        Shape[] shapes = new Shape[] {
            new Circle(new Point2D(0,0), 1.0),
            new RectShape(r),
            new RectShape(r2)
        };

        double totalArea = 0;
        double totalPerim = 0;
        for (Shape s : shapes) {
            System.out.println(s);
            totalArea += s.area();
            totalPerim += s.perimeter();
        }

        System.out.printf("Total area = %.3f, total perimeter = %.3f%n", totalArea, totalPerim);
    }
}
