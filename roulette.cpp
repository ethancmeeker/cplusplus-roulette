#include <iostream>
#include <stdlib.h>    
#include <stdio.h>     
#include <algorithm>
#include <array>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>

using namespace std; // Now I don't have to put std:: before everything which is so nice. Saw this in a turtorial.
class Handle_Money { //This class is to handle the increases that will happen to your pot if you win (both inside and outside).
  float pot, change;
  public:
    void set_values (float, float);
    float winnings() {return pot*change;}
};
void Handle_Money::set_values (float p, float c) { //Gets called by the class above and just defines the integers I will pass in.
  pot = p;
  change = c;
}
template<typename C, typename T>
bool contains(C&& c, T e) { // Found on w3 schools and modified for my use. Goes through each item in an array to check if it's there or not. For the red and black values.
    return find(begin(c), end(c), e) != end(c);
};
int spin(int ball) { // Simple random integer creator. 
  srand((unsigned) time(0)); // What does this do, I have no idea but it makes the number random.
  ball = (rand() % 37);
  // cout << ball; // for debugging purposes
  return ball;
}
void board(){ //Just has the board in it and is called when needed.
  cout << "\n    1   4   7   10   13   16   19   22   25   28   31   34\n0   2   5   8   11   14   17   20   23   26   29   32   35\n    3   6   9   12   15   18   21   24   27   30   33   36\n    1st 12 (1-12)    2nd 12 (13-24)      3rd 12 (25-36)\n             Even    Black      Red      Odd      \n";
}
int main() {
  int black[18] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
  int red[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
  float tuition; //It's good to deal with all the money as floats to avoid conflicts.
  string choose, leave1, leave2, leave3;
  tuition = 2208;
  cout << '\n';
  cout << "Welcome to the roulette tables. I see that\nyou have your BYU-I tuition money there. Maybe\nyou would like to double that money, get into Northpoint\nor something upper class like that.\n\nLet's Play!\n";
  while (tuition > 54) {
    checkpoint1: // This is nice. If you try to leave, I can instantly put you back up to this exact spot and start going down.
    cout << tuition << "\n";
    tuition -= 50;
    tuition -= 50;
    cout << tuition << "\n";
    float inside_increase, outside_increase, inside_pot, outside_pot;
    bool inside_flag=0;
    bool outside_flag=0;
    int roll = spin(roll); // Called the spin function
    string x;
    cout << x;
    cout << "\nIf you want to play, type 'y', if not, clearly type 'no': ";
    cin >> choose;
    system("clear");
    if(choose=="no"){
      cout << "\nAwwww you sure?: ";
      cin >> leave1;
      if (leave1=="yes"){
        cout << "\nYou really really sure?: ";
        cin >> leave2;
        if (leave2=="yes"){
          cout << "\nLast chance, come on, whats 1 more game gonna do?: ";
          cin >> leave3;
          if (leave3=="yes"){
            exit(1);
          }
          else{
            goto checkpoint1;
          }}
        else{
          goto checkpoint1;
        }}
      else{
        goto checkpoint1;
      }}
    else{
      int num1, num2; // These will be the numbers yo bet the ball will land
      string outside_pick_gp, choose_outside;
      inside_pot = 50.0; // Automatic pot set
      tuition -= inside_pot;
      board(); // Calls the board function above.
      cout << "\nWhere going to start with the inside bet. You can pick\neither one or two numbers. If you pick two numbers, you're\ninside pot will be tripled, if you bet on only one number,\nyou can get 7 times the initial pot. Pick the first number\nyou would like to bet on (An automatic 50 bucks are\nplaced on the inside pot).\nPut just one number right now: ";
      cin >> num1;
      cout << "Put your second number\n(If you want to bet on only 1 number, type 0): ";
      cin >> num2;
      // Checks if you want a second number or not.
      if (num2 == 0){ 
        inside_increase = 7;}
      else{
        inside_increase = 4;}
      outside_pot = 50.0; // Automatic bet for the outside values
      tuition -= outside_pot;
      system("clear");
      cout << "It's time for the outside bet (The pot is \nautomatically at 50 bucks:\n\nIf you want to bet on either black or red values, type 1\n(Pot increase:1.3).\n\nIf you would like to bet on either odd or even, type 2\n(Pot increase:1.2).\n\nIf you would like to bet on groups of twelve, type 3\n(Pot increase:2).\n\nIf you would like to bet on just the number 0, type 4\n(Pot increase:9).\n\nWhat section would you like to bet on?: "; 
      cout << tuition << "\n";
      cin >> choose_outside; 
      if (roll == num1 || roll == num2){
        inside_flag = 1;}
      else{
        inside_flag = 0;}
      if (choose_outside == "1"){ // Black or Red
        system("clear");
        outside_increase = 1.3;
        size_t m = sizeof(black)/sizeof(black[0]);
        cout << "\nblack: ";
        for (size_t i = 0; i < m; i++) {
        std::cout << black[i] << ' ';}
        cout << "\nred:   ";
        for (size_t i = 0; i < m; i++) {
        std::cout << red[i] << ' ';}
        cout << "\nWhat color would you like to be on?\n(Type 1 for black, 2 for red): ";
        cin >> outside_pick_gp;
        if (outside_pick_gp == "1"){
          if (contains(black, roll) == 1){
            outside_flag = 1;} // Got this idea from W3 schools. By making flags, we can assign them a value that you can eventually call back to and see what the value of them are. 
          else{
            outside_flag = 0;}}
        if (outside_pick_gp == "2"){
          if (contains(red, roll) == 1){
            outside_flag = 1;}
          else{
            outside_flag = 0;}}
      }
      else if (choose_outside == "2"){ // Even or Odd
        system("clear");
        outside_increase = 1.2;
        cout << "Would you like to bet on odds or evens?\n(Type 1 for odd, type 2 for evens): ";
        cin >> outside_pick_gp;
        if (outside_pick_gp == "1"){
          if (roll%2 != 0){
            outside_flag = 1;}
          else{
            outside_flag = 0;}}
        if (outside_pick_gp == "2"){
          if (roll%2 == 0){
            outside_flag = 1;}
          else{
            outside_flag = 0;}}
      }
      else if (choose_outside == "3"){ // Groups of 12
        system("clear");
        outside_increase = 2.0;
        cout << "What group of 13 would you like to use?\n(Type 1 for 1-12, type 2 for 13-24, type 3 for 25-36): ";
        cin >> outside_pick_gp;
        if (outside_pick_gp == "1"){
          if ((13 > roll) && (0 < roll)){
            outside_flag = 1;}
          else{
            outside_flag = 0;}}
        if (outside_pick_gp == "2"){
          if ((12 < roll) && (25 > roll)){
            outside_flag = 1;}
          else{
            outside_flag = 0;}}
        if (outside_pick_gp == "3"){
          if (24 < roll){
            outside_flag = 1;}
          else{
            outside_flag = 0;}} 
      }
      else{
        system("clear");
        outside_increase = 9.0;
        if (roll == 0){
          outside_flag = 1;}
        else{
          outside_flag = 0;}}
      system("clear");
      cout << "The number the ball landed on " << roll << "\n";
      if(inside_flag==1){
        float inside_winnings;
        Handle_Money payoff;
        payoff.set_values(inside_pot, inside_increase);
        cout << "Good job, the inside earnings you got: ";
        inside_winnings = payoff.winnings();
        cout << inside_winnings << "\n";
        tuition += inside_winnings;}
      else{
        cout << "Better luck next time on the inside";}
      if(outside_flag==1){
        float outside_winnings;
        Handle_Money payoff;
        payoff.set_values(outside_pot, outside_increase);
        cout << "Good job, the outside earnings you got: ";
        outside_winnings = payoff.winnings();
        cout << outside_winnings << "\n";
        tuition += outside_winnings;}
      else{
        cout << "Better luck next time on the outside";}
      cout << "\n New Amount: ";
      }
    }  
    cout << "Awwwwwwww no more money, come back\nwhen you're a little hmmmmmmm richer";
    exit(2);   
  }
  
