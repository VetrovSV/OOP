#include <cassert>
#include <iostream>
#include <vector>
#include <format>
#include <math.h>


using namespace std;

// Инвентарь для NPC или Игрока
struct Inventory {
   public:
    static const size_t max_count = 128;
    static constexpr float max_weight = 1000;

  private:
    // todo: массив из вещей
    float weight;       // вес вещей
    size_t count;       // количество вещей

  public:
    // Для примера: фабричный статический метод
    static Inventory careate_random_inventory() {
        Inventory i( 1 + rand()%1000 / 10.0,  1+ rand()%100 );
        return i;}

    // Конструктор с списком инициализации: weight(0), count(0)
    Inventory( ) : weight(0), count(0) {}
    Inventory( float w, size_t n=1 ) : count(n) {}

    void set_weight( float w) { if (w > 0 and w < max_weight) weight = w;}
    void set_count( size_t n) { if (          n < max_count) count = n;}
    float get_weight() const {return weight;}
    size_t get_count() const {return weight;}

    /// добавление вещеё из другого инвентаря в текущий
    void add(const Inventory &inv2) {
        this->weight += inv2.weight;
        this->count += inv2.count; }

    /// выдаёт строковое представление объекта
    std::string to_string() const {
        return format("Inventory. weight: {:.2f}; count: {}", weight, count);    }
};


class Quest {
public:
    string description;

    Quest(string description1):  description(description1) {}
};

class Biography {
    //
};

/// Базовый класс/// Базовый класс для оружия
class Weapon {
private:
    float damage;           // Урон
public:
    string name;            // Название

    Weapon() { name = ""; damage = 1; }
    Weapon(string name1, float  damage1) {
        name = name1;
        set_damage( damage1 );  }

    void set_damage( float d) {if ( d > 0) this->damage = d; }

    float get_damage() const { return this->damage; }

    virtual string to_string() const {
        return format("Weapon. {}; damage: {:.1f}", name, damage);
    }

    // virtual включает динамический полиморфизм для всех реализаций to_string в потомках

};

// Топор
class Axe : public Weapon {
public:
    bool can_penetrate_armor = false;            // Может пробивать броню?

    Axe(string name1, float damage1, bool is_break_armor1):
        Weapon(name1, damage1), can_penetrate_armor(is_break_armor1)  {}

    string to_string() const override {
        // тут лучше было вызывать метод to_string из базового класса
        return format("Weapon {}:\ndamage: {:.1f};\nis_break_armor: {}",
            name, get_damage(), can_penetrate_armor);
    }
};

/// Лук
class Bow : public Weapon {
    float distance;         /// Дальность стрельбы

    public:
        Bow(): distance(1) {}       // тут автоматически вызывается констр. по умол. базового класса

        ///
        Bow(string name1, float damage1, float distance1) :
            Weapon(name1, damage1) {
                set_distance( distance1);}

        ///
        float get_distance() const { return distance; }

        ///
        void  set_distance(float distance1) {
            if ( distance1 > 0)
                distance = distance1;
            // else
                // throw invalid_argument("....");
        }

        // переопределение метода из базового класса
        /// переводи объект в строку
        string to_string() const override;

};

// переопределение метода из базового класса
/// переводи объект в строку
string Bow::to_string() const {
    // Weapon::to_string() - вызов метода базового класса
    return Weapon::to_string() + format("\ndistance: {:.1f}", distance);
}


float f1(int x){ return    sqrt(x); }
float f2(int x){ return 1./sqrt(x); }

// тип: указаель на функцию которая возвр. float и принимает int
using FPointer1 = float(*)(int);
// using FPointer2 = float(int);           // ?????


using MPointer = float(Bow::*)() const;

class GameCharacter {
private:
    int hp;
    int armor;
public:
    string name;
    Inventory inventory;            // композиция с Inventory
    vector<Quest> quests;           // агрегация с Quest
    Biography bio;                  // композиция с Biography

    Weapon *weapon;                 // агрегация с Weapon

    GameCharacter() { weapon = nullptr;}

    static GameCharacter random_character() { return GameCharacter(); }
};

int main() {

    MPointer p = &Bow::get_distance;

    Bow b;
    b.p();          // !

    FPointer1 fp ;// = f1;

    fp(90);            // вызов функции f1
    fp = f2;
    fp(90);            // вызов функции f2

    {
        Bow b("Лук1", 5, 10);
        assert( b.get_distance() == 10 );
        assert( b.get_damage() == 5 );
        assert( b.name == "Лук1" );
    }

    {
        Bow b;
        assert( b.get_distance() == 1);
        assert( b.get_damage() == 1);
        assert( b.name == "");
    }


    {
        Bow b;
        b.set_distance(8);
        assert( b.get_distance() == 8);
    }

    {
        Bow b;
        try{
            b.set_distance(-1);
            assert( "Не брошено исключение типа invalid_argument" == "!" );
        } catch (const invalid_argument &e) {
            //
        }
    }

    // C style cast
    int x = (int)3.12314;
    char *c = (char*)x;

    // static_cast
    int y = static_cast<int>(0.34124234);

    Weapon *w = new Bow();
    cout << w->to_string();

    // dyncamic_cast - на этапе выполнения
    Bow *b = dynamic_cast<Bow*> ( w );
    if ( b == nullptr)
        cerr << "Не удалось преобразовать Weapon* в Bow* \n";
    else
        b->set_distance(79);

    // reinterpret cast
    char* bytes = reinterpret_cast<char*>(b);

    sizeof(*b);
    sizeof(Bow);

    // const cast
    Bow b1("Лук1", 5, 10);
    Bow b2("Лук1", 5, 10);
    //  b1 и b2 равны
    // bool is_equal = b1==b2;

    Bow &b3  = b1;
    Bow *b4  = &b1;

    // b1 и b3 идентичны
    // *b1 и b4 идентичны
}
