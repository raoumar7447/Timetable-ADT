#pragma once
#include "MyForm.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct classlist
{
	int count;
	char names[60][15]; //60 students in class, first name only.
	char rollNo[60][10];
	classlist()
	{
		count = 0;
	}
};
struct node
{
	char subject[999];
	char room_no[999];
	char start_time[10];
	char end_time[10];
	char weekday[999];
	classlist *record;
	node *next;
	node()
	{
		record = nullptr;
		next = nullptr;
	}
};
class Schedual
{
private:
	node *first;
public:
	Schedual(node * f = nullptr)
	{
		first = f;
	}
	void insert(char d[], char r[], char s[], int t, int et)
	{
		node * temp = new node;
		strcpy_s(temp->weekday, d);
		strcpy_s(temp->room_no, r);
		strcpy_s(temp->subject, s);
		//checking starting time of sessions
		if (t == 1)
		{
			strcpy_s(temp->start_time, "8:00 am");
		}
		else if (t == 2)
		{
			strcpy_s(temp->start_time, "9:30 am");

		}
		else if (t == 3)
		{
			strcpy_s(temp->start_time, "11:00 am");

		}
		else if (t == 4)
		{
			strcpy_s(temp->start_time, "12:30 pm");

		}
		else if (t == 5)
		{
			strcpy_s(temp->start_time, "2:00 pm");

		}
		else if (t == 6)
		{
			strcpy_s(temp->start_time, "3:30 pm");

		}
		else if (t == 7)
		{
			strcpy_s(temp->start_time, "5:00 pm");

		}
		else if (t == 8)
		{
			strcpy_s(temp->start_time, "6:30 pm");

		}
		//checking for ending time of sessions
		if (et == 2)
		{
			strcpy_s(temp->end_time, "9:30 am");

		}
		else if (et == 3)
		{
			strcpy_s(temp->end_time, "11:00 am");

		}
		else if (et == 4)
		{
			strcpy_s(temp->end_time, "12:30 pm");

		}
		else if (et == 5)
		{
			strcpy_s(temp->end_time, "2:00 pm");

		}
		else if (et == 6)
		{
			strcpy_s(temp->end_time, "3:30 pm");

		}
		else if (et == 7)
		{
			strcpy_s(temp->end_time, "5:00 pm");

		}
		else if (et == 8)
		{
			strcpy_s(temp->end_time, "6:30 pm");

		}
		else if (et == 9)
		{
			strcpy_s(temp->end_time, "8:00 pm");

		}
		temp->next = nullptr;
		if (first == nullptr)
		{
			first = temp;

		}
		else
		{
			node *curr = first;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}

	}
	 void print()
	{
		node *curr = first;
		ofstream file;
		file.open("Full_timetable.txt", ofstream::app);
		while (curr != nullptr)
		{
			file << curr->weekday << " ";
			file << curr->room_no << " ";
			file << curr->subject << " ";
			file << curr->start_time << " - ";
			file << curr->end_time << " ";
			curr = curr->next;
		}
		file << endl;
	}
	void loadStudentInfo(char rollnumber[], char first_name[], char subject[], char section[])
	{
		/*It has two main cases.First one is for subjects it will read student registration data if the data are of classes so we keep them in subject's list
		secondly if those are labs data then it will go to every slot of linklist and will check if they contains lab data then there are two main cases
		first one is labs are not combined and second one is labs are combined so for the first case it goes same as the class data and no changes will occur
		simply it will go to that lab and insert data but for the second cases we have used two extra string that takes the subject data of linklist until '&' comes
		and then simply concatenate with this ')' bracket now a loop will run that places data of string one into string two and on the last place we simply replace
		data with 2 now student registration data will compare with both of them and performs the tasks*/
		int counter = 0;
		bool flag;
		char dummy[999];
		strcpy_s(dummy, subject);
		strcat_s(dummy, " (");
		strcat_s(dummy, section);
		strcat_s(dummy, ")");
		node * curr = nullptr;
		if (first == nullptr)
			return;
		curr = first;
		int number = strlen(dummy);
		flag = false;
		//if registration data is a lab
		for (int check_lab = 0; check_lab < number; check_lab++)
		{
			if (dummy[check_lab] == 'L')
			{
				check_lab++;
				if (dummy[check_lab] == 'a')
				{
					check_lab++;
					if (dummy[check_lab] == 'b')
					{
						flag = true;
						break;
					}

				}
			}
		}

		if (flag == false)
		{
			while (curr != nullptr)
			{
				if (strcmp(curr->subject, dummy) == 0)
				{
					if (curr->record == nullptr)
					{
						classlist * temp = new classlist;
						strcpy_s(temp->names[counter], first_name);
						strcpy_s(temp->rollNo[counter], rollnumber);
						temp->count = counter + 1;
						curr->record = temp;

					}
					else if (curr->record != nullptr)
					{
						counter = curr->record->count;
						strcpy_s(curr->record->names[counter], first_name);
						strcpy_s(curr->record->rollNo[counter], rollnumber);
						curr->record->count = counter + 1;

					}
				}
				curr = curr->next;
			}
		}
		else
		{
			flag = true;
			int dummy_number = 0;
			char dummy_2[999];
			char string1[999] = "\0";
			char string2[999] = "\0";
			while (curr != nullptr)
			{
				strcpy_s(dummy_2, curr->subject);
				dummy_number = strlen(dummy_2);
				for (int i = 0; i < dummy_number; i++)
				{
					if (dummy_2[i] == '1' || dummy_2[i] == '2')
					{
						string1[i] = dummy_2[i];
						i++;
						if (dummy_2[i] == '&')
						{
							string1[i] = ')';
							flag = false;
							break;

						}
						else
						{
							string1[i] = dummy_2[i];
						}
					}
					else
					{
						string1[i] = dummy_2[i];
					}
				}
				if (flag == true)
				{
					if (strcmp(curr->subject, dummy) == 0)
					{
						if (curr->record == nullptr)
						{
							classlist * temp = new classlist;
							counter = temp->count;
							strcpy_s(temp->names[counter], first_name);
							strcpy_s(temp->rollNo[counter], rollnumber);
							temp->count = counter + 1;
							curr->record = temp;


						}
						else if (curr->record != nullptr)
						{
							counter = curr->record->count;
							if (curr->record->count <= 60)
							{

								strcpy_s(curr->record->names[counter], first_name);
								strcpy_s(curr->record->rollNo[counter], rollnumber);
								curr->record->count = counter + 1;
							}
							else
							{
								cout << "Class is full.Unable to add more students" << endl;
							}
						}
					}
				}
				else
				{
					dummy_number = strlen(string1);
					for (int i = 0; i < dummy_number; i++)
					{
						if (i == dummy_number - 2)
						{
							string2[i] = '2';
						}
						else
						{
							string2[i] = string1[i];
						}
					}
					if ((strcmp(string1, dummy) == 0) || (strcmp(string2, dummy) == 0))
					{
						if (curr->record == nullptr)
						{
							classlist * temp = new classlist;
							counter = temp->count;
							strcpy_s(temp->names[counter], first_name);
							strcpy_s(temp->rollNo[counter], rollnumber);
							temp->count = counter + 1;
							curr->record = temp;

						}
						else if (curr->record != nullptr)
						{

							counter = curr->record->count;
							if (curr->record->count <= 60)
							{
								strcpy_s(curr->record->names[counter], first_name);
								strcpy_s(curr->record->rollNo[counter], rollnumber);
								curr->record->count = counter + 1;
							}
							else
							{
								cout << "Class is full.Unable to add more students" << endl;
							}
						}

					}

				}

				curr = curr->next;
			}

		}

	}
	void Student_Info_print()
	{
		if (first == nullptr)
			return;
		int counter = 0;
		node *curr = first;
		ofstream file;
		file.open("Student_Info_print.txt", ofstream::app);
		while (curr != nullptr)
		{
			if (curr->record != nullptr)
			{
				while (counter < curr->record->count)
				{
					file << counter << ",";
					file << curr->record->rollNo[counter] << ",";
					file << curr->record->names[counter] << ",";
					file << curr->subject << endl;
					counter++;
				}

			}
			curr = curr->next;
		}


	}
	void printStudentTimeTable(ofstream & file,char rollno[], char subject[][100], char day[][50], char room_number[][50], char start_time[][50], char end_time[][50], int & c, char flags[])
	{
		int dummy_index = 0;
		bool flag = false;
		if (first == nullptr)
			return;
		node *curr = first;
		int counter = 0;
		while (curr != nullptr)
		{
			if (curr->record != nullptr)
			{
				counter = curr->record->count;
				for (int i = 0; i < counter; i++)
				{
					if (strcmp(curr->record->rollNo[i], rollno) == 0)
					{
						if (c == 0)
						{
							strcpy_s(subject[c], curr->subject);
							strcpy_s(room_number[c], curr->room_no);
							strcpy_s(day[c], curr->weekday);
							strcpy_s(start_time[c], curr->start_time);
							strcpy_s(end_time[c], curr->end_time);
							flags[c] = '0';
							c++;

						}
						else
						{
							for (int j = 0; j < c; j++)
							{
								if (strcmp(curr->subject, subject[j]) == 0)
								{
									flag = true;
									dummy_index = j;
									break;
								}
							}
							if (flag == true)
							{
								file << subject[dummy_index] << " : " << endl;
								file << day[dummy_index] << " " << start_time[dummy_index] << " : " << end_time[dummy_index] << " , ";
								file << room_number[dummy_index] << " || ";
								file << curr->weekday << " - ";
								file << curr->start_time << " : " << curr->end_time << " , ";
								file << curr->room_no << endl;
								flags[dummy_index] = '1';
							}
							else
							{
								strcpy_s(subject[c], curr->subject);
								strcpy_s(room_number[c], curr->room_no);
								strcpy_s(day[c], curr->weekday);
								strcpy_s(start_time[c], curr->start_time);
								strcpy_s(end_time[c], curr->end_time);
								flags[c] = '0';
								c++;

							}

						}

					}
				}
			}
			curr = curr->next;
			flag = false;
		}

	}
	void printStudentCourses(ofstream & file,char rollno[], char subject[][100], char day[][50], char room_number[][50], char start_time[][50], char end_time[][50], int & c, char flags[])
	{
		int dummy_index = 0;
		bool flag = false;
		if (first == nullptr)
			return;
		node *curr = first;
		int counter = 0;
		while (curr != nullptr)
		{
			if (curr->record != nullptr)
			{
				counter = curr->record->count;
				for (int i = 0; i < counter; i++)
				{
					if (strcmp(curr->record->rollNo[i], rollno) == 0)
					{
						if (c == 0)
						{
							strcpy_s(subject[c], curr->subject);
							strcpy_s(room_number[c], curr->room_no);
							strcpy_s(day[c], curr->weekday);
							strcpy_s(start_time[c], curr->start_time);
							strcpy_s(end_time[c], curr->end_time);
							flags[c] = '0';
							c++;

						}
						else
						{
							for (int j = 0; j < c; j++)
							{
								if (strcmp(curr->subject, subject[j]) == 0)
								{
									flag = true;
									dummy_index = j;
									break;
								}
							}
							if (flag == true)
							{
								file << subject[dummy_index] << endl;
								flags[dummy_index] = '1';
							}
							else
							{
								strcpy_s(subject[c], curr->subject);
								strcpy_s(room_number[c], curr->room_no);
								strcpy_s(day[c], curr->weekday);
								strcpy_s(start_time[c], curr->start_time);
								strcpy_s(end_time[c], curr->end_time);
								flags[c] = '0';
								c++;

							}

						}

					}
				}
			}
			curr = curr->next;
			flag = false;
		}


	}
	void printCourseTimings(ofstream & file, char coursename[], char section[])
	{
		char dummy[999];
		strcpy_s(dummy, coursename);
		strcat_s(dummy, " (");
		strcat_s(dummy, section);
		strcat_s(dummy, ")");
		node *curr = first;
		while (curr != nullptr)
		{
			if (strcmp(dummy, curr->subject) == 0)
			{
				file << curr->weekday << " ";
				file << curr->start_time << endl;
			}

			curr = curr->next;
		}
	}
	void printCourse(ofstream & file, char day[], char time[], char classroom[])
	{
		node *curr = first;
		if (first == nullptr)
			return;
		while (curr != nullptr)
		{
			if (strcmp(day, curr->weekday) == 0)
			{
				if (strcmp(time, curr->start_time) == 0)
				{
					if (strcmp(classroom, curr->room_no) == 0)
					{
						file << curr->subject << endl;
					}
				}
			}
			curr = curr->next;
		}

	}
	void saveClashes(ofstream & file,char roll_number[], char subject[][100], char day[][50], char start_time[][50], char end_time[][50], int & c)
	{
		int dummy_index = 0;
		bool flag = false;
		if (first == nullptr)
			return;
		node *curr = first;
		int counter = 0;
		while (curr != nullptr)
		{
			if (curr->record != nullptr)
			{
				counter = curr->record->count;
				for (int i = 0; i < counter; i++)
				{
					if (strcmp(curr->record->rollNo[i], roll_number) == 0)
					{
						if (c == 0)
						{
							strcpy_s(subject[c], curr->subject);
							strcpy_s(day[c], curr->weekday);
							strcpy_s(start_time[c], curr->start_time);
							strcpy_s(end_time[c], curr->end_time);
							c++;

						}
						else
						{
							for (int j = 0; j < c; j++)
							{
								if ((strcmp(curr->start_time, start_time[j]) == 0) || (strcmp(curr->end_time, end_time[j]) == 0))
								{
									dummy_index = j;
									flag = true;
									break;
								}
							}
							if (flag == true)
							{
								
									file << roll_number << " ";
									file << curr->record->names[dummy_index] << " ";
									file << "< " << subject[dummy_index] << " > " << "  with  ";
									file << "< " << curr->subject << " > " << " on ";
									file << curr->weekday << " " << curr->start_time << endl;
								
							}
							else
							{
								strcpy_s(subject[c], curr->subject);
								strcpy_s(day[c], curr->weekday);
								strcpy_s(start_time[c], curr->start_time);
								strcpy_s(end_time[c], curr->end_time);
								c++;
							}
						}
					}
				}
			}
			flag = false;
			curr = curr->next;
		}

	}
	~Schedual()
	{
		if (first != nullptr)
		{
			node *curr = nullptr;
			while (first != nullptr)
			{
				curr = first;
				first = first->next;
				delete curr;
			}
			delete first;

		}
	}
	friend class TTADT;
};
class TTADT
{
private:
	Schedual **s;
public:
	TTADT()
	{
		s = new Schedual*[5];
		for (int i = 0; i < 5; i++)
		{
			s[i] = new Schedual[28];
		}
	}
	void load_function(char filename[])
	{
		int start_time = 1;
		int end_time = 0;
		bool flag;
		char ch = '\0';
		char array[1000];
		char day[1000];
		char room[1000];
		ifstream file;
		file.open(filename);
		if (file.is_open())
		{
			file.getline(array, 999, '\n');
			file.getline(array, 999, '\n');
			file.getline(array, 999, '\n');
			file.getline(array, 999, '\n');
			for (int j = 0; j < 5; j++)			//for 5 days
			{
				file.getline(array, 999, ',');			//day
				strcpy_s(day, array);
				for (int i = 0; i < 28; i++)
				{
					file.getline(array, 999, ',');
					strcpy_s(room, array);				//room
					int number = strlen(array);
					flag = false;
					for (int check_lab = 0; check_lab < number; check_lab++)
					{
						if (array[check_lab] == 'L')
						{
							check_lab++;
							if (array[check_lab] == 'a')
							{
								check_lab++;
								if (array[check_lab] == 'b')
								{
									flag = true;
								}

							}
						}
					}

					if (flag == true)
					{
						for (int labsloop = 0; labsloop < 4; labsloop++)
						{

							end_time = start_time + 2;
							file.getline(array, 999, ',');
							s[j][i].insert(day, room, array, start_time, end_time);

							for (int k = 0; k < 17; k++)
							{
								file.get(ch);
							}
							start_time += 2;
						}

					}
					else
					{
						for (int inner_loop = 0; inner_loop < 8; inner_loop++)
						{
							end_time = start_time + 1;
							file.getline(array, 999, ',');
							s[j][i].insert(day, room, array, start_time, end_time);
							for (int k = 0; k < 8; k++)
							{
								file.get(ch);
							}
							start_time += 1;
						}
					}
					flag = false;
					start_time = 1;
					file.getline(array, 999, '\n');
					if (i < 27)
					{
						file.get(ch);
					}
				}
			}
			file.close();
		}
	}
	void print()							//simply print data of every slot of linkedlist(timetable)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 28; j++)
			{
				s[i][j].print();
			}
		}
	}

	void loadStudentInfo(char filename[])
	{
		char rollnumber[10];
		char first_name[15];
		char subject[999];
		char section[10];
		ifstream file;
		file.open(filename);
		if (file.is_open())
		{
			file.ignore(999, '\n');
			while (!(file.eof()))
			{
				file.getline(rollnumber, 10, ',');		//getting roll number from file
				file.getline(first_name, 15, ',');		//getting first name from file
				file.getline(subject, 999, ',');		//getting subject name from file
				file.getline(section, 10, '\n');		//getting section name from file

				for (int i = 0; i < 5; i++)
				{

					for (int j = 0; j < 28; j++)
					{
						s[i][j].loadStudentInfo(rollnumber, first_name, subject, section);		//it will check every single slot of linkedlist where it matches it keep students data on that particulor node
					}

				}

			}
		}
		file.close();


	}
	void Student_Info_print()					//prints students data present on a specific node
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 28; j++)
			{
				s[i][j].Student_Info_print();
			}
		}
	}
	void printStudentTimeTable(char rollno[])
	{
		ofstream file;
		file.open("printStudentTimeTable.txt", ofstream::app);
		file << "\t\t\t\tStudent Timetable function \t\t\t\t" << endl;
		char subject[10][100] = { '\0' };
		char day[10][50] = { '\0' };
		char room_number[10][50] = { '\0' };
		char start_time[10][50] = { '\0' };
		char end_time[10][50] = { '\0' };
		char flags[10] = { '\0' };
		int c = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 28; j++)
			{
				s[i][j].printStudentTimeTable(file,rollno, subject, day, room_number, start_time, end_time, c, flags);
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (flags[i] == '0')
			{
				file << subject[i] << " : " << endl;
				file << day[i] << " - ";
				file << start_time[i] << " : " << end_time[i] << " , ";
				file << room_number[i] << endl;
			}
		}

		file.close();
	}
	void printStudentCourses(char rollno[])
	{
		ofstream file;
		file.open("printStudentCourses.txt", ofstream::app);
		file << "\t\t\t\tStudent Courses function \t\t\t\t" << endl;
		char subject[10][100] = { '\0' };
		char day[10][50] = { '\0' };
		char room_number[10][50] = { '\0' };
		char start_time[10][50] = { '\0' };
		char end_time[10][50] = { '\0' };
		char flags[10] = { '\0' };
		int c = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 28; j++)
			{
				s[i][j].printStudentCourses(file,rollno, subject, day, room_number, start_time, end_time, c, flags);
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (flags[i] == '0')
			{
				file << subject[i] << endl;
			}
		}
		file.close();
	}

	void printCourseTimings(char coursename[], char section[])
	{
		ofstream file;
		file.open("printCourseTimings.txt", ofstream::app);
		file << "\t\t\t\tCourse Timings function \t\t\t\t" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 28; j++)
			{
				s[i][j].printCourseTimings(file,coursename, section);
			}
		}
		file.close();
	}
	void printCourse(char day[], char time[], char classroom[])
	{
		ofstream file;
		file.open("printCourse.txt", ofstream::app);
		file << "\t\t\t\tCourse name function \t\t\t\t" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 28; j++)
			{
				s[i][j].printCourse(file,day, time, classroom);
			}
		}
		file.close();
	}
	void saveClashes()
	{
		ofstream file;
		file.open("Save_clashes.txt", ofstream::app);
		file << "\t\t\t\tSave Clashes function \t\t\t\t" << endl;
		for (int i = 0; i < 5; i++)
		{

			for (int j = 0; j < 28; j++)
			{
				node *curr = s[i][j].first;
				while (curr != nullptr)
				{
					if (curr->record)
					{
						for (int m = 0; m < curr->record->count; m++)
						{
							char subject[10][100] = { '\0' };
							char day[10][50] = { '\0' };
							char start_time[10][50] = { '\0' };
							char end_time[10][50] = { '\0' };
							int c = 0;
							for (int k = 0; k < 28; k++)
							{
								s[i][k].saveClashes(file,curr->record->rollNo[m], subject, day, start_time, end_time, c);
							}

						}
					}
					curr = curr->next;
				}
			}

		}
		file.close();
	}
	~TTADT()
	{
		if (s != nullptr)
		{
			for (int i = 0; i < 5; i++)
			{
				delete[] s[i];

			}
			delete[] s;
		}
	}

};
//int main()
//{
//	TTADT t;
//	t.load_function("input.csv");
////	t.print();
//	t.loadStudentInfo("Registration data.csv");
////	t.Student_Info_print();
////	t.printStudentTimeTable("322");
////	t.printStudentCourses("322");
////	t.printCourseTimings("Human Computer Interaction","CS-E");
////	t.printCourseTimings("Design & Analysis of Algorithms", "CS-B");
////	t.printCourse("Wednesday", "11:00 am","CS-2");
//	t.saveClashes();
//	system("pause");
//	return 0;
//}