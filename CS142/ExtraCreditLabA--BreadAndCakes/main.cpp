#include <iostream>
#include <vector>
using namespace std;
#include "LayerCake.cpp"
#include "Bread.cpp"
#include "CupCake.cpp"
/* TEST INPUTS:
 * Bread Wheat 4 Cupcake Funfetti lemon pink 1 Layer-cake Chocolate vanilla 2 3 Layer-cake Spice cream-cheese 3 2 Cupcake Yellow cream-cheese red 3 Bread White 1 Cupcake Chocolate vanilla blue 4 Bread White 1 Cupcake Chocolate vanilla blue 1 done
 **/

int main() {
    const string BREAD_ORDER = "Bread";
    const string CUPCAKE_ORDER = "Cupcake";
    const string LAYER_CAKE_ORDER = "Layer-cake";
    string orderType;
    int quantity;
    vector<BakedGood*> orderList;

    cout << "**Bread and Cakes Bakery**" << endl << endl;
    cout << "Enter sub-order (enter \"done\" to finish)" << endl;

    do{
        cout << "Sub-order: ";
        cin >> orderType;
        if(orderType == BREAD_ORDER){
            //has structure: variety quantity
            string variety;
            cin >> variety >> quantity;
            cout << endl;
            for(int i = 0; i < quantity; i++){
                Bread* newBread = new Bread(variety);
                orderList.push_back(newBread);
            }
        }else if(orderType == CUPCAKE_ORDER){
            //has structure: flavor frosting sprinkles quantity
            string flavor, frosting, sprinklesColor;
            cin >> flavor >> frosting >> sprinklesColor >> quantity;
            cout << endl;
            for(int i = 0; i < quantity; i++){
                CupCake* newCupCake = new CupCake(flavor, frosting, sprinklesColor);
                orderList.push_back(newCupCake);
            }
        }else if(orderType == LAYER_CAKE_ORDER){
            //has structure: flavor frosting layers quantity
            string flavor, frosting;
            int layers;
            cin >> flavor >> frosting >> layers >> quantity;
            cout << endl;
            for(int i = 0; i < quantity; i++){
                LayerCake* newLayerCake = new LayerCake(flavor, frosting, layers);
                orderList.push_back(newLayerCake);
            }
        }
    }while (orderType != "done");
    cout << endl << endl;

    cout << "Order Confirmations:" << endl;
    for(int i = 0; i < orderList.size(); i++){
        cout << orderList.at(i)->ToString() << endl;
    }
    cout << endl;


    vector<BakedGood*> bakedGoodTypes;
    vector<int> bakedGoodQuantities;
    //will create a list of unique BakedGood pointers from the orderList
    for(int i = 0; i < orderList.size(); i++){
        BakedGood* currentBakedGood = orderList.at(i);
        bool isFound = false;
        for(int j = 0; j < bakedGoodTypes.size(); j++){
            if(currentBakedGood->ToString() == bakedGoodTypes.at(j)->ToString()){
                isFound = true;
            }
        }
        if(!isFound){
            bakedGoodTypes.push_back(currentBakedGood);
        }
    }
    //figures out how many of each unique item there is
    for(int i = 0; i < bakedGoodTypes.size(); i++){
        BakedGood* currentBakedGood = bakedGoodTypes.at(i);
        int numMatches = 0;
        for(int j = 0; j < orderList.size(); j++){
            if(currentBakedGood->ToString() == orderList.at(j)->ToString()){
                numMatches++;
            }
        }
        bakedGoodQuantities.push_back(numMatches);
    }

    /*cout << endl << endl << "TESTING: UNIQUENESS LIST" << endl;
    for(int i = 0; i < bakedGoodTypes.size(); i++){
        cout << bakedGoodTypes.at(i)->GetVariety() << "(" << bakedGoodQuantities.at(i) << " ordered)" << endl;
    }*/

    //print the invoice and calculate the total cost
    double totalOrderPrice = 0.0;
    int totalOrderQuantity = 0;
    cout << "Invoice:" << endl;
    cout << "Baked Good" << setw(74) << "Quantity" << setw(9) << "Total" << endl;
    for(int i = 0; i < bakedGoodTypes.size(); i++){
        BakedGood* currentBakedGood = bakedGoodTypes.at(i);
        int currentQuantity = bakedGoodQuantities.at(i);
        double currentTotalPrice = currentBakedGood->DiscountedPrice(currentQuantity);
        cout << left << setw(76) << currentBakedGood->ToString() << setw(8) << right << currentQuantity << setw(9) << fixed << setprecision(2) << currentTotalPrice << endl;
        totalOrderPrice += currentTotalPrice;
        totalOrderQuantity += currentQuantity;
    }
    cout << left << setw(76) << "Totals" << setw(8) << right << totalOrderQuantity << setw(9) << fixed <<
    setprecision(2) << totalOrderPrice << endl;
    cout << "Good Bye" << endl;
}





























