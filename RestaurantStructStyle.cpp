#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
/*
Vector can replace one dimensional array.
can collapse easily than the array
vector can allocate memory and increase dynamically
*/
using namespace std;

struct MenuItem
{
  string name;
  double itemCost;
  string desc;
  char addLetter;
  char removeLetter;
  int count; //how many of the manu item is ordered
};
//function definition
void populateMenu(vector<MenuItem> &entireMenu)
//calling by reference
{
  //put sone default value in out menu
  const int numItems = 7;
  //declare variable called Item1, 2, and 3 with data type of MenuItem
  MenuItem Item1;
  MenuItem Item2;
  MenuItem Item3;
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;


  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item3
  entireMenu.push_back(Item5); //add to the end of list the Item3
  entireMenu.push_back(Item6); //add to the end of list the Item3
  entireMenu.push_back(Item7); //add to the end of list the Item3

  vector <string> defaultMenuName;
  defaultMenuName.push_back("Green Tea");
  defaultMenuName.push_back("Item1");
  defaultMenuName.push_back("Item2");
  defaultMenuName.push_back("Item3");
  defaultMenuName.push_back("Item4");
  defaultMenuName.push_back("Item5");
  defaultMenuName.push_back("Item6");

  vector <char> defaultAddLetters;
  defaultAddLetters.push_back('A');
  defaultAddLetters.push_back('B');
  defaultAddLetters.push_back('C');
  defaultAddLetters.push_back('D');
  defaultAddLetters.push_back('E');
  defaultAddLetters.push_back('F');
  defaultAddLetters.push_back('G');

  vector <char> defaultRemoveLetters;
  defaultRemoveLetters.push_back('a');
  defaultRemoveLetters.push_back('b');
  defaultRemoveLetters.push_back('c');
  defaultRemoveLetters.push_back('d');
  defaultRemoveLetters.push_back('e');
  defaultRemoveLetters.push_back('f');
  defaultRemoveLetters.push_back('g');



  for(int i =0; i<numItems ;i++)
  {
    //add each item to the default list efficiently
    entireMenu[i].name = defaultMenuName[i];
    entireMenu[i].itemCost = 3.00 + i;
    entireMenu[i].addLetter = defaultAddLetters[i];
    entireMenu[i].removeLetter = defaultRemoveLetters[i];
    entireMenu[i].count = 0;
    entireMenu[i].desc = "delicious";

  }
}

void showMenu(vector<MenuItem> &m)
{
  cout <<fixed << setprecision(2);
  cout << "*****************"<< endl;
  cout << "\tMy Menus" << endl;
  cout << "*****************\n";

  cout << "ADD \tName \tCost \tRemove \tCount \tDESC" << endl;

  for (int i = 0; i < m.size(); i++) {
    //setw => set the width
    cout << m[i].addLetter << ")" << setw(10)<< m[i].name << setw(5)
    << "$" << m[i].itemCost << setw(5) << "(" << m[i].removeLetter
    << ")" <<setw(7) << m[i].count << setw(14)<< m[i].desc << endl;
  }
}
void acceptOrder(vector <MenuItem> &m)
{
  char option = '\0'; //for the user selected item-Menus
  double subtotal = 0.0;
  do {
    cout << "Please choose an item (x to exit): ";
    cin >> option;

    for(int i=0; i<m.size(); i++)
    {
      if(option == m[i].addLetter)
      {
        cout << "\nMenu Item " << m[i].addLetter << " selected."<<endl;
        subtotal += m[i].itemCost; //increament the subtotol by the cost of the item
        cout << "\033[2J\033[1;1H"; //to clear the screem
        m[i].count ++;
        cout << "\n1 UP on the " <<m[i].name<<endl;
        cout << "The subtotal $" << subtotal << endl;

        showMenu(m);
      }
      else if (option == m[i].removeLetter)
      {
        cout << "\nMenu Item " << m[i].removeLetter << " selected "<< endl;
        if(m[i].count> 0)
        {
          subtotal -= m[i].itemCost;
          cout << "\033[2J\033[1;1H"; //to clear the screem
          m[i].count --;
          cout << "\n1 DOWN on the " <<m[i].name<<endl;
          showMenu(m);
          cout << "The subtotal $" << subtotal << endl;

        }
        else
        {
          cout << "Count must be > 0\n"<< endl;
        }
      }
    }
  } while(option != 'x' && option != 'X');
  cout << "Thank you for placing your order.\n";


}

int main(int argc, char const *argv[])
{
  vector <MenuItem> wholeMenu; //insideis data type and name is wholeMenu
  populateMenu(wholeMenu); //put some default values in hr menu

  showMenu(wholeMenu); //displaying menu

  acceptOrder(wholeMenu); //accepting and removing an ordered
  return 0;
}
