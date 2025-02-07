// Car.java
public class Car {
    protected String brand;
    protected String model;
    protected int horsepower;

    public Car(String brand, String model, int horsepower) {
        this.brand = brand;
        this.model = model;
        this.horsepower = horsepower;
    }

    public void displayInfo() {
        System.out.println("Car: " + brand + " " + model + ", Horsepower: " + horsepower);
    }
}

// SportCar.java
public class SportCar extends Car {
    private boolean hasTurbo;

    public SportCar(String brand, String model, int horsepower, boolean hasTurbo) {
        super(brand, model, horsepower);
        this.hasTurbo = hasTurbo;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Turbo: " + (hasTurbo ? "Yes" : "No"));
    }
}

// FourByFour.java
public class FourByFour extends Car {
    private boolean hasOffroadMode;

    public FourByFour(String brand, String model, int horsepower, boolean hasOffroadMode) {
        super(brand, model, horsepower);
        this.hasOffroadMode = hasOffroadMode;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Off-road Mode: " + (hasOffroadMode ? "Enabled" : "Disabled"));
    }
}

// Main.java (to test)
public class Main {
    public static void main(String[] args) {
        Car car = new Car("Toyota", "Corolla", 120);
        SportCar sportCar = new SportCar("Ferrari", "488", 670, true);
        FourByFour fourByFour = new FourByFour("Jeep", "Wrangler", 285, true);

        car.displayInfo();
        System.out.println();
        sportCar.displayInfo();
        System.out.println();
        fourByFour.displayInfo();
    }
}


car 

