#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Sensor {
public:
    Sensor(const std::string& name, double value)
        : name(name), value(value) {}

    const std::string& getName() const {
        return name;
    }

    double getValue() const {
        return value;
    }

private:
    std::string name;
    double value;
};

class SensorMonitor {
public:
    void addReading(const std::string& name, double value) {
        readings.emplace_back(name, value);
    }

    double average() const {
        if (readings.empty()) {
            return 0.0;
        }

        double total = 0.0;

        for (const auto& reading : readings) {
            total += reading.getValue();
        }

        return total / readings.size();
    }

    void printReport() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Sensor Report\n";
        std::cout << "=============\n";

        for (const auto& reading : readings) {
            std::cout << reading.getName() << " : " << reading.getValue() << std::endl;
        }

        std::cout << "=============\n";
        std::cout << "Average Value: " << average() << std::endl;
    }

private:
    std::vector<Sensor> readings;
};

int main() {
    SensorMonitor monitor;

    monitor.addReading("Temperature", 22.80);
    monitor.addReading("Humidity", 48.50);
    monitor.addReading("Pressure", 1013.40);
    monitor.addReading("Light", 640.00);

    monitor.printReport();

    return 0;
}
