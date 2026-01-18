#include <iostream>
#include <vector>
#include <memory>

// Abstract Iterator
template <typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
};

// Concrete Iterator
template <typename T>
class VectorIterator : public Iterator<T> {
private:
    const std::vector<T>& m_collection;
    size_t m_index = 0;

public:
    explicit VectorIterator(const std::vector<T>& col) : m_collection(col) {}

    bool hasNext() const override {
        return m_index < m_collection.size();
    }

    T next() override {
        return m_collection[m_index++];
    }
};

// Abstract Collection
template <typename T>
class Collection {
public:
    virtual ~Collection() = default;
    virtual std::unique_ptr<Iterator<T>> createIterator() = 0;
};

// Concrete Collection
template <typename T>
class VectorCollection : public Collection<T> {
private:
    std::vector<T> m_items;

public:
    void add(const T& item) {
        m_items.push_back(item);
    }

    std::unique_ptr<Iterator<T>> createIterator() override {
        return std::make_unique<VectorIterator<T>>(m_items);
    }
};

// Demo
int main() {
    VectorCollection<int> collection;
    collection.add(10);
    collection.add(20);
    collection.add(30);
    collection.add(40);

    auto it = collection.createIterator();
    while (it->hasNext()) {
        std::cout << it->next() << " ";
    }
    std::cout << std::endl;

    return 0;
}