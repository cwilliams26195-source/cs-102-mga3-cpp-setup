#include <iostream>
#include <iomanip>
using namespace std;

//PROTOTYPES
void menu();
void recordsale(double amount, int option,int &count, double &totalrev ,double &highest,double &lowest, 
    bool &sale, int &count1, int &count2, int &count3,double &subtotal1,double &subtotal2,double &subtotal3);
void Snapshot(int count, double totalrev,double highest,double lowest);
void closeprint(int count,double totalrev, double highest, double lowest, int count1, double subtotal1,
    int count2, double subtotal2,int count3, double subtotal3);


//MAIN FUNCTION
int main() {
    string location;
    string currency;
    int choice;
    double amount;
    int option;
     int count = 0;
    double totalrev = 0;

    double highest ;
    double lowest ;
    bool sale = false;
    double average;

    //Grocery & produce
    int count1 = 0;
    double subtotal1 = 0.0;

    //Beverage & snacks
    int count2 = 0;
    double subtotal2 = 0.0;

    //General Merchandise
    int count3 = 0;
    double subtotal3 = 0.0;
    
    cout<<"==================================================================="<<endl;
    cout<<" -----BELIZE TRADING CO. - DAILY SALES ANALYZER-----"<<endl;
    cout<<"==================================================================="<<endl;
   cout<<"Shift Location: "; 
   cin>>location;
   cout<<"Currency ($BZ): ";
   cin>>currency;
 
 cout<<"==================================================================="<<endl;
 do{
    menu();
    cout<< "Enter choice (1-4): ";
      cin>>choice;
switch (choice){
    case 1 : recordsale(amount, option,count,totalrev,highest,lowest,sale,count1,count2,count3,subtotal1,subtotal2,subtotal3); break;
    case 2 : Snapshot(count, totalrev, highest,lowest);break;
    case 3 : closeprint(count,totalrev, highest,lowest, count1, subtotal1,count2, subtotal2,count3,subtotal3 );return 0;
    case 4 : cout<< "\nExit Without Saving";
}
 }while (choice != 4);
    
    return 0;
}
//FUNCTIONS
void menu() {
    cout<<"MAIN MENU"<<endl;
    cout<<"1. Record a New Sale Transaction"<<endl;
    cout<<"2. View Shift Snapshot (Interim Totals) "<<endl;
    cout<<"3. Close Shift & Print Daily Audit "<<endl;
    cout<<"4. Exit Without Saving"<<endl;
    
}
void recordsale(double amount, int option,int &count, double &totalrev ,double &highest,double &lowest, 
    bool &sale, int &count1, int &count2, int &count3,double &subtotal1,double &subtotal2,double &subtotal3){
char ans;

do{    cout<<"=========================Record#"<<(count+1)<<"==================================="<<endl;
    cout<<"Enter sale amount ($BZ): ";
    cin>>amount;

    if(amount<0.0) {cout<<"[ERROR] Amount must be greater than 0.\n";
    cout<<"Enter Sale amount again ($BZ): \n";
    cin>>amount; }
   totalrev += amount;
   count++;

   if(!sale){
    highest = amount;
    lowest = amount;
    sale = true;
   }else {
    if (amount>highest){
        highest = amount;
    }
  if (amount < lowest){
    lowest = amount;
  }
}
cout<<"\nSelect category: \n";
    cout<<"-> [1] Grocery & Produce\n";
    cout<<"-> [2] Beverages & Snacks\n ";
    cout<<"-> [3] General Merchandise\n";
    cout<<"Enter Category choice: ";
    cin>> option;
  
    //Options 
    switch(option){
   case 1: (option == 1);
     count1++;     
   subtotal1 +=amount;
             {cout<<">>> Sale of $BZ "<<amount<<" recorded under Grocery & Produce\n"; break;}
   case 2:  (option == 2);
   count2++;
   subtotal2 +=amount;
   {cout<<">>> Sale of $BZ "<<amount<<" recorded under Beverages & Snacks\n";break;}
   case 3:(option==3);
   count3++;
   subtotal3+=amount;
   {cout<<">>> Sale of $BZ "<<amount<<" recorded under General Merchandise\n";break;}
    }
   
    cout<<"\nDo you want to enter another transaction? (y/n): ";
    cin>> ans;
}while(ans== 'y');
 
cout<<"\nReturning to Main Menu...\n";
    }   

void Snapshot(int count, double totalrev,double highest,double lowest){
    cout<<"==================================================================="<<endl;
    cout<<"-----INTERIM SHIFT SNAPSHOT-----\n";
    cout<<"==================================================================="<<endl;
    cout<<"Total Transactions Processed: "<<count<<"\n";
    cout<<"Gross Revenue Collected: $BZ"<<totalrev<<"\n";
    
    double average=0;
    if (count > 0){
        average = totalrev / count;
    }
    
    cout<<"Average transaction: $BZ"<< average<<"\n";
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"Current Highest Sale: $BZ"<<highest<<"\n";
    cout<<"current Lowest sale: $BZ"<<lowest<<"\n";
    cout<<"==================================================================="<<endl;
}
void closeprint(int count,double totalrev, double highest, double lowest, int count1, double subtotal1,
    int count2, double subtotal2,int count3, double subtotal3){
    cout<<"==================================================================="<<endl;
    cout<<"          END-OF-DAY SALES AUDIT REPORT        \n";
    cout<<"==================================================================="<<endl;

    cout<<"Total Transactions Processed: "<< count<<"\n";
    cout<<"Gross Revenue Collected: $BZ "<<totalrev<<"\n";
    
    double average ;
    if (count > 0){
        average = totalrev / count;
    }else{
        average = 0.0; 
    }
    cout<<"Average Transaction Size: $BZ"<<average<<"\n";
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"Peak Transaction (Highest): $BZ"<<highest<<"\n";
    cout<<"Base Transaction (Lowest): $BZ"<<lowest<<"\n";
    cout<<"==================================================================="<<endl;
    cout<<"             CATEGORY BREAKDOWN                                 \n ";
    cout<<"==================================================================="<<endl;
    cout<<"Category             Count           Subtotal            Share\n";
    cout<<"------------------------------------------------------------------"<<endl;

    double share1 =0.0 ;
    if (totalrev > 0) {
      share1 =  (subtotal1 / totalrev)*100;
    }else{
        share1 = 0.0;
    }

    double share2 = 0.0;
    if (totalrev > 0) {
        share2 = (subtotal2 / totalrev)*100;
    }else{
         share2 = 0.0;
    }
    
    double share3 = 0.0;
    if (totalrev > 0) {
      share3 = (subtotal3 / totalrev)*100;
    }else { 
        share3 = 0.0;
    }

    cout<<"Grocery & Produce    "<<count1<<"                 $BZ"<<subtotal1<<"              "<<share1<<"%\n";
    cout<<"Beverages & Snacks   "<<count2<<"                 $BZ"<<subtotal2<<"              "<<share2<<"%\n";
    cout<<"General Merchandise  "<<count3<<"                 $BZ"<<subtotal3<<"              "<<share3<<"%\n";

    cout<< "\nShift reconciliation completed successfully.\n"<<"Have a safe evening!";
}