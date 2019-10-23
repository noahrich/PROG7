//------------------------------------------------------------------
// File name:   utility_Billing.cpp
// Assign ID:   PROG7
//
// Purpose:     Write the program to read the name of an input file,
//              open the file, and process each customer in the file.
//
// Author:      nrichardson Noah Richardson
//------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
    string file_name;
    long meter_start;
    long meter_end;
    string Cust_Name;
    int numCustomers = 0;
    float Charge, avgBill;
    long KWHused = 0, avgKWHused;
    float tot_Charges = 0;
    int badreadings = 0;
    int num;
    ifstream inF;
    string fname;
    long tot_KWHused;
    
    cout << endl;
    
cout << "Enter name of input file: ";
cin >> fname;
cout << endl;

inF.open(fname.c_str());
    if(inF.fail())
    {
   cout << "FATAL ERROR: Can not open file 'customers'" << endl;
   exit(1);
    }
// ------------------------------------------------------------------
//-| 1. Ask for customer Data
// ------------------------------------------------------------------
//   cout << "Enter Customer Data [PrevReading CurrReading CustomerName]: ";
// ------------------------------------------------------------------
//-| 2. Read customer Data
// ------------------------------------------------------------------
    while(inF >> meter_start >> meter_end)
    {

    inF.ignore();
    getline(inF, Cust_Name);
    numCustomers++;    
    

// ------------------------------------------------------------------
//-| 3. Display customer data 
// ------------------------------------------------------------------
    cout << endl;
    cout << meter_start << " " << Cust_Name << " " << meter_end;
    cout << endl;

// ------------------------------------------------------------------
//-| 4.  IF end_reading < start_reading output message: BAD METER READINGS: xxxxxxxx (START) xxxxxxx (END)
// ------------------------------------------------------------------
    if(meter_end < meter_start)
    {
        badreadings++;
        cout << endl;
        cout << "BAD METER READINGS:  " << meter_start << " (START)  " << meter_end << " (END)" << endl;
        cout << endl;
        cout << "-------------------------------------------------" << endl;
        cout << endl;
        cout << "CUSTOMER NAME: " << Cust_Name << endl;
        cout << endl;
        cout << "CHARGES DUE:    $DEFERRED" << endl;
        cout << endl;
        cout << "POWER USAGE:    ????? KWH" << endl;
        cout << endl;
        //cout << setfill('0') << setw(8);
        cout << "METER READINGS: ";
        cout << setfill('0');
            cout << setw(8) << meter_start;
            cout << " INITIAL  "; 
            cout << setw(8)<< meter_end; 
            cout << " FINAL" << endl;
        
    } else{   

       KWHused = meter_end - meter_start;
       tot_KWHused = KWHused + tot_KWHused;
       cout << endl;
        if(KWHused <=500)
        {
           Charge = 53.00 + 0.165 * KWHused;
           tot_Charges = Charge + tot_Charges;
        }
        else if(KWHused >=501 && KWHused <= 1000)
        {
            Charge = 75.50 + 0.125 * KWHused;
            tot_Charges = Charge + tot_Charges;
        }
        else if(KWHused >=1001 && KWHused <= 3000)
        {
            Charge = 125.75 + 0.117 * KWHused;
            tot_Charges = Charge + tot_Charges;
        }
        else
        {
            Charge = 400.07 + 0.017 * KWHused;
            tot_Charges = Charge + tot_Charges;
        }
        cout << "-------------------------------------------------" << endl;
        cout << endl;
        cout << "CUSTOMER NAME:  " << Cust_Name << endl;
        cout << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << "CHARGES DUE:    $ " << setw(6) << Charge <<endl;
        cout << endl;
        cout << fixed << showpoint << setprecision(0);
        cout << setfill(' ');
        cout << "POWER USAGE:    " << setw(5) << KWHused << " KWH" << endl;
        cout << endl;
        //cout << setfill('0') << setw(8);
        cout << "METER READINGS: ";
        cout << setfill('0');
            cout << setw(8) << meter_start;
            cout << " INITIAL  "; 
            cout << setw(8)<< meter_end; 
            cout << " FINAL" << endl;
 
        }
    cout << endl;
    cout << "-------------------------------------------------";
    cout << endl;
    }
// ------------------------------------------------------------------
//-| 4.1  Calcalute the difference of readings
// ------------------------------------------------------------------
// ------------------------------------------------------------------
//-| 5. Calculate the charges due
// ------------------------------------------------------------------
  
// ------------------------------------------------------------------
//-| 6. Display charges due
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//-| 7. Display Power Usage(the differenice)
// ------------------------------------------------------------------

// ------------------------------------------------------------------
//-| 8. Display initial meter readings and final meter readings
// ------------------------------------------------------------------
    cout << endl;
    num = numCustomers - badreadings;
    cout << setfill(' ');
    cout << "#CUSTOMERS     = " << setw(4) << numCustomers << endl;
    cout << "#BAD READINGS  = " << setw(4) << badreadings << endl;
    cout << endl;
    cout << "TOTAL KWH USED = " << setw(8)<< tot_KWHused << endl;
    avgKWHused = tot_KWHused / num;
    cout << "AVG KWH USED   = " << setw(8)<< avgKWHused << endl; 
    cout << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "TOTAL CHARGES = $  " << setw(7) << tot_Charges << endl;
    avgBill = tot_Charges/num;
    cout << "AVG BILL      = $   " << setw(7) << avgBill << endl;
    cout << endl;
    cout << endl << "(c) 2019, nrichardson Noah Richardson" << endl;
    cout << endl;

   return 0;

}//main
