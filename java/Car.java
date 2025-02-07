// Car.java
public class Car {
    private String brand;
    private String model;
    private int horsepower;
    private boolean hasTurbo;
    private boolean hasOffroadMode;

    private Car(CarBuilder builder) {
        this.brand = builder.brand;
        this.model = builder.model;
        this.horsepower = builder.horsepower;
        this.hasTurbo = builder.hasTurbo;
        this.hasOffroadMode = builder.hasOffroadMode;
    }

    public void displayInfo() {
        System.out.println("Car: " + brand + " " + model + ", Horsepower: " + horsepower);
        if (hasTurbo) {
            System.out.println("Turbo: Yes");
        }
        if (hasOffroadMode) {
            System.out.println("Off-road Mode: Enabled");
        }
    }

    // Builder Class
    public static class CarBuilder {
        private String brand;
        private String model;
        private int horsepower;
        private boolean hasTurbo;
        private boolean hasOffroadMode;

        public CarBuilder(String brand, String model, int horsepower) {
            this.brand = brand;
            this.model = model;
            this.horsepower = horsepower;
        }

        public CarBuilder setTurbo(boolean hasTurbo) {
            this.hasTurbo = hasTurbo;
            return this;
        }

        public CarBuilder setOffroadMode(boolean hasOffroadMode) {
            this.hasOffroadMode = hasOffroadMode;
            return this;
        }

        public Car build() {
            return new Car(this);
        }
    }
}

// Main.java (to test)
public class Main {
    public static void main(String[] args) {
        Car car = new Car.CarBuilder("Toyota", "Corolla", 120).build();
        Car sportCar = new Car.CarBuilder("Ferrari", "488", 670).setTurbo(true).build();
        Car fourByFour = new Car.CarBuilder("Jeep", "Wrangler", 285).setOffroadMode(true).build();

        car.displayInfo();
        System.out.println();
        sportCar.displayInfo();
        System.out.println();
        fourByFour.displayInfo();
    }
}