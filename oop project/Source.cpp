#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class attendance;
class student {
	//friend class studentmangement;
protected:
	string name;
	int rollnum;
	int contact;
	//int courses;
	int age;
	attendance* a;
	int a;




	int present;
	int absent;
	int total;
	float per;
	int obtained;
	static const int maxStudents = 100;
	static int numofst;
	static student students[maxStudents];








public:
	friend class attendance;
	student()
	{
		name = '\0';
		rollnum = 0;
		contact = 0;
		age = 0;
		//courses = 0;

	/*	present = 0;
		absent = 0;
		total = 0;
		per = 0.0;
		obtained = 0;*/

	}

	student(string name1, int rollnum1, int contact1, int age1, int present1, int absent1, int total1, float per1)
	{
		name = name1;
		rollnum = rollnum1;
		contact = contact1;
		age = age1;
		//courses = courses1;
		/*present = present1;
		absent = absent1;
		total = total1;
		per = per1;*/
	}

	~student()
	{

	}
	void add()
	{
		ofstream outfile("jav.txt", ios::app);
		{
			if (!outfile.is_open())
			{
				cout << "File not opened\n";
			}
			cout << "enter students detail: " << endl;
			cin.ignore();
			cout << "name: ";
			getline(cin, name);


			cout << "rollnum: ";
			cin >> rollnum;
			cout << "contact: ";
			cin >> contact;
			cout << "age: ";
			cin >> age;
			/*cout << "courses: ";
			cin >> courses;*/

			outfile << rollnum << "\t\t" << contact << "\t\t" << age << "\t\t" << name << endl;
			numofst++;
			outfile.close();
		}
	}


	void display1(const string& temp) {
		cout << endl << endl << "---------------- File Contents --------------------------" << endl << endl;
		ifstream file("jav.txt");
		if (file.is_open()) {
			char a;
			while (file.get(a))
			{
				cout << a;
			}
			file.close();
		}
		else {
			cout << "File not open";
		}
	}

	void removestudents()
	{
		int r;
		cout << "Enter the rollnum to remove" << endl;
		cin >> r;

		ifstream file("jav.txt");
		if (!file.is_open())
		{
			cout << "File not opened" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open())
		{
			cout << "File not opened" << endl;
			file.close();
			return;
		}

		bool b = false;
		string line;

		while (getline(file, line))
		{
			istringstream c(line);
			int r1;
			c >> r1;

			if (r1 == r)
			{
				b = true;
				cout << "student with rollnum " << r << " removed" << endl;
				continue;
			}

			outfile << line << endl;
		}

		file.close();
		outfile.close();

		if (b)
		{
			if (remove("jav.txt") != 0)
			{
				cout << "error in deleting the file" << endl;
			}
			if (rename("tempfile.txt", "jav.txt") != 0)
			{
				cout << "error in renaming the file" << endl;
			}
			else
			{
				cout << "student with roll number " << r << " removed successfully." << endl;
				display1("jav.txt");
			}
		}
		else
		{
			cout << "Roll number not found" << endl;
			remove("tempfile.txt");                           // Delete the temporary file
		}
	}

	void editstudents()
	{
		int r;
		cout << "Enter the rollnum to remove" << endl;
		cin >> r;

		ifstream file("jav.txt");
		if (!file.is_open())
		{
			cout << "File not opened" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open())
		{
			cout << "File not opened" << endl;
			file.close();
			return;
		}
		bool b = false;
		string line;

		while (getline(file, line))
		{
			istringstream c(line);
			int r1;
			c >> r1;
			if (r1 == r)
			{
				b = true;
				cout << "enter students detail: " << endl;
				cin.ignore();
				cout << "name: ";
				getline(cin, name);

				rollnum = r;                                                           //keep rollnum same

				cout << "contact: ";
				cin >> contact;
				cout << "age: ";
				cin >> age;

				cout << "student with rollnum " << r << " edited" << endl;
				outfile << rollnum << "\t\t" << contact << "\t\t" << age << "\t\t" << name << endl;
				continue;
			}
			outfile << line << endl;
		}

		file.close();
		outfile.close();

		if (b)
		{
			if (remove("jav.txt") != 0)
			{
				cout << "error in deleting the file" << endl;
			}
			if (rename("tempfile.txt", "jav.txt") != 0)
			{
				cout << "error in renaming the file" << endl;
			}
			else
			{
				cout << "student with roll number " << r << " removed successfully." << endl;
				display1("jav.txt");
			}
		}
		else
		{
			cout << "Roll number not found" << endl;
			remove("tempfile.txt");                           // Delete the temporary file
		}
	}
	static student* getStudentByRollnum(int r)
	{
		for (int i = 0; i < numofst; i++)
		{
			if (students[i].rollnum == r)
			{
				return &students[i];
			}
		}
		return nullptr;
	}
};
int student::numofst = 0;
student student::students[maxStudents];

//
//class courses {
//protected:
//	int code;
//	string name;
//	string inst;
//	int credits;
//	int capacity;
//	string students;
//public:
//
//};
//
//class system {
//
//
//
//};

class attendance//://public student
{
protected:
	student* s;



public:
	attendance()
	{}

	attendance(student* studentObj) : s(studentObj) {}

	void attendancee()
	{
		int r;
		cout << "Enter the rollnum to mark attendance" << endl;
		cin >> r;

		ifstream file("att.txt");
		if (!file.is_open())
		{
			cout << "Attendance file not opened" << endl;
			return;
		}

		// Find the corresponding student using the student array
		student* current = student::getStudentByRollnum(r);

		if (current)
		{
			cout << "Enter students' details: " << endl;

			cout << "Present: ";
			cin >> current->present;

			cout << "Total: ";
			cin >> current->total;

			current->total = current->present + current->absent;

			if (current->total == 0)
			{
				cout << "Total cannot be zero!" << endl;
			}
			else
			{
				current->per = (static_cast<double>(current->present) / current->total) * 100;
				cout << "Student with rollnum " << r << " marked attendance" << endl;

				// Open the attendance file for writing
				ofstream outfile("att.txt", ios::app);
				if (outfile.is_open())
				{
					// Write the updated attendance data to the file
					outfile << current->rollnum << "\t\t" << current->present << "\t\t" << current->absent << "\t\t" << current->total << "\t\t" << current->per << endl;
					outfile.close();
				}
				else
				{
					cout << "Error opening attendance file for writing" << endl;
				}
			}
		}
		else
		{
			cout << "Roll number not found" << endl;
		}

		file.close(); // Close the file after reading
	}

	void displayatt() {
		cout << endl << endl << "---------------- Attendance Contents --------------------------" << endl << endl;
		ifstream file("att.txt");
		if (file.is_open()) {
			char a;
			while (file.get(a)) {
				cout << a;
			}
			file.close();
		}
		else {
			cout << "File not open";
		}
	}
};


class system1// :public student//public attendance
{
public:

	void menu()
	{
		student obj, rhs[100];
		attendance obj1(rhs);
		int key = 0;
		//obj.display1("jav.txt");
		cout << endl << endl;
		while (key != 6)
		{
			cout << "-------------MAIN MENU-----------" << endl;
			cout << "enter 1 for enrollment" << endl;
			cout << "enter 2 for course registration" << endl;
			cout << "enter 3 for attendance" << endl;
			cout << "enter 4 for marks" << endl;
			cout << "enter 5 for course withdrawal" << endl;
			cout << "enter 6 for exit" << endl;

			cout << endl << "enter the key: " << endl;
			cin >> key;

			if (key == 1)
			{
				int k = 0;
				while (k != 5) {

					cout << "---------------enrollment-----------------" << endl;
					cout << "enter 1 to display already enrolled students" << endl;
					cout << "enter 2 to add new student" << endl;
					cout << "enter 3 to remove student" << endl;
					cout << "enter 4 to edit student info" << endl;
					cout << "enter 5 to exit" << endl;

					//cout << "enter 5 to display" << endl;
					int k;
					cout << "enter the choice" << endl;
					cin >> k;
					if (k == 1)
					{
						obj.display1("jav.txt");
					}
					else if (k == 2)
					{
						obj.add();
						obj.display1("jav.txt");
					}
					else if (k == 3)
					{
						obj.removestudents();
					}
					else if (k == 4)
					{
						obj.editstudents();
					}
					else if (k == 5)
					{
						cout << "exiting program" << endl;
						break;
					}
					else
					{
						cout << "invalid key" << endl;
					}
				}
			}
			else if (key == 2)
			{
				int k2 = 0;
				while (k2 != 3)
				{
					cout << "-----------------course registration-----------------" << endl;
					cout << "enter 1 to display the courses " << endl;
					cout << "enter 2 to register the courses" << endl;
					cout << "enter 3 to exit" << endl;

					//int k2;
					cout << "enter the choice" << endl;
					cin >> k2;
					if (k2 == 1)
					{
						//obj.courseregistration();
						//obj.display1("jav.txt");
					}
					else if (k2 == 2)
					{
						//obj.registeration();
						//obj.display1("jav.txt");
					}
					else if (k2 == 3)
					{
						cout << "exiting course registration" << endl;
						break;
					}
				}
			}
			else if (key == 3) {
				int k4 = 0;
				while (k4 != 3)
				{
					cout << "-----------------attendace----------------" << endl;
					cout << "enter 1 to display attendance" << endl;
					cout << "enter 2 to mark attendance" << endl;
					cout << "enter 3 to exit" << endl;

					//int k2;
					cout << "enter the choice" << endl;
					cin >> k4;
					if (k4 == 1)
					{

						obj1.displayatt();
					}
					else if (k4 == 2)
					{
						obj1.attendancee();

					}

				}
			}
			else if (key == 4) {
				int k5 = 0;
				while (k5 != 3)
				{
					cout << "-----------------marks-----------------" << endl;
					cout << "enter 1 to display marks" << endl;
					cout << "enter 2 to assign marks" << endl;
					cout << "enter 3 to exit" << endl;

					//int k2;
					cout << "enter the choice" << endl;
					cin >> k5;
					if (k5 == 1)
					{
						//obj.registeration();
						//obj.displaymarks();
					}
					else if (k5 == 2)
					{
						//obj.marks();

					}

				}
			}
			//else if (key == 5) {
			//	int k3 = 0;
			//	while (k3 != 3)
			//	{
			//		cout << "-----------------course withdrawal-----------------" << endl;
			//		cout << "enter 1 to display the course" << endl;
			//		cout << "enter 2 to withdraw the courses" << endl;
			//		cout << "enter 3 to exit" << endl;

			//		//int k2;
			//		cout << "enter the choice" << endl;
			//		cin >> k3;
			//		if (k3 == 1)
			//		{
			//			//obj.registeration();
			//		}
			//		/*else if (k3 == 2)
			//		{
			//			obj.withraw();

			//		}*/
			//	}
			//}
		}
	}
};
int main()
{
	student rhs;

	system1 object3;
	object3.menu();
	return 0;
}