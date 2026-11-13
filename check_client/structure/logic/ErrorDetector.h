//
// Created by Admin on 09.11.2026.
//

#ifndef AWS_HACKATHAN_ERRORDETECTOR_H
#define AWS_HACKATHAN_ERRORDETECTOR_H

/*
 *Der Detektor soll für ein Docker objekt eine Wahrscheinlichkiet ermitteln von einem Fehler befallen zu sein
 *Sodass untershciedlcih gehandelt werden kann.
 *Es werden je nach Wahrschienlichkeit eines Befalls die Menge an Kontext bestimmt der mitgesendet werden muss
 *Somit wird absteigend unterschiedlich große Pakete an die AWS KI gesendet:
 * below 30% -> nothing
 * below 50% -> send the stack with 3 str from the Log
 * below 80% -> send the stack with 5 str from the Log
 * till 100% -> send the stack with 10 str from the Log
 *
 * To minimize API calls but get the problems discoverd and solved
 */

#include "../FormalStructures/PrefixTree.h"

class ErrorDetector {
private:
    float probability;
    PrefixTree error_tree;
public:
    ErrorDetector();
    //logic
    int detect_string(std::stirng test);

};



#endif //AWS_HACKATHAN_ERRORDETECTOR_H
