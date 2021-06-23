Create a timetable ADT called TTADT that holds time table.The ADT has a load function that loads an CSV file containing a time table. The name of the file is given as input. The format of time table is the same used by the FAST NUCES CS dept.Before using the time table i removed extra stuff from it manually such as "Reserved for Fast School of Management (FSM)" etc.
Assumptions about timetable: There are 5 working days. There can be at max 28 parallel sessions each day/ time slot instead of 25. There will be 8 1.5 hr slots per day starting from 8:00 AM. Some slots can be combined such as in the case of lab sessions.
So we have the time table and the list of students registered in each section.
Functionality I have implemented in this:
1.	void saveClashes();
Detect any clashes and store the information in a file clash.txt.
Format:
<roll no> <name> <course 1 with section> <course 2 with section> on <day><time>

2.	void printStudentTimeTable(char rollno[]);
Print a student’s time table. 
Format:
<course 1 with section>: 
<day> - <starttime>:<endtime>, <classroom> || <day> - <starttime>:<endtime>, <classroom>, …
<day> - <starttime>:<endtime>, <classroom> || <day> - <starttime>:<endtime>, <classroom>, …

<course 2 with section>: 
<day> - <starttime>:<endtime>, <classroom> || <day> - <starttime>:<endtime>, <classroom>, …
<day> - <starttime>:<endtime>, <classroom> || <day> - <starttime>:<endtime>, <classroom>, …
~ Sample example
Programming Fundamentals (CS-B): 
Wednesday 9:30:10:50, CS-1 || Friday 9:30:10:50, CS-5

Calculus (CS-B): 
Tuesday 11:00:12:20, CS-4 || Thursday 9:30:10:50, CS-3

3.	void printCourse(char day[], char time[], char classroom );
Print the course name with section

4.	void printCourseTimings(char coursename[], char section[] );
print the class timing of a particular course
Sample example:
Monday 9:30
Wednesday 11:00

  Moreover simple CLR is used for illustration.
