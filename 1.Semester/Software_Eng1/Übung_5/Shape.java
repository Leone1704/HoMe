public abstract class Shape {
    public abstract double area();
    public abstract double perimeter();

    @Override
    public String toString() {
        return String.format("%s[area=%.2f, perimeter=%.2f]", this.getClass().getSimpleName(), area(), perimeter());
    }
}
