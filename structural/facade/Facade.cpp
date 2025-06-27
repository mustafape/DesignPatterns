#include <iostream>
#include <string>

// Subsystem 1
class CPU {
public:
    void start() { std::cout << "CPU started\n"; }
    void stop() { std::cout << "CPU stopped\n"; }
};

// Subsystem 2
class Memory {
public:
    void load(const std::string& data) { std::cout << "Memory loaded with: " << data << "\n"; }
    void clear() { std::cout << "Memory cleared\n"; }
};

// Subsystem 3
class HardDrive {
public:
    std::string read() { 
        std::cout << "Reading data from Hard Drive\n";
        return "OS files";
    }
    void shutdown() { std::cout << "Hard Drive shutdown\n"; }
};

// Facade
class ComputerFacade {
private:
    CPU m_cpu;
    Memory m_memory;
    HardDrive m_hardDrive;
public:
    void startComputer() {
        std::cout << "Starting computer...\n";
        m_cpu.start();
        std::string data = m_hardDrive.read();
        m_memory.load(data);
        std::cout << "Computer started\n";
    }
    void shutdownComputer() {
        std::cout << "Shutting down computer...\n";
        m_memory.clear();
        m_cpu.stop();
        m_hardDrive.shutdown();
        std::cout << "Computer shut down\n";
    }
};

int main() {
    ComputerFacade computer;
    computer.startComputer();
    std::cout << "----\n";
    computer.shutdownComputer();
    return 0;
}