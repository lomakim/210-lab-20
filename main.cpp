// COMSC-210 | Lab 20 | Loma Kim
#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3, MIN = 10000, MAX = 99999;
class Chair {
    private: 
    int legs;
    double * prices;

    public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        legs = (rand() % 2) + 3;    //sets legs to random # between 3-4
        for (int i = 0; i < SIZE; i++) {
            //sets price to random # between 100.00-999.99
            prices[i] = ((rand() % (MAX - MIN + 1)) + MIN) / (double)100;
        }
    }

    Chair(int l, double p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];       //sets price to the argument's counterpart
    }

    // setters and getters
    void setLegs(int l) {
        legs = l;
    }

    int getLegs() {
        return legs;
    }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(time(0));                 //seed for random numbers

    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    //now populated by default constructor
    Chair * chairPtr = new Chair;

    //creating dynamic chair object with constructor
    //now populated by default constructor
    Chair * livingChair = new Chair();

    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    //now populated by default constructor
    Chair * collection = new Chair[SIZE];
    
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    return 0;
}