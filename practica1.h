// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#ifndef PRACTICA1_H
#define PRACTICA1_H

#include <ngrest/common/Service.h>
#include <string>
#include "list.h"

class practica1: public ngrest::Service
{
public:

    // *method: POST
   // *location: /newProfessor
   std::string newProfessor(const Data& data);

    // *method: POST
   // *location: /newCourse
   std::string newCourse(const Data& data);

    // *method: POST
   // *location: /newBuilding
   std::string newBuilding(const deuxData& data);

   // *method: POST
   // *location: /newDay
   std::string newDay(const std::string& choice);

    // *method: POST
   // *location: /getB64
   std::string getB64(const std::string& img);

   // *method: POST
   // *location: /getGraphic
   std::string getGraphic(const std::string& choice);

};


#endif // PRACTICA1_H



