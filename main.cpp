/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    int value;
    const char* name;
    T(int v, const char* objectName) :   //1
    value(v), //2
    name(objectName)//3
    {
        std::cout << "Created object of class T with value " << value << " and name " << name << "." << std::endl;
    }
};

struct Comparator                                //4
{
    T* compare(T& a, T& b) const // 5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float target { 0 }, currentValue { 0 };
    float updateAndMultiply(const float& updatedValueRef);      //12
};

struct Updater
{
    static float updateAndMultiply(U& that, const float& updatedValueRef ) //10
    {
        std::cout << "U's currentValue value: " << that.target << std::endl;
        that.target = updatedValueRef;
        std::cout << "U's target updated value: " << that.target << std::endl;
        
        while( std::abs(that.currentValue - that.target) > 0.001f )
        {
            /*
             write something that makes the distance between that->currentValue and that->target get smaller
             */
            that.currentValue += (that.target - that.currentValue) * 0.5f;
        }
        std::cout << "U's currentValue updated value: " << that.currentValue << std::endl;
        return that.currentValue * that.target;
    }
};

float U::updateAndMultiply(const float& updatedValueRef)
{
    return Updater::updateAndMultiply(*this, updatedValueRef);
}
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(9 , "t1");                                             //6
    T t2(7 , "t2");                                             //6
    
    Comparator f;                                            //7
    auto* smaller = f.compare(t1 , t2);   //8
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9    
    }
    else
    {
        std::cout << "both are equal" << std::endl;
    }
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Updater::updateAndMultiply(u1, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.updateAndMultiply( updatedValue ) << std::endl;
}
