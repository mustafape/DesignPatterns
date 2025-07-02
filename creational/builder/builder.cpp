#include <iostream>
#include <string>
#include <memory>

// Product
class Laptop {
private:
    std::string m_cpu;
    std::string m_ram;
    std::string m_storage;
    std::string m_gpu;
public:
    void setCPU(const std::string& cpu) { m_cpu = cpu; }
    void setRAM(const std::string& ram) { m_ram = ram; }
    void setStorage(const std::string& storage) { m_storage = storage; }
    void setGPU(const std::string& gpu) { m_gpu = gpu; }

    void showSpecs() const {
        std::cout << "Laptop Specs:\n";
        std::cout << " CPU: " << m_cpu << "\n";
        std::cout << " RAM: " << m_ram << "\n";
        std::cout << " Storage: " << m_storage << "\n";
        std::cout << " GPU: " << m_gpu << "\n";
    }
};

// Abstract Builder
class LaptopBuilder {
public:
    virtual ~LaptopBuilder() = default;
    void createNewLaptop() { laptop_ = std::make_unique<Laptop>(); }
    std::unique_ptr<Laptop> getLaptop() { return std::move(laptop_); }

    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual void buildGPU() = 0;
protected:
    std::unique_ptr<Laptop> laptop_;
};

// Concrete Builder for Gaming Laptop
class GamingLaptopBuilder : public LaptopBuilder {
public:
    void buildCPU() override { laptop_->setCPU("Intel Core i9"); }
    void buildRAM() override { laptop_->setRAM("32GB DDR5"); }
    void buildStorage() override { laptop_->setStorage("2TB NVMe SSD"); }
    void buildGPU() override { laptop_->setGPU("NVIDIA RTX 4090"); }
};

// Concrete Builder for Business Laptop
class BusinessLaptopBuilder : public LaptopBuilder {
public:
    void buildCPU() override { laptop_->setCPU("Intel Core i7"); }
    void buildRAM() override { laptop_->setRAM("16GB DDR4"); }
    void buildStorage() override { laptop_->setStorage("1TB SSD"); }
    void buildGPU() override { laptop_->setGPU("Integrated Graphics"); }
};

// Director
class LaptopDirector {
private:
    LaptopBuilder* m_builder;
public:
    void setBuilder(LaptopBuilder* builder) { m_builder = builder; }
    std::unique_ptr<Laptop> construct() {
        m_builder->createNewLaptop();
        m_builder->buildCPU();
        m_builder->buildRAM();
        m_builder->buildStorage();
        m_builder->buildGPU();
        return m_builder->getLaptop();
    }
};

int main() {
    LaptopDirector director;

    GamingLaptopBuilder gamingBuilder;
    director.setBuilder(&gamingBuilder);
    auto gamingLaptop = director.construct();
    std::cout << "Gaming Laptop:\n";
    gamingLaptop->showSpecs();
    std::cout << "\n";

    BusinessLaptopBuilder businessBuilder;
    director.setBuilder(&businessBuilder);
    auto businessLaptop = director.construct();
    std::cout << "Business Laptop:\n";
    businessLaptop->showSpecs();

    return 0;
}