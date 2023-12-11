#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <SFML/Graphics.hpp>

using namespace std;

class courses;

class student {
	friend courses;
protected:
	string name;
	int rollnum;
	int contact;
	int age;
	int batch;
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
	
	}

	student(string name1, int rollnum1, int contact1, int age1, int present1, int absent1, int total1, float per1)
	{
		name = name1;
		rollnum = rollnum1;
		contact = contact1;
		age = age1;
		
	}

	~student()
	{}

	void display1(const string& temp) {
		cout << endl << endl << "=========================================== FILE CONTENT =========================================" << endl << endl;
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
			cout << "file not open";
		}
	}
	void display2(const string& temp) {
		cout << endl << endl << "=========================================== FILE CONTENT =========================================" << endl << endl;
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
			cout << "file not open";
		}
	}

	void addstudent()
	{
		int count = 0;
		int rollnum;
		cout << "enter the roll number: ";
		cin >> rollnum;
		int rollnumcheck = rollnum;
		int rrrr = rollnum;
		//check for 4_digit rollnum
		while (rollnumcheck != 0)
		{
			rollnumcheck = rollnumcheck / 10;
			count++;

		}
		if (count == 4)
		{
			cout << "rollnumber is authenticated" << endl;

			// check if the roll number already exists
			ifstream checkfile("jav.txt");
			if (checkfile.is_open())
			{
				string line;
				while (getline(checkfile, line))
				{
					istringstream iss(line);
					int existingroll;
					iss >> existingroll;

					if (existingroll == rollnum)
					{
						cout << "error: roll number already exists." << endl;
						checkfile.close();
						return;
					}
				}
				checkfile.close();
			}
			else
			{
				cout << "error: unable to open file." << endl;
				return;
			}

			/// roll number is unique, proceed to add student
			ofstream file("jav.txt", ios::app);
			if (file.is_open())
			{
				/*string name, courses;
				int age, contact,batch;*/

				cout << "enter batch: ";
				cin >> batch;

				cout << "enter name: ";
				cin.ignore();			 // clear the newline character from the input buffer
				getline(cin, name);

				cout << "enter contact: ";
				cin >> contact;

				cout << "enter age: ";
				cin >> age;

				// add the new student to the file
				file << rollnum<<"-L"<<batch << "\t\t" << contact << "\t\t" << age << "\t\t" << name << endl;
				file.close();

				cout << "student added successfully." << endl;

		}
		else
		{
			cout << "rollnumber is not authentic not 4 digit " << endl;
		}

			display1("jav.txt");

			 ///now, add the roll number to att.txt
			ofstream attfile("att.txt", ios::app);
			if (attfile.is_open())
			{
				attfile << rollnum << "\t\t0\t\t0\t\t0\t\t0" << endl; // assuming initial attendance details
				attfile.close();
				cout << "student added to att.txt successfully." << endl;
			}
			else
			{
				cout << "error: unable to open att.txt for writing." << endl;
				// you might want to handle this error appropriately, such as removing the student from jav.txt
			}

			// now, add the roll number to marks.txt
			ofstream marksfile("marks.txt", ios::app);
			if (marksfile.is_open())
			{
				marksfile << rollnum << "\t\t0\t\t0\t\t0" << endl; // assuming initial attendance details
				marksfile.close();
				cout << "student added to att.txt successfully." << endl;
			}
			else
			{
				cout << "error: unable to open att.txt for writing." << endl;
				// you might want to handle this error appropriately, such as removing the student from jav.txt
			}

		}
		else
		{
			cout << "error: unable to open file for writing." << endl;
		}
	}
	void removestudents()
	{
		int r;
		cout << "enter the rollnum to remove" << endl;
		cin >> r;

		ifstream file("jav.txt");
		if (!file.is_open())
		{
			cout << "file not opened" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open())
		{
			cout << "file not opened" << endl;
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

			// remove from att.txt
			ifstream attfile("att.txt");
			ofstream tempattfile("temp_attfile.txt");

			if (!attfile.is_open() || !tempattfile.is_open())
			{
				cout << "error: unable to open att.txt or temporary attfile" << endl;
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
				cout << "error: unable to delete att.txt" << endl;
			}

			if (rename("temp_attfile.txt", "att.txt") != 0)
			{
				cout << "error: unable to rename temp_attfile.txt to att.txt" << endl;
			}
			else
			{
				cout << "student with roll number " << r << " removed successfully from att.txt." << endl;
				display1("att.txt");
			}


			// remove from marks.txt
			ifstream marksfile("marks.txt");
			ofstream tempmarksfile("temp_marksfile.txt");

			if (!marksfile.is_open() || !tempmarksfile.is_open())
			{
				cout << "error: unable to open att.txt or temporary attfile" << endl;
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
				cout << "error: unable to delete txt" << endl;
			}

			if (rename("temp_marksfile.txt", "marks.txt") != 0)
			{
				cout << "error: unable to rename temp_marksfile.txt to att.txt" << endl;
			}
			else
			{
				cout << "student with roll number " << r << " removed successfully from marks.txt." << endl;
				display1("marks.txt");
			}
		}

		else
		{
			cout << "roll number not found" << endl;
			remove("tempfile.txt");   // delete the temporary file
		}
	}

	void editstudents()
	{
		int r;
		cout << "enter the rollnum to edit: " << endl;
		cin >> r;

		ifstream file("jav.txt");
		if (!file.is_open())
		{
			cout << "file not opened" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open())
		{
			cout << "file not opened" << endl;
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
				cout << "batch: ";
				cin >> batch;

				cout << "student with rollnum " << r << " edited" << endl;
				outfile << rollnum <<"-L"<<batch << "\t\t" << contact << "\t\t" << age << "\t\t" << name << endl;
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
			cout << "roll number not found" << endl;
			remove("tempfile.txt");                           // delete the temporary file
		}
	}

	void courseregistration()
	{
		ofstream outfile("jav.txt", ios::app);
		{
			if (!outfile.is_open())
			{
				cout << "file not opened\n";
			}
			outfile << "the available courses are: " << endl;
			outfile << "oop, discrete, coal, data, cps, linear, dld,  de " << endl;
			outfile.close();
			display1("jav.txt");
		}
	}

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
	
	void attendance()
	{
		int r;
		cout << "enter the rollnum to mark attendance" << endl;
		cin >> r;

		ifstream file("att.txt");
		if (!file.is_open())
		{
			cout << "file not opened" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open())
		{
			cout << "file not opened" << endl;
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
				   
				per = (present / total) * 100;

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
			cout << "roll number not found" << endl;
			remove("tempfile.txt");                           // delete the temporary file
		}
	 }
	void displayatt() {
		cout << endl << endl << "---------------- attendance contents --------------------------" << endl << endl;
		ifstream file("att.txt");
		if (file.is_open()) {
			char a;
			while (file.get(a)) {
				cout << a;
			}
			file.close();
		}
		else {
			cout << "file not open";
		}
	}	
	void marks()
	{
		int r;
		cout << "enter the rollnum to mark marks: " << endl;
		cin >> r;

		ifstream file("marks.txt");
		if (!file.is_open())
		{
			cout << "file not opened" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open())
		{
			cout << "file not opened" << endl;
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
			cout << "roll number not found" << endl;
			remove("tempfile.txt");                           // delete the temporary file
		}
	}
	void displaymarks() {
		cout << endl << endl << "---------------- marks contents --------------------------" << endl << endl;
		ifstream file("marks.txt");
		if (file.is_open()) {
			char a;
			while (file.get(a)) {
				cout << a;
			}
			file.close();
		}
		else {
			cout << "file not open";
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
	const int MAX = 9;
	string rarr[9];


public:

	void registeration()
	{
		int r;
		cout << "enter rollnum for course registration: " << endl;
		cin >> r;
	
		const int cnum = 8;
		string c[cnum] = { "cs1004","cs1005","cs1006","cs1007","ee1001","mt1002","ee1003","mt1008"};
		
		ifstream file("jav.txt");
		if (!file.is_open())
		{
			cout << "file not opened" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open())
		{
			cout << "file not opened" << endl;
			file.close();
			return;
		}

		bool b = false;
		string line;
		int num;
		cout << "enter the number of courses: " << endl;
		cin >> num;
		string courseid;
		cout << "enter the courses: " << endl;
		string courses;
		for (int i = 0; i < num && i < max; i++)
		{
			cin >> courseid;
			
			if (courseavailable(courseid, c, cnum))
			{
				rarr[i] = courseid;
			}
			else
			{
				cout << "invalid course" << endl;
				file.close();
				outfile.close();
				remove("tempfile.txt");
				return;
			}
		}
		int batch;
		while (getline(file, line))
		{
			istringstream c(line);
			int r1;
			c >> r1;

			

			if (r1 == r)
			{
				//cout << r1 << "     " << r << endl;
				b = true;
				rollnum = r;
				c.ignore(2);
				c >> batch >> contact>>age>>name;

				outfile << rollnum<<"-L"<<batch << "\t\t" << contact<<"\t\t"<<age<<"\t\t"<<name;
				outfile << "\t\t\t";
				for (int i = 0; i < num; i++)
				{
					outfile << rarr[i] << " ";
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
				cout << "error in deleting the file" << endl;
			}

			if (rename("tempfile.txt", "jav.txt") != 0)
			{
				cout << "error in renaming the file" << endl;
			}
			else
			{
				cout << "student with roll number " << r << " registered successfully." << endl;
				display1("jav.txt");
			}
			const string coursefilename = "c.txt";
			ifstream coursefile(coursefilename);
			ofstream tempfile("temp_course.txt");

			if (!coursefile.is_open() || !tempfile.is_open()) {
				cout << "error: unable to open course file or temporary file" << endl;
				return;
			}

			string line;
			while (getline(coursefile, line)) {
				istringstream iss(line);
			
				iss >> code;

				tempfile << line;

				for (int i = 0; i < num; i++) 
				{
					
					if (rarr[i]==code) {
						tempfile << "  " << rollnum;
						break;
					}
					
				}

				tempfile << endl;
			}

			coursefile.close();
			tempfile.close();

			if (remove(coursefilename.c_str()) != 0) {
				cout << "error in deleting the course file" << endl;
			}

			if (rename("temp_course.txt", coursefilename.c_str()) != 0) {
				cout << "error in renaming the temporary file" << endl;
			}
			else {
				cout << "course file updated successfully." << endl;
				display2(coursefilename);
			}
		}
		else
		{
			cout << "roll number not found" << endl;
			remove("tempfile.txt"); // delete the temporary file
		
			return;
		}

	}


	void withdraw() {
		int r;
		cout << "enter roll number: " << endl;
		cin >> r;

		ifstream file("jav.txt");
		if (!file.is_open()) {
			cout << "file not opened" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open()) {
			cout << "file not opened" << endl;
			file.close();
			return;
		}

		bool studentfound = false;
		string line;

		cout << "enter the course to withdraw: " << endl;
		string withdraw;
		cin >> withdraw;

		while (getline(file, line)) {
			istringstream c(line);
			int rollnumfromfile;
			c >> rollnumfromfile;

			if (rollnumfromfile == r) {
				studentfound = true;
				string students;
				c >> contact >> age >> name;
				c >> ws; // skip whitespaces
				getline(c, students);

				// check if the student is registered for the course to be withdrawn
				istringstream ss(students);
				string course;
				bool coursefound = false;
				while (ss >> course) {
					if (course == withdraw) {
						coursefound = true;
						break;
					}
				}

				if (!coursefound) {
					cout << "error: student with roll number " << r << " is not registered for course " << withdraw << endl;
					file.close();
					outfile.close();
					remove("tempfile.txt"); // delete the temporary file
					return;
				}

			//	 remove the specified course from the student's courses
				string updatedcourses;
				ss.clear(); // clear the state of stringstream
				ss.seekg(0); // reset the stringstream position to the beginning
				while (ss >> course) {
					if (course != withdraw) {
						updatedcourses += course + " ";
					}
				}

			//	 write back the updated information to the output file
				outfile << rollnumfromfile << "\t\t" << contact << "\t\t" << age << "\t\t" << name;
				outfile << "\t\t\t" << updatedcourses << endl;

				continue;
			}

			outfile << line << endl;
		}


		file.close();
		outfile.close();

	//	 remove the original file and rename the temp file
		if (studentfound) {
			if (remove("jav.txt") != 0) {
				cout << "error in deleting the file" << endl;
			}

			if (rename("tempfile.txt", "jav.txt") != 0) {
				cout << "error in renaming the file" << endl;
			}
			else {
				display1("jav.txt");

				cout << "course withdrawn successfully." << endl;
			}


			const string coursefilename = "c.txt";
			ifstream coursefile(coursefilename);
			ofstream tempfile("temp_course.txt");

			if (!coursefile.is_open() || !tempfile.is_open()) {
				cout << "error: unable to open course file or temporary file" << endl;
				return;
			}

			string courseline;  // rename 'line' to 'courseline'
			while (getline(coursefile, courseline)) {
				istringstream iss(courseline);

				//string code;  // declare 'code' here
				//if (!(iss >> code)) 
				//{
				//	// handle the case where reading the course code fails
				//	cout << "error: unable to read course code." << endl;
				//	break;
				//}
				iss >> code;

				tempfile << line;


				if (withdraw == code) {
					// if the course is found, remove the student's roll number from the line
					string students;
					iss >> ws; // skip whitespaces

					// manually update the student list
					string updatedstudents;
					string rollnumstr;

					while (iss >> rollnumstr) {
						int rollnumincourse = stoi(rollnumstr);
						if (rollnumincourse != r) {
							updatedstudents += " " + to_string(rollnumincourse);
						}
					}
					// update the line with the modified student list
					tempfile << updatedstudents;
				}
			/*	else
				{
					cout << withdraw << "     " << code << endl;
				}*/

				tempfile << endl;  // add a newline after each line (including the original or modified line)
			}
			coursefile.close();
			tempfile.close();

			if (remove(coursefilename.c_str()) != 0) {
				cout << "error in deleting the course file" << endl;
			}

			if (rename("temp_course.txt", coursefilename.c_str()) != 0) {
				cout << "error in renaming the temporary file" << endl;
			}
			else {
				cout << "course file updated successfully." << endl;
				display2(coursefilename);
			}

		}
		else {
			cout << "student not found" << endl;
			remove("tempfile.txt"); // delete the temporary file
		}
	}

	void addstudentincourses()
	{
		string ccode;
		cout << "enter course code: " << endl;
		cin >> ccode;

		ifstream file("c.txt");
		if (!file.is_open())
		{
			cout << "error: unable to open file" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open())
		{
			cout << "error: unable to open temporary file" << endl;
			file.close();
			return;
		}

		bool b = false;
		string line;

		int num;
		cout << "enter the number of students: " << endl;
		cin >> num;

		cout << "enter the roll numbers: " << endl;
		int studentrolls[9];  // use an array to store student roll numbers
		for (int i = 0; i < num; i++)
		{
			cin >> studentrolls[i];  // store the roll number in the array
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
				c >> ws; // skip whitespaces
				getline(c, existingstudents);

				outfile << code << "\t\t" << credits << "\t\t" << capacity << "\t\t" << sname << "\t\t" << inst;
				outfile << "\t\t" << existingstudents;

				// append the new students
				for (int i = 0; i < num; i++)
				{
					outfile << " " << studentrolls[i];
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
				cout << "error in deleting the file" << endl;
			}

			if (rename("tempfile.txt", "c.txt") != 0)
			{
				cout << "error in renaming the file" << endl;
			}
			else
			{
				cout << "students added to the course successfully." << endl;
				display2("c.txt");
			}

			const string stfilename = "jav.txt";
			ifstream studentfile(stfilename);
			ofstream tempfile("temp_sttxt");

			if (!studentfile.is_open() || !tempfile.is_open()) {
				cout << "error: unable to open student file or temporary file" << endl;
				return;
			}

			while (getline(studentfile, line))
			{
				istringstream iss(line);
				iss >> rollnum;

				tempfile << line;

				for (int i = 0; i < num; i++)
				{
					if (rollnum == studentrolls[i])
					{
						tempfile << "\t\t\t" << ccode;
						break;
					}
				}
				tempfile << endl;
			}

			studentfile.close();
			tempfile.close();

			if (remove(stfilename.c_str()) != 0) {
				cout << "error in deleting the course file" << endl;
			}

			if (rename("temp_sttxt", stfilename.c_str()) != 0) {
				cout << "error in renaming the temporary file" << endl;
			}
			else {
				cout << "course file updated successfully." << endl;
				display1(stfilename);
			}
		}
		else
		{
			cout << "course not found" << endl;
			remove("tempfile.txt"); // delete the temporary file
		}
	}

	void removestudentfromcourses() {
		string ccode;
		cout << "enter course code: " << endl;
		cin >> ccode;

		ifstream file("c.txt");
		if (!file.is_open()) {
			cout << "file not opened" << endl;
			return;
		}

		ofstream outfile("tempfile.txt");
		if (!outfile.is_open()) {
			cout << "file not opened" << endl;
			file.close();
			return;
		}

		bool coursefound = false;
		string line;

		cout << "enter the roll number: " << endl;
		int rn;
		cin >> rn;

		while (getline(file, line)) {
			istringstream c(line);
			string code;
			c >> code;

			if (code == ccode) {
				coursefound = true;

				string existingstudents;
				c >> credits >> capacity >> name >> inst;
				c >> ws; // skip whitespaces
				getline(c, existingstudents);
				string students;
				// remove the specified roll number from the existing students
				istringstream ss(existingstudents);
				int roll;
				bool rollfound = false;
				while (ss >> roll) {
					if (roll != rn) {
						students += to_string(roll) + " ";
					}
					else {
						rollfound = true;
					}
				}

				if (!rollfound) {
					cout << "error: roll number " << rn << " not found in course " << ccode << endl;
					file.close();
					outfile.close();
					remove("tempfile.txt"); // delete the temporary file
					return;
				}

				// write back the updated information to the output file
				outfile << code << "\t\t" << credits << "\t\t" << capacity << "\t\t" << name << "\t\t" << inst;
				outfile << "\t\t" << students << endl;
				continue;
			}

			outfile << line << endl;
		}

		file.close();
		outfile.close();

		// remove the original file and rename the temp file
		if (coursefound) {
			if (remove("c.txt") != 0) {
				cout << "error in deleting the file" << endl;
			}

			if (rename("tempfile.txt", "c.txt") != 0) {
				cout << "error in renaming the file" << endl;
			}
			else {
			//	display2("c.txt");
				cout << "student removed from the course successfully." << endl;
			}
		}
		else {
			cout << "course not found" << endl;
			remove("tempfile.txt"); // delete the temporary file
		}

		// Now, remove the course from "jav.txt"
		const string stfilename = "jav.txt";
		ifstream studentfile(stfilename);
		ofstream tempfile("temp_sttxt");

		if (!studentfile.is_open() || !tempfile.is_open()) {
			cout << "error: unable to open student file or temporary file" << endl;
			return;
		}

		while (getline(studentfile, line)) {
			istringstream iss(line);

			if (rollnum == rn) {
				string currentcourse;
				while (iss >> currentcourse) {
					if (currentcourse != ccode) {
						tempfile << currentcourse << "\t\t";
					}
				}
				tempfile << endl;
			}
			else {
				tempfile << line << endl;
			}
		}

		studentfile.close();
		tempfile.close();

		if (remove(stfilename.c_str()) != 0) {
			cout << "error in deleting the course file" << endl;
		}

		if (rename("temp_sttxt", stfilename.c_str()) != 0) {
			cout << "error in renaming the temporary file" << endl;
		}
		else {
			cout << "course file updated successfully." << endl;
			display1(stfilename);
		}
	}





};



class validator {
public:




};

class filehandler {

public:

	void display1(const string& temp) {
		cout << endl << endl << "---------------- file contents --------------------------" << endl << endl;
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
			cout << "file not open";
		}
	}
	void display2(const string& temp) {
		cout << endl << endl << "---------------- file contents --------------------------" << endl << endl;
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
			cout << "file not open";
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
	//	obj.display1("jav.txt");
		cout << endl << endl;
		while (key != 6)
		{
			cout << "==============================MAIN MENU=============================="<<endl;
			cout << "                        1==>>   enter 1 for enrollment" << endl;
			cout << "                        2==>>   enter 2 for course registration" << endl;
			cout << "                        3==>>   enter 3 for attendance" << endl;
			cout << "                        4==>>   enter 4 for marks" << endl;
			cout << "                        5==>>   enter 5 for course withdrawal" << endl;
			cout << "                        6==>>   enter 6 for exit" << endl;
			cout << "========================================================================" << endl;

			cout << endl << "enter the key: " << endl;
			cin >> key;

			if (key == 1)
			{
				int k = 0;
				while (k != 5) {

					cout << "-------------------ENROLLMENT--------------------" << endl;
					cout << "  1==>>    enter 1 to display enrolled students" << endl;
					cout << "  2==>>    enter 2 to add new student" << endl;
					cout << "  3==>>    enter 3 to remove student" << endl;
					cout << "  4==>>    enter 4 to edit student info" << endl;
					cout << "  5==>>    enter 5 to exit" << endl;
					cout << "---------------------------------------------------" << endl;

					cout << "enter 5 to display" << endl;
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
					cout << "-----------------COURSE REGISTRATION-----------------" << endl;
					cout << "  1==>>  enter 1 to display the courses " << endl;
					cout << "  2==>>  enter 2 to register the courses" << endl;
					cout << "  3==>>  enter 3 to add student for a course" << endl;
					cout << "  4==>>  enter 4 to remove student for a course" << endl;
					cout << "  5==>>  enter 5 to exit" << endl;
					cout << "------------------------------------------------------" << endl;

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
					cout << "-----------------ATTENDANCE----------------" << endl;
					cout << "  ==>>  enter 1 to display attendance" << endl;
					cout << "  ==>>  enter 2 to mark attendance" << endl;
					cout << "  ==>>  enter 3 to exit" << endl;
					cout << "-------------------------------------------" << endl;
					int k2;
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
					cout << "-----------------MARKS----------------" << endl;
					cout << "  ==>>  enter 1 to display marks" << endl;
					cout << "  ==>>  enter 2 to assign marks" << endl;
					cout << "  ==>>  enter 3 to exit" << endl;
					cout << "-----------------------------------------" << endl;
					int k2;
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
					cout << "-----------------COURSE WITHDRAWAL----------------" << endl;
					cout << "  ==>>  enter 1 to display the course" << endl;
					cout << "  ==>>  enter 2 to withdraw the courses" << endl;
					cout << "  ==>>  enter 3 to exit" << endl;

					int k2;
					cout << "enter the choice" << endl;
					cin >> k3;
					if (k3 == 1)
					{
						//obj.registeration();
					}
					else if (k3 == 2)
					{
					    obj.display1("jav.txt");
						rhs.withdraw();
					}
				}
			}
			else if (key == 6)
			{
				break;
 
			}
			else
			{
			cout << "invalid key" << endl;
 }
		}
	}
};

int main()
{
	//sf::Font f;
	//f.loadFromFile("new.ttf");

	//// create the window
	//sf::RenderWindow window(sf::VideoMode(900, 800), "Flex");

	//sf::Text text, text1, text2, text3,text4,text5,text6,text7,text8,text9,text10,t,t1;
	//text.setFont(f);
	//text.setCharacterSize(100);
	//text.setFillColor(sf::Color::Blue);
	//text.setPosition(350, 10);
	//text.setString("Flex");
	//text.setStyle(sf::Text::Underlined);

	//text1.setFont(f);
	//text1.setCharacterSize(20);
	//text1.setFillColor(sf::Color::Blue);
	//text1.setPosition(370, 130);
	//text1.setString("Academic Portal\n  FAST NU LHR");

	//text2.setFont(f);
	//text2.setCharacterSize(20);
	//text2.setFillColor(sf::Color::Black);
	//text2.setPosition(400, 180);
	//text2.setString("Sign In");

	//text3.setFont(f);
	//text3.setCharacterSize(20);
	//text3.setFillColor(sf::Color::Black);
	//text3.setPosition(300, 280);
	//text3.setString("Roll No.");

	//// define a 120x50 rectangle
	//sf::RectangleShape rectangle(sf::Vector2f(200.f, 30.f));

	//rectangle.setOutlineColor(sf::Color::Black);
	//rectangle.setOutlineThickness(2); // Set the thickness of the outline
	//rectangle.setFillColor(sf::Color::White); // Set background color
	//rectangle.setPosition(300.f, 310.f); // Set the position as per your requirement

	////// change the size to 100x100
	////rectangle.setSize(sf::Vector2f(100.f, 100.f));

	//text4.setFont(f);
	//text4.setCharacterSize(16);
	//text4.setFillColor(sf::Color::Black);
	//text4.setPosition(320, 310);
	//text4.setString("roll number i.e (1234) ");

	//text5.setFont(f);
	//text5.setCharacterSize(20);
	//text5.setFillColor(sf::Color::Black);
	//text5.setPosition(300, 380);
	//text5.setString("Password ");


	//// define a 120x50 rectangle
	//sf::RectangleShape rectangle1(sf::Vector2f(200.f, 30.f));

	//rectangle1.setOutlineColor(sf::Color::Black);
	//rectangle1.setOutlineThickness(2); // Set the thickness of the outline
	//rectangle1.setFillColor(sf::Color::White); // Set background color
	//rectangle1.setPosition(300.f, 410.f); // Set the position as per your requirement

	//text6.setFont(f);
	//text6.setCharacterSize(20);
	//text6.setFillColor(sf::Color::Black);
	//text6.setPosition(310, 415);
	//text6.setString("********* ");


	//// define a 120x50 rectangle
	//sf::RectangleShape rectangle2(sf::Vector2f(250.f, 70.f));

	//rectangle2.setOutlineColor(sf::Color::Black);
	//rectangle2.setOutlineThickness(2); // Set the thickness of the outline
	//rectangle2.setFillColor(sf::Color::White); // Set background color
	//rectangle2.setPosition(300.f, 480.f); // Set the position as per your requirement


	//// define a 120x50 rectangle
	//sf::RectangleShape rectangle3(sf::Vector2f(30.f, 30.f));

	//rectangle3.setOutlineColor(sf::Color::Black);
	//rectangle3.setOutlineThickness(2); // Set the thickness of the outline
	//rectangle3.setFillColor(sf::Color::White); // Set background color
	//rectangle3.setPosition(320.f, 500.f); // Set the position as per your requirement

	//text7.setFont(f);
	//text7.setCharacterSize(20);
	//text7.setFillColor(sf::Color::Black);
	//text7.setPosition(380, 500);
	//text7.setString("I'm not robot");


	//text8.setFont(f);
	//text8.setCharacterSize(20);
	//text8.setFillColor(sf::Color::Red);
	//text8.setPosition(300, 570);
	//text8.setString("INSTRUCTIONS");

	//text9.setFont(f);
	//text9.setCharacterSize(15);
	//text9.setFillColor(sf::Color::Black);
	//text9.setPosition(300, 600);
	//text9.setString("=>> Roll number shoud be 4-digit");

	//text10.setFont(f);
	//text10.setCharacterSize(15);
	//text10.setFillColor(sf::Color::Black);
	//text10.setPosition(300, 620);
	//text10.setString("=>> Sign in to enter the roll number\n=>> Press SPACE or click on SIGN IN to continue");


	//// define a circle shape and scale it for an ellipse effect
	//sf::CircleShape ellipse(12.f);
	//// set the scale for the x-axis to make it wider
	//ellipse.setScale(4.f, 2.f);
	//// change the fill color to blue
	//ellipse.setFillColor(sf::Color::Blue);
	//// set the position of the ellipse
	//ellipse.setPosition(380.f, 700.f);


	//t.setFont(f);
	//t.setCharacterSize(18);
	//t.setFillColor(sf::Color::White);
	//t.setPosition(400, 710);
	//t.setString("Sign In");


	//// run the program as long as the window is open
	//while (window.isOpen())
	//{
	//	// check all the window's events that were triggered since the last iteration of the loop
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		// "close requested" event: we close the window
	//		if (event.type == sf::Event::Closed)
	//		{
	//			window.close();
	//		}
	//		else if (event.type == sf::Event::TextEntered)
	//		{
	//			if (event.text.unicode == 32)
	//			{
	//				window.close();
	//			}
	//		}

	//		else if (sf::Mouse::getPosition(window).x > ellipse.getGlobalBounds().left && sf::Mouse::getPosition(window).x< ellipse.getGlobalBounds().left + ellipse.getGlobalBounds().width && sf::Mouse::getPosition(window).y
	//		>ellipse.getGlobalBounds().top && sf::Mouse::getPosition(window).y < (ellipse.getGlobalBounds().top + ellipse.getGlobalBounds().height) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//		{
	//			window.close();
	//		}
	//	}
	//	//// clear the window with black color
	//	window.clear(sf::Color::White);

	//	window.draw(text);

	//	window.draw(text1);

	//	window.draw(text2);
	//	window.draw(text3);
	//	window.draw(rectangle);
	//	//cin >> num;
	//	window.draw(text4);
	//	window.draw(text5);
	//	/*window.draw(rectangle1);
	//	window.draw(text6);*/
	//	/*window.draw(rectangle2);
	//	window.draw(rectangle3);

	//	window.draw(text7);*/
	//	window.draw(text8);
	//	window.draw(text9);
	//	window.draw(text10);

	//	window.draw(ellipse);
	//	window.draw(t);

	//	// end the current frame
	//	window.display();
	//}



	system1 object3;
	object3.menu();

	return 0;

}

