#include <iostream>

class Instrument {
public:
    virtual void play() const {
        std::cout << "Instrument is playing" << std::endl;
    }
};

class StringInstrument : virtual public Instrument {
public:
    void tune() const {
        std::cout << "StringInstrument is tuning" << std::endl;
    }
};

class PercussionInstrument : virtual public Instrument {
public:
    void hit() const {
        std::cout << "PercussionInstrument is hitting" << std::endl;
    }
};

class DrumGuitar : public StringInstrument, public PercussionInstrument {
public:
    void play() const override {
        std::cout << "DrumGuitar is playing" << std::endl;
    }
};

int main() {
    DrumGuitar dg;
    dg.play();
    dg.tune();
    dg.hit();
    return 0;
}
