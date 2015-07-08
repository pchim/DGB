// File: days2.0
// "Days go by..."
// Started: November 2, 2009
// Last Modified:

#include <iostream>
#include <iomanip>

using namespace std;

void enter();
void displayTimeEne();
void addTEFCS(int, int, int, int, int);
void addSCIC(int, int, int, int);
void displayFinal1();
void displayFinal2();
void doHw();
void toilet();
void study();
void inBed();
void inBedroom();
void bathroom();
void livRoom();
void porch();
void schoolSteps();
void busStop(char);
void school();
int minsLeftClass(int);
void classMESHL(int);
void cafeteria();



int TEFCS[] = {530, 50, 50, 50, 50};        // Time, Energy, Fun, Clean, Stom
int MF[] = {80, 0,};                       // money, food

const int maxNumClass = 5;                         // max number of classes
const int numClass = 4;                         // user inputted number of classes in Array
int gradeMESHL[maxNumClass];           // grade math, eng, sci, hist, lang
int realNumClass = 5;                     // user inputted real number of classes

// str, comm, intel, charisma
int SCIC[] = {50, 50, 0, 50};           // intel changes to avg in enter funct
int hwMESHL[maxNumClass];                          // homework
int startMESHL[maxNumClass] = {800, 1000, 1100, 1300, 1400};
int endMESHL[maxNumClass] = {1000, 1100, 1200, 1400, 1500};
int payAt[maxNumClass];

int f[] = {50, 50, 50};                 // friend
int alarmSet = 530;
int hwYes = 0;

char nameMESHL[maxNumClass][30] = {"Math", "English", "Science", "History", "Language"};

// Counting vars
int teeth = 0;
int workout = 0;

int main()
{
        /*
        // starts here

        cout << "How many classes do you have? ";
        cin >> numClass;
        realNumClass = numClass;
        --numClass;

        cout << "Enter the name of the first class of the day. ";
        cin >> nameMESHL[0];
        cout << "When does " << nameMESHL[0] << " class start? ";
        cin >> startMESHL[0];
        for (int counter = 1; counter <= numClass; counter++)
        {
                cout << "Enter the name of the next class. ";
                cin >> nameMESHL[counter];
                cout << "When does " << nameMESHL[counter] << " class start? ";
                cin >> startMESHL[counter];
        }


        // When using this, change const int numClass to int numClass and delete the constant.
        // When not using this, change use numClass as const int, and leave
        // it as 4, which equals 5 classes in an array 
        // ends here
        */
        



        for (int counter = 0; counter <= numClass; counter++) // grade for each class
                gradeMESHL[counter] = 75;                     // initialization
        for (int counter = 0; counter <= numClass; counter++)
                hwMESHL[counter] = 0;
        for (int counter = 0; counter <= numClass; counter++)
                payAt[counter] = 0;


        cout << "Welcome!" << endl
             << "Enter x to start! =)" << endl;
        inBed();
        cout << endl;
        displayFinal1();
        displayFinal2();
        enter();

        return 0;
}




                        //******************************
                        //     Location Functions      *
                        //******************************


// inBed Functions ------------------------------

void inBed()
{
	char choice1;	// choice
        char newLoc = '0';

      do {
      enter();
	displayTimeEne();
	cout << "A. The alarm is ringing,";
	cout << " what do you do now?" << endl;
	cout << "\t1) Sleep 5 more mins" << endl;
	cout << "\t2) Sleep 30 more mins" << endl;
	cout << "\t3) Get out of bed slowly (5 mins)" << endl;
	cout << "\t4) Get out of bed quickly (0 mins)" << endl;

        cin >> choice1;
                switch (choice1)
		{
			case '1': addTEFCS(5, 5, 0, -2, 0);
                                  addSCIC(0, -1, 0, 0);
                                  cout << "\nYou take a quick nap for 5 minutes.\n"
				           << endl;

                                  break;
			case '2': addTEFCS(30, 15, 0, -5, 0);
				  addSCIC(0, -2, 0, 0);
                                  cout << "\nThe alarm is set to ring in 30 minutes.\n"
                                     << " " << endl;

                                  break;
			case '3': addTEFCS(5, -2, 0, 0, 0);
				  addSCIC(0, 0, 0, 0);
                                  if (TEFCS[0] == alarmSet + 5)
                                  {
                                        addTEFCS(0, 0, 0, 0, 0);
                                        addSCIC(0, 1, 0, 0);
                                        cout << "\nYou get up on your first try, slowly.\n"
                                             << endl;
                                  }
                                  else
                                  {
                                        cout << "\nYou finally wake up, slowly.\n"
                                        << endl;
                                  }
                                  newLoc = '1';
                                  inBedroom();
                                  break;
			case '4': addTEFCS(0, -5, -2, 0, 0);
				  addSCIC(0, 0, 0, 0);
                                  if (TEFCS[0] == alarmSet)
                                  {
                                        addTEFCS(0, 0, 0, 0, 0);
				        addSCIC(0, 2, 0, 0);
					cout << "\nYou jump out of bed as soon as Favesong plays.\n"
					     << endl;
                                  }
                                  else
                                  {
					cout << "\nYou finally decide to wake up and you jump right out of bed.\n"
					     << endl;
                                  }
                                  newLoc = '1';
                                  inBedroom();
                                  break;
                        default: cout << "\nThat's not one of the choices.\n" << endl;
                }
        } while (newLoc == '0');
}


// inBedroom Function----------------------------------

void inBedroom()
{
	char choice1;	// choice
        char newLoc = '0';

        do {
        enter();
	displayTimeEne();
	cout << "B. You are now in your room. ";
	cout << "What do you want to do? " << endl;
        if (hwYes > 0)
                cout << "\th. Do Homework" << endl;
	cout << "\t1) Go to Sleep" << endl;
	cout << "\t2) Tidy Up Room (10 mins)" << endl;
	cout << "\t3) Watch TV (10 mins)" << endl;
	cout << "\tx. Leave." << endl;



        cin >> choice1;
                switch (choice1)
		{
			case '1': addTEFCS(0, 0, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\n"
                                       << " "
                                       << " "
                                       << " "
                                       << endl;
                                  newLoc = '1';
                                  break;
			case '2': addTEFCS(10, -10, 0, 0, 0);
                                  addSCIC(0, 1, 0, 0);
                                  // tidy room function
                                  cout << "\nYou find some mess and clean it up.\n"
                                       << " "
                                       << " "
                                       << " "
				       << endl;

                                  break;
			case '3': addTEFCS(10, -2, 5, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\nYou watch some tv for a bit.\n"
                                       << " "
                                       << " "
                                       << " "
                                      << endl;

                                  break;
                        case 'h': doHw();

                                  break;
			case 'x': cout << "\nWhere do you want to go?" << endl
                                       << "\t1) Bathroom " << endl
                                       << "\t2) Living Room " << endl
                                       << "\tx. Stay " << endl;
	                          cin >> newLoc;
	                          switch(newLoc)
		                  {       case '1': cout << "\nNow going to the bathroom.\n";
                                                    bathroom();
			                            break;
		                          case '2': cout << "\nNow going to the living room.\n";
                                                    livRoom();
			                            break;
                                          case 'x': cout << "\nYou decided to stay.\n";
                                                    inBedroom();
			                            break;
                                          case '0': cout << "\nInvalid choice.\n" << endl;
                                                    break;
		                          default: cout << "\nInvalid choice.\n" << endl;
			                           inBedroom();
                                  }
                                  break;
                        default: cout << "\nThat's not one of the choices.\n";
		   }
        } while (newLoc == '0');
}


// bathroom Function------------------------------------
void bathroom()
{
	char choice1;	// choice
        char newLoc = '0';


        do {
        enter();
	displayTimeEne();
	cout << "C. You are now in the bathroom.";
	cout << " " << endl;
	cout << "\t1) Shower (20 mins)" << endl;
	cout << "\t2) Use Toilet (5 mins)" << endl;
	cout << "\t3) Brush Teeth (5 mins)" << endl;
	cout << "\tx. Leave " << endl;

	cin >> choice1;
		switch (choice1)
		{
			case '1': addTEFCS(20, 10, 0, 30, 0);
                                  addSCIC(0, 1, 0, 0);
                                  cout << "\nYou take a shower. Twenty minutes pass.\n"
                                       << " "
                                       << " "
                                       << " "
                                       << endl;
                                  break;
			case '2': toilet();
                                  break;
			case '3': addTEFCS(5, -3, 0, 5, 0);
                                  if (teeth == 0)
                                  {
                                          addSCIC(0, 1, 0, 0);
                                          teeth++;
                                  }
                                  cout << "\nYou brush your teeth.\n"
                                       << " "
                                       << " "
                                       << " "
                                       << endl;
                                  break;
			case 'x': cout << "\nWhere do you want to go?" << endl
                                       << "\t1) Bedroom " << endl
                                       << "\t2) Living Room " << endl
                                       << "\tx. Stay " << endl;
	                          cin >> newLoc;
	                          switch(newLoc)
		                  {
                                        case '1': cout << "\nNow going to the bedroom.\n";
                                                  inBedroom();
			                          break;
		                        case '2': cout << "\nNow going to the living room.\n";
                                                  livRoom();
			                          break;
		                        case 'x': cout << "\nYou decided to stay.\n";
                                                  bathroom();
			                          break;
                                        case '0': cout << "\nInvalid choice.\n" << endl;
                                                  break;
		                        default: cout << "\nInvalid choice.\n" << endl;
			                         bathroom();
                                  }
                                  break;
                        default: cout << "\nThat's not one of the choices.\n";
		   }
        } while (newLoc == '0');

}


// livRoom Function---------------------------------------
void livRoom()
{
	char choice1;	// choice
	char newLoc = '0';

        do {
        enter();
	displayTimeEne();
	cout << "D. You are now in the living room.";
	cout << " " << endl;
	cout << "\t1) Eat a meal (30 mins)" << endl;
	cout << "\t2) Study (15 mins)" << endl;
	cout << "\t3) Work out (20 mins)" << endl;
	cout << "\t4) Practice speech (20 mins)" << endl;
	cout << "\tx. Leave " << endl;

	cin >> choice1;
		switch (choice1)
		{
			case '1': addTEFCS(30, 25, 0, 0, 20);
                                  addSCIC(0, 0, 0, 0);
                                  MF[1] += 1;
                                  cout << "\nYou prepare and eat a meal.\n"
                                       << " "
                                       << " "
                                       << " "
                                       << endl;

                                  break;
			case '2': cout << "\nYou chose to study.\n"
                                       << " "
                                       << " "
                                       << " "
                                       << endl;
                                  study();

                                  break;
			case '3': addTEFCS(20, -15, 0, -10, 0);
                                  if (workout == 0)
                                  {
                                  addSCIC(0, 1, 0, 0);
                                  workout++;
                                  }
                                  cout << "\nYou work out for twenty minutes.\n"
                                       << " "
                                       << " "
                                       << " "
                                       << endl;

                                  break;
			case '4': addTEFCS(20, -8, -3, 0, 0);
                                  addSCIC(0, 0, 0, 2);
                                  cout << "\nYou practice in the mirror for twenty minutes.\n"
                                       << " "
                                       << " "
                                       << " "
                                       << endl;

                                  break;
			case 'x': cout << "\nWhere do you want to go?" << endl
                                       << "\t1) Bedroom " << endl
                                       << "\t2) Bathroom " << endl
                                       << "\t3) Front Porch " << endl
                                       << "\tx. Stay " << endl;
	                          cin >> newLoc;
	                          switch(newLoc)
		                  {
                                        case '1': cout << "\nNow going to the bedroom.\n";
                                                  inBedroom();
			                          break;
		                        case '2': cout << "\nNow going to the bathroom.\n";
                                                  bathroom();
			                          break;
                                        case '3': addTEFCS(1, -1, 0, 0, 0);
                                                  addSCIC(0, 0, 0, 0);
                                                  cout << "\nNow going to the porch.\n";
                                                  porch();
			                          break;
		                        case 'x': cout << "\nYou decided to stay.\n";
                                                  livRoom();
                                                  break;
                                        case '0': cout << "\nInvalid choice.\n" << endl;
                                                  break;
		                        default: cout << "\nInvalid choice.\n" << endl;
                                                 livRoom();
                                  }
                                  break;
                        default: cout << "\nThat's not one of the choices.\n";
		   }
        } while (newLoc == '0');
}






                        //**************************************
                        //       Transportation Funtions       *
                        //**************************************



// porch Function -----------------------------------------
void porch()
{
	char choice1;	// choice
	char newLoc = '0';	// location
        char currentLoc = 'h';

        do {
        enter();
	displayTimeEne();
	cout << "E. You are now on your front porch.";
	cout << " " << endl;
	cout << "\t1) Walk to the bus stop (10 mins)" << endl;
	cout << "\t2) Run to the bus stop (5 mins)" << endl;
	cout << "\th. Go inside house" << endl;

	cin >> choice1;
		switch (choice1)
		{
			case '1': addTEFCS(10, -5, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\nYou decide to walk to the bus stop.\n"
                                       << " "
                                       << endl;
                                  newLoc = '1';
                                  busStop(currentLoc);
                                  break;
			case '2': addTEFCS(5, -10, -1, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\nYou decide to run to the bus stop.\n"
                                       << " "
                                       << endl;
                                  newLoc = '1';
                                  busStop(currentLoc);
                                  break;
			case 'h': addTEFCS(1, -1, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\nYou go into the house.\n"
                                       << " "
                                       << endl;
                                  newLoc = '1';
                                  livRoom();
                                  break;
                        default: cout << "\nThat's not one of the choices.\n";
		   }
        } while (newLoc == '0');
}

// busStop Function--------------------------------------------------
void busStop(char currentLoc)
{
	char choice1;	// choice
	char newLoc = '0';	// location

        do {
        enter();
	displayTimeEne();
	cout << "E. You are now at the bus stop.";
	cout << " " << endl;

        // bus stop by your house
        if (currentLoc == 'h')
        {
        	cout << "\ts. Take the bus to school" << endl;
	        cout << "\td. Take the bus to downtown" << endl;
	        cout << "\t1) Walk to your house (10 mins)" << endl;
	        cout << "\t2) Run to your house (5 mins)" << endl;
        }

        // bus stop by school
        if (currentLoc == 's')
        {
                cout << "\td. Take the bus to downtown" << endl;
	        cout << "\th. Take the bus to your house" << endl;
	        cout << "\t1) Walk to your school (10 mins)" << endl;
	        cout << "\t2) Run to your school (5 mins)" << endl;
        }

        // bus stop by your house
        if (currentLoc == 'd')
        {
                cout << "\ts. Take the bus to school" << endl;
                cout << "\th. Take the bus to your house" << endl;
	        cout << "\t1) Walk to your house" << endl;
	        cout << "\t2) Run to your house" << endl;
        }


	cin >> choice1;
		switch (choice1)
		{
			case '1': switch (currentLoc)
                                  {
                                        case 'h': addTEFCS(10, -5, 0, 0, 0);
                                                  addSCIC(0, 0, 0, 0);
                                                  cout << "\nYou decide to walk to your house.\n"
                                                       << " "
                                                       << endl;
                                                  newLoc = '1';
                                                  porch();
                                                  break;
                                        case 's': addTEFCS(10, -5, 0, 0, 0);
                                                  addSCIC(0, 0, 0, 0);
                                                  cout << "\nYou decide to walk to school.\n"
                                                       << " "
                                                       << endl;
                                                  newLoc = '1';
                                                  schoolSteps();
                                  }
                                  break;
			case '2': switch (currentLoc)
                                  {
                                        case 'h': addTEFCS(5, -10, -1, 0, 0);
                                                  addSCIC(0, 0, 0, 0);
                                                  cout << "\nYou decide to run to your house.\n"
                                                       << " "
                                                       << endl;
                                                  newLoc = '1';
                                                  porch();
                                                  break;
                                        case 's': addTEFCS(5, -10, -1, 0, 0);
                                                  addSCIC(0, 0, 0, 0);
                                                  cout << "\nYou decide to run to school.\n"
                                                       << " "
                                                       << endl;
                                                  newLoc = '1';
                                                  schoolSteps();
                                  }
                                  break;
			case 'h': switch (currentLoc)
                                  {
                                        case 'h': addTEFCS(0, 0, 0, 0, 0);
                                                  addSCIC(0, 0, 0, 0);
                                                  cout << "\nYou are already at the stop by your house.\n"
                                                       << " "
                                                       << endl;
                                                  newLoc = '1';
                                                  busStop('h');
                                                  break;
                                        case 's': addTEFCS(7, -1, 0, 0, 0);
                                                  addSCIC(0, 0, 0, 0);
                                                  cout << "\nYou decided to take the bus towards your house.\n"
                                                       << " "
                                                       << endl;
                                                  newLoc = '1';
                                                  busStop('h');
                                  }
                                  break;
                        case 's': switch (currentLoc)
                                  {
                                        case 'h': addTEFCS(7, -1, 0, 0, 0);
                                                  addSCIC(0, 0, 0, 0);
                                                  cout << "\nYou decide to take the bus towards school.\n"
                                                       << " "
                                                       << endl;
                                                  newLoc = '1';
                                                  busStop('s');
                                                  break;
                                        case 's': addTEFCS(0, 0, 0, 0, 0);
                                                  addSCIC(0, 0, 0, 0);
                                                  cout << "\nYou are already at the bus stop by school.\n"
                                                       << " "
                                                       << endl;
                                                  newLoc = '1';
                                                  busStop('s');
                                 }
                                 break;
                        default: cout << "\nThat's not one of the choices.\n";
		   }
        } while (newLoc == '0');
}


// schoolSteps Function -----------------------------------------
void schoolSteps()
{
	char choice1;	// choice
	char newLoc = '0';	// location
        char currentLoc = 's';

        do {
        enter();
	displayTimeEne();
	cout << "E. You are now at your school's steps.";
	cout << " " << endl;
	cout << "\t1) Walk to the bus stop (10 mins)" << endl;
	cout << "\t2) Run to the bus stop (5 mins)" << endl;
	cout << "\ts. Go into the school" << endl;

	cin >> choice1;
		switch (choice1)
		{
			case '1': addTEFCS(10, -5, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\nYou decide to walk to the bus stop.\n"
                                       << " "
                                       << endl;
                                  newLoc = '1';
                                  busStop(currentLoc);
                                  break;
			case '2': addTEFCS(5, -10, -1, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\nYou decide to run to the bus stop.\n"
                                       << " "
                                       << endl;
                                  newLoc = '1';
                                  busStop(currentLoc);
                                  break;
			case 's': addTEFCS(1, -1, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\nYou go into the school.\n"
                                       << " "
                                       << endl;
                                  newLoc = '1';
                                  school();
                                  break;
                        default: cout << "\nThat's not one of the choices.\n";
                 }
        } while (newLoc == '0');
}



                        //******************************
                        //       School Funtions       *
                        //******************************

// school Function---------------------------------------------------
void school()
{
        char choice1;
        int index = 20;
        int startWindow;
        int endWindow;



        enter();
	displayTimeEne();

        for (int counter = 0; counter <= numClass; counter++)
        {
                if (TEFCS[0] >= startMESHL[counter] && TEFCS[0] <= startMESHL[counter] + 10)
                        index = counter;
        }

        cout << "I. You are now at school. What do you want to do?" << endl;

        if (index <= numClass && TEFCS[0] >= startMESHL[index] && TEFCS[0] <= startMESHL[index] + 10)
                cout << "\tc. Go to " << nameMESHL[index] << " class" << endl;
        cout << "\t1) Go to the cafeteria" << endl;
        cout << "\t2) Go to the library" << endl;
        cout << "\tx. Leave school" << endl;


	cin >> choice1;
		switch (choice1)
		{
			case 'c': if (index <= numClass && TEFCS[0] >= startMESHL[index] && TEFCS[0] <= startMESHL[index] + 10)
                                  {
                                  cout << "\nYou decide to go to your class.\n"
                                       << " "
                                       << endl;
                                  classMESHL(index);
                                  }
                                  break;
			case '1': addTEFCS(1, -1, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\nYou decide to go to the cafeteria\n"
                                       << " "
                                       << endl;

                                  cafeteria();
                                  break;
			case '2': addTEFCS(0, 0, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\nYou go into the library.\n"
                                       << " "
                                       << endl;

                                  school();
                                  break;
                        case 'x': addTEFCS(1, -1, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\nYou decide to leave school.\n"
                                       << endl;
                                  schoolSteps();
                                  break;
                        default: cout << "\nThat's not one of the choices.\n";
                                 school();
                 }


}

// inClass Function ----------------------------------------------------
void classMESHL(int index)
{
        char choice1;
        char newLoc = '0';

        for (int minsLeft = minsLeftClass(index);
             minsLeft > 0 && newLoc == '0';
             minsLeft = minsLeftClass(index))
        {
        enter();
	displayTimeEne();
        cout << "Minutes left until end of class: " << minsLeft << endl;
        cout << "You are now in " << nameMESHL[index] << " class." << endl;
        if (minsLeft >= 5)
        {
	cout << "\t1) Pay attention (10 mins)" << endl;
	cout << "\t2) Go to sleep (15 mins)" << endl;
	cout << "\t3) Talk to friend (15 mins)" << endl;
	cout << "\t4) Doodle (5 mins)" << endl;
        }
        cout << "\t5) Wait until class ends" << endl;
	cout << "\tx. Leave" << endl;

	cin >> choice1;
		switch (choice1)
		{
			case '1': if (minsLeft >= 10)
                                  {
                                  addTEFCS(10, -2, -3, 0, 0);
                                  addSCIC(0, 1, 0, 0);
                                  gradeMESHL[index]++;
                                  cout << "\nYou pay attention to the teacher for 10 minutes.\n"
                                       << " "
                                       << endl;
                                  }
                                  else
                                        cout << "\nThere's not enough time for that.\n";
                                  break;
			case '2': if (minsLeft >= 15)
                                  {
                                  addTEFCS(15, 25, 0, 0, 0);
                                  addSCIC(0, -1, 0, 0);
                                  gradeMESHL[index]--;
                                  cout << "\nYou take a nice nap for 15 minutes. You gain 25 energy.\n"
                                       << " "
                                       << endl;
                                  }
                                  else
                                        cout << "\nThere's not enough time for that.\n";
                                  break;
			case '3': if (minsLeft >= 15)
                                  {
                                  addTEFCS(15, -2, 3, 0, 0);
                                  addSCIC(0, -1, 0, 1);
                                  cout << "\nYou talk to classmate1 for 15 minutes instead of paying attention.\n"
                                       << " "
                                       << endl;
                                  }
                                  else
                                        cout << "\nThere's not enough time for that.\n";
                                  break;
			case '4': if (minsLeft >= 5)
                                  {
                                  addTEFCS(5, -1, 9, 0, 0);
                                  addSCIC(0, -1, 0, 0);
                                  cout << "\nYou doodle in your notepad for 5 minutes.\n"
                                       << " "
                                       << endl;
                                  }
                                  else
                                        cout << "\nThere's not enough time for that.\n";
                                  break;
                        case '5': addTEFCS(minsLeft, 0, 0, 0, 0);
                                  cout << "\nYou wait until the end of class.\n"
                                       << " "
                                       << endl;
                                  break;
			case 'x': cout << "Okay, you sneak out quietly.\n" << endl;
                                  addTEFCS(1, -1, 5, 0, 0);
                                  addSCIC(0, -2, 0, 0);
                                  gradeMESHL[index]--;
                                  newLoc = '1';
                                  school();
                                  break;
                        default: cout << "\nThat's not one of the choices.\n";
                }
        }

        if (newLoc == '0')
        {
        enter();
        hwMESHL[index]++;
        hwYes++;
        displayTimeEne();
        cout << "\nClass is over now. You recieve today's homework, and it's due tomorrow.\n"
             << "Enter x to continue.\n" << endl;
        school();
        }

}


// cafeteria Function -------------------------------------------------------------
void cafeteria()
{
	char choice1;	// choice
	char newLoc = '0';	// location

        do {
        enter();
	displayTimeEne();
	cout << "J. You are now in the school cafeteria.";
	cout << " " << endl;
	cout << "\t1) Buy and eat a meal (30 mins, $5)" << endl;
	cout << "\t2) Buy and eat a snack (15 mins, $2)" << endl;
	cout << "\t3) Eat leftovers (5 mins)" << endl;
	cout << "\t4) Talk to classmate1 (15 mins)" << endl;
	cout << "\tx. Leave." << endl;


	cin >> choice1;
		switch (choice1)
		{
			case '1': addTEFCS(30, 25, 0, -5, 20);
                                  addSCIC(0, 0, 0, 0);
                                  MF[0] += -5;
                                  MF[1] += 1;
                                  cout << "\nYou buy a meal, sit down, and eat it.\n"
                                       << " "
                                       << endl;
                                  break;
			case '2': addTEFCS(15, 10, 0, -3, 10);
                                  addSCIC(0, 0, 0, 0);
                                  MF[0] += -2;
                                  cout << "\nYou buy a snack and eat it all.\n"
                                       << " "
                                       << endl;
                                  break;
			case '3': addTEFCS(5, 5, -3, -5, 8);
                                  addSCIC(0, 0, 0, -1);
                                  cout << "\nYou find some leftovers and fill some hunger.\n"
                                       << " "
                                       << endl;
                                  break;
			case '4': addTEFCS(15, -3, 3, 0, 0);
                                  addSCIC(0, 0, 0, 1);
                                  cout << "\nYou talk to classmate1 for 15 minutes.\n"
                                       << " "
                                       << endl;
                                  break;
			case 'x': addTEFCS(1, -1, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\nYou decide to go back to the main school hall\n"
                                       << endl;
                                  newLoc = '1';
                                  school();
                                  break;
                        default: cout << "\nThat's not one of the choices.\n";
		   }
        } while (newLoc == '0');
}





























                        //******************************
                        //       Status Functions      *
                        //******************************

void doHw()
{
        int choice1;

        if (hwYes <= 0)
                cout << "\nYou have no Homework!\n" << endl;

        if (hwYes > 0)
        {
                cout << "\nWhich Homework?" << endl;
                for (int counter = 0; counter <= numClass; counter++)
                {
                if (hwMESHL[counter] == 1)
                        cout << "\t" << (counter + 1) << ") " << nameMESHL[counter]
                             << " homework." << endl;
                }
                cin >> choice1;
                choice1--;
                if (hwMESHL[choice1] > 0)
                {
                        hwMESHL[choice1]--;
                        hwYes--;
                }
        }


}

void toilet()
{
        addTEFCS(5, -2, 0, -2, -3);
        addSCIC(0, 0, 0, 0);
        MF[1] = 0;
        cout << "\nYou used the toilet. There's no more food in you.\n"
             << " "
             << " "
             << " "
             << endl;
}

void study()
{
        int index;
        char again;

        do {
        enter();
	displayTimeEne();
	cout << "X. What class do you want to study for?";
	cout << " " << endl;

        for (int counter = 0; counter <= numClass; counter++)
        {
                cout << "\t" << (counter + 1) << ") "<< nameMESHL[counter] << endl;
        }

        cin >> index;

        gradeMESHL[(index - 1)] += 2;

        addTEFCS(15, -5, -1, 0, 0);
        addSCIC(0, 1, 0, 0);

        cout << "\nYou study " << nameMESHL[index - 1] << " for 15 minutes.\n";
        cout << "Do you want to continue studying? (y/n)\n" << endl;

        cin >> again;
                if (again == 'y' || again == 'Y')
                        cout << "\nYou chose to keep on studying.\n";
        } while (again == 'y' || again == 'Y');

        cout << "\nYou decided to stop studying.\n";
}

int minsLeftClass(int index)
{
        int minsLeft;

        if (endMESHL[index] % 100 < TEFCS[0] % 100)
        minsLeft = endMESHL[index] - TEFCS[0] - 40 * ((endMESHL[index] - TEFCS[0]) / 100 + 1);
        else
        minsLeft = endMESHL[index] - TEFCS[0] - 40 * ((endMESHL[index] - TEFCS[0]) / 100);

        return minsLeft;
}



                        //******************************
                        //    Time/Energy Functions    *
                        //******************************



void enter()
{
        char enter;
        int totalGrade = 0;

        cin.ignore();
        cin.get(enter);

        for (int counter = 0; counter <= numClass; counter++)
                totalGrade += gradeMESHL[counter];

        SCIC[2] = (totalGrade / realNumClass);
}

void displayFinal1()
{
	displayTimeEne();
	cout << "Money:   " << MF[0] << endl << endl;
	cout << "Fun:          " << TEFCS[2] << endl;
        cout << "Cleanliness:  " << TEFCS[3] << endl;
	cout << "Stomach:      " << TEFCS[4] << endl;

}

void displayFinal2()
{
	cout << "Strength:     " << SCIC[0] << endl;
	cout << "Commitment:   " << SCIC[1] << endl;
	cout << "Intelligence: " << SCIC[2] << endl;
	cout << "Charisma      " << SCIC[3] << endl;
}









void addTEFCS(int addMins, int eneAdd, int funAdd, int cleAdd, int stoAdd)
{
        if (addMins >= 0)
        {
                for (int count = 1; count <= addMins; count++)
                {
                        TEFCS[0] += 1;
                        if (TEFCS[0] % 100 == 60)
                        {
                                TEFCS[0] += 40;
                                TEFCS[4] += -4;
                                TEFCS[1] += -4;
                                TEFCS[2] += -2;
                        }
                        if (TEFCS[0] == 2400)
                                TEFCS[0] = 0;
                }
        }

        else
        {
                for (int count = -1; count >= addMins; count--)
                {
                        TEFCS[0] += -1;
                        if (TEFCS[0] % 100 == 99)
                                TEFCS[0] += -40;
                        if (TEFCS[0] == -1)
                                TEFCS[0] = 2359;
                }
        }

	TEFCS[1] += eneAdd;
	TEFCS[2] += funAdd;
        TEFCS[3] += cleAdd;
	TEFCS[4] += stoAdd;
}


void addSCIC(int strAdd, int comAdd, int telAdd, int chaAdd)
{
        SCIC[0] += strAdd;
	SCIC[1] += comAdd;
        for (int index = 0; index <= 4; index++)
                gradeMESHL[index] += telAdd;
	SCIC[3] += chaAdd;
}

void displayTimeEne()
{
        const int SPACES = 9;
        int hours = TEFCS[0] / 100,
            hoursAfter1300 = TEFCS[0] / 100 - 12,
            mins = TEFCS[0] % 100;


        cout << setw(8) << left << "Time:";
        cout << fixed << right;

        if (TEFCS[0] < 100)
        {
                cout << cout.fill('0');
                cout << "12:"
                     << setw(2) << mins << " " << endl;
        }
        else if (TEFCS[0] < 1300)
        {
                cout << cout.fill('0');
                cout << hours << ":"
                     << setw(2) << mins << (TEFCS[0] < 1200 ? " " : ".") << endl;
        }
        else
        {
                cout << cout.fill('0');
                cout << hoursAfter1300 << ":"
                     << setw(2) <<  mins << "." << endl;
        }

        cout.fill(' ');
	cout << setw(SPACES) << left << "Energy:" << right << TEFCS[1];
	cout << endl;

}



/*
void NAME()
{
	char choice1;	// choice
	char newLoc = '0';	// location

        do {
        enter();
	displayTimeEne();
	cout << "X. ";
	cout << " " << endl;
	cout << "\t1) " << endl;
	cout << "\t2) " << endl;
	cout << "\t3) " << endl;
	cout << "\t4) " << endl;

	cin >> choice1;
		switch (choice1)
		{
			case '1': addTEFCS(0, 0, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\n\n"
                                       << " "
                                       << endl;
                                  break;
			case '2': addTEFCS(0, 0, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\n"
                                       << " "
                                       << endl;
                                  break;
			case '3': addTEFCS(0, 0, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\n"
                                       << " "
                                       << endl;
                                  break;
			case '4': addTEFCS(0, 0, 0, 0, 0);
                                  addSCIC(0, 0, 0, 0);
                                  cout << "\n"
                                       << " "
                                       << endl;
                                  break;
			case 'x': cout << "\nWhere do you want to go?" << endl
                                       << "\t1) L1 " << endl
                                       << "\t2) L2 " << endl
                                       << "\tx. L3 " << endl;
	                          cin >> newLoc;
	                          switch(newLoc)
                                  {
		                        case '1': cout << "\nNow going to the .\n";
                                                  BR();
			                          break;
		                        case '2': cout << "\nNow going to the .\n";
                                                  DR();
			                          break;
		                        case '3': cout << "\nNow going to the .\n";
                                                  NR();
			                          break;
                                        case 'x': cout << "\nYou decided to stay.\n;
                                                  OR();
                                                  break;
		                        default: cout << "\nInvalid choice.\n" << endl;
			                         OR();
                                  }
                                  break;
                        default: cout << "\nThat's not one of the choices.\n";
		   }
        } while (newLoc == '0');
}
*/
