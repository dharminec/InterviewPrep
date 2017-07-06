#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>


#define null ((void*)0)

////////////////////////////////////////////////////////////////////////////////
/* TESLA MOTORS FIRMWARE TEST
 * You have 90 minutes to complete the test.  Any answers given after 90 minutes
 * count significantly less towards the total score. There are 9 questions
 * ordered from lowest point value to highest.
 *
 * Do not use outside aid or share the content of this test
 *
 * All solutions should work in coderpad and can be compiled and run in Coderpad.io
 *
 * A main() function is provided at the bottom for your use
 */
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// 1) Celestial Body Struct
////////////////////////////////////////////////////////////////////////////////
// celestialBody_s is a data structure that represents celestial bodies in the
// solar system. However, the data structure is taking up too much space on
// an x86 system (32-bit aligned). How can the celestialBody_s structure be
// changed so that it needs 8 or fewer bytes for storage without losing fidelity
// in any of the members. Solutions that do not meet this requirement in
// coderpad will be considered incorrect.

// INCORRECT STRUCTURE
typedef struct s_celestialBody {
    uint8_t  zenithAngle;
    uint8_t  azimuthAngle;
    uint16_t distanceFromEarth;
    uint32_t mass;
} celestialBody_s;

////////////////////////////////////////////////////////////////////////////////
// 2) Function-like macro
////////////////////////////////////////////////////////////////////////////////
// Suppose the compiler you are using does not support inline functions
// Write a function-like macro INCREMENT to increment a variable by an
// arbitrary amount. Both the variable to increment and the increment
// amount should be passed in as parameters.

#define INC(a,inc) do{\
  (a)= (a)+(inc);\
  }while(0)
////////////////////////////////////////////////////////////////////////////////
// 3) Array pointer math
////////////////////////////////////////////////////////////////////////////////
//
// Write some code in the arrayMath() function to print out the values located at:
// row 0, column 0
// row 1, column 2
// row 2, column 2
// You are not allowed to use [] to reference the elements of the array.
// You are only allowed to use pointers.
// There should be no compiler warnings or errors.
//
int myArray[3][4] =
{
    {0, 3, 6, 9},
    {1, 4, 7, 10},
    {2, 5, 8, 11}
};
void arrayMath()
{
    printf("myArry[0][0] =%d\n",**myArray);
    printf("myArry[1][0] =%d\n",*(*(myArray+1)+2));
    printf("myArry[2][2] =%d\n",*(*(myArray+2)+2));
}

////////////////////////////////////////////////////////////////////////////////
// 4) Periodic Tasks
////////////////////////////////////////////////////////////////////////////////
//
// Assume there are two periodic tasks in the system. They run every 10ms and
// 100ms. The system starts up in main, which then creates the two tasks. Main
// is not shown here.
// Assume that the 100ms task is running at lower priority than the 10ms task.
// When the 10ms task needs to run, it interrupts the 100ms task, executes,
// and then returns control to the 100ms task.
// Please explain what is wrong with this code.
//

volatile int componentValue = 1;
int finalValue = 1;


void task_100ms()
{
    finalValue = componentValue * 2;
  //  sleep(50);

    if(finalValue == (componentValue * 2))
    {
        printf("finalValue is: %d", finalValue);
        printf("componentValue is : %d", componentValue);
    }
}

void task_10ms()
{
    componentValue += 1;
    if(componentValue > 20)
    {
        componentValue = 0;
    }
}
/* PLEASE PUT YOUR ANSWER HERE

   I noticed that while reading componentValue variable in task_100ms task, interrupts are   not disabled. This can create a issue becasue if the processor is not 32 or 64bit    (assuming int is 4 byte long) then it can take two cycles to read the entire variable. If the processor has read only lower byte and if task is interupted by 10ms task, then variable componentValue will be changed.So when task return the control to 100ms task , it will continue from where it left.So it will read the higher byte which was left. Becasue of this we will endup having wrong value in finalvalue.

   We can use mutex or binary semaphore to lock the variable while accessing.

*/

////////////////////////////////////////////////////////////////////////////////
// 5) Struct pointer math
////////////////////////////////////////////////////////////////////////////////
//
// Write some code in the structMath() function to print out the values for
// keyValue and alternateKeyValue from the Tesla laptop definition without using
// the '.' or '->' operators to directly reference the qwerty struct or its
// members.
// There should be no compiler warnings or errors.
//
typedef enum
{
    MOUSE_NONE,
    MOUSE_UP,
    MOUSE_DOWN,
    MOUSE_LEFT,
    MOUSE_RIGHT,
} mouse_direction_E;

typedef struct
{
    bool leftButton;
    bool rightButton;
    bool middleButton;
    bool mouseOn;
    mouse_direction_E direction;
} mouse_S;

typedef struct
{
    char keyValue;
    char alternateKeyValue;
} keyboard_S;

typedef struct
{
    mouse_S simpleMouse;
    keyboard_S qwerty;
} laptop_S;

laptop_S tesla =
{
    .simpleMouse =
    {
        .leftButton = false,
        .rightButton = false,
        .middleButton = false,
        .mouseOn = false,
        .direction = MOUSE_NONE,
    },
    .qwerty =
    {
        .keyValue = '5',
        .alternateKeyValue = '%'
    },
};

void structMath()
{
    // code here
    //printf("Sizeof mouse_S = %ld\n",sizeof(mouse_S));
    const char * ptesla = (const char*)&tesla;

    printf("Tesla keyvalue = %c\n",ptesla[8]);
    printf("Tesla alternateKeyValue = %c\n",ptesla[9]);
}

////////////////////////////////////////////////////////////////////////////////
// 6) Hysteresis
////////////////////////////////////////////////////////////////////////////////
//
// heatingRequired
//
//  This function indicates whether heating is required to maintain a set
//  temperature, based on the current heater request state (initially off),
//  specified set temperature and the current tempareture.  The implementation
//  should have 1 degree of hysteresis around the set temperature to prevent
//  excessive toggling of the heater.  I.e., If the heater is already on, it
//  shall stay on within the range of [setTemp - 1 degC, setTemp + 1 degC].
//
//  arguments:
//   setTempHalfDeg - The set temperature in half-degree increments
//   curTempHalfDeg - The current temperature in half-degree increments
//
//  returns:
//   boolean indicating whether or not the heater should be active
//
bool heatingRequired(int16_t setTempHalfDeg, int16_t curTempHalfDeg)
{
    return false; // replace this line
}

////////////////////////////////////////////////////////////////////////////////
// 7) Nibble Swap
////////////////////////////////////////////////////////////////////////////////
// The messaging protocol used by certain vehicle controllers requires that all
// nibbles in data payloads be swapped (e.g. 0x1234 -> 0x2143). Write a function
// that takes an unsigned 64-bit integer and swaps the nibbles like so:
// 0x0123456789ABCDEF to 0x1032547698BADCFE. The function should be independent
// of machine endianess.

uint64_t payload_nibble_swap(uint64_t p)
{
    uint64_t nibbleSwappedVal = p;
    unsigned char *pp = (unsigned char *)&p;
    unsigned char *pnibble = (unsigned char *)&nibbleSwappedVal;
    unsigned int i= 1;

    if(*(const char*)&i == 1)
    {
          for(i = 0; i < 8; i++)
         {
               pnibble[i] = pp[8-i-1];
         }
    }

    nibbleSwappedVal = ((nibbleSwappedVal & 0xf0f0f0f0f0f0f0f0) >> 4UL) |
                            ((nibbleSwappedVal & 0x0f0f0f0f0f0f0f0f) << 4UL);
    return nibbleSwappedVal;
}

////////////////////////////////////////////////////////////////////////////////
// 8a) Braking Check
////////////////////////////////////////////////////////////////////////////////
// Design an input checker for a function that is used in an extremely safety
// critical braking system. This function takes two arguments, a pointer
// to a memory location that contains the distance to an obstacle in meters and
// a signed integer that is the closure rate in m/s.
//
// Implement the functions brakes_checkPointerAddr() and
// brakes_checkPointerData() so that the data used by the emergency braking
// calculation is guaranteed to be safe.
//

/*
 * @param distancePtr - int32_t pointer to data to be used
 *
 * returns true if pointer is non-NULL, 4 byte aligned
 * and in the range 0x1000 to 0xF000, false otherwise
 */
bool brakes_checkPointerAddr(int32_t* distancePtr)
{
    bool retVal = false;
    int32_t const *temp =  distancePtr;
   if( !((int32_t)(void *)temp & 3u)
       && (temp != null)
       && (temp > (int32_t*)0x1000)
       && (temp < (int32_t*)0xF000 ) )
    {
        retVal = true;
    }
    return retVal;
}

/*
 * @param distancePtr - int32_t pointer to data to be used (guaranteed to be non-NULL)
 *
 * returns true if data value is positive, non-zero and not
 * equal to the sentinel value 0x7FFFFFFF, false otherwise
 */
bool brakes_checkPointerData(int32_t* distancePtr)
{
    bool retVal = false;
    int32_t const * temp = distancePtr;
   if((*temp > 0) && (*temp != 0x7FFFFFFF))
      retVal = true;
    return retVal;
}

#define CLOSURE_RATE_THRESH 20U
#define DISTANCE_THRESH 100

/*
 * @param distancePtr - int32_t pointer to data to be used
 * @param closureRate - int32_t variable with the current closure rate in m/s
 *
 * returns TRUE if input data is valid and less than the
 * DISTANCE_THRESH constant and the closureRate is greater than the
 * CLOSURE_RATE_THRESH, FALSE otherwise
 */
bool brakes_activateEmergencyBraking(int32_t* distancePtr, int32_t closureRate)
{
    bool activateBrakes = false;
    if (brakes_checkPointerAddr(distancePtr))
    {
        if (brakes_checkPointerData(distancePtr))
        {
            if ((*distancePtr < DISTANCE_THRESH) && (closureRate > CLOSURE_RATE_THRESH))
            {
                activateBrakes = true;
            }
        }
    }
    return activateBrakes;
}

////////////////////////////////////////////////////////////////////////////////
// 8b) Braking Check Part 2
////////////////////////////////////////////////////////////////////////////////
//
// While testing the implementation for brakes_activateEmergencyBraking() above,
// an engineer discovered that there were cases where the closureRate was below
// the threshold, but an event was triggered.  Please explain what could have
// gone wrong and why.
//

////////////////////////////////////////////////////////////////////////////////
// 9) State Machine
////////////////////////////////////////////////////////////////////////////////
//
// Write a function to implement the state machine shown in the diagram below.
//  * The initial state of the state machine should be A
//  * State machine input is provided as an argument to the function
//  * The function should output the current state of the state machine
//
//
//     Input = 1   +---------+   Input = 4
//   +------------>|         |<------------+
//   |             | State A |             |
//   |  Input = 2  |         |  Input = 3  |
//   |   +-------- +---------+ --------+   |
//   |   |                             |   |
//   |   V                             V   |
// +---------+      Input = 6      +---------+
// |         |<--------------------|         |
// | State C |                     | State B |
// |         |-------------------->|         |
// +---------+      Input = 5      +---------+
//
//                                 +---------+
//              Input =            |         |
//              Unexpected Value   |  FAULT  |
//             +------------------>|         |
//                                 +---------+
//

#define NoOfState 4
#define NoOfInput 6
typedef enum state_t {
    A,
    B,
    C,
    fault,
} state_t;

typedef enum input_t {
    one,
    two,
    three,
    four,
    five,
    six
} input_t;

typedef void (*StateAction)();

typedef struct StateTable{
    state_t NextState;
}StateTable;

StateTable transition [NoOfState] [NoOfInput] =
{
    {A, C, B, A, fault, fault},
    {A, C, fault, A, fault, B},
    {fault, C, fault, A, A, B},
    {A, fault, fault, A, B, C},
};

state_t FSM(state_t state,input_t input)
{
    switch(state)
    {
      case A:
            switch(input)
            {
              case one:
                break;
              case two:
                state = C;
                break;
              case three:
                state = B;
                break;
              case four:
                break;
              default :
                state = fault;
                printf("Fault\n");
                break;
            }
            break;
        case B:
            switch(input)
            {
              case three:
                break;
              case four:
                state = A;
                break;
              case five:
                break;
              case six:
                state = C;
                break;
              default :
                state = fault;
                printf("Fault\n");
                break;
            }
            break;
        case C:
            switch(input)
            {
              case one:
                state = A;
                break;
              case two:
                break;
              case five:
                state = B;
                break;
              case six:
                break;
              default :
                state = fault;
                printf("Fault\n");
                break;
            }
            break;
      default:
        state = fault;
        printf("Fault\n");
        break;
    }
    return state;
}
////////////////////////////////////////////////////////////////////////////////
// Use this main to test your code
// All solutions should work in coderpad
////////////////////////////////////////////////////////////////////////////////
int main()
{
    celestialBody_s S;

    state_t state =  transition[0][3].NextState;


    printf("Sizeof celestialBody_s = %ld Bytes\n", sizeof(S));
    arrayMath();
    structMath();


    printf("payload_nibble_swap(0x0123456789ABCDEF) = %lx",
            payload_nibble_swap(0xEFCDAB8967452301));


    return 0;
}
