 #include <math.h> // include math functions
/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On a new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) Instantiate 1 or 2 instances of each of your user-defined types in the main function at the bottom of that file, and call some of those member functions.
 
 3) make them print out something interesting via std::cout
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type
{
    int a; //a member variable
    UDT() { a = 0; }             //3) the constructor
    void printThing()            //1) the member function
    {
        std::cout << "UDT::printThing() " << a << std::endl;  //5) printing out something interesting
    }
};

int main()
{
    UDT foo;              //4) instantiating a UDT in main()
    foo.printThing();     //4) calling a member function of the instance that was instantiated.
    
    return 0;
}
}

//insert Example::main() into main() of user's repo.



/*
 1)
 */



struct BoulderProblem
{
    int problemGrade;
    double wallAngle;
    
    BoulderProblem()
    {
        problemGrade = 3;
        wallAngle = 30;
    }

    struct Hold
    {
        int holdType;
        double holdSize; 
        double holdHeight;

        Hold()
        {
            holdType = 2;
            holdSize = 0.8;
            holdHeight = 1;
        }

        void printHoldInfo()
        {
            std::cout << "Hold Type: " << holdType;
            std::cout << "\nHold Size: " << holdSize;
            std::cout << "\nHold Height: " << holdHeight;
            std::cout << std::endl;
        }
    };

    double calculateDifficulty( double ropeLength );

    Hold crimp;
};

double BoulderProblem::calculateDifficulty( double ropeLength )
{
    std::cout << "Calculating difficulty...\n";
    return ((problemGrade * crimp.holdType) / crimp.holdSize) - ropeLength;
}

/*
 2)
 */

struct TopRopeRoute
{
    double wallAngle;

    TopRopeRoute()
    {
        wallAngle = 10;
    }

    struct RouteGrade
    {
        double gradeNumber;
        char gradeLetter; 
        
        RouteGrade()
        {
            gradeNumber = 5.10;
            gradeLetter = 100; // ascii letter 'd'
        }

        void printGradeInfo()
        {
            std::cout << "Grade is: " << gradeNumber << gradeLetter << std::endl;
        }
    };

    void buildRoute( int moves, double wallHeight );

    RouteGrade hard;
};

void TopRopeRoute::buildRoute( int moves, double wallHeight = 40.36 )
{
    BoulderProblem::Hold hold;

    for ( int i = moves; i > 0; i-- )
    {
         hold.holdHeight = ( wallHeight / moves ) * i;
         std::cout << "Hold height for move " << i << " is: " << hold.holdHeight << std::endl;
    }
}

/*
 3)
 */

 struct Mountain 
 {
     int height;
     int routes;

    Mountain()
    {
        height = 15;
        routes = 20;
    }

    void mountainFeatures( TopRopeRoute face, BoulderProblem base, double mountain );

    void constructMountain( double baseDiameter );
 };

void Mountain::mountainFeatures(TopRopeRoute face, BoulderProblem base, double mountain )
{
    std::cout << "Mountain height is " << height << " feet and has " << routes << " routes\n";

    for ( int i = this->routes; i > 0; i-- ) // not sure if I'm using pointers right
    {
        std::cout << "Route #" << i << std::endl;
        
        face.buildRoute( this->height, ( mountain + base.calculateDifficulty( 20.25 ) ) );
    }
}

void Mountain::constructMountain( double baseDiameter )
{
    TopRopeRoute wall;
    BoulderProblem slab;

    double mountain = M_PI* pow( baseDiameter / 2, 2 ) * this->height; // included math.h at line 1

    std::cout << "The mountain takes up " << mountain << " ft^3 of space.\n";

    mountainFeatures( wall, slab, mountain ); 
}

/*
 4)
 */

struct CrackClimb
{
    bool isBoulder;
    double crackWidth;
    int rockColor;

    CrackClimb()
    {
        isBoulder = false;
        crackWidth = 8;
        rockColor = 2;
    }

    int restPoint( int holdNumber, bool isRoof );
};

int CrackClimb::restPoint( int holdNumber, bool isRoof = false )
{
    int x = 0;

    for( int i = 0; i <= 1; i++ )
    {
        if( isRoof == false )
        {
            x = holdNumber;
        }
        else 
        {
            x = holdNumber + 1;
        }
    }

    std::cout << "The rest point is at " << x << " feet.\n";
    return x;
}

/*
 5)
 */

struct Shoe
{
    float shoeSize;
    bool isMale;
    bool isBoot;
    int rubberType;
    int agressiveness;

    Shoe()
    {
        shoeSize = 8.5f;
        isMale = true;
        isBoot = false;
        rubberType = 3;
        agressiveness = 1;
    }

    bool shoeFit( int painTolerance );
};

bool Shoe::shoeFit( int painTolerance )
{
    if( painTolerance > shoeSize )
    {
        std::cout << "The shoe fits!\n";
        return true;
    }

    std::cout << "The shoe doesn't fit!\n";

    return false;
}

/*
 6)
 */

struct RockClimber
{
    double experience;
    int age;
    int height;
    double strength;
    bool isMale;
 
    RockClimber()
    {
        experience = 25.87;
        age = 33;
        height = 167;
        strength = 99.28;
        isMale = false;
    }

    void climb( BoulderProblem blue, TopRopeRoute red, CrackClimb green );
    bool completeCheck ( int difficulty, double experience, double strength );
};

void RockClimber::climb( BoulderProblem blue, TopRopeRoute red, CrackClimb green )
{
    bool x = experience * blue.problemGrade >= strength;
    bool y = experience / red.wallAngle > 5;
    bool z = strength / green.crackWidth >= experience;

    if( x == true && 
        y == true &&
        z == true )
    {
        std::cout << "I'm ready to climb!\n"; // had to move iostream include to line 2
    }
    else
    {
        std::cout << "I'm not ready to climb.\n";
    }
}

/*
 7)
 */

struct Hiker
{
    RockClimber leader;
    double stamina = 22.45;

    struct Backpack 
    {
        bool water = true;
        bool food = true;
        bool rope = true;
        
        double backpackWeight ( double waterWeight, double foodWeight, double ropeWeight );
    };

    bool hasBackpack = true;
};

double Hiker::Backpack::backpackWeight ( double waterWeight, double foodWeight, double ropeWeight )
{
    return waterWeight + foodWeight + ropeWeight;
}

/*
 8)
 */

struct Gym
{
    BoulderProblem pink;
    TopRopeRoute orange;
    CrackClimb brown;

    void setClimbs( int climbsCount, int difficultySpread );
};

void Gym::setClimbs( int climbsCount, int difficultySpread )
{
    for ( int i = climbsCount; i > 0; i-- )
    {
        orange.buildRoute( 40, orange.wallAngle * difficultySpread );
    }
}

/*
 9)
 */

struct Exercise
{
    int muscleGroup = 6;
    int difficulty = 3;
    bool useWeight = false;


    void doExercise ( RockClimber trainee );
    bool exerciseComplete ( int strength, double stamina );
};

void Exercise::doExercise ( RockClimber trainee )
{
    int x = difficulty * 10;
    int setsPossible = 0;

    for ( double i = trainee.strength; i > x; i = i - x )
    {
        setsPossible++;
    }
}

bool Exercise::exerciseComplete ( int strength, double stamina )
{
    return strength + stamina > muscleGroup * (difficulty * 10);
}

/*
 10)
 */

struct TrainingPlan
{
    Exercise pushUp;
    Exercise pullUp;
    Exercise shoulderPress;
    Exercise deadLift;
    Exercise squat;

    void createPlan( int intensity, int rounds, double restPeriod );
};

void TrainingPlan::createPlan ( int intensity, int rounds, double restPeriod )
{
    RockClimber trainee;

    restPeriod = restPeriod - intensity;

    for( int i = rounds; i > 0; i-- )
    {
        pushUp.doExercise( trainee );
        pullUp.doExercise( trainee );
        shoulderPress.doExercise( trainee );
        deadLift.doExercise( trainee );
        squat.doExercise( trainee );
    }
}


int main()
{
    Example::main();

//1
    std::cout << "\n**=============================**\n\n";

    BoulderProblem blue;
    BoulderProblem::Hold crimp;

    double difficulty = blue.calculateDifficulty( 2.22 );
    crimp.printHoldInfo();
    std::cout << "Difficulty: " << difficulty << std::endl;

//2
    std::cout << "\n**=============================**\n\n";

    TopRopeRoute red;
    TopRopeRoute::RouteGrade medium;

    red.buildRoute(10, 40.36);
    medium.printGradeInfo();

//3
    std::cout << "\n**=============================**\n\n";

    Mountain dingbat;

    dingbat.constructMountain( 33.456 );

//4
    std::cout << "\n**=============================**\n\n";

    CrackClimb green;

    green.restPoint( 32, false );

//5
    std::cout << "\n**=============================**\n\n";    

    Shoe scarpa;

    scarpa.shoeFit( 8 );

//6
    std::cout << "\n**=============================**\n\n";   

    RockClimber Drew;

    Drew.climb(blue, red, green);

//7
    std::cout << "\n**=============================**\n\n";   



    std::cout << "\n**=============================**\n\n";   

    std::cout << "good to go!" << std::endl;
}
