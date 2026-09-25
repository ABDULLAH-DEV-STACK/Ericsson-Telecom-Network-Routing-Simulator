#include <iostream>
#include <regex>
#include <string>
#include "sqlite3.h"

using namespace std;

// --- CLASS 1 :Network Database  --- //
// Responsible for Databbase connection and database oprations 

class NetworkDatabase {
private: 
sqlite3* db; 
// Execute a SQL statement and report errors 
   bool executeSQL(const string& sql) {
    char* errorMessage = nullptr;
    int result = sqlite3_exec(
         db, 
         sql.c_str(),
         nullptr,
         nullptr,
         &errorMessage 
    );
          if (result != SQLITE_OK) {
                    cerr << "[Database Error] "
                                     << errorMessage << endl;
                                      sqlite3_free(errorMessage);
                                      return false;
          }

                   return true;
      }
public:
 // Contructor 
 NetworkDatabase() :
 db(nullptr) {
    // Open SQLite database
    int result = sqlite3_open ("telecom_network.db", &db);
    if (result != SQLITE_OK) {
        cerr << "[Database Error]" 
        << "Unable to open database." << endl;
        return;
    }
    cout << "[Database]Connection successful." << endl; 

    // Enable Foreign Key support
    executeSQL("PRAGMA foreign_keys = ON;");
    
    // Create Cell Towers table 
    string createTowers =
      "CREATE TABLE IF NOT EXISTS CellTowers ("
      "TowerID INTEGER PRIMARY KEY, "
      "Location TEXT NOT NULL, "
      "CurrentLoad INTEGER NOT NULL, "
      "CHECK(CurrentLoad >= 0 AND CurrentLoad <= 100)"
      ");";

         executeSQL(createTowers);
         
        // Create Call Logs Table 
        
        string createLogs =
          "CREATE TABLE IF NOT EXISTS CallLogs ("
          "CallID INTEGER PRIMARY KEY, "
          "TowerID INTEGER NOT NULL, "
          "Caller TEXT NOT NULL, "
          "Receiver TEXT NOT NULL, "
          "FOREIGN KEY (TowerID) REFERENCES CellTowers(TowerID)"
          ");";

        executeSQL(createLogs);



           // Insert Sample Towers


           string insertData = 
           "INSERT OR IGNORE INTO CellTowers "
           "(TowerID, Location, CurrentLoad) VALUES"
           "(1 , 'Downtown_Sector_A' , 85), "
              "(2 , 'North_Sector_B' , 30), "
                "(3 , 'West_Sector_C' , 95);";

                executeSQL(insertData);
      }

       // Return database connection 
       // 
       sqlite3* getDB() {
        return db;
       }


      // Display all Towers |
      void displayTowers() { 

     const char* sql = 
     "Select TowerID, Location, CurrentLoad" 
     "FROM CellTowers"
     "ORDER BY TowerID;";
      sqlite3_stmt* statement =
      nullptr;
        int result =
        sqlite3_prepare_v2(
            db, 
            sql,
            -1 ,
            &statement ,
            nullptr
        );
        if (result != SQLITE_OK) {
            cerr << "[Database Error]" 
            << sqlite3_errmsg(db) 
            << endl;
            return;
        }
        cout <<" \n -------------------- CELL TOWERS -------------------- \n";
         
        while 
        (sqlite3_step(statement)== SQLITE_ROW) {
         int towerID = 
         sqlite3_column_int(statement,0);
         const unsigned char* location =
            sqlite3_column_text(statement,1);
            int currentLoad =
            sqlite3_column_int(statement,2);
            cout << "TowerID: " << towerID
            << ", Location: " << location
            << ", CurrentLoad: " << currentLoad
            << "%" << endl;
            cout << "------------------------------------------------------" << endl;
        }
       sqlite3_finalize(statement);

      }
       
      // Update Tower Load 

      bool updateTowerLoad(int towerID, int newload) {
       if (newload < 0 || newload > 100) {
        cerr << "[Error] Invalid load value. Must be between 0 and 100." << endl;
        return false;
       }
       const char* sql =
       "UPDATE CellTowers SET CurrentLoad = ? WHERE TowerID = ?;";
       sqlite3_stmt* statement = nullptr;
       int result = sqlite3_prepare_v2(db, sql, -1, &statement, nullptr);
       if (result != SQLITE_OK) {
        cerr << "[Database Error] " << sqlite3_errmsg(db) << endl;
        return false;
       }
       // bind new load 
        sqlite3_bind_int(statement, 1, newload);

        // bind tower ID
        sqlite3_bind_int(statement, 2, towerID);
        result = sqlite3_step(statement);
        if (result != SQLITE_DONE) {
            cerr << "[Database Error] " << sqlite3_errmsg(db) << endl;
            sqlite3_finalize(statement);
            return false;
        }
        sqlite3_finalize(statement);
        return true;
     } 
      
     // Destructor
     ~NetworkDatabase() {
        if (db != nullptr) {
            int result = sqlite3_close(db);
            if (result != SQLITE_OK) {
                cerr << "[Database Error] Unable to close database: "
                     << sqlite3_errmsg(db) << endl;
            } else {
                cout << "[Database] Connection closed successfully." << endl;
            }
        }
 



    }
};

// --- CLASS 2 : TelecomRouter --- //
// Responsible for call-routing logic

class TelecomRouter {
 private :
 sqlite3* db ;
  public : 
 // Construtor 
 TelecomRouter(sqlite3* databaseConnection) {
    db = databaseConnection;
 }

 // Valid Phone Number 

 bool   isValidPhoneNumber(
    const string& phonenumber  
 ) {
  // Allow digits spacesand 
    regex phonepattern(R"(^[0-9][0-9 -]*$)");
    return regex_match(phonenumber, phonepattern);
 }
 // Route call 

 void routecall(
    const string& phoneNumber 
 ) {
    if (!isValidPhoneNumber(phoneNumber)) {
        cout << "\n============================================================"
             << endl;
        cout << "[Router] Invalid phone number." << endl;
        return;
    }

    cout << "[Router] Analyzing Tower Traffic..." << endl;

 // Find Tower With The Lowest Load 

 const char* findTowerSQL = 
 "SELECT TowerID, "
 "Location, "
 "CurrentLoad "
 "FROM CellTowers "
 "ORDER BY CurrentLoad ASC "
 "LIMIT 1;";

 sqlite3_stmt* statement =
 nullptr;
 int result = 
 sqlite3_prepare_v2(
   db,
   findTowerSQL,
   -1 ,
 &statement, 
   nullptr
 );

 if (result != SQLITE_OK) {
   
  cerr << "[Router Error]"
   << sqlite3_errmsg(db)
   << endl;
  return;
 }
  // Execute SELECT query 
   result = 
   sqlite3_step(statement);
    if (result == SQLITE_ROW)
    {
       // Get Tower Infromation 
        int towerID =
        sqlite3_column_int(statement, 0);
         const unsigned char* 
         location = 
         sqlite3_column_text(statement, 1);
         int currentload =
         sqlite3_column_int(statement, 2);
         cout << "[Network] Selected Tower:"
         << towerID
          << endl;
      cout << "[Network] Location :"
      << location
       <<  endl;
       cout << "[Network] Current Load :"
        << currentload 
        << "%" 
        << endl ;
        cout << "[Network] Call successfully routed ."
        << endl ;
        sqlite3_finalize(statement);

       // Save Call Log Using Prepared Statemnt 

       const char* logSQL =
       "INSERT INTO CallLogs"
       "(PhoneNumber, RoutedTowerID)"
       "VALUES (? , ?);"; 
       sqlite3_stmt*
       LogStatement =
       nullptr; 
       result =
       sqlite3_prepare_v2(
       db,
       logSQL,
       -1,
       &LogStatement,
       nullptr
       );
       if (result != 
        SQLITE_OK) {
        cerr << "[Database Error]"
        <<  sqlite3_errmsg(db)
        << endl;
          return;
     }
       // Bind phone number safely
       sqlite3_bind_text(
      LogStatement,
       1 ,
     phoneNumber.c_str(),
     -1,
     SQLITE_TRANSIENT );
         // Bind tower ID 
         sqlite3_bind_int(
              LogStatement,
              2 ,
              towerID
         );

         result =
         sqlite3_step(LogStatement);
           if (result != SQLITE_OK) {
            cerr <<"[Database Error]"
            << sqlite3_errmsg(db)
            << endl;
              cout << "[DATABASE]"
              << "Call Log Saved Successfully."
              << endl;
           }
           sqlite3_finalize(LogStatement);
    }
    else {
          cout << "[Network]"
          << "No available towers ."
          << endl;
          sqlite3_finalize(statement);
    }
      cout << "=========================================="
      << endl;
 }
};

// MAIN PROGRAM 

int main() {

cout << "===================================================="
<< endl;
cout << " ERICSSON TELECOM NETWORKING SIMULATER "
<< endl;

// Create Dtabase Object 

NetworkDatabase networkDb;


// Check Database Connection 

  if (networkDb.getDB() == nullptr )   {

     cerr << "[System Error]"
     << "Database Connection Failed. "
     << endl;
     return 1;
  }

  // Create Router 
  TelecomRouter router(
     networkDb.getDB()
  ) ;

  // Display Current Tower Status 

  networkDb.displayTowers();


  // Optional : Update Tower Load 

  char updateChoice ;
  cout << "\nDo you want to update a tower load? (y/n):";
  cin >> updateChoice;
  
  if (updateChoice == 'y'  || updateChoice == 'Y') {

   int towerID;
   int newLoad;
  cout << "Enter tower ID :";
  cin >> towerID;
  cout << "Enter new load (0-100):";
  cin >> newLoad;
  networkDb.updateTowerLoad(
      towerID,
      newLoad
  );
  }


  // Clear Input Buffer 


  cin.ignore();


  //Get Caller Number 

  string callerNumber;
  cout << "\nEnter Mobile Number"
       << "(example 555-0192):";
   getline (
      cin,
      callerNumber
   ); 
   cout << "\nSimulation Complete."
   << endl; 
   return 0;

}
