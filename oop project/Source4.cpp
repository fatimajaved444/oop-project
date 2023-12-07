//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<string>
//using namespace std;
//class student {
//	friend courses;
//protected:
//	string name;
//	int rollnum;
//	int contact;
//	int age;
//	string* rcourses;// = new string[max];///////////////////////
//	int max = 8;
//
//
//	int present;
//	int absent;
//	int total;
//	float per;
//	int obtained;
//	int numofst = 9;
//	int maxst = 100;
//
//
//public:
//	friend class attendance;
//	student()
//	{
//		name = '\0';
//		rollnum = 0;
//		contact = 0;
//		age = 0;
//
//		rcourses = new string[max];
//	}
//
//	student(string name1, int rollnum1, int contact1, int age1, int present1, int absent1, int total1, float per1)
//	{
//		name = name1;
//		rollnum = rollnum1;
//		contact = contact1;
//		age = age1;
//		//courses = courses1;
//		/*present = present1;
//		absent = absent1;
//		total = total1;
//		per = per1;*/
//	}
//
//	~student()
//	{
//		delete[]rcourses;
//	}
//
//
//	void display1(const string& temp) {
//		cout << endl << endl << "---------------- File Contents --------------------------" << endl << endl;
//		ifstream file("jav.txt");
//		if (file.is_open()) {
//			char a;
//			while (file.get(a))
//			{
//				cout << a;
//			}
//			file.close();
//		}
//		else {
//			cout << "File not open";
//		}
//	}
//	void display2(const string& temp) {
//		cout << endl << endl << "---------------- File Contents --------------------------" << endl << endl;
//		ifstream file("c.txt");
//		if (file.is_open()) {
//			char a;
//			while (file.get(a))
//			{
//				cout << a;
//			}
//			file.close();
//		}
//		else {
//			cout << "File not open";
//		}
//	}
//
//
//
//	bool courseavailable(const string& course, const string* c, const int& cnum)
//	{
//
//		for (int i = 0; i < cnum; i++)
//		{
//			if (course == c[i])
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//
//	void registeration()
//	{
//		int r;
//		cout << "Enter rollnum for course registration: " << endl;
//		cin >> r;
//
//		const int cnum = 8;
//		string c[cnum] = { "oop","discrrete","coal","data","cps","linear","dld","de" };
//		rcourses = new string[max];
//
//		ifstream file("jav.txt");
//		if (!file.is_open())
//		{
//			cout << "File not opened" << endl;
//			delete[]rcourses;
//			return;
//		}
//
//		ofstream outfile("tempfile.txt");
//		if (!outfile.is_open())
//		{
//			cout << "File not opened" << endl;
//			file.close();
//			delete[]rcourses;
//			return;
//		}
//
//		bool b = false;
//		string line;
//		int num;
//		cout << "Enter the number of courses: " << endl;
//		cin >> num;
//
//		cout << "Enter the courses: " << endl;
//		string courses;
//		for (int i = 0; i < num && i < max; i++)
//		{
//			string course;
//			cin >> course;
//			//getline(cin, course);
//			if (courseavailable(course, c, cnum))
//			{
//				rcourses[i] = course;
//			}
//			else
//			{
//				cout << "invalid course" << endl;
//				file.close();
//				outfile.close();
//				remove("tempfile.txt");
//				delete[]rcourses;
//				return;
//			}
//		}
//
//		while (getline(file, line))
//		{
//			istringstream c(line);
//			int r1;
//			c >> r1;
//
//			if (r1 == r)
//			{
//				b = true;
//				rollnum = r;
//				c >> contact >> age >> name;
//
//				outfile << rollnum << "\t\t" << contact << "\t\t" << age << "\t\t" << name;
//				outfile << "\t\t\t";
//				for (int i = 0; i < num; i++)
//				{
//					outfile << rcourses[i] << " ";
//				}
//				outfile << endl;
//
//				// Now, let's also add the roll number to c.txt
//				ifstream cFile("c.txt");
//				ofstream cOutfile("ctempfile.txt");
//
//				if (!cFile.is_open() || !cOutfile.is_open())
//				{
//					cout << "Error: Unable to open c.txt or ctempfile.txt" << endl;
//					file.close();
//					outfile.close();
//					remove("tempfile.txt");
//					delete[]rcourses;
//					return;
//				}
//
//				bool courseFound = false;
//				while (getline(cFile, line))
//				{
//					istringstream c(line);
//					int code;
//					c >> code;
//
//					if (code == num)
//					{
//						courseFound = true;
//
//						string existingstudents;
//						int credits, capacity;
//						string sname, inst;
//						c >> credits >> capacity >> sname >> inst;
//						c >> ws; // Skip whitespaces
//						getline(c, existingstudents);
//
//						cOutfile << code << "\t\t" << credits << "\t\t" << capacity << "\t\t" << sname << "\t\t" << inst;
//						cOutfile << "\t\t" << existingstudents << " " << rollnum << endl;
//						continue;
//					}
//
//					cOutfile << line << endl;
//				}
//
//				cFile.close();
//				cOutfile.close();
//
//				if (!courseFound)
//				{
//					cout << "Error: Course not found in c.txt" << endl;
//					file.close();
//					outfile.close();
//					remove("tempfile.txt");
//					delete[]rcourses;
//					return;
//				}
//
//				// Replace the original c.txt with the temporary file
//				if (remove("c.txt") != 0 || rename("ctempfile.txt", "c.txt") != 0)
//				{
//					cout << "Error updating c.txt" << endl;
//				}
//				break;
//			}
//			outfile << line << endl;
//		}
//
//		file.close();
//		outfile.close();
//
//		if (b)
//		{
//			if (remove("jav.txt") != 0)
//			{
//				cout << "Error in deleting the file" << endl;
//			}
//
//			if (rename("tempfile.txt", "jav.txt") != 0)
//			{
//				cout << "Error in renaming the file" << endl;
//			}
//			else
//			{
//				cout << "Student with roll number " << r << " registered successfully." << endl;
//				display1("jav.txt");
//			}
//		}
//		else
//		{
//			cout << "Roll number not found" << endl;
//			remove("tempfile.txt");
//		}
//		delete[]rcourses;
//	}
//};
//
//class courses :public student {
//protected:
//	int code;
//	string sname;
//	string inst;
//	int credits;
//	int capacity;
//
//	string students;
//public:
//
//	void addstudentincourses()
//	{
//		int ccode;
//		cout << "Enter course code: " << endl;
//		cin >> ccode;
//
//		ifstream file("c.txt");
//		if (!file.is_open())
//		{
//			cout << "Error: Unable to open file" << endl;
//			return;
//		}
//
//		ofstream outfile("tempfile.txt");
//		if (!outfile.is_open())
//		{
//			cout << "Error: Unable to open temporary file" << endl;
//			file.close();
//			return;
//		}
//
//		bool b = false;
//		string line;
//
//		int num;
//		cout << "Enter the number of students: " << endl;
//		cin >> num;
//
//		cout << "Enter the roll numbers: " << endl;
//		string students;
//		for (int i = 0; i < num; i++)
//		{
//			int rn;
//			cin >> rn;
//
//			ifstream checkfile("jav.txt");
//			if (checkfile.is_open())
//			{
//				bool rollnumberexists = false;
//				string line;
//				while (getline(checkfile, line))
//				{
//					istringstream iss(line);
//					int existingRoll;
//					iss >> existingRoll;
//
//					if (existingRoll == rn)
//					{
//						rollnumberexists = true;
//						break;
//					}
//				}
//				checkfile.close();
//
//				if (!rollnumberexists)
//				{
//					cout << "Error: Roll number " << rn << " doesn't exist in txt file." << endl;
//					file.close();
//					outfile.close();
//					remove("tempfile.txt"); // Delete the temporary file
//					return;
//				}
//			}
//			else
//			{
//				cout << "Error: Unable to open jav.txt" << endl;
//				file.close();
//				outfile.close();
//				remove("tempfile.txt"); // Delete the temporary file
//				return;
//			}
//
//			students += to_string(rn) + " ";
//		}
//
//		while (getline(file, line))
//		{
//			istringstream c(line);
//			int code;
//			c >> code;
//
//			if (code == ccode)
//			{
//				b = true;
//
//				string existingstudents;
//
//				c >> credits >> capacity >> sname >> inst;
//				c >> ws; // Skip whitespaces
//				getline(c, existingstudents);
//
//				outfile << code << "\t\t" << credits << "\t\t" << capacity << "\t\t" << sname << "\t\t" << inst;
//				outfile << "\t\t" << existingstudents << " " << students << endl;
//				continue;
//			}
//
//			outfile << line << endl;
//		}
//
//		file.close();
//		outfile.close();
//
//		if (b)
//		{
//			if (remove("c.txt") != 0)
//			{
//				cout << "Error in deleting the file" << endl;
//			}
//
//			if (rename("tempfile.txt", "c.txt") != 0)
//			{
//				cout << "Error in renaming the file" << endl;
//			}
//			else
//			{
//				cout << "Students added to the course successfully." << endl;
//				display2("c.txt");
//			}
//		}
//		else
//		{
//			cout << "Course not found" << endl;
//			remove("tempfile.txt"); // Delete the temporary file
//		}
//	}
//
//};
//
//
//class system1// :public student//public attendance
//{
//public:
//
//	void menu()
//	{
//		student obj;
//		courses rhs;
//
//		int key = 0;
//		//obj.display1("jav.txt");
//		cout << endl << endl;
//		while (key != 6)
//		{
//			cout << "-------------MAIN MENU-----------" << endl;
//			cout << "enter 1 for enrollment" << endl;
//			cout << "enter 2 for course registration" << endl;
//			cout << "enter 3 for attendance" << endl;
//			cout << "enter 4 for marks" << endl;
//			cout << "enter 5 for course withdrawal" << endl;
//			cout << "enter 6 for exit" << endl;
//
//			cout << endl << "enter the key: " << endl;
//			cin >> key;
//
//			
//			if (key == 2)
//			{
//				int k2 = 0;
//				while (k2 != 5)
//				{
//					cout << "-----------------course registration-----------------" << endl;
//					cout << "enter 1 to display the courses " << endl;
//					cout << "enter 2 to register the courses" << endl;
//					cout << "enter 3 to add student for a course" << endl;
//					cout << "enter 4 to remove student for a course" << endl;
//					cout << "enter 5 to exit" << endl;
//
//					cout << "enter the choice" << endl;
//					cin >> k2;
//					if (k2 == 1)
//					{
//						obj.display2("c.txt");
//
//					}
//					else if (k2 == 2)
//					{
//						obj.display1("jav.txt");
//						obj.registeration();
//
//					}
//					else if (k2 == 3)
//					{
//						rhs.display2("c.txt");
//						rhs.addstudentincourses();
//					}
//					/*else if (k2 == 4)
//					{
//						rhs.display2("c.txt");
//						rhs.removestudentfromcourses();
//						rhs.display2("c.txt");
//					}*/
//
//					else if (k2 == 5)
//					{
//						cout << "exiting course registration" << endl;
//						break;
//					}
//					else
//					{
//						break;
//					}
//				}
//			}
//		}
//	}
//};
//
//int main()
//{
//	student rhs;
//
//	system1 object3;
//	object3.menu();
//
//	return 0;
//
//}