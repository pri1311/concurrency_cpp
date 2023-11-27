#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>

using namespace std;

void printTime() {
    // Get the current time
    std::time_t currentTime = std::time(nullptr);

    // Convert the current time to a string
    std::string currentTimeStr = std::ctime(&currentTime);

    // Print the current time
    std::cout << "Current time: " << currentTimeStr;
}

// the code for writing the message has been moved to a separate function. 
// This is because every thread has to have an initial function, which is where the new thread of execution begins.
// For the initial thread in an application, this is main(), but for every other thread it’s specified in the constructor of a std::thread object 
// in this case, the std::thread object named t has the new function hello() as its initial function.
//  This is the next difference: rather than just writing directly to standard output or calling hello() from main(), this program launches a whole new thread to do it, bringing the thread count to two—the initial thread that starts at main() and the new thread that starts at hello().
void hello() {
    cout<<"Hello Concurrent World\n";
}

int main() {
    thread t(hello);
    // After the new thread has been launched, the initial thread continues execution.
    // If it didn’t wait for the new thread to finish, it would merrily continue to the end of main() and thus end the program—possibly before the new thread had had a chance to run. 
    // This is why the call to join() is there, this causes the calling thread (in main()) to wait for the thread associated with the std::thread object, in this case, t.
    t.join(); 
}