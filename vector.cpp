#include <iostream>

template<typename Value>
class Vector {
    private:
    Value *arr;
    int arr_size;
    int capacity;
    public:
    Vector() : arr(nullptr),arr_size(0),capacity(0) {} // default constructor - no values
    Vector(size_t n)  { // parameterized constructor - arr_size only
        arr_size = n;
        arr = new Value[arr_size];
        capacity = n;
    }
    Vector(size_t n, const Value& value) { // parameterized constructor - value added to the array 'n' times
        arr_size = n;
        capacity = arr_size;
        arr = new Value[arr_size];
        for(int i = 0; i < arr_size;i++) {
            arr[i] = value;
        }
    }
    Vector(const Vector& other) { // copy constructor 
        arr_size = other.arr_size;
        capacity = other.capacity;
        arr = new Value[other.capacity];
        for(int i = 0; i < arr_size; i++) {
            arr[i] = other.arr[i];
        }
    }
    
    Value& operator[](int index) {
        if(index >= arr_size || index < 0) throw std::runtime_error("Vector index out of bounds");
        return arr[index];
    }
    Vector& operator=(const Value& other) {
        if(this == &other) return *this;
        delete[] arr;
        arr_size = other.arr_size;
        capacity = other.capacity;
        arr = new Value[other.capacity];
        for(int i = 0; i < arr_size; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    ~Vector() { // free allocated memory
        delete[] arr;
    }
    void rearr_size() { // space needed to insert a new element
        if(capacity == 0) capacity = 1;
        capacity = 2 * capacity;
        // std::cout << "\n rearr_sized to " << capacity << "\n";
        Value* new_arr = new Value[capacity];
        for(int i = 0; i < arr_size; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }
    void push_back(const Value& val) {     // array arr_size grows
        if(arr_size == capacity) rearr_size();
        arr[arr_size++] = val;
    }
    Value pop_back() {          // array arr_size decreases
        if(arr_size == 0) throw std::runtime_error("Error: Array is already empty");
        Value v = arr[arr_size-1];
        arr_size--;
        return v;
    }
    Value& at(int index) {
        if(index >= arr_size || index < 0) throw std::runtime_error("Vector index out of bounds");
        return arr[index];
    }
    const Value* begin(){      // begin iterator
        return arr;
    }
    const Value* end() {       // end iterator
        return arr+arr_size;
    }
    void clear() {
        arr_size = 0;
    }

    int size() { return arr_size; }
    bool empty() { return arr_size == 0; }
    int getCapacity() { return capacity; }
    void display() const {      // only for debugging purposes
        for(int i = 0; i < arr_size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

// template<typename T>
// std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
//     for (int i = 0; i < v.size(); i++) {
//         os << v.at(i) << " ";
//     }
//     return os;
// }

int main() {
    Vector<int> v1(5,10);
    v1.display();
    std::cout << std::endl << "goofball " << v1[4];
    v1[4] = 69; 
    std::cout << std::endl << "goofball " << v1[4] << std::endl;
    v1.display();
    Vector<int> v2(v1);
    v2[4] = 55;
    std::cout << "v1: \n";
    v1.display();
    std::cout << "v2: \n";
    v2.display();
    v2.push_back(79);
    v2.push_back(89);
    v2.push_back(51);
    v2.display();
    v2.pop_back();
    v2.pop_back();
    v2.pop_back();
    v2.display();
    std::cout << v2.at(4) << std::endl;
    // Vector<Vector<int>> v2d(4);
    // for(int i = 0; i < 4; i++){
    //     for(int j = 0; j < 4; j++){
    //         v2d[i][j] = i+j;
    //     }
    // }
    // v2d.display();
}