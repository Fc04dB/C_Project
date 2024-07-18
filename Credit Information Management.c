#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 100
#define MAX_RECORDS 100

typedef struct {
    char id[10];
    char name[20];
    char gender[10];
    char dob[15];
    char phone[15];
    char email[30];
} Student;

typedef struct {
    char id[10];
    char name[50];
    int credits;
    char type[20];
} Course;

typedef struct {
    char course_id[10];
    char student_id[10];
    char student_name[20];
    int grade;
} Record;

Student students[MAX_STUDENTS];
Course courses[MAX_COURSES];
Record records[MAX_RECORDS];

int student_count = 0;
int course_count = 0;
int record_count = 0;

//函数声明
void add_student();
void delete_student();
void update_student();
void search_student();

void add_course();
void delete_course();
void update_course();
void search_course();

void add_record();
void delete_record();
void update_record();
void search_record();

void print_student_grades();
void print_student_credits();
void check_graduation();

void save_students_to_file();
void load_students_from_file();
void save_courses_to_file();
void load_courses_from_file();
void save_records_to_file();
void load_records_from_file();

void menu();

int main() {
    load_students_from_file();
    load_courses_from_file();
    load_records_from_file();
    menu();
    return 0;
}

void menu() {
    printf(" a88888b.                         dP oo   dP      dP          .8888b    \n") ;
    printf("d8'   `88                         88      88      88          88  \n");
    printf("88        88d888b. .d8888b. .d888b88 dP d8888P    88 88d888b. 88aaa  .d8888b. \n");
    printf("88        88'  `88 88ooood8 88'  `88 88   88      88 88'  `88 88     88'  `88 \n");
    printf("Y8.   .88 88       88.  ... 88.  .88 88   88      88 88    88 88     88.  .88 \n");
    printf(" Y88888P' dP       `88888P' `88888P8 dP   dP      dP dP    dP dP     `88888P'    \n") ;
    int choice;
    
    while (1) {
        printf("\n=====学分信息管理系统=====\n");
        printf("==========================\n");
        printf("学生信息管理：\n");
        printf("1. 增加学生\n");
        printf("2. 删除学生\n");
        printf("3. 更新学生信息\n");
        printf("4. 查找学生\n");
        printf("==========================\n");
        printf("课程信息管理：\n");
        printf("5. 增加课程\n");
        printf("6. 删除课程\n");
        printf("7. 更新课程信息\n");
        printf("8. 查找课程\n");
        printf("==========================\n");
        printf("成绩信息管理：\n");
        printf("9. 增加成绩\n");
        printf("10. 删除成绩\n");
        printf("11. 更新成绩\n");
        printf("12. 查找成绩\n");
        printf("==========================\n");
        printf("综合信息检索：\n");
        printf("13. 打印学生所有课程成绩及平均分\n");
        printf("14. 打印学生所有课程成绩及总学分\n");
        printf("15. 判断学生是否达到毕业要求\n");
        printf("16. 保存并退出\n");
        printf("请选择(1-16): ");
        scanf("%d", &choice);
        getchar(); // 吃掉换行符

        switch (choice) {
            case 1: add_student(); break;
            case 2: delete_student(); break;
            case 3: update_student(); break;
            case 4: search_student(); break;
            case 5: add_course(); break;
            case 6: delete_course(); break;
            case 7: update_course(); break;
            case 8: search_course(); break;
            case 9: add_record(); break;
            case 10: delete_record(); break;
            case 11: update_record(); break;
            case 12: search_record(); break;
            case 13: print_student_grades(); break;
            case 14: print_student_credits(); break;
            case 15: check_graduation(); break;
            case 16: 
                save_students_to_file();
                save_courses_to_file();
                save_records_to_file();
                exit(0);
            default: printf("无效选择，请重新输入。\n");
        }
    }
}

//学生信息管理
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("学生人数已达上限！\n");
        return;
    }
    printf("请输入学号: ");
    gets(students[student_count].id);
    printf("请输入姓名: ");
    gets(students[student_count].name);
    printf("请输入性别: ");
    gets(students[student_count].gender);
    printf("请输入出生年月: ");
    gets(students[student_count].dob);
    printf("请输入电话: ");
    gets(students[student_count].phone);
    printf("请输入Email: ");
    gets(students[student_count].email);
    student_count++;
    printf("学生添加成功！\n");
}

void delete_student() {
    char id[10];
    printf("请输入要删除的学生学号: ");
    gets(id);
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("学生删除成功！\n");
            return;
        }
    }
    printf("找不到该学生！\n");
}

void update_student() {
    char id[10];
    printf("请输入要更新的学生学号: ");
    gets(id);
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("请输入新的姓名: ");
            gets(students[i].name);
            printf("请输入新的性别: ");
            gets(students[i].gender);
            printf("请输入新的出生年月: ");
            gets(students[i].dob);
            printf("请输入新的电话: ");
            gets(students[i].phone);
            printf("请输入新的Email: ");
            gets(students[i].email);
            printf("学生信息更新成功！\n");
            return;
        }
    }
    printf("找不到该学生！\n");
}

void search_student() {
    char id[10];
    printf("请输入要查找的学生学号: ");
    gets(id);
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("学号: %s\n", students[i].id);
            printf("姓名: %s\n", students[i].name);
            printf("性别: %s\n", students[i].gender);
            printf("出生年月: %s\n", students[i].dob);
            printf("电话: %s\n", students[i].phone);
            printf("Email: %s\n", students[i].email);
            return;
        }
    }
    printf("找不到该学生！\n");
}

// 课程信息管理
void add_course() {
    if (course_count >= MAX_COURSES) {
        printf("课程数量已达上限！\n");
        return;
    }
    printf("请输入课程号: ");
    gets(courses[course_count].id);
    printf("请输入课程名称: ");
    gets(courses[course_count].name);
    printf("请输入学分: ");
    scanf("%d", &courses[course_count].credits);
    getchar(); // 吃掉换行符
    printf("请输入课程类别: ");
    gets(courses[course_count].type);
    course_count++;
    printf("课程添加成功！\n");
}

void delete_course() {
    char id[10];
    printf("请输入要删除的课程号: ");
    gets(id);
    for (int i = 0; i < course_count; i++) {
        if (strcmp(courses[i].id, id) == 0) {
            for (int j = i; j < course_count - 1; j++) {
                courses[j] = courses[j + 1];
            }
            course_count--;
            printf("课程删除成功！\n");
            return;
        }
    }
    printf("找不到该课程！\n");
}

void update_course() {
    char id[10];
    printf("请输入要更新的课程号: ");
    gets(id);
    for (int i = 0; i < course_count; i++) {
        if (strcmp(courses[i].id, id) == 0) {
            printf("请输入新的课程名称: ");
            gets(courses[i].name);
            printf("请输入新的学分: ");
            scanf("%d", &courses[i].credits);
            getchar(); // 吃掉换行符
            printf("请输入新的课程类别: ");
            gets(courses[i].type);
            printf("课程信息更新成功！\n");
            return;
        }
    }
    printf("找不到该课程！\n");
}

void search_course() {
    char id[10];
    printf("请输入要查找的课程号: ");
    gets(id);
    for (int i = 0; i < course_count; i++) {
        if (strcmp(courses[i].id, id) == 0) {
            printf("课程号: %s\n", courses[i].id);
            printf("课程名称: %s\n", courses[i].name);
            printf("学分: %d\n", courses[i].credits);
            printf("课程类别: %s\n", courses[i].type);
            return;
        }
    }
    printf("找不到该课程！\n");
}

//成绩信息管理
void add_record() {
    if (record_count >= MAX_RECORDS) {
        printf("成绩记录数量已达上限！\n");
        return;
    }
    printf("请输入课程号: ");
    gets(records[record_count].course_id);
    printf("请输入学生学号: ");
    gets(records[record_count].student_id);
    printf("请输入学生姓名: ");
    gets(records[record_count].student_name);
    printf("请输入成绩: ");
    scanf("%d", &records[record_count].grade);
    getchar(); // 吃掉换行符
    record_count++;
    printf("成绩记录添加成功！\n");
}

void delete_record() {
    char course_id[10];
    char student_id[10];
    printf("请输入要删除的课程号: ");
    gets(course_id);
    printf("请输入要删除的学生学号: ");
    gets(student_id);
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].course_id, course_id) == 0 && strcmp(records[i].student_id, student_id) == 0) {
            for (int j = i; j < record_count - 1; j++) {
                records[j] = records[j + 1];
            }
            record_count--;
            printf("成绩记录删除成功！\n");
            return;
        }
    }
    printf("找不到该成绩记录！\n");
}

void update_record() {
    char course_id[10];
    char student_id[10];
    printf("请输入要更新的课程号: ");
    gets(course_id);
    printf("请输入要更新的学生学号: ");
    gets(student_id);
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].course_id, course_id) == 0 && strcmp(records[i].student_id, student_id) == 0) {
            printf("请输入新的成绩: ");
            scanf("%d", &records[i].grade);
            getchar(); // 吃掉换行符
            printf("成绩记录更新成功！\n");
            return;
        }
    }
    printf("找不到该成绩记录！\n");
}

void search_record() {
    char course_id[10];
    char student_id[10];
    printf("请输入要查找的课程号: ");
    gets(course_id);
    printf("请输入要查找的学生学号: ");
    gets(student_id);
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].course_id, course_id) == 0 && strcmp(records[i].student_id, student_id) == 0) {
            printf("课程号: %s\n", records[i].course_id);
            printf("学生学号: %s\n", records[i].student_id);
            printf("学生姓名: %s\n", records[i].student_name);
            printf("成绩: %d\n", records[i].grade);
            return;
        }
    }
    printf("找不到该成绩记录！\n");
}

void print_student_grades() {
    char student_id[10];
    printf("请输入学生学号: ");
    gets(student_id);
    int total_grades = 0, num_courses = 0;
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].student_id, student_id) == 0) {
            printf("学生学号: %s, 学生姓名: %s\n", records[i].student_id, records[i].student_name);
            break;
        }
    }
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].student_id, student_id) == 0) {
            printf("课程号: %s, 课程名称: %s , 成绩: %d\n", records[i].course_id, courses[i].name,records[i].grade);
            total_grades += records[i].grade;
            num_courses++;
        }
    }
    if (num_courses > 0) {
        printf("平均成绩: %.2f\n", (double)total_grades / num_courses);
    } else {
        printf("找不到该学生的成绩记录！\n");
    }
}

void print_student_credits() {
    char student_id[10];
    printf("请输入学生学号: ");
    gets(student_id);
    int total_credits = 0;
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].student_id, student_id) == 0) {
            printf("学生学号: %s, 学生姓名: %s\n",records[i].student_id, records[i].student_name);
            break;
        }
    }
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].student_id, student_id) == 0) {
            for (int j = 0; j < course_count; j++) {
                if (strcmp(records[i].course_id, courses[j].id) == 0) {
                    printf("课程号: %s,课程名称: %s , 成绩: %d, 学分: %d\n", records[i].course_id, courses[i].name, records[i].grade, courses[j].credits);
                    total_credits += courses[j].credits;
                }
            }
        }
    }
    printf("总学分: %d\n", total_credits);
}

void check_graduation() {
    char student_id[10];
    printf("请输入学生学号: ");
    gets(student_id);
    int basic_credits = 0, major_basic_credits = 0, major_elective_credits = 0, practical_credits = 0;
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].student_id, student_id) == 0) {
            for (int j = 0; j < course_count; j++) {
                if (strcmp(records[i].course_id, courses[j].id) == 0) {
                    if (strcmp(courses[j].type, "基础类课程") == 0) {
                        basic_credits += courses[j].credits;
                    } else if (strcmp(courses[j].type, "专业基础类课程") == 0) {
                        major_basic_credits += courses[j].credits;
                    } else if (strcmp(courses[j].type, "专业选修类课程") == 0) {
                        major_elective_credits += courses[j].credits;
                    } else if (strcmp(courses[j].type, "实践类课程") == 0) {
                        practical_credits += courses[j].credits;
                    }
                }
            }
        }
    }
    printf("基础类课程学分: %d\n", basic_credits);
    printf("专业基础类课程学分: %d\n", major_basic_credits);
    printf("专业选修类课程学分: %d\n", major_elective_credits);
    printf("实践类课程学分: %d\n", practical_credits);

    if (basic_credits >= 20 && major_basic_credits >= 30 && major_elective_credits >= 25 && practical_credits >= 25) {
        printf("该学生已达到毕业要求！\n");
    } else {
        printf("该学生未达到毕业要求！\n");
    }
}

//加载、保存文件
void save_students_to_file() {
    FILE *file = fopen("./students.txt", "w");
    if (file == NULL) {
        printf("无法打开学生信息文件！\n");
        return;
    }
    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%s %s %s %s %s %s\n", students[i].id, students[i].name, students[i].gender, students[i].dob, students[i].phone, students[i].email);
    }
    fclose(file);
    printf("学生信息保存成功！\n");
}

void load_students_from_file() {
    FILE *file = fopen("./students.txt", "r");
    if (file == NULL) {
        printf("无法打开学生信息文件！\n");
        return;
    }
    student_count = 0;
    while (fscanf(file, "%s %s %s %s %s %s", students[student_count].id, students[student_count].name, students[student_count].gender, students[student_count].dob, students[student_count].phone, students[student_count].email) != EOF) {
        student_count++;
    }
    fclose(file);
    printf("学生信息加载成功！\n");
}

void save_courses_to_file() {
    FILE *file = fopen("./courses.txt", "w");
    if (file == NULL) {
        printf("无法打开课程信息文件！\n");
        return;
    }
    for (int i = 0; i < course_count; i++) {
        fprintf(file, "%s %s %d %s\n", courses[i].id, courses[i].name, courses[i].credits, courses[i].type);
    }
    fclose(file);
    printf("课程信息保存成功！\n");
}

void load_courses_from_file() {
    FILE *file = fopen("./courses.txt", "r");
    if (file == NULL) {
        printf("无法打开课程信息文件！\n");
        return;
    }
    course_count = 0;
    while (fscanf(file, "%s %s %d %s", courses[course_count].id, courses[course_count].name, &courses[course_count].credits, courses[course_count].type) != EOF) {
        course_count++;
    }
    fclose(file);
    printf("课程信息加载成功！\n");
}

void save_records_to_file() {
    FILE *file = fopen("./records.txt", "w");
    if (file == NULL) {
        printf("无法打开成绩信息文件！\n");
        return;
    }
    for (int i = 0; i < record_count; i++) {
        fprintf(file, "%s %s %s %d\n", records[i].course_id, records[i].student_id, records[i].student_name, records[i].grade);
    }
    fclose(file);
    printf("成绩信息保存成功！\n");
}

void load_records_from_file() {
    FILE *file = fopen("./records.txt", "r");
    if (file == NULL) {
        printf("无法打开成绩信息文件！\n");
        return;
    }
    record_count = 0;
    while (fscanf(file, "%s %s %s %d", records[record_count].course_id, records[record_count].student_id, records[record_count].student_name, &records[record_count].grade) != EOF) {
        record_count++;
    }
    fclose(file);
    printf("成绩信息加载成功！\n");
}
