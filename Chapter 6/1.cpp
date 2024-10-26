#include <iostream>

class Transport {
public:
    virtual void move() const {
        std::cout << "Transport is moving" << std::endl;
    }
};

class LandTransport : virtual public Transport {
public:
    void drive() const {
        std::cout << "LandTransport is driving" << std::endl;
    }
};

class WaterTransport : virtual public Transport {
public:
    void sail() const {
        std::cout << "WaterTransport is sailing" << std::endl;
    }
};

class AmphibiousVehicle : public LandTransport, public WaterTransport {
public:
    void move() const override {
        std::cout << "AmphibiousVehicle is moving" << std::endl;
    }
};

int main() {
    AmphibiousVehicle av;
    av.move();
    av.drive();
    av.sail();
    return 0;
}
