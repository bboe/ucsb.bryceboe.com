#include <iostream>
using namespace std;

struct Record {                      // CHANGE TO class

// DECLARE A public SECTION, AND DEFINE A NEW METHOD NAMED setGrades,
// THAT TAKES FOUR double ARGUMENTS

// DECLARE A private SECTION AND MAKE ALL DATA PART OF IT
    double quiz1, quiz2;
    double midterm, final;
};

Record getScores();

char letterEquiv(double grade);      // MOVE TO private SECTION OF THE CLASS
                            // AND FIX SIGNATURE TO SUPPORT CONSTANT OBJECTS

char overallGrade(const Record r);   // MOVE TO public SECTION OF THE CLASS
                            // AND MAKE SIGNATURE BE 'char overallGrade() const'

int main() {
    Record rec = getScores();
    cout << "Grade is " << overallGrade(rec) << endl;    // FIX USAGE OF rec
    return 0;
}

// getScores IS AN external FUNCTION, SO IT MUST USE setGrades TO SET THE VALUES
// OF THE OBJECT'S private DATA (Hint: You'll need some local variables.)
Record getScores() {
    Record result;
    cout << "Enter scores in this order: 2 quizzes, midterm, final: ";
    cin >> result.quiz1 >> result.quiz2 >> result.midterm >> result.final;
    return result;
}

// THE NEXT TWO FUNCTIONS ARE METHODS OF THE CLASS, SO THEY MUST PROPERLY
// BE IDENTIFIED AS SUCH WITH THE SCOPE RESOLUTION OPERATOR '::'

char letterEquiv(double grade) {      // FIX SIGNATURE
    if (grade >= 90) return 'A';
    if (grade >= 80) return 'B';
    if (grade >= 70) return 'C';
    if (grade >= 60) return 'D';
    return 'F';
}

char overallGrade(const Record r) {   // FIX SIGNATURE
    // ALSO CHANGE HOW THE OBJECT'S DATA ARE ACCESSED (WHO IS r NOW?  ;-)
    double quizPct = (r.quiz1 / 10 + r.quiz2 / 10) / 2;
    double overall = 25 * quizPct + 0.25 * r.midterm + 0.5 * r.final;
    return letterEquiv(overall);
}

// ASK A TA TO HELP IF YOU GET STUCK, BUT FIRST TRY YOUR BEST TO FIGURE IT OUT!
