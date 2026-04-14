import java.util.Objects;

public final class RectShape extends Shape {
    private final Rectangle rect;

    public RectShape(Rectangle r) {
        this.rect = Objects.requireNonNull(r, "rect must not be null");
    }

    @Override
    public double area() { return rect.area(); }

    @Override
    public double perimeter() { return rect.perimeter(); }

    @Override
    public String toString() { return String.format("RectShape[%s]", rect); }
}
