#include <iostream>
#include <string>
using namespace std;

const int maxrow=10;
string b_title [maxrow]={};
string b_author[maxrow]={};
string b_isbn[maxrow]={};
string b_publisher[maxrow]={};
int counter;

void AddRecord() {
    char title[50];
    char author[20];
    char isbn[20];
    char publisher[30];

    cin.ignore();
    cout <<"\n| Book Author: ";
    cin.getline(author, 20);
    cout << "| Book Title: ";
    cin.getline(title, 50);
    cout << "| Publisher: ";
    cin.getline(publisher, 30);
    cout << "| ISBN: ";
    cin.getline(isbn, 20);
  

 for (int x = 0; x < maxrow; x++)
 {
    if(b_author[x] == "\0")
    {
        b_author[x] = author;
        b_title[x] = title;
        b_isbn[x] = isbn;
        b_publisher[x] = publisher;
        break;
    }
 }
}
void DeleteRecord(string borrow)
{
    int x, j;
    int size = 10;
    int counter = 0;

    for (int x = 0; x < size; x++)
{
    if (b_title[x] == borrow)
    {
        for(j=x; j<(size-1); j++){
         b_title[j] = b_title[j+1];
         b_author[j] = b_author[j+1];
         b_isbn[j]=b_isbn[j+1];
        b_publisher[j]=b_publisher[j+1];
  
        }
        counter++;
        break;
    }
}
if (counter == 0)
{ 
    cout << "\n Book title does not exist!"<<endl;
    
}
else

        cout << "\n Successfully Borrowed!" << endl;
    }
void ListRecord()
{
 int counter = 0;
 int x;
cout << "Current Record(s)" <<endl;
    for (int x = 0; x < maxrow; x++)
    if (b_author[x] != "\0") {
    counter++;
    cout << " " << counter << ". "<<"Author: " << b_author[x]<<endl; 
    cout<< "    Book Title: " << b_title[x]<<endl;
    cout<<"    Publisher: "<<b_publisher[x]<< endl;
    cout<< "    ISBN: " << b_isbn[x]<<endl;
    }
    else if (counter==0) {
    cout << "\n No Record found!" << endl;
    break;
    }
   
}
void BubbleSort(){
      int x;
    string temp;
    for(int x = 0; x < maxrow; x++)
    for(int j = x+1; j < maxrow; j++) {
        if(b_title[x] > b_title[j]) {
            temp = b_title[x];
            b_title[x] = b_title[j];
            b_title[j] = temp;
        }   
    }
    for(int x = 0; x < maxrow; x++) {
         cout<<b_title[x]<<endl;
    }
}


int main()
{
    cout << "| L I B R A R Y  M A N A G E M E N T   S Y S T E M \n";
    int option;
    string search;
    string borrow;
    do{
    cout << "|===================================================================|" << endl;
    cout << "| 1-Insert book in the library" << endl;
    cout << "| 2-Borrow book from library" << endl;
    cout << "| 3-Display all books"<<endl;
    cout << "| 4-Search book" << endl;
    cout << "| 5-Sorted list of Books " <<endl;
    cout << "| 6-Exit" << endl;
    cout << "|===================================================================|" << endl;
    cout << "| Select option >> ";
    cin >> option;

    switch (option)
    {
    case 1: AddRecord();
    break;

    case 2: cin.ignore();
    cout << "| Borrow by title >> " << endl;
    getline(cin, borrow);
    DeleteRecord(borrow);
    break;
    

    case 3: ListRecord();
   
    break;

    case 4:cin.ignore();
    cout << "| Searching for book using title" << endl;
    getline(cin, search);
    SearchRecord(search);
    break;
    
    case 5:
    cout << "| Sorted List of Books using title: " << endl;
    BubbleSort();
    break;

    case 6:
    cout<<"Exit...."<<endl;
    return 0;
    
    default:
    cout << "| Invalid Entry!" << endl;
    return 0;
    }
  
    }while (option<6);
}