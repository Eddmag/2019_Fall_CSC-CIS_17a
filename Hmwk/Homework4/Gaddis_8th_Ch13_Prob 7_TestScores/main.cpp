/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on November 12, 2019, 10:52 PM
 * Purpose: 7. TestScores Class
                    Design a TestScores class that has member variables to hold three test scores. The
                    class should have a constructor, accessor, and mutator functions for the test score fields
                    and a member function that returns the average of the test scores. Demonstrate the
                    class by writing a separate program that creates an instance of the class. The program
                    should ask the user to enter three test scores, which are stored in the TestScores
                    object. Then the program should display the average of the scores, as reported by the
                    TestScores object.
 * 
 */
// system libraries
#include <iostream>

using namespace std;

// user libraries

// classes
class TestScores{
    private:
        float test1;
        float test2;
        float test3;
    public:
        TestScores(){
            test1 = 0.0;
            test2 = 0.0;
            test3 = 0.0;
        }
        getTest1(){
            return test1;
        }
        getTest2(){
            return test2;
        }
        getTest3(){
            return test3;
        }
        getTestAverages(){
            return static_cast<float>((test1 + test2 + test3 )/ 3.0);
        }
        setTest1(float i){
            test1 = i;
        }
        setTest2(float i){
            test2 = i;
        }
        setTest3(float i){
            test3 = i;
        }
};
int main(int argc, char** argv) {
    TestScores classroom1;
    int i;
    cout << "What is the score for test 1?" << endl;
    cin >> i;
    classroom1.setTest1(i);
    cout << "What is the score for test 2?" << endl;
    cin >> i;
    classroom1.setTest2(i);
    cout << "What is the score for test 3?" << endl;
    cin >> i;
    classroom1.setTest3(i);
    cout << "The average score for these tests is " << classroom1.getTestAverages() << endl;
    return 0;
}

