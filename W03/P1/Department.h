/***********************************************************************
// OOP244 Workshop 3 # p1: tester program
//
// File	Department.h
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
#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
namespace sdds {

    const int MAX_TOPIC_LENGTH = 25;

    struct Project {
        char m_topic[MAX_TOPIC_LENGTH+1];
        double m_cost;
    };

	//class Department does here
	
    class Department {
    private:
       char* dep_name;
       Project* project;
       int num_project;
       double dep_budget;
    public:
       Department();
       void updateName(const char* newname);
       void updateBudget(double change);
       bool addProject(Project& newproject);
       void createDepartment(const char* newname, Project& newproject, double change);
       Project* fetchProjects() const;
       int fetchNumProjects() const;
       double fetchBudget() const;
       char* fetchName() const;
       double totalexpenses();
       double remainingBudget();
       void clearDepartment();
   };
	
	//helper functions - do not belong inside the class
    void display(const Project& project);
    void display(const Department& department);

}
#endif // !SDDS_DEPARTMENT_H_