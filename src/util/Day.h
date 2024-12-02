#ifndef DAY_H
#define DAY_H

#include <iostream>
#include <string>
#include <fstream>

class Day {
private:
    std::string   m_inputFolder { "./src/inputs/" };
    std::ifstream m_input;

public:
    Day(std::string file) {
        m_input.open(m_inputFolder + file);
        if (!m_input) std::cerr << "failed to open file " << m_inputFolder << file;
    };

    ~Day() {
        m_input.close();
    };

    inline void run() {
        std::cerr << "No implementation for void run() found\n";
    }

    inline std::ifstream& getInput() {
        return m_input;
    }
};

#endif
