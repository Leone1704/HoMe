import java.util.Objects;

public final class Rectangle {
    private final Point2D bl; // bottom-left
    private final Point2D tr; // top-right

    public Rectangle(Point2D bl, Point2D tr) {
        this.bl = Objects.requireNonNull(bl, "bl must not be null");
        this.tr = Objects.requireNonNull(tr, "tr must not be null");
        if (tr.getX() <= bl.getX() || tr.getY() <= bl.getY()) {
            throw new IllegalArgumentException("tr must be strictly to the top-right of bl (tr.x>bl.x and tr.y>bl.y)");
        }
    }

    public double width() { return tr.getX() - bl.getX(); }
    public double height() { return tr.getY() - bl.getY(); }
    public double area() { return width() * height(); }
    public double perimeter() { return 2 * (width() + height()); }

    public boolean contains(Point2D p) {
        Objects.requireNonNull(p, "p must not be null");
        return p.getX() >= bl.getX() && p.getX() <= tr.getX()
            && p.getY() >= bl.getY() && p.getY() <= tr.getY();
    }

    public static Rectangle fromCenter(Point2D c, double w, double h) {
        Objects.requireNonNull(c, "center must not be null");
        if (w <= 0 || h <= 0) throw new IllegalArgumentException("width and height must be > 0");
        double halfW = w / 2.0;
        double halfH = h / 2.0;
        Point2D bl = c.translate(-halfW, -halfH);
        Point2D tr = c.translate(halfW, halfH);
        return new Rectangle(bl, tr);
    }

    @Override
    public String toString() {
        return String.format("Rectangle[bl=%s, tr=%s, w=%.2f, h=%.2f]", bl, tr, width(), height());
    }
}
