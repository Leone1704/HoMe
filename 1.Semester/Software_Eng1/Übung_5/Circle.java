import java.util.Objects;

public final class Circle extends Shape {
    private final Point2D center;
    private final double r;

    public Circle(Point2D c, double r) {
        this.center = Objects.requireNonNull(c, "center must not be null");
        if (r <= 0) throw new IllegalArgumentException("radius must be > 0");
        this.r = r;
    }

    @Override
    public double area() { return Math.PI * r * r; }

    @Override
    public double perimeter() { return 2 * Math.PI * r; }

    public Point2D getCenter() { return center; }
    public double getRadius() { return r; }

    @Override
    public String toString() {
        return String.format("Circle[center=%s, r=%.2f, area=%.2f, perimeter=%.2f]", center, r, area(), perimeter());
    }
}
