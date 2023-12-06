////#include<iostream>
////#include<fstream>
////#include<sstream>
////#include<limits>
////using namespace std;
////
////class student {
////	friend class studentmangement;
////protected:
////	string name;
////	int rollnum;
////	int contact;
////	int courses;
////	int age;
////
////public:
////	student()
////	{
////		name = '\0';
////		rollnum = 0;
////		contact = 0;
////		age = 0;
////		courses = 0;
////
////	}
////	student(string name1, int rollnum1, int contact1, int age1)
////	{
////		name = name1;
////		rollnum = rollnum1;
////		contact = contact1;
////		age = age1;
////		//courses = courses1;
////
////	}
////	/*student(const student& obj)
////	{
////		name = obj.name;
////		rollnum = obj.rollnum;
////		contact = obj.contact;
////		age = obj.age;
////		courses = obj.courses;
////		marks = obj.marks;
////		attendance = obj.attendance;
////	}*/
////	~student()
////	{
////
////	}
////};
////class studentmangement :public student
////{
////private:
////	student** s;
////	int numofst;
////	int maxst = 100;
////public:
////
////	studentmangement()
////	{
////		numofst = 0;
////		s = new student * [maxst];
////		for (int i = 0; i < maxst; i++)
////		{
////			s[i] = nullptr;
////		}
////	}
////	~studentmangement()
////	{
////		for (int i = 0; i < numofst; i++)
////		{
////			delete s[i];
////		}
////		delete[] s;
////	}
////	void add()
////	{
////		ofstream outfile("jav.txt", ios::app);
////		{
////			if (!outfile.is_open())
////			{
////				cout << "File not opened\n";
////			}
////			cout << "enter students detail: " << endl;
////			cin.ignore();
////			cout << "name: ";
////			getline(cin, name);
////
////
////			cout << "rollnum: ";
////			cin >> rollnum;
////			cout << "contact: ";
////			cin >> contact;
////			cout << "age: ";
////			cin >> age;
////			/*cout << "courses: ";
////			cin >> courses;*/
////
////			outfile << rollnum << "\t\t" << contact << "\t\t" << age << "\t\t" << name << endl;
////			numofst++;
////			outfile.close();
////		}
////	}
////
////
////	void display1(const string& temp) {
////		cout << endl << endl << "---------------- File Contents --------------------------" << endl << endl;
////		ifstream file("jav.txt");
////		if (file.is_open()) {
////			char a;
////			while (file.get(a))
////			{
////				cout << a;
////			}
////			file.close();
////		}
////		else {
////			cout << "File not open";
////		}
////	}
////
////	void removestudents()
////	{
////		int r;
////		cout << "Enter the rollnum to remove" << endl;
////		cin >> r;
////
////		ifstream file("jav.txt");
////		if (!file.is_open())
////		{
////			cout << "File not opened" << endl;
////			return;
////		}
////
////		ofstream outfile("tempfile.txt");
////		if (!outfile.is_open())
////		{
////			cout << "File not opened" << endl;
////			file.close();
////			return;
////		}
////
////		bool b = false;
////		string line;
////
////		while (getline(file, line))
////		{
////			istringstream c(line);
////			int r1;
////			c >> r1;
////
////			if (r1 == r)
////			{
////				b = true;
////				cout << "student with rollnum " << r << " removed" << endl;
////				continue;
////			}
////
////			outfile << line << endl;
////		}
////
////		file.close();
////		outfile.close();
////
////		if (b)
////		{
////			if (remove("jav.txt") != 0)
////			{
////				cout << "error in deleting the file" << endl;
////			}
////			if (rename("tempfile.txt", "jav.txt") != 0)
////			{
////				cout << "error in renaming the file" << endl;
////			}
////			else
////			{
////				cout << "student with roll number " << r << " removed successfully." << endl;
////				display1("jav.txt");
////			}
////		}
////		else
////		{
////			cout << "Roll number not found" << endl;
////			remove("tempfile.txt");                           // Delete the temporary file
////		}
////	}
////
////	void editstudents()
////	{
////		int r;
////		cout << "Enter the rollnum to remove" << endl;
////		cin >> r;
////
////		ifstream file("jav.txt");
////		if (!file.is_open())
////		{
////			cout << "File not opened" << endl;
////			return;
////		}
////
////		ofstream outfile("tempfile.txt");
////		if (!outfile.is_open())
////		{
////			cout << "File not opened" << endl;
////			file.close();
////			return;
////		}
////		bool b = false;
////		string line;
////
////		while (getline(file, line))
////		{
////			istringstream c(line);
////			int r1;
////			c >> r1;
////			if (r1 == r)
////			{
////				b = true;
////				cout << "enter students detail: " << endl;
////				cin.ignore();
////				cout << "name: ";
////				getline(cin, name);
////
////				rollnum = r;                                                           //keep rollnum same
////
////				cout << "contact: ";
////				cin >> contact;
////				cout << "age: ";
////				cin >> age;
////
////				cout << "student with rollnum " << r << " edited" << endl;
////				outfile << rollnum << "\t\t" << contact << "\t\t" << age << "\t\t" << name << endl;
////				continue;
////			}
////			outfile << line << endl;
////		}
////
////		file.close();
////		outfile.close();
////
////		if (b)
////		{
////			if (remove("jav.txt") != 0)
////			{
////				cout << "error in deleting the file" << endl;
////			}
////			if (rename("tempfile.txt", "jav.txt") != 0)
////			{
////				cout << "error in renaming the file" << endl;
////			}
////			else
////			{
////				cout << "student with roll number " << r << " removed successfully." << endl;
////				display1("jav.txt");
////			}
////		}
////		else
////		{
////			cout << "Roll number not found" << endl;
////			remove("tempfile.txt");                           // Delete the temporary file
////		}
////	}
////
////	void courseregistration()
////	{
////		ofstream outfile("jav.txt", ios::app);
////		{
////			if (!outfile.is_open())
////			{
////				cout << "File not opened\n";
////			}
////			outfile << "the available courses are: " << endl;
////			outfile << "oop, discrete, coal, data, cps, linear, dld,  de " << endl;
////			outfile.close();
////			display1("jav.txt");
////			///////////////////////
////		}
////	}
////	bool courseavailable(const string& course, const string* c, const int& cnum)
////	{
////		for (int i = 0; i < cnum; i++)
////		{
////			if (course == c[i])
////			{
////				return true;
////			}
////		}
////		return false;
////	}
////
////	void registeration()
////	{
////		int r;
////		cout << "Enter rollnum for course registration: " << endl;
////		cin >> r;
////		const int cnum = 8;
////		string c[cnum] = { "oop","discrrete","coal","data","cps","linear","dld","de" };
////		string a[8] = {};
////
////		ifstream file("jav.txt");
////		if (!file.is_open())
////		{
////			cout << "File not opened" << endl;
////			return;
////		}
////
////		ofstream outfile("tempfile.txt");
////		if (!outfile.is_open())
////		{
////			cout << "File not opened" << endl;
////			file.close();
////			return;
////		}
////
////		bool b = false;
////		string line;
////		int num;
////		cout << "Enter the number of courses: " << endl;
////		cin >> num;
////
////		cout << "Enter the courses separated by spaces: " << endl;
////		string courses;
////		for (int i = 0; i < num; i++)
////		{
////			string course;
////			cin >> course;
////			if (courseavailable(course, c, cnum))
////			{
////				courses += course + "  ";
////				//a[i] = courses;
////			}
////			else
////			{
////				cout << "invalid course" << endl;
////				file.close();
////				outfile.close();
////				remove("tempfile.txt");
////				return;
////			}
////		}
////		while (getline(file, line))
////		{
////			istringstream c(line);
////			int r1;
////			c >> r1;
////
////			if (r1 == r)
////			{
////				b = true;
////				rollnum = r;
////				c >> contact >> age >> name;
////
////				outfile << rollnum << "\t\t" << contact << "\t\t" << age << "\t\t " << name;
////				outfile << "\t\t" << courses << endl;
////
////				continue;
////			}
////			else
////			{
////				cout << "rollnum not found" << endl;
////			}
////
////			outfile << line << endl;
////		}
////
////		file.close();
////		outfile.close();
////
////		if (b)
////		{
////			if (remove("jav.txt") != 0)
////			{
////				cout << "Error in deleting the file" << endl;
////			}
////
////			if (rename("tempfile.txt", "jav.txt") != 0)
////			{
////				cout << "Error in renaming the file" << endl;
////			}
////			else
////			{
////				cout << "Student with roll number " << r << " registered successfully." << endl;
////				display1("jav.txt");
////			}
////		}
////		else
////		{
////			cout << "Roll number not found" << endl;
////			remove("tempfile.txt"); // Delete the temporary file
////		}
////	}
////
////	void withdrawal()
////	{
////		int r;
////		cout << "Enter rollnum for course registration: " << endl;
////		cin >> r;
////
////		const int cnum = 8;
////		string c[cnum] = {};
////
////		ifstream file("jav.txt");
////		if (!file.is_open())
////		{
////			cout << "File not opened" << endl;
////			return;
////		}
////
////		ofstream outfile("tempfile.txt");
////		if (!outfile.is_open())
////		{
////			cout << "File not opened" << endl;
////			file.close();
////			return;
////		}
////
////		bool b = false;
////		string line;
////		int num;
////
////
////
////		while (getline(file, line))
////		{
////			istringstream c(line);
////			int r1;
////			c >> r1;
////
////			if (r1 == r)
////			{
////				b = true;
////				rollnum = r;
////				c >> contact >> age >> name;
////
////				for (int i = 0; i < 8; i++)
////				{
////					///c >> courses[i];
////
////				}
////
////
////				outfile << rollnum << "\t\t" << contact << "\t\t" << age << "\t\t " << name;
////				outfile << "\t\t" << courses << endl;
////
////				continue;
////			}
////			else
////			{
////				cout << "rollnum not found" << endl;
////			}
////
////			outfile << line << endl;
////		}
////
////		file.close();
////		outfile.close();
////
////		if (b)
////		{
////			if (remove("jav.txt") != 0)
////			{
////				cout << "Error in deleting the file" << endl;
////			}
////
////			if (rename("tempfile.txt", "jav.txt") != 0)
////			{
////				cout << "Error in renaming the file" << endl;
////			}
////			else
////			{
////				cout << "Student with roll number " << r << " registered successfully." << endl;
////				display1("jav.txt");
////			}
////		}
////		else
////		{
////			cout << "Roll number not found" << endl;
////			remove("tempfile.txt"); // Delete the temporary file
////		}
////	}
////
////
////
////};
////int main()
////{
////	studentmangement obj;
////	int key = 0;
////	obj.display1("jav.txt");
////	cout << endl << endl;
////	while (key != 6)
////	{
////		cout << "-------------MAIN MENU-----------" << endl;
////		cout << "enter 1 for enrollment" << endl;
////		cout << "enter 2 for course registration" << endl;
////		cout << "enter 3 for attendance" << endl;
////		cout << "enter 4 for marks" << endl;
////		cout << "enter 5 for course withdrawal" << endl;
////		cout << "enter 6 for exit" << endl;
////
////		cout << endl << "enter the key: " << endl;
////		cin >> key;
////
////		if (key == 1)
////		{
////			int k = 0;
////			while (k != 5) {
////
////				cout << "---------------enrollment-----------------" << endl;
////				cout << "enter 1 to display already enrolled students" << endl;
////				cout << "enter 2 to add new student" << endl;
////				cout << "enter 3 to remove student" << endl;
////				cout << "enter 4 to edit student info" << endl;
////				cout << "enter 5 to exit" << endl;
////
////				//cout << "enter 5 to display" << endl;
////				int k;
////				cout << "enter the choice" << endl;
////				cin >> k;
////				if (k == 1)
////				{
////					obj.display1("jav.txt");
////				}
////				else if (k == 2)
////				{
////					obj.add();
////					obj.display1("jav.txt");
////				}
////				else if (k == 3)
////				{
////					obj.removestudents();
////				}
////				else if (k == 4)
////				{
////					obj.editstudents();
////				}
////				else if (k == 5)
////				{
////					cout << "exiting program" << endl;
////					break;
////				}
////				else
////				{
////					cout << "invalid key" << endl;
////				}
////			}
////		}
////		else if (key == 2)
////		{
////			int k2 = 0;
////			while (k2 != 3)
////			{
////				cout << "-----------------course registration-----------------" << endl;
////				cout << "enter 1 to display the courses " << endl;
////				cout << "enter 2 to register the courses" << endl;
////				cout << "enter 3 to exit" << endl;
////
////				//int k2;
////				cout << "enter the choice" << endl;
////				cin >> k2;
////				if (k2 == 1)
////				{
////					obj.courseregistration();
////					//obj.display1("jav.txt");
////				}
////				else if (k2 == 2)
////				{
////					obj.registeration();
////					//obj.display1("jav.txt");
////				}
////				else if (k2 == 3)
////				{
////					cout << "exiting course registration" << endl;
////					break;
////				}
////			}
////		}
////		else if (key == 5) {
////			int k3 = 0;
////			while (k3 != 3)
////			{
////				cout << "-----------------course withdrawal-----------------" << endl;
////				cout << "enter 1 to display the course" << endl;
////				cout << "enter 2 to withdraw the courses" << endl;
////				cout << "enter 3 to exit" << endl;
////
////				if (k3 == 1)
////				{
////					obj.registeration();
////				}
////				else if (k3 == 2)
////				{
////
////
////				}
////
////			}
////
////
////		}
////
////
////
////	}
////	return 0;
////}
//
//
//
//void withdraw() {
//	int r;
//	cout << "Enter roll number: " << endl;
//	cin >> r;
//
//	ifstream file("jav.txt");
//	if (!file.is_open()) {
//		cout << "File not opened" << endl;
//		return;
//	}
//
//	ofstream outfile("tempfile.txt");
//	if (!outfile.is_open()) {
//		cout << "File not opened" << endl;
//		file.close();
//		return;
//	}
//
//	bool studentFound = false;
//	string line;
//
//	cout << "Enter the course to withdraw: " << endl;
//	string courseToWithdraw;
//	cin >> courseToWithdraw;
//
//	while (getline(file, line)) {
//		istringstream c(line);
//		int rollnumFromFile;
//		c >> rollnumFromFile;
//
//		if (rollnumFromFile == r) {
//			studentFound = true;
//			string students;
//			c >> contact >> age >> name;
//			c >> ws; // Skip whitespaces
//			getline(c, students);
//
//			// Remove the specified course from the student's courses
//			string updatedCourses;
//			istringstream ss(students);
//			string course;
//			while (ss >> course) {
//				if (course != courseToWithdraw) {
//					updatedCourses += course + " ";
//				}
//			}
//
//			// Write back the updated information to the output file
//			outfile << rollnumFromFile << "\t\t" << contact << "\t\t" << age << "\t\t" << name;
//			outfile << "\t\t\t" << updatedCourses << endl;
//			continue;
//		}
//
//		outfile << line << endl;
//	}
//
//	file.close();
//	outfile.close();
//
//	// Remove the original file and rename the temp file
//	if (studentFound) {
//		if (remove("jav.txt") != 0) {
//			cout << "Error in deleting the file" << endl;
//		}
//
//		if (rename("tempfile.txt", "jav.txt") != 0) {
//			cout << "Error in renaming the file" << endl;
//		}
//		else {
//			cout << "Course withdrawn successfully." << endl;
//		}
//	}
//	else {
//		cout << "Student not found" << endl;
//		remove("tempfile.txt"); // Delete the temporary file
//	}
//}