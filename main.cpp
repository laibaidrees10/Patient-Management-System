#include "Problem2.h"

int main()
{
    PriorityQueue queue;
    int patientID, severity, arrivalTime;
    string name;
    char morePatients;

    do
    {
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cout << "Enter Patient Name: ";
        cin.ignore();
        getline(cin, name);

        do
        {
            cout << "Enter Severity (1-10): ";
            cin >> severity;
            if (severity < 1 || severity > 10)
            {
                cout << "Severity must be between 1 and 10. Please try again.\n";
            }
        } while (severity < 1 || severity > 10);

        cout << "Enter Arrival Time: ";
        cin >> arrivalTime;

        queue.enqueue(patientID, name, severity, arrivalTime);

        do
        {
            cout << "Do you want to enter another patient? (y/n): ";
            cin >> morePatients;
        } while (morePatients != 'y' && morePatients != 'Y' && morePatients != 'n' && morePatients != 'N');

    } while (morePatients == 'y' || morePatients == 'Y' );

    cout << "\nViewing Patients:\n";
    queue.viewPatients();

    cout << "\nServing Patients:\n";
    queue.servePatient();

    cout << "\nViewing Remaining Patients:\n";
    queue.viewPatients();

    return 0;
}
