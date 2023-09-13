/***********************************************************************
// OOP244 Workshop 3 # p1: tester program
//
// File	Department.cpp
// Version 1.0
// Date		Feb 02, 2023
// Author	Ching Wei Lai
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {


    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

    //set the department to empty state or initial value 
    Department::Department() {
       dep_name = nullptr;
       project = nullptr;
       num_project = 0;
       dep_budget = 15345.99;
    }

    void Department::updateName(const char* newname) {
       // check the provided name is not empty
       if (newname != nullptr) {
          // If the department is already set, it will deallocate the name. 
          if (dep_name != nullptr){
             delete[] dep_name;
          }
          // or it creates enough memory for the name of the department (DMA) and copies the data of the new name
          dep_name = new char[strlen(newname) + 1];
          strcpy(dep_name, newname);
       }
    }

    void Department::updateBudget(double change) {
       dep_budget += change;
    }

    bool Department::addProject(Project& newproject) {

       //This function will add a new project to the department as long as the total cost does not exceed the allocated budget.
       bool check = false;
       
       //If the new project cost in addition to the total cost of the current project does not exceed the budget
       if (dep_budget >= newproject.m_cost + totalexpenses()) {
             //allocates a temp array of projects with new size = old size + 1
             Project* temp = new Project[num_project + 1];

             //copy all projects from the old array to the new one  (For loop)
             for (int i = 0; i < num_project; i++) {
                temp[i] = project[i];
             }

             //add data to the last position of the temp array
             temp[num_project] = newproject;

             //wipe out the old array (delete)
             delete[] project;
             project = nullptr;
             project = temp;
             num_project++;
             check = true;
       }
       return check;
    }

    //This function will use functions updateName, addProject and updateBudget to set the name of the department, add a project to it and update its budget.
    void Department::createDepartment(const char* newname, Project& newproject, double change) {
       updateName(newname);
       addProject(newproject);
       updateBudget(change);
    }

    Project* Department::fetchProjects() const {
       return project;
    }

    int Department::fetchNumProjects() const {
       return num_project;
    }

    double Department::fetchBudget() const {
       return dep_budget;
    }

    char* Department::fetchName() const {
       return dep_name;
    }

    // This function will calculate and return the expenses of a department. The total expenses of a department is the total cost of all its current projects.
    double Department::totalexpenses() {
       double total_exp = 0.00;
       for (int i = 0; i < num_project; i++) {
          total_exp += project[i].m_cost;
       }
       return total_exp;
    }

    //This function will calculate and return the remaining budget of a department by subtracting the total expenses from the budget.
    double Department::remainingBudget() {
       double remaining = 0.0;
       remaining = dep_budget - totalexpenses();
       return remaining;
    }

    //This function will clear all the dynamic memory allocation in a department.
    void Department::clearDepartment() {
       delete[] dep_name;
       dep_name = nullptr;
       delete[] project;
       project = nullptr;
       num_project = 0;
       dep_budget = 15345.99;
    }
}