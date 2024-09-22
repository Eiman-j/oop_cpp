#include <iostream>
#include <iomanip>
using namespace std;

#define CALCULATE_SALARY_WITH_OT_BONUS
#define ENABLE_SORTING
const int total_employees = 100;
int employeeCounter = 0;
int inputID;
struct Employee
{
    int empID;
    char name[25];
    char postion[25];
    float hourlyRate;
    float hoursWorked;
    float overtimeHours;
    float bonus;
    float totalSalary;
};

void addEmployee(Employee e[], int size)
{
    cout<<"Enter Employee ID: ";
    cin>>e[employeeCounter].empID;
    cout<<"Enter Employee Name:  ";
    cin>>e[employeeCounter].name;
    cout<<"Enter Employee Position:  ";
    cin>>e[employeeCounter].postion;
    cout<<"Enter Employee Hourly Rate:  ";
    cin>>e[employeeCounter].hourlyRate;
    if(e[employeeCounter].hourlyRate<=0)
    {
        cout<<"Enter a Non-Negative/Non-Zero Value for Employee Hourly Rate:  ";
        cin>>e[employeeCounter].hourlyRate;
    }
    cout<<"Enter Employee Hours Worked:  ";
    cin>>e[employeeCounter].hoursWorked;
    if(e[employeeCounter].hoursWorked<0)
    {
        cout<<"Enter a Non-Negative/Non-Zero Value for Employee Hours Worked:  ";
        cin>>e[employeeCounter].hoursWorked;
    }
    cout<<"Enter Employee Overtime Hours:  ";
    cin>>e[employeeCounter].overtimeHours;
    if(e[employeeCounter].overtimeHours<0)
    {
        cout<<"Enter a Non-Negative/Non-Zero Value for Employee Overtime Hours:  ";
        cin>>e[employeeCounter].overtimeHours;
    }
    cout<<"Enter Employee Bonus:  ";
    cin>>e[employeeCounter].bonus;
    if(e[employeeCounter].bonus<0)
    {
        cout<<"Enter a Non-Negative/Non-Zero Value for Employee Bonus:  ";
        cin>>e[employeeCounter].bonus;
    }
    //cout<<"Enter Employee Total Salary:  ";
    //cin>>e[employeeCounter].totalSalary;
    e[employeeCounter].totalSalary = (e[employeeCounter].hourlyRate* e[employeeCounter].hoursWorked) + (e[employeeCounter].overtimeHours * e[employeeCounter].hourlyRate) + e[employeeCounter].bonus;
    employeeCounter++;

}



void displayDetails(Employee e[], int size)
{
    for(int i=0; i<size; i++)
    {
        if(e[i].empID==inputID)
        {
            cout<<"Details of Employee "<<e[i].empID<<": "<<endl;
            cout<<"Name:  "<<e[i].name<<endl;
            cout<<"Position:  "<<e[i].postion<<endl;
            cout<<"Total Hours Worked:  "<<e[i].hoursWorked<<endl;
            //#undef CALCULATE_SALARY_WITH_OT_BONUS
            #ifdef CALCULATE_SALARY_WITH_OT_BONUS
                cout<<"Total Salary:  "<<e[i].totalSalary<<endl;
            #endif

        }
        
    }
 
}

void bubblesortID(Employee e[], int size)
{
    for(int i=0; i<size -1; i++)
    {
        for(int j=0; j<size - i - 1; j++)
        {
            if(e[j].empID>e[j+1].empID)
            {
                swap(e[j], e[j+1]);
            }
        }
    }
}

bool searchID(int inputID, Employee e[], int low, int high)
{
    int mid = (low + (high - low))/2;
    while(low<=high)
    {   
        int mid = low + (high - low)/2;
        if(e[mid].empID==inputID)
        {
            return true;
        }
        else if(e[mid].empID<inputID)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}



int main()
{
    
    Employee e[total_employees];
    int choice;
    cout<<"Enter your choice:\n1.Enter Employee Information\n2.Display Employee Information\n3.Exit\n";
    cin>>choice;
    if(employeeCounter<total_employees)
    {
    while (choice!=3)
    {
        switch (choice)
        {
            case 1:
            addEmployee(e, total_employees);
            break;
            case 2:
            #ifdef ENABLE_SORTING
                bubblesortID(e, employeeCounter);
            #endif  
            cout<<"Enter Employee ID:  ";
            cin>>inputID;
            if(searchID(inputID, e, 0, employeeCounter-1))
            {
                displayDetails(e, employeeCounter);
            }
            else
            {
                cout<<"Employee ID is not valid, please try again!"<<endl;
            }
            break;
            default:
            cout<<"Enter Appropriate Choice";
            break;

        }
        cout<<"Enter your choice:\n1.Enter Employee Information\n2.Display Employee Information\n3.Exit\n";
        cin>>choice;

    }
    
}

else
{
    cout<<"ERROR^^^";
}

return 0;

}