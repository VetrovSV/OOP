#include <cassert>
#include <cstddef>
#include <cstring>
#include <iterator>

template <typename E>
class DynamicArray{
    E* arr = nullptr;       // массив
    size_t size = 0;        // количество эл-в, которые заняты
    size_t capacity = 1;    // ёмкость массива (кол-во доступной памяти в элементах)

  public:
    ///  ...
    DynamicArray(){
        arr = new E[capacity]; }

    /// ...
    DynamicArray(size_t capacity1){
        if (capacity1 != 0){
            capacity = capacity1;
            arr = new E[capacity];  }
        else { arr = new E[capacity]; }
    }

    /// Получить элемент по индексу i
    /// ...
    E get(size_t i) const {
        if ( i < size )
            return arr[i];
        else return E();
        // подумать, что если условие не выполнено
    }

    /// Получить элемент по индексу i
    /// ...
    E set(size_t i, E x) {
        if ( i < size )
            arr[i] = x;
        // подумать, что если условие не выполнено
    }


    // оператор [] - аналог set
    E& operator[](size_t i) {
        if ( i < size ) return arr[i];
        // подумать, что если условие не выполнено
    }

    // ...
    size_t get_size() const { return size;}
    // ...
    size_t get_capacity() const { return capacity;}

    // ...
    void add(E x){
        // проверка на заполненность
        if ( size < capacity ) {
            arr[size] = x;
            size++;
        } else {
            // TODO: добавить память
        }
    }

    ~DynamicArray() {

        if (arr != nullptr){
            delete[] arr;
            arr = nullptr;
        } }

    DynamicArray copy() const {
        DynamicArray result( capacity );
        result.size = this->size;
        memcpy( result.arr, this->arr, this->size*sizeof(E) );
        return result;
    }

};


int main(){

    {
        DynamicArray<int> a;
        assert( a.get_size() == 0 );
        assert( a.get_capacity() == 1 );
    }

    {
        DynamicArray<int> a;
        a.add(123);
        assert( a.get(0) == 123 );
        assert( a.operator[](0) == 123 );
        assert( a[0] == 123 );
        assert( a.get_size() == 1 );
        assert( a.get_capacity() == 1 );
    }

    {
        // DynamicArray<int> a;
        // a.add(123);

        // DynamicArray<int> b;
        // b = a;

        // assert( a.get_size() == b.get_size() );
        // assert( a.get_capacity() == b.get_capacity() );
        // // b.set(0, 99);
        // // assert( a.get(0) == 123 );
        // // assert( b.get(0) == 99 );
    }

    {
        DynamicArray<int> a;
        a.add(111);

        DynamicArray<int> b;
        b = a.copy();

        assert( a.get_size() == b.get_size() );
        assert( a.get_capacity() == b.get_capacity() );
        assert( b.get(0) == a.get(0) );

        a.set(0, 112);
        assert( b.get(0) == 111 );

        b.set(0, 222);
        assert( a.get(0) == 112 );

        assert( a.get(0) == 123 );
        assert( b.get(0) == 99 );
    }

}
