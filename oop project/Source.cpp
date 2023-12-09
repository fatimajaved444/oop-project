#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class courses;

class student {
	friend courses;
protected:
	string name;
	int rollnum;
	int contact;
	int age;
	string* rcourses;
	int max = 8;

	int present;
	int absent;
	int total;
	float per;
	int obtained;
	int numofst = 0;
	int maxst = 100;

	int code;
	string sname;
	string inst;
	int credits;
	int capacity;
	string students;

public:
	friend class attendance;
	student()
	{
		name = '\0';
		rollnum = 0;
		contact = 0;
		age = 0;
		
		rcourses = new string[max];
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
		delete[]rcourses;
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
	void display2(const string& temp) {
		cout << endl << endl << "---------------- File Contents --------------------------" << endl << endl;
		ifstream file("c.txt");
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

	void addstudent()
	{
		int count = 0;
		int rollnum;
		cout << "Enter the roll number: ";
		cin >> rollnum;
		int rollnumcheck = rollnum;

		//check for 4_digit rollnum
		while (rollnumcheck != 0)
		{
			rollnumcheck = rollnumcheck / 10;
			count++;

		}
		if (count == 4)
		{
			cout << "rollnumber is authenticated" << endl;

			// Check if the roll number already exists
			ifstream checkfile("jav.txt");
			if (checkfile.is_open())
			{
				string line;
				while (getline(checkfile, line))
				{
					istringstream iss(line);
					int existingRoll;
					iss >> existingRoll;

					if (existingRoll == rollnum)
					{
						cout << "Error: Roll number already exists." << endl;
						checkfile.close();
						return;
					}
				}
				checkfile.close();
			}
			else
			{
				cout << "Error: Unable to open file." << endl;
				return;
			}

			// Roll number is unique, proceed to add student
			ofstream file("jav.txt", ios::app);
			if (file.is_open())
			{
				string name, courses;
				int age, contact;

				cout << "Enter name: ";
				cin.ignore();			 // Clear the newline character from the input buffer
				getline(cin, name);

				cout << "Enter contact: ";
				cin >> contact;

				cout << "Enter age: ";
				cin >> age;

				// Add the new student to the file
				file << rollnum << "\t\t" << contact << "\t\t" << age << "\t\t" << name << endl;
				file.close();

				cout << "Student added successfully." << endl;




		}
		else
		{
			cout << "rollnumber is not authentic not 4 digit " << endl;
		}

	
		//	display1("jav.txt");

			// Now, add the roll number to att.txt
			ofstream attFile("att.txt", ios::app);
			if (attFile.is_open())
			{
				attFile << rollnum << "\t\t0\t\t0\t\t0\t\t0" << endl; // Assuming initial attendance details
				attFile.close();
				//cout << "Student added to att.txt successfully." << endl;
			}
			else
			{
				cout << "Error: Unable to open att.txt for writing." << endl;
				// You might want to handle this error appropriately, such as removing the student from jav.txt
			}

			// Now, add the roll number to marks.txt
			ofstream marksFile("marks.txt", ios::app);
			if (marksFile.is_open())
			{
				marksFile << rollnum << "\t\t0\t\t0\t\t0" << endl; // Assuming initial attendance details
				marksFile.close();
				//cout << "Student added to att.txt successfully." << endl;
			}
			else
			{
				cout << "Error: Unable to open att.txt for writing." << endl;
				// You might want to handle this error appropriately, such as removing the student from jav.txt
			}

		}
		else
		{
			cout << "Error: Unable to open file for writing." << endl;
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

			// Remove from att.txt
			ifstream attfile("att.txt");
			ofstream tempattfile("temp_attfile.txt");

			if (!attfile.is_open() || !tempattfile.is_open())
			{
				cout << "Error: Unable to open att.txt or temporary attfile" << endl;
				return;
			}

			while (getline(attfile, line))
			{
				istringstream c(line);
				int r1;
				c >> r1;

				if (r1 != r)
				{
					tempattfile << line << endl;
				}
			}
			attfile.close();
			tempattfile.close();

			if (remove("att.txt") != 0)
			{
				cout << "Error: Unable to delete att.txt" << endl;
			}

			if (rename("temp_attfile.txt", "att.txt") != 0)
			{
				cout << "Error: Unable to rename temp_attfile.txt to att.txt" << endl;
			}
			else
			{
				cout << "Student with roll number " << r << " removed successfully from att.txt." << endl;
				//display1("att.txt");
			}


			// Remove from marks.txt
			ifstream marksfile("marks.txt");
			ofstream tempmarksfile("temp_marksfile.txt");

			if (!marksfile.is_open() || !tempmarksfile.is_open())
			{
				cout << "Error: Unable to open att.txt or temporary attfile" << endl;
				return;
			}

			while (getline(marksfile, line))
			{
				istringstream c(line);
				int r1;
				c >> r1;

				if (r1 != r)
				{
					tempmarksfile << line << endl;
				}
			}
			marksfile.close();
			tempmarksfile.close();

			if (remove("marks.txt") != 0)
			{
				cout << "Error: Unable to delete txt" << endl;
			}

			if (rename("temp_marksfile.txt", "marks.txt") != 0)
			{
				cout << "Error: Unable to rename temp_marksfile.txt to att.txt" << endl;
			}
			else
			{
				cout << "Student with roll number " << r << " removed successfully from marks.txt." << endl;
				//display1("marks.txt");
			}
		}

		else
		{
			cout << "Roll number not found" << endl;
			remove("tempfile.txt");   // Delete the temporary file
		}
	}

	void editstudents()
	{
		int r;
		cout << "Enter the rollnum to edit: " << endl;
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
				cout << "student with roll number " << r << "edited successfully." << endl;
				display1("jav.txt");
			}
		}
		else
		{
			cout << "Roll number not found" << endl;
			remove("tempfile.txt");                           // Delete the temporary file
		}
	}

	//void courseregistration()
	//{
	//	ofstream outfile("jav.txt", ios::app);
	//	{
	//		if (!outfile.is_open())
	//		{
	//			cout << "File not opened\n";
	//		}
	//		outfile << "the available courses are: " << endl;
	//		outfile << "oop, discrete, coal, data, cps, linear, dld,  de " << endl;
	//		outfile.close();
	//		display1("jav.txt");
	//	}
	//}


	bool courseavailable(const string& course, const string* c, const int& cnum)
	{
			
		for (int i = 0; i < cnum; i++)
		{
			if (course == c[i])
			{
				return true;
			}
		}
		return false;
	}
	
	
	void withdraw() {
		int r;
		cout << "Enter roll number: " << endl;
		cin >> r;

		ifstream file("jav.txt");
		if (!file.is_open()) {
			cout << "File not opened" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open()) {
			cout << "File not opened" << endl;
			file.close();
			return;
		}

		bool studentfound = false;
		string line;

		cout << "Enter the course to withdraw: " << endl;
		string withdraw;
		cin >> withdraw;

		while (getline(file, line)) {
			istringstream c(line);
			int rollnumFromFile;
			c >> rollnumFromFile;

			if (rollnumFromFile == r) {
				studentfound = true;
				string students;
				c >> contact >> age >> name;
				c >> ws; // Skip whitespaces
				getline(c, students);

				// Check if the student is registered for the course to be withdrawn
				istringstream ss(students);
				string course;
				bool courseFound = false;
				while (ss >> course) {
					if (course == withdraw) {
						courseFound = true;
						break;
					}
				}

				if (!courseFound) {
					cout << "Error: Student with roll number " << r << " is not registered for course " << withdraw << endl;
					file.close();
					outfile.close();
					remove("tempfile.txt"); // Delete the temporary file
					return;
				}

				// Remove the specified course from the student's courses
				string updatedcourses;
				ss.clear(); // Clear the state of stringstream
				ss.seekg(0); // Reset the stringstream position to the beginning
				while (ss >> course) {
					if (course != withdraw) {
						updatedcourses += course + " ";
					}
				}

				// Write back the updated information to the output file
				outfile << rollnumFromFile << "\t\t" << contact << "\t\t" << age << "\t\t" << name;
				outfile << "\t\t\t" << updatedcourses << endl;
				continue;
			}

			outfile << line << endl;
		}

		file.close();
		outfile.close();

		// Remove the original file and rename the temp file
		if (studentfound) {
			if (remove("jav.txt") != 0) {
				cout << "Error in deleting the file" << endl;
			}

			if (rename("tempfile.txt", "jav.txt") != 0) {
				cout << "Error in renaming the file" << endl;
			}
			else {
				cout << "Course withdrawn successfully." << endl;
			}
		}
		else {
			cout << "Student not found" << endl;
			remove("tempfile.txt"); // Delete the temporary file
		}
	}

	void attendance()
	{
		int r;
		cout << "Enter the rollnum to mark attendance" << endl;
		cin >> r;

		ifstream file("att.txt");
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
				
				rollnum = r;                                           //keep rollnum same

				cout << "total ";
				cin >> total;
				cout << "present ";
				cin >> present;
				absent = total - present;
				if (present > total)
				{
					cout << "not valid!" << endl;
				}
				else
				{
					double per = (static_cast<double>(present) / total) * 100;

					cout << "student with rollnum " << r << " marked attendance" << endl;
					outfile << rollnum << "\t\t" << present << "\t\t" << absent << "\t\t" << total << "\t\t" << per << endl;
					continue;
				}
				   
				//per = (present / total) * 100;

			}
			outfile << line << endl;
		}
		file.close();
		outfile.close();

		if (b)
		{
			if (remove("att.txt") != 0)
			{
				cout << "error in deleting the file" << endl;
			}
			if (rename("tempfile.txt", "att.txt") != 0)
			{
				cout << "error in renaming the file" << endl;
			}
			else
			{
				cout << "student with roll number " << r << " marked successfully." << endl;
				displayatt();
			}
		}
		else
		{
			cout << "Roll number not found" << endl;
			remove("tempfile.txt");                           // Delete the temporary file
		}
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
	void marks()
	{
		int r;
		cout << "Enter the rollnum to mark marks: " << endl;
		cin >> r;

		ifstream file("marks.txt");
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
				//cin.ignore();
				//cout << "name: ";
				//getline(cin, name);

				rollnum = r;                                           //keep rollnum same

				cout << "total ";
				cin >> total;
				cout << "obtained ";
				cin >> obtained;
				if (obtained > total) {
					cout << "obtained number cant be greater than total number" << endl;
				}
				else
				{

					double per = (static_cast<double>(obtained) / total) * 100;

					cout << "student with rollnum " << r << " marked numbers" << endl;
					outfile << rollnum << "\t\t" << obtained << "\t\t" << total << "\t\t" << per << endl;
					continue;
				}

			}
			outfile << line << endl;
		}

		file.close();
		outfile.close();

		if (b)
		{
			if (remove("marks.txt") != 0)
			{
				cout << "error in deleting the file" << endl;
			}
			if (rename("tempfile.txt", "marks.txt") != 0)
			{
				cout << "error in renaming the file" << endl;
			}
			else
			{
				cout << "student with roll number " << r << " marked successfully." << endl;
				displaymarks();
			}
		}
		else
		{
			cout << "Roll number not found" << endl;
			remove("tempfile.txt");                           // Delete the temporary file
		}
	}
	void displaymarks() {
		cout << endl << endl << "---------------- Marks Contents --------------------------" << endl << endl;
		ifstream file("marks.txt");
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

class courses :public student {
protected:
	string code;
	string sname;
	string inst;
	int credits;
	int capacity;
	string students;
	string newcourse;
public:

	void registeration()
	{
		int r;
		cout << "Enter rollnum for course registration: " << endl;
		cin >> r;
	//	newroll = r;
		const int cnum = 8;
		string c[cnum] = { "cs1004","cs1005","cs1006","cs1007","ee1001","mt1002","ee1003","mt1008"};
		rcourses = new string[max];

		ifstream file("jav.txt");
		if (!file.is_open())
		{
			cout << "File not opened" << endl;
			delete[]rcourses;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open())
		{
			cout << "File not opened" << endl;
			file.close();
			delete[]rcourses;
			return;
		}

		bool b = false;
		string line;
		int num;
		cout << "Enter the number of courses: " << endl;
		cin >> num;
		string courseid;
		cout << "Enter the courses: " << endl;
		string courses;
		for (int i = 0; i < num && i < max; i++)
		{
			cin >> courseid;
			
			if (courseavailable(courseid, c, cnum))
			{
				rcourses[i] = courseid;
				//newcourse = rcourses[i];
			}
			else
			{
				cout << "invalid course" << endl;
				file.close();
				outfile.close();
				//delete[]rcourses;
				remove("tempfile.txt");
				return;
			}
		}
		while (getline(file, line))
		{
			istringstream c(line);
			int r1;
			c >> r1;

			if (r1 == r)
			{
				b = true;
				rollnum = r;
				c >> contact >> age >> name;

				outfile << rollnum << "\t\t" << contact << "\t\t" << age << "\t\t" << name;
				outfile << "\t\t\t";
				for (int i = 0; i < num; i++)
				{
					outfile << rcourses[i] << " ";
				}
				outfile << endl;
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
				cout << "Error in deleting the file" << endl;
			}

			if (rename("tempfile.txt", "jav.txt") != 0)
			{
				cout << "Error in renaming the file" << endl;
			}
			else
			{
				cout << "Student with roll number " << r << " registered successfully." << endl;
				display1("jav.txt");
			}
			const string coursefilename = "c.txt";
			ifstream coursefile(coursefilename);
			ofstream tempFile("temp_course.txt");

			if (!coursefile.is_open() || !tempFile.is_open()) {
				cout << "Error: Unable to open course file or temporary file" << endl;
				return;
			}

			string line;
			while (getline(coursefile, line)) {
				istringstream iss(line);
			
				iss >> code;

				tempFile << line;

				for (int i = 0; i < num; i++) 
				{
					
					if (rcourses[i]==code) {
						tempFile << "  " << rollnum;
						break;
					}
					
				}

				tempFile << endl;
			}

			coursefile.close();
			tempFile.close();

			if (remove(coursefilename.c_str()) != 0) {
				cout << "Error in deleting the course file" << endl;
			}

			if (rename("temp_course.txt", coursefilename.c_str()) != 0) {
				cout << "Error in renaming the temporary file" << endl;
			}
			else {
				cout << "Course file updated successfully." << endl;
				display2(coursefilename);
			}
		}
		else
		{
			cout << "Roll number not found" << endl;
			remove("tempfile.txt"); // Delete the temporary file
		}
		delete[]rcourses;
	}
	
	
	void addstudentincourses()
	{
		string ccode;
		cout << "Enter course code: " << endl;
		cin >> ccode;

		ifstream file("c.txt");
		if (!file.is_open())
		{
			cout << "Error: Unable to open file" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open())
		{
			cout << "Error: Unable to open temporary file" << endl;
			file.close();
			return;
		}

		bool b = false;
		string line;

		int num;
		cout << "Enter the number of students: " << endl;
		cin >> num;

		cout << "Enter the roll numbers: " << endl;
		int studentRolls[9];  // Use an array to store student roll numbers
		for (int i = 0; i < num; i++)
		{
			cin >> studentRolls[i];  // Store the roll number in the array
		}

		while (getline(file, line))
		{
			istringstream c(line);
			string code;
			c >> code;

			if (code == ccode)
			{
				b = true;

				string existingstudents;
				c >> credits >> capacity >> sname >> inst;
				c >> ws; // Skip whitespaces
				getline(c, existingstudents);

				outfile << code << "\t\t" << credits << "\t\t" << capacity << "\t\t" << sname << "\t\t" << inst;
				outfile << "\t\t" << existingstudents;

				// Append the new students
				for (int i = 0; i < num; i++)
				{
					outfile << " " << studentRolls[i];
				}

				outfile << endl;
				continue;
			}

			outfile << line << endl;
		}

		file.close();
		outfile.close();

		if (b)
		{
			if (remove("c.txt") != 0)
			{
				cout << "Error in deleting the file" << endl;
			}

			if (rename("tempfile.txt", "c.txt") != 0)
			{
				cout << "Error in renaming the file" << endl;
			}
			else
			{
				cout << "Students added to the course successfully." << endl;
				display2("c.txt");
			}

			const string stfilename = "jav.txt";
			ifstream studentfile(stfilename);
			ofstream tempFile("temp_sttxt");

			if (!studentfile.is_open() || !tempFile.is_open()) {
				cout << "Error: Unable to open student file or temporary file" << endl;
				return;
			}

			while (getline(studentfile, line))
			{
				istringstream iss(line);

				iss >> rollnum;

				tempFile << line;

				for (int i = 0; i < num; i++)
				{
					if (rollnum == studentRolls[i])
					{
						tempFile << " " << ccode;
						break;
					}
				}
				tempFile << endl;
			}

			studentfile.close();
			tempFile.close();

			if (remove(stfilename.c_str()) != 0) {
				cout << "Error in deleting the course file" << endl;
			}

			if (rename("temp_sttxt", stfilename.c_str()) != 0) {
				cout << "Error in renaming the temporary file" << endl;
			}
			else {
				cout << "Course file updated successfully." << endl;
				display1(stfilename);
			}
		}
		else
		{
			cout << "Course not found" << endl;
			remove("tempfile.txt"); // Delete the temporary file
		}
	}

	void removestudentfromcourses() {
		int ccode;
		cout << "Enter course code: " << endl;
		cin >> ccode;

		ifstream file("c.txt");
		if (!file.is_open()) {
			cout << "File not opened" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open()) {
			cout << "File not opened" << endl;
			file.close();
			return;
		}

		bool courseFound = false;
		string line;


		cout << "Enter the roll numbers: " << endl;
		int rn;

		cin >> rn;
		ifstream checkfile("jav.txt");
		if (checkfile.is_open())
		{
			bool rollnumberexists = false;
			string line;
			while (getline(checkfile, line))
			{
				istringstream iss(line);
				int existingRoll;
				iss >> existingRoll;

				if (existingRoll == rn)
				{
					rollnumberexists = true;
					break;
				}
			}
			checkfile.close();

			if (!rollnumberexists)
			{
				cout << "Error: Roll number " << rn << " doesn't exist in file." << endl;
				file.close();
				outfile.close();
				remove("tempfile.txt"); // Delete the temporary file
				return;
			}
		}
		else
		{
			cout << "Error: Unable to open jav.txt" << endl;
			file.close();
			outfile.close();
			remove("tempfile.txt"); // Delete the temporary file
			return;
		}

		while (getline(file, line)) {
			istringstream c(line);
			int code;
			c >> code;

			if (code == ccode)
			{
				courseFound = true;
				
				string existingstudents;
				c >> credits >> capacity >> name >> inst;
				c >> ws;    // Skip whitespaces
				getline(c, existingstudents);
				string students;
				// Remove the specified roll numbers from the existing students
				istringstream ss(existingstudents);
				int roll;
				while (ss >> roll) {
					if (roll != rn) {
						students += to_string(roll) + " ";
					}
				}
				// Write back the updated information to the output file
				outfile << code << "\t\t" << credits << "\t\t" << capacity << "\t\t" << name << "\t\t" << inst;
				outfile << "\t\t" << students << endl;
				continue;
			}

			outfile << line << endl;
		}

		file.close();
		outfile.close();

		// Remove the original file and rename the temp file
		if (courseFound) {
			if (remove("c.txt") != 0) {
				cout << "Error in deleting the file" << endl;
			}
			
			if (rename("tempfile.txt", "c.txt") != 0) {
				cout << "Error in renaming the file" << endl;
			}
			else {
				cout << "Student removed from the course successfully." << endl;
			}
		}
		else {
			cout << "Course not found" << endl;
			remove("tempfile.txt"); // Delete the temporary file
		}
	}
};

class system1// :public student//public attendance
{
public:

	void menu()
	{
		student obj;
		courses rhs;
	
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
						obj.addstudent();
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
				while (k2 != 5)
				{
					cout << "-----------------course registration-----------------" << endl;
					cout << "enter 1 to display the courses " << endl;
					cout << "enter 2 to register the courses" << endl;
					cout << "enter 3 to add student for a course" << endl;
					cout << "enter 4 to remove student for a course" << endl;
					cout << "enter 5 to exit" << endl;

					cout << "enter the choice" << endl;
					cin >> k2;
					if (k2 == 1)
					{
						obj.display2("c.txt");
						
					}
					else if (k2 == 2)
					{
						obj.display1("jav.txt");
						rhs.registeration();
						
					}
					else if (k2 ==3 )
					{
						rhs.display2("c.txt");
						rhs.addstudentincourses();
					}
					else if (k2 == 4)
					{
						rhs.display2("c.txt");
						rhs.removestudentfromcourses();
						rhs.display2("c.txt");
					}

					else if (k2 == 5)
					{
						cout << "exiting course registration" << endl;
						break;
					}
					else
					{
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

						obj.displayatt();
					}
					else if (k4 == 2)
					{
						obj.attendance();

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
						obj.displaymarks();
					}
					else if (k5 == 2)
					{
						obj.marks();

					}

				}
			}
			else if (key == 5) {
				int k3 = 0;
				while (k3 != 3)
				{
					cout << "-----------------course withdrawal-----------------" << endl;
					cout << "enter 1 to display the course" << endl;
					cout << "enter 2 to withdraw the courses" << endl;
					cout << "enter 3 to exit" << endl;

					//int k2;
					cout << "enter the choice" << endl;
					cin >> k3;
					if (k3 == 1)
					{
						//obj.registeration();
					}
					else if (k3 == 2)
					{
						obj.display1("jav.txt");
						obj.withdraw();
						obj.display1("jav.txt");
					}
				}
			}
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