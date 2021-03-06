#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
 char response1;
    char response2;

    cout << "Enter list type (i - int, f - float, s - std::string): ";
    cin >> response1;
    
    DoublyLinkedList<int> intList;
    DoublyLinkedList<float> floatList;
    DoublyLinkedList<string> stringList;

    ifstream readFile(argv[1]);
    string input = "";
    while (getline(readFile, input)) {
        istringstream iss(input);
        int num;
	float floatNum;
	string stringValue;
	
        //Add to list
        if (response1 == 'i') {
	  while (iss >> num) {
            intList.initialize(num);
            intList.insertItem(num);
	  }
	} else if (response1=='f'){
	   while (iss >> floatNum) {
	    floatList.initialize(floatNum);
	    floatList.insertItem(floatNum);
	  }
	}else if(response1 == 's'){
	   while (iss >> stringValue) {
	    stringList.initialize(stringValue);
	    stringList.insertItem(stringValue);
	  }
	}
    }

   
    while(true)
    {
        //int input
        if (response1 == 'i')
        {
            DoublyLinkedList<int> intItem;

            cout<< "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m), printReverse (r), swapAtl (s), quit (q)";
            cout << endl;
            cin >> response2;
            while (response2 != 'q')
            {
                if (response2 == 'i')
                {
		  intList.print();
                    cout << "Item to insert: ";
                    int num;
                    cin >> num;
                    intList.insertItem(num);
                    intList.print();
                }

                else if(response2=='d')
                {
                    int num;
                    cout<<"Item to delete:";
                    cin>>num;
                    intList.deleteItem(num);
                    intList.print();
                }

                else if(response2 == 'l')
                {
                    cout<<"The length is: "<<intList.lengthIs();
                    cout<<endl;
                }

                else if(response2 == 'p')
                {
                    intList.print();

                }

                else if(response2 == 'm')
                {
                    intList.mode();
                }

                else if(response2 == 'r')
                {
                    intList.printReverse();
                }

                else if(response2 =='s')
                {
                    intList.swapAlternate();
                }
                cout<< "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m), printReverse (r), swapAtl (s), quit (q)";
                cout << endl;
                cin >> response2;
            }
            return 0;

        }
        //float input
        else if(response1 =='f')
        {
            DoublyLinkedList<float> floatItem;
            if (response2 == 'i')
            {
                cout << "Item to insert: ";
                float num;
                cin >> num;
                floatList.insertItem(num);
                floatList.print();
            }

            else if(response2=='d')
            {
                float num;
                cout<<"Item to delete:";
                cin>>num;
                floatList.deleteItem(num);
                floatList.print();
            }

            else if(response2 == 'l')
            {
                cout<<"The length is: "<<floatList.lengthIs();
                cout<<endl;
            }

            else if(response2 == 'p')
            {
                floatList.print();
            }

            else if(response2 == 'r')
            {
                floatList.printReverse();
            }
	    else if(response2 == 'q'){
	      return 0;
	    }
	     cout<< "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m), printReverse (r), swapAtl (s), quit (q)";
                cout << endl;
                cin >> response2;
        }


        //string input
        else if(response1 == 's')
        {
            DoublyLinkedList<string> stringItem;
            if (response2 == 'i')
            {
                cout << "Item to insert: ";
                string inputString;
                cin >> inputString;
                stringList.insertItem(inputString);
                stringList.print();
            }

            else if(response2=='d')
            {
                string inputString;
                cout<<"Item to delete:";
                cin>>inputString;
                stringList.deleteItem(inputString);
                stringList.print();
            }

            else if(response2 == 'l')
            {
                cout<<"The length is: "<<stringList.lengthIs();
                cout<<endl;
            }

            else if(response2 == 'p')
            {
                stringList.print();
            }

            else if(response2 == 'r')
            {
                stringList.printReverse();
            }

	    else if(response2=='q'){
	      return 0;
	    }

            cout<< "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m), printReverse (r), swapAtl (s), quit (q)";
                cout << endl;
                cin >> response2;
        }

        else
        {
            cout<<"Please enter a valid response.\n";
            cout << "Enter list type (i - int, f - float, s - std::string): ";
            cin >> response1;
        }

    }
//    return 0;
}
