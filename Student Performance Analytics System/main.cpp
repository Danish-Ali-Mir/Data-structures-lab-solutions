#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Stu {
    int id;
    char name[100];
    char dept[4];
    int sem;
    float gpa;
    int cred;
    int yr;
    Stu* nxt;
};

Stu* first = nullptr;
int total = 0;

/* ===================== DATA LOADING ===================== */
void load() {
    ifstream in("students_data.txt");
    ofstream issues("data_issues.txt");

    if (!in) {
        cout << "Input file not found\n";
        return;
    }

    int id, sem, cred, yr;
    float gpa;
    char dept[4];
    string fname, lname;

    while (in >> id >> fname >> lname >> dept >> sem >> gpa >> cred >> yr) {

        // Validation
        if (gpa < 0 || gpa > 4 || sem < 1 || sem > 8) {
            issues << "Invalid record skipped: " << id << endl;
            continue;
        }

        Stu* n = new Stu;
        n->id = id;
        strcpy(n->name, (fname + " " + lname).c_str());
        strcpy(n->dept, dept);
        n->sem = sem;
        n->gpa = gpa;
        n->cred = cred;
        n->yr = yr;
        n->nxt = nullptr;

        if (!first) first = n;
        else {
            Stu* t = first;
            while (t->nxt) t = t->nxt;
            t->nxt = n;
        }
        total++;
    }

    in.close();
    issues.close();
}

/* ===================== UTILITY ===================== */
void swapStu(Stu* a, Stu* b) {
    Stu temp = *a;
    *a = *b;
    *b = temp;
    a->nxt = b->nxt;
    b->nxt = temp.nxt;
}

/* ===================== SELECTION SORT ===================== */
void sortCGPA(Stu* head) {
    for (Stu* i = head; i; i = i->nxt) {
        Stu* maxN = i;
        for (Stu* j = i->nxt; j; j = j->nxt) {
            if (j->gpa > maxN->gpa ||
               (j->gpa == maxN->gpa && j->cred > maxN->cred))
                maxN = j;
        }
        if (maxN != i) swapStu(i, maxN);
    }
}

/* ===================== INSERTION SORT (NAME) ===================== */
void insertName(Stu** h, Stu* n) {
    if (!*h || strcmp(n->name, (*h)->name) < 0) {
        n->nxt = *h;
        *h = n;
        return;
    }
    Stu* c = *h;
    while (c->nxt && strcmp(n->name, c->nxt->name) > 0)
        c = c->nxt;
    n->nxt = c->nxt;
    c->nxt = n;
}

/* ===================== FILE 1 ===================== */
void makeFile1() {
    Stu* copy = nullptr;
    for (Stu* o = first; o; o = o->nxt) {
        Stu* n = new Stu(*o);
        n->nxt = copy;
        copy = n;
    }

    sortCGPA(copy);

    ofstream out("ranked_by_cgpa.txt");
    out << "====================================================\n";
    out << "        STUDENTS RANKED BY CGPA\n";
    out << "====================================================\n";
    out << "Rank | ID     | Name              | Dept | Sem | CGPA | Credits | Year\n";
    out << "-----|--------|-------------------|------|-----|------|---------|------\n";

    int r = 1;
    for (Stu* c = copy; c; c = c->nxt) {
        out << setw(3) << r++ << "  | "
            << setw(6) << c->id << " | "
            << left << setw(17) << c->name << " | "
            << setw(4) << c->dept << " | "
            << setw(3) << c->sem << " | "
            << fixed << setprecision(2) << c->gpa << " | "
            << setw(7) << c->cred << " | "
            << c->yr << endl;
    }
    out.close();
}

/* ===================== FILE 4 (SECOND SORT) ===================== */
void makeFile4() {
    Stu *elite=nullptr, *high=nullptr, *good=nullptr, *sat=nullptr, *need=nullptr;
    int e=0,h=0,g=0,s=0,n=0;

    for (Stu* c = first; c; c = c->nxt) {
        Stu* x = new Stu(*c);
        x->nxt = nullptr;

        if (c->gpa >= 3.7) insertName(&elite,x), e++;
        else if (c->gpa >= 3.3) insertName(&high,x), h++;
        else if (c->gpa >= 3.0) insertName(&good,x), g++;
        else if (c->gpa >= 2.5) insertName(&sat,x), s++;
        else insertName(&need,x), n++;
    }

    ofstream out("performance_tiers.txt");
    out << "PERFORMANCE TIERS\n=================\n\n";
    out << "Elite: " << e << " (" << fixed << setprecision(1) << e*100.0/total << "%)\n";
    for (Stu* c=elite;c;c=c->nxt) out<<c->name<<" "<<c->gpa<<endl;
    out.close();
}

/* ===================== CLEANUP ===================== */
void freeAll() {
    while (first) {
        Stu* t = first;
        first = first->nxt;
        delete t;
    }
}

int main() {
    load();
    if (!first) return 0;

    makeFile1();
    makeFile4();
    freeAll();

    cout << "All files generated successfully\n";
    return 0;
}
