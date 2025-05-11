#include <iostream>
#include <string>

using namespace std;

struct Patient
{
    int patientID;
    string name;
    int severity;
    int arrivalTime;
    Patient *next;

    Patient(int id, const string &n, int sev, int time)
        : patientID(id), name(n), severity(sev), arrivalTime(time), next(nullptr) {}
};

class PriorityQueue
{
private:
    Patient *front;

public:
    PriorityQueue() : front(nullptr) {}

    void enqueue(int id, const string &name, int severity, int arrivalTime)
    {
        Patient *newPatient = new Patient(id, name, severity, arrivalTime);

        if (!front || severity > front->severity || (severity == front->severity && arrivalTime < front->arrivalTime))
        {
            newPatient->next = front;
            front = newPatient;
        }
        else
        {
            Patient *temp = front;
            while (temp->next && (temp->next->severity > severity || (temp->next->severity == severity && temp->next->arrivalTime <= arrivalTime)))
            {
                temp = temp->next;
            }
            newPatient->next = temp->next;
            temp->next = newPatient;
        }
        cout << "Patient: " << name << " with severity " << severity << " added to the queue.\n\n";
    }

    void servePatient()
    {
        if (!front)
        {
            cout << "The queue is empty. No patients to serve.\n\n";
            return;
        }
        Patient *temp = front;
        cout << "Serving Patient ID: " << temp->patientID
             << ", Name: " << temp->name
             << ", Severity: " << temp->severity
             << ", Arrival Time: " << temp->arrivalTime << "\n\n";
        front = front->next;
        delete temp;
    }

    void viewPatients() const
    {
        if (!front)
        {
            cout << "No patients in the queue.\n\n";
            return;
        }
        Patient *temp = front;
        cout << "Patients in Queue (Ordered by Severity and Arrival Time):\n";
        while (temp)
        {
            cout << "ID: " << temp->patientID
                 << ", Name: " << temp->name
                 << ", Severity: " << temp->severity
                 << ", Arrival Time: " << temp->arrivalTime << "\n\n";
            temp = temp->next;
        }
    }

    ~PriorityQueue()
    {
        while (front)
        {
            Patient *temp = front;
            front = front->next;
            delete temp;
        }
    }
};
