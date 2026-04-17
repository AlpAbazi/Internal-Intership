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
            System.out.println("4. Exit");
            System.out.print("Choose: ");
            int choice = getValidInt(1, 4);
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
}