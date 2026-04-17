import java.util.*;

enum Status {
    ACTIVE,
    INACTIVE,
    GRADUATED;

    static void printOptions() {
        System.out.println("1. ACTIVE");
        System.out.println("2. INACTIVE");
        System.out.println("3. GRADUATED");
    }

    static Status fromChoice(int choice) {
        return switch (choice) {
            case 1 -> ACTIVE;
            case 2 -> INACTIVE;
            case 3 -> GRADUATED;
            default -> ACTIVE;
        };
    }
}

class Student {
    private final String name;
    private final int id;
    private Status status;

    Student(String name, int id, Status status) {
        this.name = name;
        this.id = id;
        this.status = status;
    }

    int getId() {
        return id;
    }

    Status getStatus() {
        return status;
    }

    void setStatus(Status status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return String.format("%-25s | %-6d | %-10s", name, id, status);
    }
}

public class MiniProject {
    private static final List<Student> students = new ArrayList<>();
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {
            printHeader("Student Registry Mini-Project");
            printMainMenu();
            int choice = readInt("Choose an option:", 1, 5);
            switch (choice) {
                case 1 -> addStudent();
                case 2 -> viewStudents();
                case 3 -> updateStatus();
                case 4 -> generateReport();
                case 5 -> exitProgram();
                default -> printError("Unexpected choice. Please try again.");
            }
        }
    }

    private static void printMainMenu() {
        System.out.println("1. Add Student");
        System.out.println("2. View Students");
        System.out.println("3. Update Status");
        System.out.println("4. Generate Report");
        System.out.println("5. Exit");
    }

    private static void addStudent() {
        printSection("Add Student");
        String name = readNonEmptyLine("Enter full name:");
        int id = readUniqueId("Enter student ID:");
        Status status = selectStatus("Choose initial status:");
        students.add(new Student(name, id, status));
        printSuccess("Student added successfully.");
        pressEnterToContinue();
    }

    private static void viewStudents() {
        printSection("Student List");
        if (students.isEmpty()) {
            printInfo("No students registered yet.");
        } else {
            System.out.printf("%-25s | %-6s | %-10s%n", "Name", "ID", "Status");
            System.out.println("---------------------------+--------+------------");
            for (Student student : students) {
                System.out.println(student);
            }
        }
        pressEnterToContinue();
    }

    private static void updateStatus() {
        printSection("Update Student Status");
        if (students.isEmpty()) {
            printInfo("No students available to update.");
            pressEnterToContinue();
            return;
        }
        int id = readInt("Enter student ID to update:", Integer.MIN_VALUE, Integer.MAX_VALUE);
        Student student = findStudentById(id);
        if (student == null) {
            printError("Student not found.");
        } else {
            System.out.println("Current student: " + student);
            Status newStatus = selectStatus("Choose new status:");
            student.setStatus(newStatus);
            printSuccess("Status updated for student ID " + id + ".");
        }
        pressEnterToContinue();
    }

    private static void generateReport() {
        printSection("Registration Report");
        if (students.isEmpty()) {
            printInfo("No students registered yet.");
            pressEnterToContinue();
            return;
        }
        int total = students.size();
        int active = countByStatus(Status.ACTIVE);
        int inactive = countByStatus(Status.INACTIVE);
        int graduated = countByStatus(Status.GRADUATED);
        int maxId = students.stream().mapToInt(Student::getId).max().orElse(0);
        int minId = students.stream().mapToInt(Student::getId).min().orElse(0);

        System.out.printf("Total students:          %d%n", total);
        System.out.printf("Active students:         %d%n", active);
        System.out.printf("Inactive students:       %d%n", inactive);
        System.out.printf("Graduated students:      %d%n", graduated);
        System.out.printf("Student ID range:        %d - %d%n", minId, maxId);
        System.out.println("------------------------------------------------");
        System.out.printf("Class size:              %s%n", classifyClassSize(total));
        System.out.printf("Graduation rate:         %s%%%n", formatPercent((double) graduated / total * 100));
        System.out.printf("Graduation summary:      %s%n", interpretGraduationRate((double) graduated / total * 100));
        System.out.printf("Activity rate:           %s%%%n", formatPercent((double) active / total * 100));
        System.out.printf("Activity summary:        %s%n", interpretActivityLevel((double) active / total * 100));
        pressEnterToContinue();
    }

    private static String readNonEmptyLine(String prompt) {
        while (true) {
            System.out.print(prompt + " ");
            String line = scanner.nextLine().trim();
            if (!line.isEmpty()) {
                return line;
            }
            printError("Input cannot be empty. Please enter a valid value.");
        }
    }

    private static int readInt(String prompt, int min, int max) {
        while (true) {
            System.out.print(prompt + " ");
            String input = scanner.nextLine().trim();
            try {
                int value = Integer.parseInt(input);
                if (value >= min && value <= max) {
                    return value;
                }
                printError("Please enter a number between " + min + " and " + max + ".");
            } catch (NumberFormatException e) {
                printError("Invalid input. Please enter a whole number.");
            }
        }
    }

    private static int readUniqueId(String prompt) {
        while (true) {
            int id = readInt(prompt, 1, Integer.MAX_VALUE);
            if (findStudentById(id) == null) {
                return id;
            }
            printError("This ID already exists. Please choose another ID.");
        }
    }

    private static Status selectStatus(String prompt) {
        System.out.println(prompt);
        Status.printOptions();
        int choice = readInt("Enter option:", 1, 3);
        return Status.fromChoice(choice);
    }

    private static Student findStudentById(int id) {
        for (Student student : students) {
            if (student.getId() == id) {
                return student;
            }
        }
        return null;
    }

    private static int countByStatus(Status status) {
        int count = 0;
        for (Student student : students) {
            if (student.getStatus() == status) {
                count++;
            }
        }
        return count;
    }

    private static String classifyClassSize(int total) {
        if (total < 5) {
            return "Small class (fewer than 5 students)";
        }
        if (total < 15) {
            return "Medium class (5-14 students)";
        }
        return "Large class (15 or more students)";
    }

    private static String interpretGraduationRate(double rate) {
        if (rate < 30) {
            return "Low graduation rate (needs improvement)";
        }
        if (rate < 70) {
            return "Moderate graduation rate (acceptable)";
        }
        return "High graduation rate (excellent)";
    }

    private static String interpretActivityLevel(double rate) {
        if (rate > 80) {
            return "Highly active (most students engaged)";
        }
        if (rate > 50) {
            return "Moderately active (more than half engaged)";
        }
        return "Low activity (needs more engagement)";
    }

    private static String formatPercent(double value) {
        return String.format(Locale.US, "%.2f", value);
    }

    private static void printHeader(String title) {
        System.out.println();
        System.out.println("================================================");
        System.out.println("  " + title);
        System.out.println("================================================");
    }

    private static void printSection(String title) {
        System.out.println();
        System.out.println("---- " + title + " ----");
    }

    private static void printSuccess(String message) {
        System.out.println("[SUCCESS] " + message);
    }

    private static void printError(String message) {
        System.out.println("[ERROR] " + message);
    }

    private static void printInfo(String message) {
        System.out.println("[INFO] " + message);
    }

    private static void pressEnterToContinue() {
        System.out.println();
        System.out.print("Press Enter to continue...");
        scanner.nextLine();
    }

    private static void exitProgram() {
        printInfo("Exiting program. Goodbye!");
        System.exit(0);
    }
}
