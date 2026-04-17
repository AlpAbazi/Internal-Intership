import java.util.*;

enum Status {
    ACTIVE,
    INACTIVE,
    GRADUATED
}

class Student {
    String name;
    int id;
    Status status;

    Student(String name, int id, Status status) {
        this.name = name;
        this.id = id;
        this.status = status;
    }
}

public class MiniProject {
    static List<Student> students = new ArrayList<>();
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {
            System.out.println("Main Menu:");
            System.out.println("1. Add Student");
            System.out.println("2. View Students");
            System.out.println("3. Update Status");
            System.out.println("4. Generate Report");
            System.out.println("5. Exit");
            System.out.print("Choose: ");
            int choice = getValidInt(1, 5);
            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    viewStudents();
                    break;
                case 3:
                    updateStatus();
                    break;
                case 4:
                    generateReport();
                    break;
                case 5:
                    System.exit(0);
            }
        }
    }

    static int getValidInt(int min, int max) {
        while (true) {
            try {
                int num = scanner.nextInt();
                if (num >= min && num <= max) {
                    return num;
                } else {
                    System.out.println("Invalid choice. Please enter between " + min + " and " + max);
                }
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter a number.");
                scanner.next(); // consume invalid input
            }
        }
    }

    static void addStudent() {
        System.out.print("Enter name: ");
        String name = scanner.next();
        System.out.print("Enter id: ");
        int id = scanner.nextInt();
        System.out.println("Choose status:");
        System.out.println("1. ACTIVE");
        System.out.println("2. INACTIVE");
        System.out.println("3. GRADUATED");
        int statusChoice = getValidInt(1, 3);
        Status status = switch (statusChoice) {
            case 1 -> Status.ACTIVE;
            case 2 -> Status.INACTIVE;
            case 3 -> Status.GRADUATED;
            default -> Status.ACTIVE; // won't happen
        };
        students.add(new Student(name, id, status));
        System.out.println("Student added.");
    }

    static void viewStudents() {
        for (Student s : students) {
            System.out.println("Name: " + s.name + ", ID: " + s.id + ", Status: " + s.status);
        }
    }

    static void updateStatus() {
        System.out.print("Enter student ID to update: ");
        int id = scanner.nextInt();
        Student student = null;
        for (Student s : students) {
            if (s.id == id) {
                student = s;
                break;
            }
        }
        if (student == null) {
            System.out.println("Student not found.");
            return;
        }
        System.out.println("Choose new status:");
        System.out.println("1. ACTIVE");
        System.out.println("2. INACTIVE");
        System.out.println("3. GRADUATED");
        int statusChoice = getValidInt(1, 3);
        Status status = switch (statusChoice) {
            case 1 -> Status.ACTIVE;
            case 2 -> Status.INACTIVE;
            case 3 -> Status.GRADUATED;
            default -> Status.ACTIVE;
        };
        student.status = status;
        System.out.println("Status updated.");
    }

    static void generateReport() {
        if (students.isEmpty()) {
            System.out.println("No students registered yet.");
            return;
        }
        int total = students.size();
        int active = 0;
        int inactive = 0;
        int graduated = 0;
        int maxId = Integer.MIN_VALUE;
        int minId = Integer.MAX_VALUE;
        for (Student s : students) {
            if (s.status == Status.ACTIVE) active++;
            else if (s.status == Status.INACTIVE) inactive++;
            else if (s.status == Status.GRADUATED) graduated++;
            if (s.id > maxId) maxId = s.id;
            if (s.id < minId) minId = s.id;
        }
        System.out.println("=== Student Registration Report ===");
        System.out.println("Total Registrations: " + total);
        System.out.println("Active Students: " + active);
        System.out.println("Inactive Students: " + inactive);
        System.out.println("Graduated Students: " + graduated);
        System.out.println("Highest ID: " + maxId);
        System.out.println("Lowest ID: " + minId);
        // Classification for class size
        String classSize;
        if (total < 5) classSize = "Small class (fewer than 5 students)";
        else if (total < 15) classSize = "Medium class (5-14 students)";
        else classSize = "Large class (15 or more students)";
        System.out.println("Class Size Classification: " + classSize);
        // Graduation rate
        double gradRate = (double) graduated / total * 100;
        String graduationRate;
        if (gradRate < 30) graduationRate = "Low graduation rate (needs improvement)";
        else if (gradRate < 70) graduationRate = "Moderate graduation rate (acceptable)";
        else graduationRate = "High graduation rate (excellent)";
        System.out.println("Graduation Rate: " + String.format("%.2f", gradRate) + "% - " + graduationRate);
        // Activity level
        double activeRate = (double) active / total * 100;
        String activity;
        if (activeRate > 80) activity = "Highly active (most students engaged)";
        else if (activeRate > 50) activity = "Moderately active (half engaged)";
        else activity = "Low activity (needs more engagement)";
        System.out.println("Activity Level: " + String.format("%.2f", activeRate) + "% - " + activity);
    }
}