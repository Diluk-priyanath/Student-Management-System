## Student-Management-System

The **Student Management System** is a console-based application developed in C language to efficiently manage student and course information. It allows users to add, update, view, and manage student details, course information, and calculate GPA values. The system saves all data persistently in text files for future reference.

### Key Features:
- **Menu-Driven Interface:** Provides a user-friendly menu with six options:
  1. Add Students
  2. Add Courses
  3. View Courses
  4. View Student Details and GPA
  5. Update Student Details
  6. Update Course Details
  7. Exit the Program
- **Data Storage:** 
  - **Student Data:** Stored in `stu.txt`, including:
    - Index Number
    - Name
    - Department
    - Grades
  - **Course Data:** Stored in `coursedetails.txt`, including:
    - Course ID
    - Course Name
    - Course Values
  - All records are appended to maintain a cumulative log of information.
- **GPA Calculation:** Automatically calculates and displays GPA values for students based on their grades.
- **Comprehensive Reporting:** Generates detailed reports in the respective text files for easy access and analysis.

This system simplifies the management of student records and course details while ensuring data persistence and accurate GPA calculation.
