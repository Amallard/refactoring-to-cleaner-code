/*
Joe’s Pizza Palace needs a program to calculate the number of slices a pizza of any size can be divided into. 
The program should also report the number of pizzas someone should order for a party. 
Assume each person at the party will eat 3 slices each. 
The program should prompt the user for the diameter of the pizzas they wish to order and the number of people who will be at the party. 
The program should then calculate and display the number of slices per pizza and the number of pizzas needed for the party. 
  - A slice must have an area of 14.125 inches
  - Number of slices per pizza is the area of the pizza divided by the area of a slice
  - Area of a pizza is calculated with Area = PI * r^2 where PI = 3.14159 and r is the radius of the pizza
  - The number of slices should be fixed point and rounded to one decimal place
  - PI must be a named constant
–----------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <math.h>  
using namespace std;

int getUserInput(string message) {
  int input;
  cout << message;
  cin >> input;
  return input;
}

int getPizzaDiameterFromUser() {
  return getUserInput("What size pizza would you like? (Enter the inch diameter of the pizza)\n");
}

int getNumberOfPeopleFromUser() {
  return getUserInput("How many people are at the party?\n");
}

double calculateCircleArea(double radius) {
  const double PI = 3.14159;
  return PI * pow(radius, 2.0);
}

double calculatePizzaArea () {
  int pizzaDiameter = getPizzaDiameterFromUser();
  double pizzaRadius = pizzaDiameter / 2;
  return calculateCircleArea(pizzaRadius);
}

double calcNumSlicesPerPizza() {
  double pizzaArea = calculatePizzaArea();
  const double SLICE_AREA = 14.125;  
  double numSlicesPerPizza = pizzaArea / SLICE_AREA;

  return numSlicesPerPizza;
}

int calcNumPizzasNeeded(double numberOfSlicesPerPizza) {
  int slicesPerPerson = 3;
  int numberOfPeople = getNumberOfPeopleFromUser();
  
  return ((numberOfPeople * slicesPerPerson) / numberOfSlicesPerPizza) + 1;
}

void displayResults(double numberOfSlicesPerPizza, int numPizzasNeeded) {
  cout << endl;
  cout << "Number of slices per pizza: "  
    << setprecision(1) << fixed << showpoint << numberOfSlicesPerPizza << endl;
    
  cout << "Number of pizzas needed: "  
    << numPizzasNeeded << endl << endl;
}

int main() {
  double numberOfSlicesPerPizza = calcNumSlicesPerPizza();
  int numPizzasNeeded = calcNumPizzasNeeded(numberOfSlicesPerPizza);
  
  displayResults(numberOfSlicesPerPizza, numPizzasNeeded);

  return 0;
}
