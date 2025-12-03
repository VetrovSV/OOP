#include <iostream>
#include <vector>
#include <format>


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
                set_distance( distance1 );}

        ///
        float get_distance() const { return distance; }
        ///
        void  set_distance(float distance1) { if ( distance1 > 0) distance = distance1; }

        // переопределение метода из базового класса
        /// переводи объект в строку
        string to_string() const override {
            // Weapon::to_string() - вызов метода базового класса
            return Weapon::to_string() + format("\ndistance: {:.1f}", distance);
        }

};


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


    Weapon *w = new Weapon("Меч", 20);
    Axe *a = new Axe("Базовый топор", 4, false);

    // так нельзя! Т.к. в w фактиески записан не Axe а Weapon
    Axe *a2 = dynamic_cast<Axe*>(w);
    if ( a2 == nullptr )     // проверка, удалось ли преобразовать
        cerr << "Не удалось преобразовать Weapon* в Axe*\n";


}
