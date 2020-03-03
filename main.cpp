 #include <math.h> // include math functions
 #include <typeinfo>
/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
namespace Example {
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()


//insert Example::main() into main() of user's repo.



/*
 1)
 */



struct BoulderProblem
{
    int problemGrade;
    double wallAngle;
    
    BoulderProblem() : problemGrade( 3 ), wallAngle( 30 ) {}

    struct Hold
    {
        int holdType { 2 };
        double holdSize; 
        double holdHeight;

        Hold() : holdSize( 0.8 ), holdHeight( 1 ) {}
        
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
    std::cout << "Calculating difficulty for V" << problemGrade << " problem at a " << wallAngle << " degree incline.\n";
    return ((problemGrade * crimp.holdType) / crimp.holdSize) - ropeLength;
}

/*
 2)
 */

struct TopRopeRoute
{
    double wallAngle { 10 };

//  TopRopeRoute(){}

    struct RouteGrade
    {
        double gradeNumber;
        char gradeLetter; 
        
        RouteGrade() : 
        gradeNumber( 5.10 ), 
        gradeLetter( 100 ) // ascii letter 'd' 
        {}

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

    std::cout << "The wall is at a " << wallAngle << " degree incline.\n";

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
    int height { 15 };
    int routes { 20 };

//    Mountain(){}

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
    bool isBoulder { false };
    double crackWidth;
    int rockColor;

    CrackClimb() : crackWidth( 8 ), rockColor( 2 ) {}

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
    std::cout << "The width of the crack is " << crackWidth << " in.\n";
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

    Shoe() : shoeSize( 8.5f ), isMale ( true ), isBoot ( false ), rubberType ( 3 ), agressiveness ( 1 ) {}

    void shoeInfo()
    {
        std::cout << "This size " << shoeSize << ( isBoot ? " boot" : " shoe" ) << " has type " << rubberType << " rubber.\n";
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
 
    RockClimber() : experience( 25.87 ), age( 33 ), height( 167 ), strength( 99.28 ), isMale( false ) {}

    void climb( BoulderProblem blue, TopRopeRoute red, CrackClimb green );
    bool climberCheck ( int difficulty );
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
        std::cout << "I'm ready to climb!\n";
    }
    else
    {
        std::cout << "I'm not ready to climb.\n";
    }
}

bool RockClimber::climberCheck( int difficulty )
{
    std::cout << "Your strength is: " << strength << " and you have " << experience << ".\n";
    
    if( difficulty > strength + experience )
    {
        std::cout << "You do not meet the requirements to attempt this climb.\n";
    
        return false;
    }

    std::cout << "You can do this climb.\n";

    return true;
}

/*
 7)
 */

struct Hiker
{
    RockClimber leader;
    double stamina { 22.45 };
    bool hasBackpack;

    Hiker()
    {
        hasBackpack = true;
    }

    struct Backpack 
    {
        bool water { true };
        bool food { true };
        bool rope { true };
        
        double backpackWeight ( double waterWeight, double foodWeight, double ropeWeight );
    };


};

double Hiker::Backpack::backpackWeight ( double waterWeight, double foodWeight, double ropeWeight )
{
    std::cout << "I've got my backpack!\n";
    std::cout << "I am carrying " << ( water ? "water" : "" ) << ( food ? ", food" : "" ) << ( rope ? ", rope" : "" ) << ".\n"; 
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

    int rating;

    Gym()
    {
        rating = 5;
    }

    void setClimbs( int climbsCount, int difficultySpread );
};

void Gym::setClimbs( int climbsCount, int difficultySpread )
{
    std::cout << "This gym's rating is: " << rating << std::endl;

    for ( int i = climbsCount; i > 0; i-- )
    {
        std::cout << "Gym Route# " << i << std::endl;
        
        orange.buildRoute( 40, orange.wallAngle * difficultySpread );
    }
}

/*
 9)
 */

struct Exercise
{
    int muscleGroup;
    int difficulty;
    bool useWeight { false };

    Exercise() : muscleGroup( 6 ), difficulty( 3 ) {}

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

    std::cout << "This exercise is for muscle group " << muscleGroup << " and " << ( useWeight ? "uses weights.\n" : "does not use weights.\n" );
 
    std::cout << "I did " << setsPossible << " sets of the exercise.\n";
}

bool Exercise::exerciseComplete ( int strength, double stamina )
{
    bool x = strength + stamina > muscleGroup * (difficulty * 10);

    if( x )
    {
        std::cout << "I completed the exercise.\n";
    }

    std::cout << "I couldn't do it.\n";
    return x;
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

//    TrainingPlan() {};

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
        std::cout << "Round Complete.\n\n";
    }
}

void divider()
{
    std::cout << "\n**=============================**\n\n";
}

int main()
{
    Example::main();

//1
    divider();

    BoulderProblem blue;
    BoulderProblem::Hold crimp;

    double difficulty = blue.calculateDifficulty( 2.22 );
    crimp.printHoldInfo();
    std::cout << "Difficulty: " << difficulty << std::endl;

//2
    divider();

    TopRopeRoute red;
    TopRopeRoute::RouteGrade medium;

    red.buildRoute(10, 40.36);
    medium.printGradeInfo();

//3
    divider();

    Mountain dingbat;

    dingbat.constructMountain( 33.456 );

//4
    divider();

    CrackClimb green;

    green.restPoint( 32, false );

//5
    divider();    

    Shoe scarpa;

    scarpa.shoeFit( 8 );
    scarpa.shoeInfo();

//6
    divider();   

    RockClimber Drew;

    Drew.climberCheck( 200 );
    Drew.climb(blue, red, green);

//7
    divider();   

    Hiker::Backpack JanSport;

    JanSport.backpackWeight( 10.32, 34.32, 10.12 );

//8
    divider();   

    Gym local;

    local.setClimbs( 2, 3 );

//9
    divider();   

    Exercise pullUp;

    pullUp.doExercise( Drew );
    pullUp.exerciseComplete( 15, 22.56 );

//10
    divider();   

    TrainingPlan DrewsPlan;

    DrewsPlan.createPlan( 3, 3, 33.56 );

    divider();

    std::cout << "good to go!" << std::endl;
}
