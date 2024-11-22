#include <iostream>

class Performer {
public:
    virtual void perform() const {
        std::cout << "Performer is performing" << std::endl;
    }
};

class SoloArtist : virtual public Performer {
public:
    void singSolo() const {
        std::cout << "SoloArtist is singing solo" << std::endl;
    }
};

class Band : virtual public Performer {
public:
    void playTogether() const {
        std::cout << "Band is playing together" << std::endl;
    }
};

class SuperBand : public SoloArtist, public Band {
public:
    void perform() const override {
        std::cout << "SuperBand is performing" << std::endl;
    }
};

int main() {
    SuperBand sb;
    sb.perform();
    sb.singSolo();
    sb.playTogether();
    return 0;
}
