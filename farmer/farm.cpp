// farm.cpp
//
// Farming Stimulator 2018 Super Deluxe Version

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum FieldStatus { empty, plowed, planted, ready, harvested, sold };
enum WeatherCondition { normal, drought, rain, sunshine, hail };


struct Crop {
    std::string cropType = "None";
    int monthsToGrow = -1;
    int sellPrice = -1;
};

class Wallet {
public:
    Wallet() {}
    Wallet(int startingBalance) : currentBalance{startingBalance} {}

    int setCurrentBalance(int startingBalance)  { 
        currentBalance = startingBalance; 
        return currentBalance;
    }
    int getCurrentBalance() { return currentBalance; }
    int adjustCurrentBalance(int amtToAdjust) {
        return currentBalance += amtToAdjust; 
    }

private:
    int currentBalance;
};

class Entity {
public:
    Entity() {}
};

class Field : public Entity {
public:
    Field() {}
    Field(std::string fieldName, int acres, int purchasePrice) 
        : fieldName{fieldName}, acres{acres}, purchasePrice{purchasePrice}, 
                            owned{false}, fieldStatus{empty} {}

    FieldStatus getFieldStatus() { return fieldStatus; }
    FieldStatus setFieldStatus(FieldStatus fieldStatus) { 
        this->fieldStatus = fieldStatus;
        return this->fieldStatus; 
    }


    bool getOwned() { return owned; }
    bool setOwned(bool owned) { 
        this->owned = owned;
        return this->owned; 
    }
    Crop getCrop() { return crop; }
    Crop setCrop(std::string cropType, int monthsToGrow, int sellPrice) { 
        this->crop.cropType = cropType;
        this->crop.monthsToGrow = monthsToGrow;
        this->crop.sellPrice = sellPrice;
        return this->crop; 
    }
    int decrementMonth() {
        if (crop.monthsToGrow > 0)
            crop.monthsToGrow--;
        return crop.monthsToGrow;
    }
    int getMonthsToGrow() { return crop.monthsToGrow; }
    int getPurchasePrice() { return this->purchasePrice; }
    std::string getFieldName() { return this->fieldName; }

    // Weather conditions are field specific
    WeatherCondition getWeatherEffects() {
        srand(time(nullptr)); // use current time as seed
        switch (rand() % 4) {
            case 1: 
                return rain;
            case 2:
                return drought;
            case 3:
                return hail;
            case 4: 
                return sunshine;
            default:
                return normal;

        }
    }
private:
    std::string fieldName;
    int acres;
    int purchasePrice;
    bool owned;
    FieldStatus fieldStatus;
    Crop crop;
};


class Farm : public Entity {
public:
    Farm() {
        FieldStatus fieldStatus = empty;
        Field field("Field 1", 5, 500);
        fields = field;
        wallet.setCurrentBalance(700); 
    }

    Field& getField() { return fields; } 
    //subscripting access
//    Field& operator[](int i) { return fields[i]; }    

    Wallet& getWallet() { return wallet; }
private:
    Field fields;
    Wallet wallet;
};

//////////////////////////////////////////////////////////////
// Standard Functions
/////////////////////////////////////////////////////////////

void displayMenu(bool displayMenu) {
    
    if (displayMenu) {
        cout << "Farm Menu" << endl;
        cout << "---------" << endl;
        cout << "1. Status" << endl;
        cout << "2. Plow" << endl;
        cout << "3. Plant" << endl;
        cout << "4. Harvest" << endl;
        cout << "5. Sell Crop" << endl;
        cout << "b. Buy Field" << endl;
        cout << "n. Advance to Next Month" << endl;
        cout << "m. Toggle menu" << endl;
        cout << "q. Quit" << endl;
    }
    else {
        cout << "======================================================================================================" << endl;
        cout << "m. Toggle menu  ";
        cout << "1. Status  ";
        cout << "2. Plow  ";
        cout << "3. Plant  ";
        cout << "4. Harvest  ";
        cout << "5. Sell Crop  ";
        cout << "b. Buy Field  ";
        cout << "n. Next Month  ";
        cout << "q. Quit" << endl;
    }
}

void displayFieldStatus(Field field, Wallet wallet) {
    cout << field.getFieldName() << endl;
    cout << "Owned: " << (field.getOwned() ? "true" : "false") << endl;
    cout << "Crop: " << field.getCrop().cropType << endl;
    cout << "Crop sell price: " << field.getCrop().sellPrice << endl;
    cout << "Time to harvest: " << field.getCrop().monthsToGrow << endl;
    cout << "Current balance: " << wallet.getCurrentBalance() << endl;
    cout << "Current field status: ";
    switch (field.getFieldStatus()) {
        case empty:
            cout << "empty" << endl;
            break;
        case plowed:
            cout << "plowed" << endl;
            break;
        case planted:
            cout << "planted" << endl;
            break;
        case harvested:
            cout << "harvested" << endl;
            break;
        case sold:
            cout << "crop sold" << endl;
            break;
    }
}

void advanceNextMonth(Field& field, Wallet& wallet) {
    cout << endl;
    cout << "One Month Passed" << endl;
    field.decrementMonth();
    int monthlyAdjust = 0;
    switch (field.getWeatherEffects()) {
        case rain: 
            monthlyAdjust = 30;
            cout << "Rain bonus +" << monthlyAdjust << endl;
            break;
        case  sunshine:
            monthlyAdjust = 20;
            cout << "Sunshine bonus +" << monthlyAdjust << endl;
            break;
        case hail:
            monthlyAdjust = -20;
            cout << "Hail Expense " << monthlyAdjust << endl;
            break;
        case drought: 
            monthlyAdjust = -30;
            cout << "drought expense " << monthlyAdjust << endl;
            break;
        default:
            monthlyAdjust = -10;
            cout << "Normal monthly expense " << monthlyAdjust << endl;
    }

    wallet.adjustCurrentBalance(monthlyAdjust); // monthly expense 
    displayFieldStatus(field, wallet);
    cout << endl;

}

bool dispatcher(bool& toggleMenuOn, char choice, Farm& farm) {
    bool doContinue = true;
    Field& field = farm.getField();
    Wallet& wallet = farm.getWallet();

    if (choice > '1' && choice < '6' && field.getOwned() == false ) {
        cout << "You must own the field" << endl << endl;
        return doContinue;
    }

    switch (choice) {
        case '1': 
            cout << endl;
            cout << "Status:" << endl << endl;
            displayFieldStatus(field, wallet);
            cout << endl;
            break;
        case '2':
            cout << endl;
            cout << "Plowed" << endl << endl;
            displayFieldStatus(field, wallet);
            field.setFieldStatus(plowed);
            cout << endl;
            break;
        case '3':
            cout << endl;
            if (field.getFieldStatus() == plowed) {
                cout << "Planted" << endl << endl;
                wallet.adjustCurrentBalance(-100); // cost of seed
                field.setFieldStatus(planted);
                field.setCrop("Corn", 3, 200);
                displayFieldStatus(field, wallet);
            }
            else {
                cout << "Field must be plowed first" << endl;
            }
            cout << endl;
            break;
        case '4':
            cout << endl;
            if (field.getFieldStatus() == planted) {
                if (field.getMonthsToGrow() == 0) {
                    cout << "Harvested" << endl << endl;
                    field.setFieldStatus(harvested);
                    displayFieldStatus(field, wallet);
                }
                else {
                    cout << "The " << field.getCrop().cropType << " still has " << field.getMonthsToGrow();
                }
            }
            else {
                cout << "Field must be planted first" << endl;
            }
            cout << endl;
            break;
        case '5':
            cout << endl;
            if (field.getFieldStatus() == harvested) {
                cout << "Crop sold" << endl << endl;
                field.setFieldStatus(sold);
                wallet.adjustCurrentBalance(field.getCrop().sellPrice); 
                displayFieldStatus(field, wallet);
            }
            else {
                cout << "Field must be harvested first" << endl;
            }
            cout << endl;
            break;
        case 'b':
            wallet.adjustCurrentBalance(-field.getPurchasePrice()); 
            field.setOwned(true);
            cout << endl;
            cout << "Bought Field" << endl << endl;
            displayFieldStatus(field, wallet);
            cout << endl;
            break;
        case 'n':
            advanceNextMonth(field, wallet);
            break;
        case 'm':
            toggleMenuOn = !toggleMenuOn;
            break;
        case 'q':
            cout << endl;
            cout << "Quitting" << endl << endl;
            doContinue = false;
            break;
    }
    displayMenu(toggleMenuOn);
    return doContinue;
}

void mainLoop() {
    char choice = 'x';
    bool loop = true;
    bool toggleMenuOn = false;
    Farm farm;
    
    displayMenu(toggleMenuOn);
    while (loop) {
        cout << "======================================================================================================" << endl;
        cout << ">";
        cin >> choice;
        loop = dispatcher(toggleMenuOn, choice, farm);
    }
}

int main() {
    mainLoop();
}
