#include <algorithm>
#include <cstdlib>

namespace UPF {

template <typename T>
class vector {
   protected:
    // Type definitions
    using value_type = T;
    using size_type = size_t;
    using pointer = T*;
    using reference = T&;
    using const_reference = const T&;

    const size_type c_initial_capacity = 5;
    // Members

    size_type m_capacity, m_size;
    pointer m_array;

   public:
    // constructors
    vector() : m_capacity{c_initial_capacity},
               m_size{0},
               m_array{new value_type[m_capacity]} {
    }
    
    vector(const vector& other) : m_capacity{other.m_capacity},
                                  m_size{other.m_size},
                                  m_array{new value_type[other.m_capacity]} {
        std::copy(other.m_array, other.m_array + other.m_size, m_array);
    }

    // destructor
    virtual ~vector() {
        delete[] m_array;
    }

    size_type size() const {
        return m_size;
    }

    size_type capacity() const {
        return m_capacity;
    }

    void push_back(const_reference value) {
        if (m_size == m_capacity) {
            m_capacity *= 2;
            pointer newarray = new value_type[m_capacity];
            std::copy(m_array, m_array + m_size, newarray);
            delete[] m_array;
            m_array = newarray;
        }
        m_array[m_size++] = value;
    }

    void pop_back() {
        (&m_array[--m_size])->~value_type();
    }

    reference operator[](size_type pos) {
        return m_array[pos];
    }

    const_reference operator[](size_type pos) const {
        return m_array[pos];
    }

    vector& operator=(const vector& rhs) {
        if (this != &rhs) {
            m_capacity = rhs.m_capacity;
            m_size = rhs.m_size;
            delete[] m_array;
            m_array = new value_type[m_capacity];
            std::copy(rhs.m_array, rhs.m_array + rhs.m_size, m_array);
        }
        return *this;
    }
};

}  // namespace UPF